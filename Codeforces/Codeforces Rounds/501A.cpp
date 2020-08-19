#include<bits/stdc++.h>
using namespace std;

int main(){
float a,b,c,d;
	cin>>a>>b>>c>>d;
	float n1 = max(3*a/10, a - (a/250)*c), n2 = max(3*b/10, b - (b/250)*d);
	if(n1 == n2) cout<<"Tie\n";
	else if(n1 > n2) cout<<"Misha\n";
	else cout<<"Vasya\n";
return 0;
}