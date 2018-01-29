#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
 
#define sz(v) (int)v.size()
#define lop(i,n) for(int i=0; i<n; i++)
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
	bool unionSet(int i, int j) {
		bool flag = !isSameSet(i, j);
		if (flag) { // if from different set
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
 
int main()
{	
	//p459
	int t; string in; char mx;
	cin>>t;
	while(t--){
		cin>>mx;
		cin.get();
		UnionFind uf(mx-'A'+1);
		while(getline(cin,in) && in!="") uf.unionSet(in[0]-'A', in[1]-'A');
		cout<<uf.numDisjointSets()<<endl;
		if(t) cout<<endl;
	}
 
	return 0;
}