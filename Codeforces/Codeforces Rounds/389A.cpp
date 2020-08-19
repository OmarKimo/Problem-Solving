#include <bits/stdc++.h>
using namespace std;

#define sc(x)  scanf("%d",&x)
#define lop(i,n) for(int i=0; i<n; i++)

int gcd (int x, int y){ return !y ? x : gcd(y, x%y); }

int main()
{	
	int num,gcdAll,n,ans=0;
	cin>>n;
	cin>>gcdAll;
	lop(i,n-1) sc(num), gcdAll=gcd(gcdAll,num);
	cout<<gcdAll*n<<endl;

	return 0;
}