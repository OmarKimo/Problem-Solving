#include <bits/stdc++.h>
using namespace std;

int main(){
int n, num;
cin >>n;
vector<vector<int>> v(n+2);
for(int i=2; i<=n; i++){
cin>>num;
v[num].push_back(i);
}
for(int i=1;i<=n;i++){
if(!v[i].size()) continue;
if(v[i].size() < 3) return puts("No");
int cnt = 0;
for(int j=0;j<v[i].size(); j++)
if(!v[v[i][j]].size()) cnt++;
if(cnt<3) return puts("No");
}
cout<<"Yes\n";
return 0;}