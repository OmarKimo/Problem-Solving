#include <bits/stdc++.h>
using namespace std;

int main(){
int a,b,c,n;
cin>>a>>b>>c>>n;
int pass = a+b-c;
if(a<c || b<c ||pass < 0 || pass >= n) cout<<-1;
else cout<<n-pass;
return 0;
}