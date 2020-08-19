#include <bits/stdc++.h>
using namespace std;

int main(){

map<char,int> mp;
	char arr[9] = {'6','7','8','9','T','J','Q','K','A'};
	for(int i=0; i<9; i++) mp[arr[i]] = i+1;
	string trump, card1, card2;
	cin>>trump>>card1>>card2;
	if((card1[1] == trump[0] && card2[1] != trump[0]) || (card1[1] == card2[1] && mp[card1[0]] > mp[card2[0]])) cout<<"YES\n";
	else cout<<"NO\n";

return 0;
}