#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(),v.end()
#define rev(v) reverse(all(v))

int main()
{	
	int a,b,c;
	cin>>a>>b;
	c = a+b;
	string aa = "", bb = "", cc = "";
	while(a){
		if(a%10) aa+=(a%10)+'0';
		a/=10;
	}
	while(b){
		if(b%10) bb+=(b%10)+'0';
		b/=10;
	}
	while(c){
		if(c%10) cc+=(c%10)+'0';
		c/=10;
	}
	rev(aa), rev(bb), rev(cc);
	if(stoi(aa) + stoi(bb) == stoi(cc)) cout<<"YES\n";
	else cout<<"NO\n";

	return 0;
}