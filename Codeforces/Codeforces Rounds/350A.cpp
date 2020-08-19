#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

#define sc(x)  scanf("%d",&x)
#define all(v) v.begin(),v.end()
#define lop(i,n) for(int i=0; i<n; i++)

int main()
{	
	int n,m,ans=0;
	cin>>n>>m;
	vi v1(n),v2(m);
	lop(i,n) sc(v1[i]), ans = max(ans,v1[i]);
	lop(i,m) cin>>v2[i];
	sort(all(v1)), sort(all(v2));
	ans = max(2*v1[0], ans);
	if(v2[0] <= ans) return puts("-1");
	cout<<ans<<endl;

	return 0;
}