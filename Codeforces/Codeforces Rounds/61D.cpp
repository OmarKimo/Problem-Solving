#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define sc(x)  scanf("%d",&x)
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
#define lop(i,n) for(int i=0; i<n; i++)
#define PB push_back
#define f first
#define s second

vector<vii> graph(100010);
vi dis(100010,0), vis(100010,0);
void dfs(int node, int dist){
	vis[node]=1,dis[node]=dist;
	lop(i,sz(graph[node])) if(!vis[graph[node][i].f]) dfs(graph[node][i].f, dist + graph[node][i].s);
}


int main()
{	
	int n,u,v,w; ll ans=0;
	cin>>n;
	lop(i,n-1) sc(u),sc(v),sc(w),graph[u].PB(ii(v,w)), graph[v].PB(ii(u,w)),ans+=2*w;
	dfs(1,0);
	ans -= *max_element(all(dis));
	cout<<ans<<endl;
	
	return 0;
}