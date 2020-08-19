#include<bits/stdc++.h>
using namespace std;

int main(){
	int a,b,r;
	cin>>a>>b>>r;
	int cnt = min(((a/(2*r)) >= 1) + (a/2-r)/(2*r) + (a/2-r)/(2*r), ((b/(2*r)) >= 1) + (b/2-r)/(2*r) + (b/2-r)/(2*r));
	if(cnt%2) printf("First\n");
	else printf("Second\n");

return 0;
}