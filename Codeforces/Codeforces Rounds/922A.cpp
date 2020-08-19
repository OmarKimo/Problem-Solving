#include<bits/stdc++.h>
using namespace std;
int main(){
int x,y;
	cin>>x>>y;
	y--;
	if(y < 0 || (!y && x) || (x-y) < 0 || (x-y)%2) cout<<"No\n";
	else cout<<"Yes\n";
return 0;
}