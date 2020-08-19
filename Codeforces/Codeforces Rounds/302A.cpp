#include <bits/stdc++.h>
using namespace std;

#define sc(x)  scanf("%d",&x)
#define lop(i,n) for(int i=0; i<n; i++)

int main()
{	
	int l,r,num,num1=0,num_1=0,n,m;
	cin>>n>>m;
	lop(i,n) sc(num), num1 += (num == 1)?1:0, num_1 += (num==-1)?1:0;
	lop(i,m){
		sc(l),sc(r);
		int cnt = r-l+1;
		if(cnt%2 || cnt/2 > num1 || cnt/2 > num_1) printf("0\n");
		else printf("1\n");
	}

	return 0;
}