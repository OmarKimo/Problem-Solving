#include <bits/stdc++.h>
using namespace std;

typedef vector<string> vs;
typedef map<int,int> mii;

#define lop(i,n) for(int i=0; i<n; i++)

int main()
{	
	int val=0,n,m;
	cin>>n>>m;
	vs v(n);
	lop(i,n) cin>>v[i];
	mii mp;
	lop(i,m) mp[i] = -1;
	lop(i,n) {
		lop(j,m){
			if(v[i][j] == '-') continue;
			if(j%2 == val) v[i][j] = 'B';
			else v[i][j] = 'W';
		}
		val = !val;
	}
	lop(i,n) cout<<v[i]<<endl;

	return 0;
}