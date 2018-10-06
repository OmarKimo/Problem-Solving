#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define scl(x) scanf("%lld",&x)
#define lop(i,end) for(int i=0; i<end; i++)

int main()
{
    int n;
    ll x,xo;
    while(cin>>n && n){
        cin>>xo;
        lop(i,n-1) scl(x), xo ^= x;
        if(xo) cout<<"Yes\n";
        else cout<<"No\n";
    }

    return 0;
}
