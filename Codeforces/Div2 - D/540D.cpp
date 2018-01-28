#include <bits/stdc++.h>
using namespace std;

#define mem(arr,val) memset(arr,val,sizeof arr)

const int N = 110;
int S,R,P;
double dp[N][N][N][3];
double solve(int r, int sc, int p, int cond){
	if(sc < 0 || p < 0 || r < 0) return 0;
	if(!sc && !p && r) return !cond;
	if(!r && !p && sc) return cond == 1;
	if(!sc && !r && p) return cond == 2;

	if(dp[r][sc][p][cond] == dp[r][sc][p][cond]) return dp[r][sc][p][cond];
	dp[r][sc][p][cond] = 0;
	double val = 1.0 / (r*p + r*sc + p*sc);
	dp[r][sc][p][cond] += sc*p*val*solve(r,sc,p-1,cond) + r*sc*val*solve(r,sc-1,p,cond) + r*p*val*solve(r-1,sc,p,cond);
	return dp[r][sc][p][cond];
}

int main()
{	
	//540D
	cin>>R>>S>>P;
	mem(dp,-1);
	printf("%.12f %.12f %.12f\n", solve(R,S,P,0),solve(R,S,P,1),solve(R,S,P,2));

	return 0;
}