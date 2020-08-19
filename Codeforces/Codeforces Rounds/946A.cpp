#include<bits/stdc++.h>
using namespace std;

int main(){
int num,n,A=0,B=0;
cin>>n;
while(n--) scanf("%d",&num), (num >= 0) ? (A+=num) : (B+=num);
cout<<A-B<<endl;

return 0;
}