#include<bits/stdc++.h>
using namespace std;

int main(){
int n;
	cin>>n;
	if(n%2) return puts("-1");
	vector<int> v(n);
	for(int i=1; i<=n; i+=2) v[i-1] = i+1, v[i] = i;
	for(int i=1; i<=n; i++) cout<<v[i-1]<<' ';

return 0;
}