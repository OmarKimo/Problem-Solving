#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
#define lop(i,n) for(int i=0; i<n; i++)
#define loop(i,start,n) for(int i=start; i<n; i++)
#define PB push_back

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
	bool unionSet(int i, int j, int & mx) {
		bool flag = !isSameSet(i, j);
		if (flag) {
			int x = findSet(i), y = findSet(j);
			if (rank[x] > rank[y]) setSize[x] += setSize[y], mx=max(mx,setSize[x]), swap(x,y);
			else setSize[y] += setSize[x], mx=max(mx,setSize[y]);
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

int main(){

	//p10608
	int u,v,n,t,m,ans=0;
	cin>>t;
	while(t--){
		cin>>n>>m;
		ans=0;
		UnionFind uf(n+1);
		lop(i,m) {
			cin>>u>>v;
			uf.unionSet(u,v,ans);
		}
		cout<<ans<<endl;
	}
	return 0;
}