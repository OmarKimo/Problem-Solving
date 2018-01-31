#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;

#define mem(arr,val) memset(arr,val,sizeof arr)
#define sz(v) (int)v.size()
#define rsz(v) v.resize
#define lop(i,n) for(int i=0; i<n; i++)
#define PB push_back
#define f first
#define s second

const int N = 110;
int n,m, dp[N][N][30][2];
vector<vii> graph;
int solve(int i, int j, int cround, int play){
	if(dp[i][j][cround][play] != -1) return dp[i][j][cround][play];
	dp[i][j][cround][play] = play;
	if(play) {
		lop(k,sz(graph[j])) 
			if(graph[j][k].s >= cround) 
				dp[i][j][cround][play] = min(dp[i][j][cround][play], solve(i, graph[j][k].f, graph[j][k].s, !play));
	}
	else {
		lop(k,sz(graph[i])) 
			if(graph[i][k].s >= cround) 
				dp[i][j][cround][play] = max(dp[i][j][cround][play], solve(graph[i][k].f, j, graph[i][k].s, !play));
	}
	return dp[i][j][cround][play];
}


int main()
{	
	//918D
	int u,v; char w;
	cin>>n>>m;
	rsz(graph)(n);
	lop(i,m){
		cin>>u>>v>>w;
		graph[u-1].PB(ii(v-1,w-'a'));
	}
	mem(dp,-1);
	lop(i,n){
		lop(j,n){
			if(solve(i,j,0,0)) cout<<'A';
			else cout<<'B';
		}
		cout<<endl;
	}

	return 0;
}