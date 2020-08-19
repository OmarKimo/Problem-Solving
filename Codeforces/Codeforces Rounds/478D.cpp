#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define mem(arr,val) memset(arr,val,sizeof arr)
#define lop(i,n) for(int i=0; i<n; i++)

const ll MOD = (ll)(1e9)+7;
const int N = 500000;

int main()
{	
	//478D
	int R,G,h,mid,l=0,r=1000;
	cin>>R>>G;
	while(l < r){
		mid = l + (r-l+1)/2;
		if(mid*(mid+1)/2 > R+G) r = mid-1;
		else l = mid;
	}
	h = l;
	int dp[2][N], p = h&1;
	mem(dp,0);
	if(R > G) swap(R,G);
	lop(i,R+1){
		if(h*(h+1)/2 - i > G) continue;
		dp[p][i] = 1;
	}
	for(int i = h-1; i>=0; i--){
		p = !p;
		int tot = i*(i+1)/2;
		for(int j = 0; j<=R && j<=tot; j++){
			int green = tot - j;
			if(green > G) continue;
			dp[p][j] = (dp[!p][j] + dp[!p][j+i+1])%MOD;
		}
	}
	cout<<dp[0][0]<<endl;

	return 0;
}