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
typedef vector<int> vi ;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vb> vvb;
typedef vector<vc> vvc;
typedef map<int,int> mii;
typedef map<string,int> msi;
typedef map<int,string> mis;
typedef map<string,string> mss;
typedef map<int,char> mic;
typedef map<char,int> mci;
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

int n,m,ch=0,flag=0,tmpi,tmpj,di,dj;
vvi vis(60,vi (60,0));
vvc mat(60,vc(60));
void dfs(int i, int j, int dircx, int dircy){
	if(i >= n || i < 0 || j>=m || j<0) return;
	if(vis[i][j] || mat[i][j] != mat[tmpi][tmpj]) return;
	if(ch >= 4 && i == tmpi && j == tmpj && (dircx != -di || dircy != -dj)) { flag=1; return; }
	ch++; 
	if(i != tmpi || j != tmpj) vis[i][j] = 1;
	lop(k,4) {
		if(i == tmpi && j == tmpj) ch=1,di=dx[k],dj=dy[k];
		dfs(i+dx[k], j+dy[k], dx[k], dy[k]);
	}
}

int main()
{

	//510B
	cin>>n>>m;
	lop(i,n) lop(j,m) cin>>mat[i][j];
	lop(i,n) lop(j,m){
		clr(vis), rsz(vis)(60,vi (60,0));
		ch = 0, tmpi = i, tmpj = j;
		dfs(i,j,0,0);
		if(flag) return puts("Yes");
	}
	cout<<"No\n";



	return 0;
}