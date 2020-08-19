#include <bits/stdc++.h>
using namespace std;

int main(){

freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	cin>>n;
	string s;
	cin>>s;
	for(int i=0; i<n/2; i++){
		int id1 = i, id2 = i+n/2;
		if(s[id1] == 'R' && s[id2] == 'L') cout<<id2+1 << ' '<<id1+1<<endl;
		else cout<<id1+1 << ' '<<id2+1<<endl;
	}

	return 0;
}