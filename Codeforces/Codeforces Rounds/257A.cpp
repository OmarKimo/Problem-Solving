#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
#define lop(i,n) for(int i=0; i<n; i++)
#define PB push_back

int main()
{	
	int ans=0,sum=0,n,m,k,num;
	cin>>n>>m>>k;
	vi v;
	lop(i,n){
		cin>>num;
		if(num > 1) v.PB(num);
	}
	sort(all(v));
	int i=sz(v) - 1;
	sum = k;
	for(; i>=0 && sum<m; i--) sum+=v[i]-1,ans++;
	if(sum < m) cout<<-1<<endl;
	else cout<<ans<<endl;

	return 0;
}