#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(),v.end()
#define mem(arr,val) memset(arr,val,sizeof arr)
#define sz(v) (int)v.size()
#define lop(i,n) for(int i=0; i<n; i++)

int dp[350][350][3];
string R = "";
int solve(int idx, int rem, int r){
	if(rem < 0) return 0;
	if(idx == 350) return !rem && r;
	if(dp[idx][rem][r] != -1) return dp[idx][rem][r];
	dp[idx][rem][r] = 0;
	lop(i,10){
		if(!r && i < R[idx]-'0') continue;
		dp[idx][rem][r] |= solve(idx+1, rem - i, r || i > R[idx]-'0');
	}
	return dp[idx][rem][r];
}

string path(int idx, int rem, int r){
	if(idx == 350) return "";
	lop(i,10){
		if(!r && i < R[idx]-'0') continue;
		if( solve(idx+1, rem - i, r || i > R[idx]-'0') ) return char('0'+i) + path(idx+1, rem - i, r || i > R[idx]-'0');
	}
}

int main()
{	
	//509C
	int num,n;
	cin>>n;
	R = string(350,'0');
	lop(i,n){
		cin>>num;
		mem(dp,-1);
		solve(0,num,0);
		R = path(0,num,0);
		int flag=0;
		lop(j,sz(R)){
			if(!flag && R[j] != '0') flag =1;
			if(flag) cout<<R[j];
		}
		cout<<endl;
	}

	return 0;
}