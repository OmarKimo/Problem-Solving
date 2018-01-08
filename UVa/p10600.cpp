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
 
//enum diR { d, r, u, l , dr, ur, dl, ul };
int dX[] = { 1, 0, -1, 0, 1, -1, 1, -1 };
int dY[] = { 0, 1, 0, -1, 1, 1, -1, -1 };
 
char letters[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
 
int dcmp(ld d1,ld d2){ return fabs(d1-d2)<=EPS?0:d1>d2?1:-1; } //Compare Double Numbers
ll gcd (ll x, ll y){ return !y ? x : gcd(y, x%y); }
ll lcm (ll a, ll b) { return a * (b / gcd(a, b)); }
int ord(int r,int c,int nCol) { return (nCol*r) + c + 1; } //convert index from 2D matrix to 1D array. (Zero-indexed)
 
/***Disjoint-Set Data Structure***/
struct UnionFind {
//private: 
	vi p, rank; //p stands for Parent
	int forests;
//public:
	UnionFind(int N) { 
		rank.assign(N, 0);
		p.assign(N, 0);
		forests = N;
		for (int i = 0; i < N; i++) p[i] = i; 
	}
	int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); } //Dynamic Programming ^_^
	bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
	bool unionSet(int i, int j) {
		bool flag = !isSameSet(i, j);
		if (flag) { // if from different set
			int x = findSet(i), y = findSet(j);
			if (rank[x] > rank[y]) swap(x,y); // rank keeps the tree short
			p[x] = y;
			if (rank[x] == rank[y]) rank[y]++;
			forests--;
		}
		return flag;
	}
	vvi connected_component(){
		vvi list(sz(p));
		lop(i,sz(p)) list[findSet(i)].PB(i);
		return list;
	}
};
 
vvi flag(111,vi(111,0));
pair<int, vector<edge>> MST_Kruskal(vector<edge> EdgeList, int V){ 
	int E = sz(EdgeList);
	vector<edge> edges;
	int mst_cost = 0;
	UnionFind UF(V+1);
	for (int i = 0; i < E; i++) {
		edge e = EdgeList[i];
		if(flag[e.s.f][e.s.s] || flag[e.s.s][e.s.f]) continue;
		if (UF.unionSet(e.s.f, e.s.s)) {
			mst_cost += e.f;
			edges.PB(e);
		} 
	}
if(sz(edges) != V-1) return mP(oo,vector<edge>());
	return mP(mst_cost,edges);
}
 
 
int main()
{
	//p10600
	int t;
	cin>>t;
	while(t--){
		int n,m,u,v,w,ans1,ans2=oo;
		cin>>n>>m;
		rsz(flag)(111,vi(111,0));
		vector<edge> edges;
		pair<int,vector<edge>> mst;
		lop(i,m) sc(u),sc(v),sc(w),edges.PB(mP(w,ii(u,v)));
		sort(all(edges));
		mst = MST_Kruskal(edges,n);
		ans1 = mst.f;
		lop(i,sz(mst.s)){
			edge e = mst.s[i];
			flag[e.s.f][e.s.s] = flag[e.s.s][e.s.f] = 1;
			ans2 = min(ans2,MST_Kruskal(edges,n).f);
			flag[e.s.f][e.s.s] = flag[e.s.s][e.s.f] = 0;
		}
		cout<<ans1<<' '<<ans2<<endl;
	}
 
 
 
	return 0;
}