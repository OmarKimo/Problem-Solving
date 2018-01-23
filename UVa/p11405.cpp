#include <bits/stdc++.h>
using namespace std;

#define mem(arr,val) memset(arr,val,sizeof arr)
#define sz(v) (int)v.size()

int dp[1010][1010];
string s1,s2;
int solve(int i,int j){
	if(i >= sz(s1) || j >= sz(s2)) return 0;
	if(dp[i][j] != -1) return dp[i][j];
	if(s1[i] == s2[j]) return dp[i][j] = 1+solve(i+1,j+1);
	return dp[i][j] = max(solve(i,j+1), solve(i+1,j));
}

int main()
{	
	//p11405
	int t=0;
	while(getline(cin,s1), getline(cin,s2)){
		mem(dp,-1);
		cout<<solve(0,0)<<endl;
	}

	return 0;
}