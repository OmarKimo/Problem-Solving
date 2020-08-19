#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define all(v) v.begin(),v.end()
#define mem(arr,val) memset(arr,val,sizeof arr)
#define lop(i,n) for(int i=0; i<n; i++)

const ll MOD = (ll)(1e9)+7;
const int N = 5100;
int n;
int arr[N], dp[N][N];

int solve(int idx, int lev, int cond){
	if(idx == n) return 1;
	if(dp[idx][lev] != -1) return dp[idx][lev];
	dp[idx][lev] = 0;
	if(arr[idx]) {
		dp[idx][lev] = (dp[idx][lev] + solve(idx+1, lev+1, 0)%MOD)%MOD;
		if(cond && lev) dp[idx][lev] = (dp[idx][lev] + solve(idx, lev-1, cond)%MOD)%MOD;
	}
	else{
		dp[idx][lev] = (dp[idx][lev] + solve(idx+1, lev, 1)%MOD)%MOD;
		if(cond && lev) dp[idx][lev] = (dp[idx][lev] + solve(idx, lev-1, cond)%MOD)%MOD;
	}
	return dp[idx][lev];
}

int main()
{	
	//909C
	cin>>n;
	mem(dp,-1), mem(arr,0);
	char c;
	lop(i,n){
		cin>>c;
		if(c == 'f') arr[i] = 1;
	}
	cout<<solve(0,0,0)%MOD<<endl;

	return 0;
}