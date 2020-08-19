#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;

#define all(v) v.begin(),v.end()
#define mem(arr,val) memset(arr,val,sizeof arr)
#define sz(v) (int)v.size()
#define lop(i,n) for(int i=0; i<n; i++)
#define loop(i,start,n) for(int i=start; i<n; i++)
#define f first
#define s second

const int N = 18;
int n, m, dp[N][1<<N];
vii v(300); set<string> st;
map<int,string> names; map<string,int> idxs;

int c_nBits1 (int mask)
{
	int ret = 0;
	while(mask){
		if(mask&1) ret++;
		mask >>=1;
	}
	return ret;
}

int solve(int idx, int mask){
	lop(i,m) if((mask & (1<<v[i].f)) && (mask & (1<<v[i].s))) return -20;
	if(idx == n) return c_nBits1(mask);
	if(dp[idx][mask] != -1) return dp[idx][mask];
	return dp[idx][mask] = max(solve(idx+1, mask | (1<<idx)), solve(idx+1, mask));
}

void path(int idx, int mask){
	if(idx == n) return;
	if(solve(idx+1, mask | (1<<idx)) == solve(idx,mask)) { st.insert(names[idx+1]); return path(idx+1, mask | (1<<idx)); }
	else return path(idx+1, mask);
}

int main()
{	
	//144B
	cin>>n>>m;
	string x1,x2;
	loop(i,1,n+1){
		cin>>x1;
		names[i] = x1, idxs[x1] = i;
	}
	lop(i,m){
		cin>>x1>>x2;
		v[i].f = idxs[x1]-1, v[i].s = idxs[x2]-1;
	}
	mem(dp,-1);
	cout<<solve(0,0)<<endl;
	path(0,0);
	for(set<string>::iterator it = st.begin(); it != st.end(); it++) cout<<*it<<endl;

	return 0;
}