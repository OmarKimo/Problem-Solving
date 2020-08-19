#include <bits/stdc++.h>
using namespace std;

typedef vector<string> vs;

#define lop(i,n) for(int i=0; i<n; i++)

int main()
{	
	int n,m,ans=0;
	cin>>n>>m;
	vs v(n);
	lop(i,n) cin>>v[i];
	lop(i,n){
		lop(k,m){
			bool chk = true;
			lop(j,n){
				if(i!=j && v[i][k] < v[j][k]){
					chk = false;
					break;
				}
			}
			if(chk) {
				ans++;
				break;
			}
		}
	}
	cout<<ans<<endl;

	return 0;
}