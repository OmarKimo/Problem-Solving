#include<bits/stdc++.h>
using namespace std;

int main(){
int ans=0,val,x,y;
	cin>>x>>y;
	if(!y && (!x || x==1)) return puts("0");
	if((x > 0 && y > (-x+1) && y <= x) || (x < 0 && y >= x && y < -x)) val = x, ans = 1;
	else ans = 2,val = y;
	if(val < 0) ans += (abs(val)*2 - 1) *2;
	else ans += (val-1)*4; 
	cout<<ans<<endl;
return 0;
}