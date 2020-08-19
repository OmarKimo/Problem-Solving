#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;

#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
#define lop(i,n) for(int i=0; i<n; i++)
#define loop(i,start,n) for(int i=start; i<n; i++)
#define PB push_back
#define f first
#define s second

ll ans=0;
pair<ll,ll> cal(string x){
	ll cnts=0,cnth=0;
	lop(i,sz(x)){
		if(x[i] == 's') cnts++;
		else cnth++, ans+=cnts;
	}
	return make_pair(cnts,cnth);
}

bool my(pair<ll,ll> p1, pair<ll,ll> p2){
	return p1.f*p2.s > p2.f*p1.s;
}

int main()
{	
	//D
	int n;
	cin>>n;
	vector<pair<ll,ll>> v(n);
	string in;
	lop(i,n){
		cin>>in;
		v[i] = cal(in);
	}
	sort(all(v),my);
	ll ss = 0;
	lop(i,n) ans+=ss*v[i].s, ss += v[i].f;
	cout<<ans<<endl;

	return 0;
}