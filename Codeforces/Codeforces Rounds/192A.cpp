#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,num=1;
	cin>>n;
	map<int,int> mp;
	for(int i=0; i<44720; i++) mp[((i+1)*(i+2))/2]++;
	while(num*(num+1)/2 < n){
		int rem = n - num*(num+1)/2;
		if(mp[rem]) return puts("YES");
		num++;
	}
	cout<<"NO\n";
return 0;
}