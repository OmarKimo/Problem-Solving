#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define all(v) v.begin(),v.end()
#define mem(arr,val) memset(arr,val,sizeof arr)
#define sz(v) (int)v.size()
#define rev(v) reverse(all(v))
#define lop(i,n) for(int i=0; i<n; i++)

ll dp[11][64][1<<10];
ll solve(int base, int rem, int mask){
	if(rem <= 0) return !mask;
	if(dp[base][rem][mask] != -1) return dp[base][rem][mask];
	dp[base][rem][mask] = 0;
	lop(i,base) dp[base][rem][mask] += solve(base, rem-1, mask ^ (1<<i));
	return dp[base][rem][mask];
}

string Convert(ll n, int base){
	if(!n) return "0";
	string ret = "";
	while(n){
		ret += (n%base)+'0';
		n/=base;
	}
	rev(ret);
	return ret;
}

ll getAns(ll n, int base){
	string num = Convert(n,base);
	int mask = 0;
	ll ans = 0;
	for(int i=0; i<sz(num); i++){
		for(int j=0; j<num[i]-'0'; j++){
			if(!i && !j) continue;
			ans += solve(base, sz(num)-i-1, mask ^ (1<<j));
		}
		if(i) ans += solve(base, i, 0) - solve(base, i-1, 1);
		mask ^= 1<<(num[i]-'0');
	}
	return ans+=(!mask);
}

int main()
{	
	//855E
	int q,b;
	ll l,r;
	cin>>q;
	mem(dp,-1);
	while(q--){
		cin>>b>>l>>r;
		cout<<getAns(r,b) - getAns(l-1,b)<<endl;
	}

	return 0;
}