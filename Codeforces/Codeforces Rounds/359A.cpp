#include<bits/stdc++.h>
using namespace std;

int main(){
int ans=4,num,n,m;
	cin>>n>>m;
	for(int i=0; i<n; i++) for(int j=0; j<m; j++) {
		cin>>num;
		if(num) if(!i || !j || i==n-1 || j==m-1) ans =2;
	}
	cout<<ans<<endl;
return 0;
}