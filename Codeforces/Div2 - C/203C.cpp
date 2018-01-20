#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;


#define sc(x)  scanf("%d",&x)
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
#define lop(i,n) for(int i=0; i<n; i++)
#define PB push_back
#define f first
#define s second

bool my(ii p1, ii p2){
	if(p1.first == p2.f) return p1.second<p2.second;
	return p1.f<p2.f;
}

int main()
{	
	//203C
	int n,d,a,b,x,y;
	cin>>n>>d>>a>>b;
	vii v(n); vi ans;
	lop(i,n) sc(x),sc(y),v[i].first = x*a + y*b, v[i].second=i+1;
	sort(all(v),my);
	lop(i,n){
		if(v[i].first > d) break;
		d -= v[i].first;
		ans.PB(v[i].s);
	}
	cout<<sz(ans)<<endl;
	lop(i,sz(ans)) cout<<ans[i]<<' ';

	return 0;
}