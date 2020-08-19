#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define mem(arr,val) memset(arr,val,sizeof arr)
#define lop(i,n) for(int i=0; i<n; i++)

const ll OO = (ll)(1e18)+9;
const int N = 2010;

ll p,n,k,dp[N][N],keys[N],emps[N];
ll solve(int emp, int key){ //no. of groups, count of people in each group
	if(emp == n) return 0;
	if(key == k) return OO;
	if(dp[emp][key] != -1) return dp[emp][key];
	return dp[emp][key] = min( solve(emp, key+1), max( abs(keys[key] - emps[emp]) + abs(p - keys[key]), solve(emp+1, key+1) ) );
}


int main()
{	
	//831D
	cin>>n>>k>>p;
	lop(i,n) cin>>emps[i];
	lop(i,k) cin>>keys[i];
	sort(emps,emps+n), sort(keys,keys+k), mem(dp,-1);
	cout<<solve(0,0)<<endl;

	return 0;
}