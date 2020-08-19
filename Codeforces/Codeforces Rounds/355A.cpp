#include <bits/stdc++.h>
using namespace std;

int main(){
        int k,d;
	cin>>k>>d;
	if(!d && k==1) return puts("0");
        else if(!d) return puts("No solution");
        if(k==1){
		cout<<d<<endl;
		return 0;
	}
	string ans = "1";
	for(int i=0; i<k-2; i++) ans+='0';
	if(k>1) ans+=(d-1)+'0';
	cout<<ans<<endl;

        return 0;
}