#include <bits/stdc++.h>
using namespace std;

int main()
{
	
	//p12708
	int t; long long n;
	cin>>t;
	while(t--){
		cin>>n;
		if(n%2) cout<<(n-1)/2<<endl;
		else cout<<n/2<<endl;
	}
	return 0;
}