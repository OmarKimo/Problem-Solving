#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define sc(x)  scanf("%d",&x)
#define lop(i,n) for(int i=0; i<n; i++)

int main()
{	
	int sum1=0, sum2=0, ans=0, n;
	cin>>n;
	vii v(n);
	lop(i,n) sc(v[i].first),sc(v[i].second), sum1+=v[i].first, sum2+=v[i].second;
	if(sum2%2 && sum1%2){
		bool chk = false;
		lop(i,n) if(v[i].first%2 != v[i].second%2) chk=true;
		if(!chk) ans = -1;
		else ans = 1;
	}
	else if(sum2%2 || sum1%2) ans = -1;
	cout<<ans<<endl;

	return 0;
}