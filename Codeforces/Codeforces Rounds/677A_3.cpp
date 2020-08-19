#include <bits/stdc++.h>
using namespace std;

#define sc(x) scanf("%d",&x)
#define lop(i,n) for(int i=0; i<n; i++)

int main(){
//677A
int n,h,num,ans=0;
cin>>n>>h;
lop(i,n) sc(num), ans += (num>h) ? (2) : (1);
cout<<ans<<endl;

return 0;
}