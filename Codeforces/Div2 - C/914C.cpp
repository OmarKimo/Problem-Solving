#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define mem(arr,val) memset(arr,val,sizeof arr)
#define lop(i,n) for(int i=0; i<n; i++)
#define loop(i,start,n) for(int i=start; i<n; i++)

const ll MOD = (ll)(1e9)+7;

string num;
int k;
int dp[1010][1010][3][2], arr[1010];
int solve(int idx, int cnt, int r, int isOne){
	if(idx == sz(num)) {
		if(!k || !cnt) return isOne;
                else if(k && isOne) return 0;
		else return arr[cnt] == k-1;
	}
	if(dp[idx][cnt][r][isOne] != -1) return dp[idx][cnt][r][isOne];
	dp[idx][cnt][r][isOne] = 0;
	lop(i,2){
		if(!r && i > num[idx]-'0') continue;
		dp[idx][cnt][r][isOne] = (dp[idx][cnt][r][isOne] + solve(idx+1, cnt + i, r || i < num[idx]-'0', !cnt && i && idx+1 == sz(num))%MOD )%MOD;
	}
	return dp[idx][cnt][r][isOne];
}

int c_nBits1 (int mask)
{
	int ret = 0;
	while(mask){
		if(mask&1) ret++;
		mask >>=1;
	}
	return ret;
}

int main()
{	
	//914C
	cin>>num>>k;
	mem(arr,0), mem(dp,-1);
	arr[0] = -1;
	loop(i,2,1010) arr[i] = 1+arr[c_nBits1(i)];
	cout<<solve(0,0,0,0)%MOD<<endl;

	return 0;
}