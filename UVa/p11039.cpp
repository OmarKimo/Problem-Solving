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
#define ord(i) (int)(8*(i.f-1)+i.s)

const int oo = 2147483647;
const double EPS = 1e-9;
const double PI=acos(-1.0);

//enum dir { d, r, u, l };
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

//enum diR { d, r, u, l , dr, ur, dl, ul };
int dX[] = { 1, 0, -1, 0, 1, -1, 1, -1 };
int dY[] = { 0, 1, 0, -1, 1, 1, -1, -1 };


int dot(int x, int y, int x2, int y2) {return x * x2 + y * y2; }
ll gcd (ll x, ll y){ return !y ? x : gcd(y, x%y); }
//Compare Double Numbers
int cmpDouble(ld d1,ld d2){ return fabs(d1-d2)<=EPS?0:d1>d2?1:-1; }


int main()
{
	//
	int t,n,num,cnt=0;
	cin>>t;
	while(t--){
		cin>>n;
		vi red, blue;
		cnt=0;
		lop(i,n){
			cin>>num;
			if(num>0) red.push_back(num);
			else blue.push_back(abs(num));
		}
		sort(all(red), [](int i, int j){return i>j; } ), sort(all(blue),[](int i, int j){return i>j; });

		int i1=0,i2=0,flag=0,can=0,mx=oo;
		if(blue[0] > red[0]) flag=1;
		while(true){
			can=0;
			if(flag){
				loop(i,i1,sz(blue)){
					if(blue[i] < mx) { can=1,mx=blue[i],i1=i+1; break; }
				}
				flag=0;
				if(can) cnt++;
				else break;
			}
			else{
				loop(i,i2,sz(red)){
					if(red[i] < mx) { can=1,mx=red[i],i2=i+1; break; }
				}
				flag=1;
				if(can) cnt++;
				else break;
			}
		}
		cout<<cnt<<endl;
	}

	return 0;
}