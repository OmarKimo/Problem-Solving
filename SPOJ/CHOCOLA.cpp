#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;

#define all(v) v.begin(),v.end()
#define lop(i,n) for(int i=0; i<n; i++)
#define f first
#define s second

int n,m;
bool my(ii p1, ii p2){
	if(p1.f == p2.f) return p1.s < p2.s;
	return p1.f > p2.f;
}

int main()
{	
	//CHOCOLA
	int t;
	cin>>t;
	while(t--){
		ll ans = 0;
		cin>>m>>n;
		vii v(n+m-2);
		lop(i,n+m-2) {
			cin>>v[i].f;
			if(i > m-2)  v[i].s = 2;
			else v[i].s = 1;
		}
		sort(all(v), my);
		int cntx = 1, cnty = 1;
		lop(i,n+m-2){
			if(v[i].s == 1) ans += cnty * v[i].f, cntx++;
			else ans += cntx * v[i].f, cnty++;
		}
		cout<<ans<<endl;
	}

	return 0;
}