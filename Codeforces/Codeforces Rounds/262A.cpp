#include <bits/stdc++.h>
using namespace std;

#define sc(x)  scanf("%d",&x)
#define lop(i,n) for(int i=0; i<n; i++)

int numLucky(int n){
	int ret=0;
	while(n){
		ret += (n%10 == 7 || n%10 == 4) ? 1 : 0;
		n/=10;
	}
	return ret;
}

int main()
{	
	int num,n,k,ans=0;
	cin>>n>>k;
	lop(i,n) sc(num), ans += (numLucky(num) <= k) ? 1 : 0;
	cout<<ans<<endl;

	return 0;
}