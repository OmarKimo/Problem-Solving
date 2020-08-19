#include<bits/stdc++.h>
using namespace std;

int main(){
int n;
cin>>n;
int cnt=0, num;
set<int> st;
while(n--){
cin>>num;
if(num) st.insert(num);
}
cout<<st.size();
return 0;
}