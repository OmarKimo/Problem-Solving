#include<bits/stdc++.h>
using namespace std;

int main(){
int mx = 0, n,c;
	cin>>n>>c;
	vector<int> v(n);
	for(int i=0; i<n; i++) cin>>v[i];
	for(int i=0; i<n-1; i++) mx = max(mx, v[i] - v[i+1] - c);
	cout<<mx<<endl;

return 0;
}