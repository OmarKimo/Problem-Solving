#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

#define lop(i,n) for(int i=0; i<n; i++)

int main()
{	
	int sum=0,n,k;
	cin>>n>>k;
	vvi ans(n,vi(n,0));
	lop(i,n) ans[i][i] = k;
	lop(i,n){
		lop(j,n) cout<<ans[i][j]<<' ';
		cout<<endl;
	}

	return 0;
}