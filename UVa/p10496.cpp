#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;

#define all(v) v.begin(),v.end()
#define mem(arr,val) memset(arr,val,sizeof arr)
#define sz(v) (int)v.size()
#define rsz(v) v.resize
#define clr(v) v.clear()
#define lop(i,n) for(int i=0; i<n; i++)
#define loop(i,start,n) for(int i=start; i<n; i++)
#define f first
#define s second

const int oo = 2147483647;

int dp[20][1<<11];
int nx,ny,sx,sy,nb;
vii v;
int solve(int idx, int mask){ 
	if(((1<<nb)-1) == mask) return abs(sx - v[idx].f) + abs(sy - v[idx].s);

	if(dp[idx][mask] != -1) return dp[idx][mask];
	dp[idx][mask] = oo;
	loop(i,1,nb){
		if((1<<i) & mask) continue;
		dp[idx][mask] = min(dp[idx][mask], solve(i, (1<<i) | mask ) + abs(v[idx].f - v[i].f) + abs(v[idx].s - v[i].s));
	}
	return dp[idx][mask];
}

int main()
{	
	//p10496
	int t;
	cin>>t;
	while(t--){
		cin>>nx>>ny>>sx>>sy>>nb;
		clr(v), rsz(v)(++nb);
		loop(i,1,nb) cin>>v[i].f>>v[i].s;
		v[0] = ii(sx,sy);
		mem(dp,-1);
		printf("The shortest path has length %d\n", solve(0,1));
	}
	
	return 0;
}