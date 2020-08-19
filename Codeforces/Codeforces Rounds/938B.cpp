#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

#define sc(x)  scanf("%d",&x)
#define lop(i,n) for(int i=0; i<n; i++)

int main()
{	
	//
	int num = (int)1e6, n,ans=0;
	cin>>n;
	vi v(n);
	lop(i,n) sc(v[i]), ans = max(ans, min(v[i]-1, num-v[i]));
	cout<<ans<<endl;
    
	return 0;
}