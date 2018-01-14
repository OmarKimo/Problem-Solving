#include <bits/stdc++.h>
using namespace std;
 
typedef vector<int> vi;
#define loop(i,start,n) for(int i=start; i<n; i++) 
const int oo = 2147483647;
 
int main()
{	
	//p105
	vi high(10010,0);
	int L,R,H,start=oo,end=0;
	while(cin>>L>>H>>R){
		loop(i,L,R) high[i] = max(high[i],H);
		end = max(end,R);
		start = min(start,L);
	}
	int flag = 1; H = 0;
	loop(i,start,end+1){
		if(high[i] != H){
			if(flag) flag = 0;
			else cout<<' ';
			printf("%d %d", i, high[i]);
			H = high[i];
		}
	}
	cout<<endl;
 
	return 0;
}