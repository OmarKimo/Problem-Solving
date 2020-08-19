#include<bits/stdc++.h>
using namespace std;

int main(){
	long long mn,mx,n,m;
	cin>>n>>m;
	mx = ((n-m+1)*(n-m))/2;
	long long rem = n - ((n/m)*m), base = n/m;
	mn = (m-rem)*((base*(base-1))/2) + rem*((base*(base+1))/2);
	cout<<mn<<' '<<mx<<endl;

	return 0;
}