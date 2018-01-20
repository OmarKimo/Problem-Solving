#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define sz(v) (int)v.size()
#define lop(i,n) for(int i=0; i<n; i++)

int main()
{	
	//noS Read Think Code Debug Difficulty Type Discription
	//66A xx 1 3 7 2 2 greedy/impl. 

	//66A
	string num, longs = "9223372036854775807";
	ll by = 127, sh = 32767, in = 2147483647;
	cin>>num;
	if(num[0] == '-') num.erase(num.begin(),num.begin()+1), longs[sz(longs)-1] = '8', by++, sh++, in++;

	if(sz(num) < 3 || (sz(num) == 3 && stoi(num) <= by)) return puts("byte");
	if(sz(num) < 5 || (sz(num) == 5 && stoi(num) <= sh)) return puts("short");
	if(sz(num) < 10 || (sz(num) == 10 && stoll(num) <= in)) return puts("int");
	if(sz(num) < sz(longs)) return puts("long");
	if(sz(num) > sz(longs)) return puts("BigInteger");
	lop(i,sz(num)){
		if(num[i] > longs[i]) return puts("BigInteger");
		else if(num[i] < longs[i]) return puts("long");
	}
	return puts("long");
	
	return 0;
}