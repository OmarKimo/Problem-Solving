#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define mem(arr,val) memset(arr,val,sizeof arr)
#define lop(i,n) for(int i=0; i<n; i++)
#define loop(i,start,n) for(int i=start; i<n; i++)

const ll MOD = (ll)(1e9)+7;

int main()
{	
	//166E
	int n;
	cin>>n;
	int dp[3][4];
	mem(dp,0);
	int p = 1;
	dp[p][0] = 1;
	for(int i = n-1; i>=0; i--){
		p = !p;
		lop(j,4) dp[p][j] = 0;
		lop(j,4){
			if(j) dp[p][j] = (dp[p][j] + dp[!p][0])%MOD;
			if(j!=1) dp[p][j] = (dp[p][j] + dp[!p][1])%MOD;
			if(j!=2) dp[p][j] = (dp[p][j] + dp[!p][2])%MOD;
			if(j!=3) dp[p][j] = (dp[p][j] + dp[!p][3])%MOD;
		}
	}
	cout<<dp[p][0]<<endl;

	return 0;
}