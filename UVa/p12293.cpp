#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,winner,pw,amount;
    string ans[] = {"Alice\n", "Bob\n"};
    while(cin>>n && n){
        winner = 0, amount = pw = 1;
        while(n > 0){
            if(n == 1) winner = 1;
            n -= amount+1;
            amount += 2*pw, pw*=2;
        }
        cout<<ans[winner];
    }

    return 0;
}