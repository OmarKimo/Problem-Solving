#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

#define lop(i,n) for(int i=0; i<n; i++)

int main()
{	
	int n,mn=1000;
	cin>>n;
	vi v(n);
	lop(i,n) cin>>v[i];
	lop(i,n) mn = min(mn,abs(v[i]-v[(i+1)%n]));
	lop(i,n) if(abs(v[i]-v[(i+1)%n]) == mn) return cout<<i+1<<' '<<1+(i+1)%n<<endl, 0;
}