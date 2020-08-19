#include <bits/stdc++.h>
using namespace std;

int main(){
        //401C
	int n,m;
	cin>>n>>m;
	if(n-1 > m || (!(m%2) && m/2 - 1 > n) || (m%2 && m/2 - 1 >= n) ) return puts("-1");
	if(n > m) printf("0"),n--;
	m -= n;
	while(n--){
		if(m > 0) printf("1"), m--;
		cout<<10;
	}
        while(m--) cout<<1;
	cout<<endl;
        return 0;
}