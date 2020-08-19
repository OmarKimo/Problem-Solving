#include <bits/stdc++.h>
using namespace std;

int main(){
int n,num,mx=-10000000;
cin>>n;
while(n--){
cin>>num;
if(num < 0 || (int)sqrt(num) * (int)sqrt(num) != num) mx =max(mx,num);
}
cout<<mx<<endl;
return 0;
}