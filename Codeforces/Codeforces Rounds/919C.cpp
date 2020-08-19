#include <bits/stdc++.h>
using namespace std;

typedef vector<string> vs;

#define sz(v) (int)v.size()
#define lop(i,n) for(int i=0; i<n; i++)

int main()
{	
	//C
	int n,m,k,cnt=0,ans=0;
	cin>>n>>m>>k;
	vs mat(n);
	lop(i,n) cin>>mat[i];
	m = sz(mat[0]);
	lop(i,n){
		cnt = 0;
		lop(j,m){
			if(mat[i][j] == '.') {
				cnt++;
				if(cnt >= k) ans++;
			}
			else cnt=0;
		}
	}

	lop(i,m){
		cnt = 0;
		lop(j,n){
			if(mat[j][i] == '.') {
				cnt++;
				if(cnt >= k) ans++;
			}
			else cnt=0;
		}
	}
        if(k==1) ans/=2;
	cout<<ans<<endl;

	return 0;
}