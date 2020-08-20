#include <iostream>
#include <stdio.h>
#include <limits.h>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <bitset>
#include <string>
#include <stack>
#include <queue>
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
typedef pair<ll,ll> llll;
typedef vector<int> vi ;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<ii> vii;
typedef vector<llll> vllll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vb> vvb;
typedef vector<vc> vvc;
typedef vector<vii> vvii;
typedef map<int,int> mii;
typedef map<string,int> msi;
typedef map<int,string> mis;
typedef map<string,string> mss;
typedef map<int,char> mic;
typedef map<char,int> mci;

#define sc(x)  scanf("%d",&x)
#define scl(x) scanf("%I64d",&x)
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


const ll OO = (ll)1e18+9;
const int oo = 2147483647;
const double EPS = 1e-9;
const double PI=acos(-1.0);

//enum dir { u, r, d, l };
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

//enum diR { d, r, u, l , dr, ur, dl, ul };
int dX[] = { 1, 0, -1, 0, 1, -1, 1, -1 };
int dY[] = { 0, 1, 0, -1, 1, 1, -1, -1 };

char letters[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

int dot(int x, int y, int x2, int y2) {return x * x2 + y * y2; }
ll gcd (ll x, ll y){ return !y ? x : gcd(y, x%y); }
int ord(int r,int c,int nCol) { return (nCol*r) + c + 1; } //transform from 2-D matrix to 1-D array. (Zero-indexed)
//Compare Double Numbers
int cmpDouble(ld d1,ld d2){ return fabs(d1-d2)<=EPS?0:d1>d2?1:-1; }

int a,b,target,steps=0;

void path1(int v1, int v2){
	if(v1 == target || v2 == target) return;

	if(!v2) steps++, path1(v1,b);
	else if(v1 == a) steps++, path1(0,v2);
	else{
		steps++;
		if(v1 + v2 > a) path1(a,v2-a+v1);
		else path1(v1+v2,0);
	}
}

void path2(int v1, int v2){
	if(v1 == target || v2 == target) return;

	if(!v1) steps++, path2(a,v2);
	else if(v2 == b) steps++, path2(v1,0);
	else{
		steps++;
		if(v1 + v2 > b) path2(v1-b+v2,b);
		else path2(0,v1+v2);
	}
}

int main()
{
	
	//
	int t,ans=0;
	cin>>t;
	while(t--){
		cin>>a>>b>>target;
		if(a<b) swap(a,b);
		if(target > a || target % gcd(a,b)){ puts("-1"); continue; }
		steps=0;
		path1(0,0);
		ans=steps, steps=0;
		path2(0,0);
		ans = min(ans,steps);
		cout<<ans<<endl;
	}
	return 0;
}