#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
#define lop(i,n) for(int i=0; i<n; i++)
#define loop(i,start,n) for(int i=start; i<n; i++)
#define PB push_back
#define mP make_pair
#define f first
#define s second

int main()
{	
	//363C
	string x,ans="";
	cin>>x;
	vector<pair<char,int>> v;
	int cnt=1;
	loop(i,1,sz(x)){
		if(x[i] == x[i-1]) cnt++;
		else v.PB(mP(x[i-1],cnt)), cnt=1;
	}
	v.PB(mP(x.back(),cnt));
	lop(i,sz(v)-1){
		if(v[i].s == 1) ans += v[i].f;
		else if(v[i].s == 2 && (!i || (i && v[i-1].s < 2)) ) ans += v[i].f, ans += v[i].f;
		else if(v[i].s == 2 && (i && v[i-1].s == 2)) v[i].s = 1, ans+=v[i].f;
		else if(v[i].s > 2 && (!i || (i && v[i-1].s < 2)) ) v[i].s = 2, ans += v[i].f, ans += v[i].f;
		else if(v[i].s > 2 && (i && v[i-1].s == 2)) v[i].s = 1, ans+=v[i].f;
	}
	if(v.back().s == 1) ans += v.back().f;
	else if(sz(v) == 1 || v[sz(v)-2].s < 2) ans += v.back().f, ans += v.back().f;
	else if(v[sz(v)-2].s == 2) ans += v.back().f;
	cout<<ans<<endl;
	
	return 0;
}