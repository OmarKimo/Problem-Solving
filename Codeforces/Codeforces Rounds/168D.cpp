#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define mem(arr,val) memset(arr,val,sizeof arr)
#define lop(i,n) for(int i=0; i<n; i++)

const int N = 210;
double dp[N][N][N], prob[N];
int n,l,k,prize[N];
double solve(int tour, int win, int cap){
        if(cap >= n) cap = n;
	if(tour == n) return win >= l && cap >= 0;
	if(dp[tour][win][cap] == dp[tour][win][cap]) return dp[tour][win][cap];
	return dp[tour][win][cap] = prob[tour] * solve(tour+1, win+1, cap+prize[tour]) + (1.0-prob[tour]) * solve(tour+1,win,cap);
}

int main()
{	
	//168D
	cin>>n>>l>>k;
	lop(i,n) { cin>>prob[i]; prob[i]/=100.0; }
	lop(i,n) cin>>prize[i];
	mem(dp,-1);
	printf("%.12f\n",solve(0,0,k));

	return 0;
}