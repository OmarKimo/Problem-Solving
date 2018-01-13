#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;

#define sc(x)  scanf("%d",&x)
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
#define lop(i,n) for(int i=0; i<n; i++)
#define f first
#define s second

bool my(ii p1, ii p2){
	if(p1.s == p2.s) return p1.f < p2.f;
	return p1.s < p2.s;
}

int main()
{	
	//492C
	long long n,r,avg,req,sum=0,ans=0;
	cin>>n>>r>>avg;
	req = n*avg;
	vii v(n);
	lop(i,n) sc(v[i].f),sc(v[i].s),sum+=v[i].f;
	if(sum>=req)  return puts("0");
	req = req-sum;
	sort(all(v),my);
	lop(i,n){
		if(r-v[i].f >= req) ans+=req*v[i].s,req=0;
		else ans+=(r - v[i].f)*v[i].s, req -= (r - v[i].f);
	}
	cout<<ans<<endl;

	return 0;
}