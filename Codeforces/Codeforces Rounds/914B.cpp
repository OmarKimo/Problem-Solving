#include <bits/stdc++.h>
using namespace std;

int main(){
int n;
cin>>n;
vector<int> v(n); map<int,int> mp;
for(int i=0; i<n; i++) scanf("%d",&v[i]), mp[v[i]]++;
for(int i=0; i<n; i++) if(mp[v[i]]%2) return puts("Conan");
cout<<"Agasa\n";
return 0;
}