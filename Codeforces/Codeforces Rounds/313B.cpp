#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
#define lop(i,n) for(int i=0; i<n; i++)
#define loop(i,start,n) for(int i=start; i<n; i++)

int main()
{	
	int n,l,r;
	string x;
	cin>>x>>n;
	vi suff(sz(x)-1,0);
	suff[0] = (x[1] == x[0]);
	loop(i,2,sz(x)) suff[i-1] = (x[i] == x[i-1]) + suff[i-2];
	lop(i,n){
		cin>>l>>r;
		l--,r--;
		if(!l) cout<<suff[r-1]<<endl;
		else cout<<suff[r-1]-suff[l-1]<<endl;
	}

	return 0;
}