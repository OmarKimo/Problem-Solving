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

bool my1(pair<ii,ii> p1, pair<ii,ii> p2){
	if(p1.f.s == p2.f.s) return p1.f.f < p2.f.f;
	return p1.f.s > p2.f.s;
}

bool my2(pair<ii,ii> p1, pair<ii,ii> p2){
	if(p1.s.f == p2.s.f) return p1.s.s < p2.s.s;
	return p1.s.f < p2.s.f;
}

int main()
{	
	//416C
	int n,t,cnt=0,ans=0;
	cin>>n;
	vector<pair<ii,ii>> v(n);
	lop(i,n) sc(v[i].f.f), sc(v[i].f.s), v[i].s.f = i+1, v[i].s.s = 0;
	sort(all(v),my1);
	cin>>t;
	vii tables(t);
	lop(i,t) sc(tables[i].f), tables[i].s = i+1;
	sort(all(tables));
	lop(i,n){
		if(!sz(tables)) break;
		lop(j,sz(tables)) if(tables[j].f >= v[i].f.f) { 
			v[i].s.s = tables[j].s; 
			ans += v[i].first.second, cnt++;
			tables.erase(tables.begin() + j, tables.begin()+j+1);
			break; 
		}
	}
	sort(all(v),my2);
	cout<<cnt<<' '<<ans<<endl;
	lop(i,n) if(v[i].second.s) cout<<i+1<<' '<<v[i].s.s<<endl;

	return 0;
}