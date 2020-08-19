#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef map<int,int> mii;

#define sc(x)  scanf("%d",&x)
#define all(v) v.begin(),v.end()
#define lop(i,n) for(int i=0; i<n; i++)
#define loop(i,start,n) for(int i=start; i<n; i++)
#define rloop(i,end,n) for(int i=n-1; i>=end; i--)
#define PB push_back
#define sz(v) (int)v.size()

int main()
{	
	//525B
	string str; int m,num;
	mii mp; vi swaps,action;
	cin>>str>>m;
	lop(i,m) sc(num),mp[num]++;
	rloop(i,1,sz(str)/2+1) if(mp[i]%2) swaps.PB(i);
	int siz = sz(swaps);
	lop(i,siz) 
		if((siz - i) % 2){ //There's odd pieces.
			if(!i) loop(j,swaps[i],sz(str)/2+1) action.PB(j);
			else loop(j,swaps[i],swaps[i-1]) action.PB(j);
		}
	lop(i,sz(action)){
		char tmp = str[action[i]-1];
		str[action[i]-1] = str[sz(str) - action[i]];
		str[sz(str) - action[i]] = tmp;
	}
	cout<<str<<endl;

	return 0;
}