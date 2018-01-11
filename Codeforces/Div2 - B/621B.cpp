#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef map<int,int> mii;

#define sc(x)  scanf("%d",&x)
#define lop(i,n) for(int i=0; i<n; i++)
#define loop(i,start,n) for(int i=start; i<n; i++)

int main()
{	
	//621B
	int n,x,y;
	ll ans=0;
	cin>>n;
	mii mpadd,mpdiff; 
	set<int> stadd,stdiff; 
	vi series(2001,0);
	loop(i,1,2001) series[i] = series[i-1]+i-1; 
	lop(i,n) sc(x),sc(y),mpadd[x+y]++,mpdiff[x-y]++,stadd.insert(x+y),stdiff.insert(x-y);
	for(set<int>::iterator it = stadd.begin(); it!=stadd.end(); it++) ans+=series[mpadd[*it]];
	for(set<int>::iterator it = stdiff.begin(); it!=stdiff.end(); it++) ans+=series[mpdiff[*it]];
	cout<<ans<<endl;

	return 0;
}