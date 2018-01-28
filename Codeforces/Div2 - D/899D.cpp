#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define sz(v) (int)v.size()
#define lop(i,n) for(int i=0; i<n; i++)
#define loop(i,start,n) for(int i=start; i<n; i++)

int main()
{	
	//899D
	int flag=0,n,mxSum, ans=0;
	cin>>n;
	mxSum = 2*n - 1;
	string R = to_string(mxSum);
	lop(i,sz(R)) if(R[i] != '9') { flag = 1; break; }
	if(!flag) return puts("1");
	if(sz(R) == 1){
		while(mxSum > 2){
			ans += mxSum/2;
			if(mxSum > n) ans += n - mxSum + 1;
                        if(!(mxSum%2)) ans--;
			mxSum--;
		}
		cout<<ans<<endl; return 0;
	}
	loop(i,1,sz(R)) R[i] = '9';
	lop(i,9){
		R[0] = i+'0';
		ll num = stoll(R);
		if(num > mxSum) break;
		if(num <= n) ans += num/2;
		else ans += num/2 - num + n + 1;
	}
	cout<<ans<<endl;

	return 0;
}