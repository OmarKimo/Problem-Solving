#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define all(v) v.begin(),v.end()
#define mem(arr,val) memset(arr,val,sizeof arr)
#define sz(v) (int)v.size()
#define rsz(v) v.resize
#define clr(v) v.clear()
#define lop(i,n) for(int i=0; i<n; i++)

int n;
int dp[50][50]; vi v;
int solve(int idx, int last){
	if(idx == n) return 0;
	if(dp[idx][last] != -1) return dp[idx][last];
	int ret = 0;
	if(v[idx] > v[last]) ret = solve(idx+1, idx) + 1;
	ret = max(ret, solve(idx+1, last));
	return dp[idx][last] = ret;
}

int main()
{	
	cin>>n;
	rsz(v)(++n,0);
	lop(i,n-1) cin>>v[i+1];
	mem(dp,-1);
	cout<<solve(1,0)<<endl;
	
	return 0;
}