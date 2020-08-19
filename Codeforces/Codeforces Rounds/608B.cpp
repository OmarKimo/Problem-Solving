#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;

#define sz(v) (int)v.size()
#define lop(i,n) for(int i=0; i<n; i++)
#define loop(i,start,n) for(int i=start; i<n; i++)
#define PB push_back
#define f first
#define s second

int main()
{	
	//608B
	string a,b; ll ans=0;
	cin>>a>>b;
	vii A;
	lop(i,sz(a)) A.PB( (a[i] == '0') ? (ii(1,0)) : (ii(0,1)) );
	loop(i,1,sz(a)) A[i].f+=A[i-1].f, A[i].s+=A[i-1].s;

	lop(i,sz(b)){
		int num1 = (i < sz(a)) ? (sz(b)-sz(a)) : (sz(b) - 1 - i), num2 = (i < sz(a)) ? (i) : (sz(a)-1);
		if(b[i]=='0'){
				ans+=A[num2].s;
				if(i && num1 < num2) ans-=A[num2-num1-1].s;
			}
		else{
			ans+=A[num2].f;
			if(i && num1 < num2) ans-=A[num2-num1-1].f;
		}
	}
	cout<<ans<<endl;

	return 0;
}