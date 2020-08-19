#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
#define lop(i,n) for(int i=0; i<n; i++)

int main()
{	

	//
	string s1,s2;
	cin>>s1>>s2;
	if(sz(s1) != sz(s2)) return puts("NO");
	int flag=0,f=-1,s=-1;
	lop(i,sz(s1)){
		if(s1[i] != s2[i]){
			if(f==-1) f=i;
			else if(s==-1)s=i;
			else return puts("NO");
		}
	}
	string ss = s1;
	sort(all(ss));
	lop(i,sz(ss)-1) if(ss[i] == ss[i+1]) flag=1;
	if((f==-1 && flag) || (f!=-1 && s!=-1 && s1[f] == s2[s] && s1[s] == s2[f])) cout<<"YES\n";
	else cout<<"NO\n";

	return 0;
}