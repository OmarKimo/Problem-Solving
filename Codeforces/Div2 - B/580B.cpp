#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;

#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
#define lop(i,n) for(int i=0; i<n; i++)
#define f first
#define s second


int main()
{	
	//580B 
	ll d,mx=0; int n;
	cin>>n>>d;
	vii v(n);
	lop(i,n) cin>>v[i].f>>v[i].s;
	sort(all(v));
	int r=0; ll sum=0;
	lop(i,n){
		while(r < n && v[r].f - v[i].f < d) sum += v[r].s, r++;
		mx = max(mx,sum);
		sum-=v[i].s;
	}
	cout<<mx<<endl;

	return 0;
}