#include<bits/stdc++.h>
using namespace std;

int main(){
int mn=1e9,n,num;
cin>>n;
while(n--) scanf("%d",&num), mn=min(mn,num);
if(mn== 1) return puts("-1");
cout<<"1\n";
}