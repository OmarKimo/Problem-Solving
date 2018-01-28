#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define mem(arr,val) memset(arr,val,sizeof arr)
#define lop(i,n) for(int i=0; i<n; i++)

ll n,p,q,r;
ll dp[100010][3];
int vis[100010][3];
ll arr[100010];
ll solve(int idx, int con){
	if(con == 3) return 0;
	if(idx == n){
		if(!con) return (p+q+r)*arr[n-1];
		if(con == 1) return (q+r)*arr[n-1];
		if(con == 2) return r*arr[n-1];
	}
	if(vis[idx][con]) return dp[idx][con];
	vis[idx][con] = 1;
	if(!con) return dp[idx][con] = max(solve(idx+1, con), solve(idx, con+1) + p*arr[idx]);
	if(con == 1) return dp[idx][con] = max(solve(idx+1, con), solve(idx, con+1) + q*arr[idx]);
	if(con == 2) return dp[idx][con] = max(solve(idx+1, con), solve(idx, con+1) + r*arr[idx]);
}

int main()
{	
	//855B
	cin>>n>>p>>q>>r;
	lop(i,n) cin>>arr[i];
	mem(vis,0);
	cout<<solve(0,0)<<endl;

	return 0;
}