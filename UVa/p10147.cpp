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
 
vii towns;
bool fun(edge e1, edge e2){
return e1.f < e2.f;
}
vi MST_Kruskal(vector<edge> EdgeList, int V){
	int w,E = sz(EdgeList);
	vi ret;
	UnionFind UF(V+1);
	for (int i = 0; i < E; i++) {
		edge e = EdgeList[i];
		UF.unionSet(e.s.f, e.s.s);
	}
	clr(EdgeList);
	loop(i,1,V+1) loop(j,i+1,V+1) w = pow((towns[i-1].f - towns[j-1].f),2) + pow((towns[i-1].s - towns[j-1].s),2), EdgeList.PB(mP(w, ii(i, j)));
	sort(all(EdgeList),fun); E = sz(EdgeList);
	for (int i = 0; i < E; i++) {
		edge e = EdgeList[i];
		if (UF.unionSet(e.s.f, e.s.s)) {
			 ret.PB(1);
cout<<e.s.f<< ' ' <<e.s.s<<endl;
		} 
	}
	return ret;
}
 
 
int main()
{
	//p10147
	int t;
	cin>>t;
	while(t--){
		clr(towns);
		int n, m, x, y, u, v, w;
		cin>>n;
		lop(i,n) sc(x),sc(y),towns.PB(ii(x,y));
		cin>>m;
		vector<edge> EdgeList;
		lop(i,m) sc(u),sc(v), w = pow((towns[u-1].f - towns[v-1].f),2) + pow((towns[u-1].s - towns[v-1].s),2), EdgeList.PB(mP(w, ii(u, v)));
		vi out = MST_Kruskal(EdgeList,n);
		if(!sz(out)) cout<<"No new highways need\n";
		if(t) cout<<endl; 
	}
	return 0;
}