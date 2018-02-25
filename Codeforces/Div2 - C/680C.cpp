#include<bits/stdc++.h>
using namespace std;

int main(){

	//680C
	int pr[19] = {2,3,4,5,7,9,11,13,17,19,23,25,29,31,37,41,43,47,49};
	int cnt = 0;
	string res;
	for(int i=0; i<19; i++){
		cout<<pr[i]<<endl;
		fflush(stdout);
		cin>>res;
		cnt += res == "yes";
	}
	if(cnt > 1) cout<<"composite\n";
	else cout<<"prime\n";

	return 0;
}