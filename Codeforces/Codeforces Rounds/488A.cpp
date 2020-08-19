#include <bits/stdc++.h>
using namespace std;

bool isLucky(int num){
	while(num){
		if(num%10 == 8) return true;
		num/=10;
	}
	return false;
}

int main()
{	
	int ans=1,a;
	cin>>a;
	while(!isLucky(abs(++a))) ans++;
	cout<<ans<<endl;

	return 0;
}