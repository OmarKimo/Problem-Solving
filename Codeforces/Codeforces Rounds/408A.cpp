#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

#define lop(i,n) for(int i=0; i<n; i++)

int main()
{	
	int ans = 2147483647, n, num;
	cin>>n;
	vi K(n);
	lop(i,n) cin>>K[i];
	lop(i,n){
		int time = K[i]*15;
		lop(j,K[i]){
			cin>>num;
			time += num*5;
		}
		ans = min(ans,time);
	}
	cout<<ans<<endl;

	return 0;
}