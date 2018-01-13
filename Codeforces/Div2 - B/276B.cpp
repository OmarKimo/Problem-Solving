#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
#define loop(i,start,n) for(int i=start; i<n; i++)

int excess(string x){
	sort(all(x));
	int cnt=1,ret=0;
	char c = x[0];
	loop(i,1,sz(x)){
		if(x[i] != c) ret += (cnt%2), cnt=1;
		else cnt++;
		c = x[i];
	}
	ret += cnt%2;
	return ret;
}

int main()
{	
	//
	string str;
	cin>>str;
	int cnt = excess(str);
	if(cnt <= 1) return puts("First");
	if(sz(str) % 2) cout<<"First\n";
	else cout<<"Second\n";

	return 0;
}