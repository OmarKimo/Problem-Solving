#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

#define sz(v) (int)v.size()
#define lop(i,n) for(int i=0; i<n; i++)
#define loop(i,start,n) for(int i=start; i<n; i++)

int main()
{	
	int flag=0,y,k,n;
	cin>>y>>k>>n;
	vi ans;
	loop(i,1,(n/k)+1){
		if(i*k <= y) continue;
		if(i*k > n) break;
		cout<<i*k - y<<' ';
		flag=1;
	}
	if(!flag) cout<<-1<<endl;

	return 0;
}