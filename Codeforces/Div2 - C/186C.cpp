#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll BigMod(ll num, ll p, ll md){
	if(!p) return 1;
	
	if(p%2){
		return ((num%md) * BigMod(num,p-1,md)) % md;

	}
	else{
		ll c = BigMod(num,p/2,md);
		return ((c%md)*(c%md))%md;
	}
}

int main()
{	
	ll n,out;
	cin>>n;
	out = BigMod(2,n,1000000007);
	cout<<(out*(out+1)/2)%1000000007<<endl;

	return 0;
}