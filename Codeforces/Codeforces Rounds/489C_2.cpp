#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
#define rev(v) reverse(all(v))
#define lop(i,n) for(int i=0; i<n; i++)

int main()
{	
	//489C
	int c,ts,num,sum; string mi = "", ma="";
	cin>>num>>sum;
	ts = sum;
	//max.
	lop(i,num) c = min(9,sum), sum -= c, ma += c + '0';
	if(sum > 0 || !sz(ma) || (sz(ma) > 1 && ma[0] == '0')) return puts("-1 -1");

	//min.
	lop(i,num){
		if(i != num-1) c = min(9,ts-1);
		else c = ts;
		if(c > 9 || c < 0) return puts("-1 -1");
		ts -= c;
		mi += c + '0';
	}
	rev(mi);
	if(ts > 0 || !sz(mi) || (sz(mi) > 1 && mi[0] == '0')) return puts("-1 -1");

	cout<<mi<<' '<<ma<<endl;

	return 0;
}