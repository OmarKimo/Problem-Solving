#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
#define lop(i,n) for(int i=0; i<n; i++)
#define loop(i,start,n) for(int i=start; i<n; i++)
#define rloop(i,end,n) for(int i=n-1; i>=end; i--)

int main()
{	
	//435B
	string num; int k;
	cin>>num>>k;
	lop(i,sz(num)){
		if(!k) break;
		int mx = i;
		loop(j,i+1,min(sz(num),i+k+1)) if(num[j] > num[mx]) mx = j;
		if(mx == i) continue;
		rloop(j,i+1,mx+1){
			char c = num[j];
			num[j] = num[j-1];
			num[j-1] = c;
                        k--;
		}
	}
	cout<<num<<endl;

	return 0;
}