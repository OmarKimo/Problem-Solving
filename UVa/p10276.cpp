#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

#define lop(i,n) for(int i=0; i<n; i++)

int main()
{	
	//p10276
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		vi v(n,0);
		int num = 1;
		while(true){
			int flag = 0;
			lop(i,n) if(!v[i] || (int)sqrt(num+v[i]) * (int)sqrt(num+v[i]) == (num+v[i])) { v[i] = num, flag=1; break; }
			if(!flag) break;
			num++;
		}
		cout<<num-1<<endl;
	}

	return 0;
}