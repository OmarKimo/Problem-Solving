#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef map<int,int> mii;

#define sz(v) (int)v.size()
#define lop(i,n) for(int i=0; i<n; i++)

int main()
{	
	vi v;
	int k;
	cin>>k;
	k*=2;
	vs mat(4); mii mp;
	lop(i,4) cin>>mat[i];
	lop(i,4) lop(j,4){
                if(mat[i][j] < '0' || mat[i][j] > '9') continue;
		if(!mp[mat[i][j]-'0']) v.push_back(mat[i][j]-'0');
		mp[mat[i][j]-'0']++;
	}
	lop(i,sz(v)) if(mp[v[i]] > k) return puts("NO");
	cout<<"YES\n";

	return 0;
}