#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;


#define sc(x)  scanf("%d",&x)
#define lop(i,n) for(int i=0; i<n; i++)

int main()
{	
	int n,d,sum=0;
	cin>>n>>d;
	vi t(n);
	lop(i,n) sc(t[i]),sum+=t[i];
	sum+=(n-1)*10;
	if(sum > d) return puts("-1");
	cout<<(d-sum)/5 + (n-1)*2<<endl;
	
	return 0;
}