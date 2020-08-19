#include <bits/stdc++.h>
using namespace std;

int main()
{	
	int n,dis=0,mn;
	cin>>n;
	vector<int> v(n);
	for(int i=0; i<n; i++) cin>>v[i];
	map<int,int> mp;
	for(int i=0; i<n-1; i++) mp[v[i+1] - v[i]]++, dis = max(dis, v[i+1] - v[i]);
	mn = 2000;
	for(int i=1; i<n-1; i++){
		//if(mp[v[i+1] - v[i-1]] > 1) continue;
		mn = min(mn, max(v[i+1] - v[i-1],dis));
		
	}
	cout<<mn<<endl;

	return 0;
}