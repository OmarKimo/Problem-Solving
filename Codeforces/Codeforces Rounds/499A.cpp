#include<bits/stdc++.h>
using namespace std;

int main(){
int l,r,ans=0,m = 1, n,x;
	cin>>n>>x;
	for(int i=0; i<n; i++) {
		cin>>l>>r;
		ans += (l-m)%x + (r-l+1);
		m = r+1;
	}
	cout<<ans<<endl;
return 0;
}