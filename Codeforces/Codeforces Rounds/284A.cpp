#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define lop(i,n) for(int i=0; i<n; i++)
#define loop(i,start,n) for(int i=start; i<n; i++)

bool ans(ll num, ll p){
	ll n = num;
	if((n-1)%p == 0) return false;
	lop(i,p-2) {
		n = (n*num)%p;
		if((i != p - 3 && !(n-1)) || (i == p - 3 && n-1)) return false;
	}
	return true;
}


int main()
{	
	int cnt=0,p;
	cin>>p;
if(p==2) return puts("1");
	loop(i,1,p) if(ans(i,p)) cnt++;
	cout<<cnt<<endl;

	return 0;
}