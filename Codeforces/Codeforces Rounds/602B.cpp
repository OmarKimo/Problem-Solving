#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

#define sc(x)  scanf("%d",&x)
#define lop(i,n) for(int i=0; i<n; i++)
#define loop(i,start,n) for(int i=start; i<n; i++)

int main()
{	
	//602B
	int n,zero,num,mx=1;
	cin>>n;
	vi v(n-1);
	sc(zero);
	lop(i,n-1) sc(num), v[i] = num - zero, zero = num;
	int cnt = 2, pre=0;
	loop(i,1,n-1){
		if(!v[i]) { cnt++; continue; }
		if(v[i] == v[pre]) { mx = max(mx,cnt); cnt = i - pre+1, pre = i; continue; }
		cnt++, pre = i;
	}
	mx = max(mx,cnt);
	cout<<mx<<endl;

	return 0;
}