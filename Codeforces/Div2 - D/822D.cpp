#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = (ll)(1e9)+7;
const int N = (int)5e6 + 10;

int main()
{	
	//822D
	ll t,l,r;
	cin>>t>>l>>r;
	int arr[N],dp[N];
	for(ll i=2; i<N; i++) if(!arr[i]) for(ll j = i+i; j<N; j+=i) if(!arr[j]) arr[j] = i;
	for(ll i=2; i<N; i++){
		if(!arr[i]) dp[i] = (i*(i-1)/2) % MOD;
		else{
			ll pr = arr[i], cnt = i/pr;
			dp[i] = (cnt*dp[pr] + dp[cnt])%MOD;
		}
	}
	ll ans = 0, mulT = 1;
	for(ll i = l; i<=r; i++) {
		ans = (ans + mulT*(ll)dp[i])%MOD;
		mulT = (mulT * t)%MOD;
	}
	cout<<ans<<endl;

	return 0;
}