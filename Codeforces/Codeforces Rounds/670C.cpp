#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef map<int,int> mii;

#define sc(x)  scanf("%d",&x)
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
#define lop(i,n) for(int i=0; i<n; i++)
#define PB push_back
#define mP make_pair
#define f first
#define s second

bool my(pair<ii,int> p1, pair<ii,int> p2){
	if(p1.f.f == p2.f.f && p1.f.s == p2.f.s) return p1.s > p2.s;
	if(p1.f.f == p2.f.f) return p1.f.s > p2.f.s;
	return p1.f.f > p2.f.f;
}

int main()
{	
	//670C
	int n,m;
	cin>>n;
	vi v(n); mii mp;
	lop(i,n) sc(v[i]),mp[v[i]]++;
	cin>>m; vi b(m), c(m);
	lop(i,m) sc(b[i]);
	lop(i,m) sc(c[i]);
	vector<pair<ii,int>>filter;
	lop(i,m) filter.PB(mP(ii(mp[b[i]],mp[c[i]]),i+1));
	sort(all(filter),my);
	cout<<filter[0].s<<endl;

	return 0;
}