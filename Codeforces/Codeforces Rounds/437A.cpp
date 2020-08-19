#include <bits/stdc++.h>
using namespace std;

typedef vector<string> vs;

#define sz(v) (int)v.size()
#define lop(i,n) for(int i=0; i<n; i++)

int main()
{	
	char ans = ' ';
	vs v(4);
	lop(i,4) cin>>v[i];
	lop(i,4){
		int cnt1 = 0, cnt2=0;
		lop(j,4){
			if(i!=j){
				int sz1 = sz(v[i]) -2, sz2 = sz(v[j]) - 2;
				if(sz1*2 <= sz2) cnt1++;
				if(sz2*2 <= sz1) cnt2++;
			}
		}
		if(cnt1 == 3 || cnt2 == 3) ans = ans == ' ' ? char('A' + i) : ' ';
	}
	if(ans == ' ') cout<<"C\n";
	else cout<<ans<<endl;

	return 0;
}