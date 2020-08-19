#include<bits/stdc++.h>
using namespace std;

int main(){
long long x,y,z,a,b, reqb, reqy;
cin>>a>>b>>x>>y>>z;
reqb = z*3+y;
reqy = 2*x+y;
long long ans = 0;
if(reqy > a) ans += reqy - a;
if(reqb > b) ans += reqb - b;
cout<<ans<<endl;


return 0;
}