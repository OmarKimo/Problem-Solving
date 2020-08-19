#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
#define lop(i,n) for(int i=0; i<n; i++)


int main()
{	
	int n,q,num;
	cin>>n;
	vi v(n); lop(i,n) cin>>v[i]; sort(all(v));
	cin>>q;
	lop(i,q){
		cin>>num;
		int idx = upper_bound(all(v),num) - v.begin();
		cout<<idx<<endl;
	}

	return 0;
}