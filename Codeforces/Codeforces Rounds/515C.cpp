#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
#define rev(v) reverse(all(v))
#define lop(i,n) for(int i=0; i<n; i++)
#define PB push_back
int main()
{	
	//515C
map <int,vi> mp;
mp[2] = {2};
mp[3] = {3};
mp[4] = {3,2,2};
mp[5] = {5};
mp[6] = {3,5};
mp[7] = {7};
mp[8] = {2,2,2,7};
mp[9] = {3,3,2,7};
int n;
cin>>n;
string x;
cin>>x;
vi ans;
lop(i,sz(x)) lop(j,sz(mp[x[i]-'0'])) ans.PB(mp[x[i]-'0'][j]);
sort(all(ans));
rev(ans);
lop(i,sz(ans)) cout<<ans[i];
cout<<endl;

	return 0;
}