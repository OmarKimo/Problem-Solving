#include <bits/stdc++.h>
using namespace std;

int main(){
int k,power=0,n;
	cin>>k>>n;
	while(n>k){
		if(n%k) return puts("NO");
		n/=k, power++;
	}
	if(n != k) cout<<"NO\n";
	else printf("YES\n%d\n",power);

return 0;
}