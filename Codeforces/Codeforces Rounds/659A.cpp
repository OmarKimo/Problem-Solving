#include<bits/stdc++.h>
using namespace std;

int main(){
        int n,a,b;
	cin>>n>>a>>b;
	if(!b) { cout<<a<<endl; return 0; }
	if(b < 0){
		b = -b%n;
		b = n - b;
                if((a+b) > n) cout<<(a+b)-n<<endl;
                else cout<<a+b<<endl;
	}
	else{
		b%=n;
		if((a+b) > n) cout<<(a+b)-n<<endl;
                else cout<<a+b<<endl;
	}
        return 0;
}