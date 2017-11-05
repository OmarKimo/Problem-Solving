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
ll lcm (ll a, ll b) { return a * (b / gcd(a, b)); }
int ord(int r,int c,int nCol) { return (nCol*r) + c + 1; } //transform from 2-D matrix to 1-D array. (Zero-indexed)
//Compare Double Numbers
int cmpDouble(ld d1,ld d2){ return fabs(d1-d2)<=EPS?0:d1>d2?1:-1; }


struct edge {
	int to, w;

	edge(int to, int w): to(to), w(w) {}

	bool operator < (const edge & e) const {
		return w > e.w;
	}
};

vll dist1(10010,oo), dist2(10010,oo);
vector<vector<edge>> graph(10010), rgraph(10010);
void Dijkstra1(int src)
{
	dist1[src] = 0;

	priority_queue<edge> q;
	q.push( edge(src, 0) );

	while(!q.empty()) {
		edge e = q.top();	q.pop();

		if(e.w > dist1[e.to]) continue;
		int nod = e.to;

		lop(j, sz(graph[e.to])) {
			edge ne = graph[e.to][j];
			if(dist1[ne.to] > dist1[nod] + ne.w) {
				ne.w = dist1[ne.to] = dist1[nod] + ne.w;
				q.push( ne );
			}
		}
	}
}

void Dijkstra2(int src)
{
	dist2[src] = 0;

	priority_queue<edge> q;
	q.push( edge(src, 0) );

	while(!q.empty()) {
		edge e = q.top();	q.pop();

		if(e.w > dist2[e.to]) continue;
		int nod = e.to;

		lop(j, sz(rgraph[e.to])) {
			edge ne = rgraph[e.to][j];
			if(dist2[ne.to] > dist2[nod] + ne.w) {
				ne.w = dist2[ne.to] = dist2[nod] + ne.w;
				q.push( ne );
			}
		}
	}
}


int main()
{
	
	//p12047
	int flag,u,v,t,n,m,S,D,c,P, mx;
	cin>>t;
	vector<pair<ii,int>> edges;
	while(t--){

		mx = flag = 0;
		clr(dist1), clr(dist2), clr(graph), clr(rgraph), clr(edges);
		rsz(dist1)(10010,oo), rsz(dist2)(10010,oo), rsz(graph)(10010), rsz(rgraph)(10010);

		cin>>n>>m>>S>>D>>P;

		lop(i,m) sc(u), sc(v), sc(c), graph[u].PB(edge(v,c)), rgraph[v].PB(edge(u,c)), edges.PB(mP(mP(u,v),c));

		Dijkstra1(S), Dijkstra2(D);

		lop(i,m) {
			ll val = dist1[edges[i].f.f] + dist2[edges[i].f.s] + edges[i].s;
			if(val <= P) flag=1, mx = max(mx, edges[i].s);
		}

		if(flag) cout<<mx<<endl;
		else cout<<-1<<endl;
	}



	return 0;
}