#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("input.txt", "r",stdin);
	freopen("output.txt", "w", stdout);
	int n;
	cin>>n;
	int x,y;
	cin>>x>>y;
	if(x==n) n = y;
	else if(y==n) n = x;
	cin>>x>>y;
	if(x==n) n = y;
	else if(y==n) n = x;
	cin>>x>>y;
	if(x==n) n = y;
	else if(y==n) n = x;
	cout<<n<<endl;

	return 0;
}