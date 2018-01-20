#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;

#define all(v) v.begin(),v.end()
#define lop(i,n) for(int i=0; i<n; i++)

int main()
{	
	//812C
	int n; ll mon,ans=0;
	cin>>n>>mon;
	vll v(n); lop(i,n) cin>>v[i];
	ll l = 0, r = n, mid;
	while(l<r){
		mid = l + (r-l + 1)/2, ans=0;
		priority_queue<ll> pq;
		lop(i,n) pq.push(-v[i] - mid*(i+1));
		lop(i,mid) ans+=pq.top(), pq.pop();
		if(-ans>mon) r = mid-1;
		else l = mid;
	}
	ans=0;
	lop(i,n) v[i] += l*(i+1);
	sort(all(v));
	lop(i,l) ans+=v[i];
	cout<<l << ' '<<ans<<endl;
	
	return 0;
}