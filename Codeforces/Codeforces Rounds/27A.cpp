#include <bits/stdc++.h>
using namespace std;

typedef map<int,int> mii;

#define sc(x)  scanf("%d",&x)
#define lop(i,n) for(int i=0; i<n; i++)

int main()
{	
	mii mp;
	int num,n;
	cin>>n;
	lop(i,n) sc(num),mp[num]++;
	num = 0;
	while(++num) if(!mp[num]) return cout<<num<<endl, 0;

	return 0;
}