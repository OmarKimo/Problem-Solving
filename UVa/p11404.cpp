#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vvi;

#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
#define rsz(v) v.resize
#define clr(v) v.clear()

vector<vs> dp(1010, vs(1010));
vvi vis;
string x;
string solve(int i, int j){ 
	if(i > j) return "";

	if(vis[i][j]) return dp[i][j];
	vis[i][j] = 1;
	if(x[i] == x[j] && i != j) return dp[i][j] = x[i] + solve(i+1,j-1) + x[j];
	else if(x[i] == x[j]) return dp[i][j] = x[i];

	string x1 = solve(i+1,j);
	string x2 = solve(i,j-1);
	if(sz(x1) < sz(x2)) return dp[i][j] = x2;
	if(sz(x1) == sz(x2)) return dp[i][j] = (x1 > x2) ? x2 : x1; 
	
	return dp[i][j] = x1;
}

int main()
{	
	//p11404
	while(getline(cin,x)){
		clr(vis), rsz(vis)(1010, vi(1010,0));
		cout<<solve(0,sz(x)-1)<<endl;
	}
	
	return 0;
}