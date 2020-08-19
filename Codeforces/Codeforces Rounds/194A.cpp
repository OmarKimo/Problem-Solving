#include<bits/stdc++.h>
using namespace std;

int main(){
int n,k;
	cin>>n>>k;
	k-=2*n;
	if(k >= n) cout<<0<<endl;
	else cout<<n-k<<endl;
return 0;
}