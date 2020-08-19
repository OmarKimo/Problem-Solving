#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(),v.end()
#define rev(v) reverse(all(v))

int main()
{	
	string s;
	cin>>s;
	string h = s.substr(0,2), m = s.substr(3,5), hh = h;
	rev(hh);
	int n1=stoi(h),n2=stoi(m);
	if(n2 >= stoi(hh) || (n1 > 5 && n1 < 10) || (n1 < 20 && n1 > 15)){
		n1++, n1%=24;
		if(n1 < 10 && n1 > 5) n1 = 10;
		if(n1 < 20 && n1 > 15) n1 = 20;
		h = "";
		if(n1 < 10) h = "0";
		h += to_string(n1);
		hh = h;
		h += ':';
		rev(hh);
		h += hh;
		cout<<h<<endl;
	}
	else{
		h += ':';
		h+=hh;
		cout<<h<<endl;
	}

	return 0;
}