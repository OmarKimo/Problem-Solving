#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define lop(i,n) for(int i=0; i<n; i++)

const ll OO = (ll)(1e18)+9;

int main()
{	
	ll num,mn=OO,mx=0; int n;
	cin>>n;
	map<ll,ll> mp;
	lop(i,n){
		cin>>num;
		mn = min(mn,num);
		mx = max(num,mx);
		mp[num]++;
	}
ll ans=0;
if(mx != mn) ans = mp[mn]*mp[mx];
else lop(i,mp[mn]-1) ans+=i+1;
	cout<<mx - mn<<' '<<ans<<endl;
	
	return 0;
}