#include <bits/stdc++.h>
using namespace std;

#define mem(arr,val) memset(arr,val,sizeof arr)
#define lop(i,n) for(int i=0; i<n; i++)

int n;
set<char> st;
int dp[210][210][210];
int solve(int r, int g, int b){
	if((!r && !g && !b) || r<0 || g<0 || b<0) return 0;
	if(!r && !g) { st.insert('B'); return 0; }
	if(!r && !b) { st.insert('G'); return 2; }
	if(!g && !b) { st.insert('R'); return 1; }

	if(dp[r][g][b] != -1) return dp[r][g][b];
	dp[r][g][b] =  solve(r+1,g-1,b-1) + solve(r-1,g-1,b+1) + solve(r-1,g+1,b-1);
	if(r > 1) dp[r][g][b] += solve(r-1,g,b);
	if(g > 1) dp[r][g][b] += solve(r,g-1,b);
	if(b > 1) dp[r][g][b] += solve(r,g,b-1);
	return dp[r][g][b];
}

int main()
{	
	//626B
	string x; int R=0,G=0,B=0;
	cin>>n>>x;
	lop(i,n) (x[i] == 'R') ? (R++) : (x[i] == 'G' ? (G++) : (B++));
	mem(dp,-1);
	solve(R,G,B);
	for(set<char>::iterator it = st.begin(); it!=st.end(); it++) cout<<*it;
	cout<<endl;

	return 0;
}