#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef map<int,int> mii;

#define lop(i,n) for(int i=0; i<n; i++)
#define f first
#define s second

int main()
{	
	int n,ans=0;
	cin>>n;
	vii v(n);
	mii le,ri,up,lo;
	lop(i,n) cin>>v[i].f>>v[i].second;
	lop(i,n){
		lop(j,n){
			if(i!=j){
				if(v[i].first == v[j].f){
					lo[i] += (v[j].second < v[i].s) ? 1 : 0;
					up[i] += (v[j].second > v[i].s) ? 1 : 0;
				}
				else if(v[i].s == v[j].s){
					le[i] += (v[j].f < v[i].f) ? 1 : 0;
					ri[i] += (v[j].f > v[i].f) ? 1 : 0;
				}
			}
		}
		if(le[i] && lo[i] && ri[i] && up[i]) ans++;
	}
	cout<<ans<<endl;

	return 0;
}