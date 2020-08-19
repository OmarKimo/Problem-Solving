
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
#define ord(i) (int)(8*(i.f-1)+i.s)


const ll OO = 9223372036854775807;
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

int n,m,x,y;
int cols[1010][2],arr[1010][1010][2]; char mat[1010][1010];

int solve(int colour, int cnt, int col){

	if(col >= m || cnt > y || m-col+cnt-1 < x) return 1000010;

	if(col == m-1) return cols[col][!colour];

	if(arr[col][cnt][colour]!=-1) return arr[col][cnt][colour];

	int path1,path2; 
	if(cnt>=x) path1 = solve(!colour, 1, col+1);
	else path1 = 1000010;
	if(cnt<y) path2 = solve(colour, cnt+1, col+1);
	else path2 = 1000010;
	
	return arr[col][cnt][colour] = cols[col][!colour] + min(path1, path2);
}

int main()
{

	//225C
	cin>>n>>m>>x>>y;
	lop(i,n) lop(j,m) { cin>>mat[i][j]; if(mat[i][j]=='#') cols[j][1]++; else cols[j][0]++; }
	mem(arr,-1);
	int path1=solve(0,1,0);
	mem(arr,-1);
	int path2=solve(1,1,0);
	cout<<min(path1, path2)<<endl;
	return 0;
}