#include<bits/stdc++.h>
using namespace std;
int main(){

        long long ans=0,n,m;
	cin>>n>>m;
	if(n>m) swap(n,m);
	while(n && m){
		if(2*n <= m) ans += n, m-=2*n, n=0;
		else if(n >= 2 && m >= 1) n -= 2, m--, ans++;
                else break;
	}
	cout<<ans<<endl;

	return 0;
}