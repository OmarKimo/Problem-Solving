#include <iostream>
#include <stdio.h>
#include <limits.h>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <complex>
#include <bitset>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>
#include <iomanip>
#include <valarray>
#include <sstream>
#include <fstream>
#include <functional>
#include <utility>
#include <numeric>
#include <iterator>

using namespace std;
typedef unsigned int uint;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vector<char>> vvc;
typedef map<int,int> mii;
typedef pair<int, ii> edge;


#define sc(x)  scanf("%d",&x)
#define scl(x) scanf("%lld",&x)
#define all(v) v.begin(),v.end()
#define mem(arr,val) memset(arr,val,sizeof arr)
#define sz(v) (int)v.size()
#define rsz(v) v.resize
#define clr(v) v.clear()
#define rev(v) reverse(all(v))
#define lop(i,n) for(int i=0; i<n; i++)
#define rlop(i,n) for(int i=n-1; i>=0; i--)
#define loop(i,start,n) for(int i=start; i<n; i++)
#define rloop(i,end,n) for(int i=n-1; i>=end; i--)
#define PB push_back
#define pb pop_back
#define mP make_pair
#define f first
#define s second
#define ord0(s) (int)(s-'0')
#define orda(s) (int)(s-'a')
#define ordA(s) (int)(s-'A')

const ll OO = (ll)(1e18)+9;
const ll MOD = (ll)(1e9)+7;
const int oo = 2147483647;
const double EPS = 1e-8;
const double PI = acos(-1.0);

//enum dir { u, r, d, l };
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

//enum diR { d, r, u, l , dr, ur, dl, ul };
int dX[] = { 1, 0, -1, 0, 1, -1, 1, -1 };
int dY[] = { 0, 1, 0, -1, 1, 1, -1, -1 };

char letters[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

int dcmp(ld d1,ld d2){ return fabs(d1-d2)<=EPS?0:d1>d2?1:-1; } //Compare Double Numbers
ll gcd (ll x, ll y){ return !y ? x : gcd(y, x%y); }
ll lcm (ll a, ll b) { return a * (b / gcd(a, b)); }
int ord(int r,int c,int nCol) { return (nCol*r) + c + 1; } //convert index from 2D matrix to 1D array. (Zero-indexed)

const int N = 100010;
ll noise[N];
pair<ll,ll> cal(string x, int idx){
	ll cnts=0,cnth=0;
	ll cnt = 0;
	vector<ll> nums(sz(x),0);
	if(x[0] == 'h') cnth++, nums[0] = 1;
	else cnts++;
	loop(i,1,sz(x)){
		if(x[i] == 's') cnts++, nums[i] = nums[i-1];
		else cnth++, nums[i] = 1 + nums[i-1];
	}
	lop(i,sz(x)) if(x[i] == 's') cnt += (ll)nums.back() - (ll)nums[i];
	noise[idx] = cnt;
	return pair<ll,ll>(cnts,cnth);
}

bool my(pair<pair<ll,ll>,int> p1, pair<pair<ll,ll>,int> p2){
	return p1.first.f*p2.f.s > p2.first.f*p1.f.s;
}

int main()
{	
	//
	int n;
	ll ans = 0;
	cin>>n;
	vector<pair<pair<ll,ll>,int>> v(n);
	string in;
	lop(i,n){
		cin>>in;
		v[i].f = cal(in, i), v[i].second = i;
	}
	sort(all(v),my);
	ans = noise[v[0].s];
	ll ss = v[0].first.first;
	loop(i,1,n){
		ans += noise[v[i].s] + ss * v[i].first.second;
		ss += v[i].first.f;
	}
	cout<<ans<<endl;


	return 0;
}