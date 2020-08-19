#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;

#define sz(v) (int)v.size()
#define lop(i,n) for(int i=0; i<n; i++)

const ll MOD = (ll)(1e9)+7;

int main()
{	
	//152C
	int n,m;
	ll ans=1;
	cin>>n>>m;
	vs v(n);
	lop(i,n) cin>>v[i];
	for(int i=0; i<m; i++){
		set<char> st;
		for(int j=0; j<n; j++) st.insert(v[j][i]);
		ans *= sz(st);
		ans %= MOD;
	}
	cout<<ans<<endl;

	return 0;
}