#include <bits/stdc++.h>
using namespace std;

#define lop(i,n) for(int i=0; i<n; i++)

int main()
{	
	int n;
	cin>>n;
if(!n) return puts("O-|-OOOO");
	while(n){
		int digit = n%10;
		n/=10;
		string out = "";
		if(!digit){
			out = "O-|-OOOO";
		}
		else if(digit < 5){
			out = "O-|";
			lop(i,digit) out += 'O';
			out+='-';
			int rest = 5-digit-1;
			lop(i,rest) out+='O';
		}
		else{
			out = "-O|";
			lop(i,digit-5) out += 'O';
			out+='-';
			int rest = 5-(digit-5)-1;
			lop(i,rest) out+='O';
		}
		cout<<out<<endl;
	}

	return 0;
}