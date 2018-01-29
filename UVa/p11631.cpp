#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<ll, ii> edge;


#define sc(x)  scanf("%d",&x)
#define scl(x) scanf("%lld",&x)
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
#define lop(i,n) for(int i=0; i<n; i++)
#define loop(i,start,n) for(int i=start; i<n; i++)
#define PB push_back
#define mP make_pair
#define f first
#define s second

struct UnionFind {
	vi p, rank, setSize;
	int forests;
	UnionFind(int N) { 
		setSize.assign(N, 1);
		rank.assign(N, 0);
		p.assign(N, 0);
		forests = N;
		for (int i = 0; i < N; i++) p[i] = i; 
	}
	int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
	bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
	bool unionSet(int i, int j) {
		bool flag = !isSameSet(i, j);
		if (flag) {
			int x = findSet(i), y = findSet(j);
			if (rank[x] > rank[y]) setSize[x] += setSize[y], swap(x,y);
			else setSize[y] += setSize[x];
			p[x] = y;
			if (rank[x] == rank[y]) rank[y]++;
			forests--;
		}
		return flag;
	}
	int numDisjointSets() { return forests; }
	int sizeOfSet(int i) { return setSize[findSet(i)]; }
	vvi connected_component(){
		vvi list(sz(p));
		lop(i,sz(p)) list[findSet(i)].PB(i);
		return list;
	}
};

ll MST_Kruskal(vector<edge> EdgeList, int V){
	int E = sz(EdgeList);
	vector<edge> edges;
	ll mst_cost = 0;
	UnionFind UF(V+1);
	for (int i = 0; i < E; i++) {
		edge e = EdgeList[i];
		if (UF.unionSet(e.s.f, e.s.s)) {
			mst_cost += e.f;
			edges.PB(e);
		} 
	}
	return mst_cost;
}


int main()
{	
	//p11631
	int u,v,n,m; ll w;
	while(cin>>n>>m && (n || m)){
		vector<edge> edges;
		ll sum=0;
		lop(i,m) sc(u),sc(v),scl(w),sum+=w,edges.PB(mP(w,ii(u,v)));
		sort(all(edges));
		cout<<sum-MST_Kruskal(edges, n)<<endl;
	}

	return 0;
}