#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
ll n,k;
	cin>>n>>k;
	map<ll,int> mp;
for(ll i=1; i<=k; i++){
if(++mp[n%i] > 1) return puts("No");
}
cout<<"Yes\n";
return 0;
}