#include<bits/stdc++.h>
using namespace std;

int main(){
int a,b,n1=0,n2=0,n3=0;
	cin>>a>>b;
	for(int i=1; i<=6; i++){
		if(abs(a-i) < abs(b-i)) n1++;
		else if(abs(a-i) > abs(b-i)) n3++;
		else n2++;
	}
	printf("%d %d %d\n",n1,n2,n3);
return 0;
}