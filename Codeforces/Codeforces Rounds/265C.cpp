#include<bits/stdc++.h>
using namespace std;

int main(){

	//265C
	char str[1000009];
	scanf("%s", str);
	int sz = strlen(str), id1=0,id2=0,v1[1000100], v2[1000100];
	for(int i=0; i<sz; i++){
		if(str[i] == 'l') v2[id2++] = i+1;
		else v1[id1++] = i+1;
	}
	for(int i = 0; i < id1; i++) printf("%d\n",v1[i]);
	for(int i = id2-1; i>=0; i--) printf("%d\n",v2[i]);

	return 0;
}