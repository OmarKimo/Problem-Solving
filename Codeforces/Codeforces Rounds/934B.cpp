#include <bits/stdc++.h>
using namespace std;

int main(){
int k;
cin>>k;
if(k>36)return puts("-1");
for(int i=0; i<k/2; i++) cout<<8;
k -= (k/2)*2;
if(k) cout<<6<<endl;

return 0;
}