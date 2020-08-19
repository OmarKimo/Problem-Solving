#include <bits/stdc++.h>
using namespace std;

#define sc(x)  scanf("%d",&x)
#define mem(arr,val) memset(arr,val,sizeof arr)
#define lop(i,n) for(int i=0; i<n; i++)

const int N = 70;
int n,arr[N],dp[N][3];
int solve(int idx, int who){
	if(idx == n) return 0;
	if(dp[idx][who] != -1) return dp[idx][who];
	if(!who) return dp[idx][who] = max(arr[idx] + solve(idx+1, !who), solve(idx+1, who));
	else return dp[idx][who] = min(solve(idx+1, !who), arr[idx] + solve(idx+1, who));
}

int main()
{	
	//859C
	cin>>n;
	int sum=0;
	lop(i,n) sc(arr[i]),sum+=arr[i];
	mem(dp,-1);
	int ans = solve(0,0);
	cout<<sum-ans<<' '<<ans<<endl;

	return 0;
}