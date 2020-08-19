#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define sz(v) (int)v.size()
#define lop(i,n) for(int i=0; i<n; i++)
#define mP make_pair
#define f first
#define s second

int main()
{	
	string s;
	cin>>s;
	int flag = 0;
	ll l=0,r=0,pos;
	vector<pair<ll,ll>> left, right;
	lop(i,sz(s)){
		if(s[i] == '=') continue;
		if(s[i] != '^'){
			if(flag) right.push_back(mP(s[i] -'0', i+1));
			else left.push_back(mP(s[i] -'0', i+1));
		}
		else pos = i+1, flag = 1;
	}
	lop(i,sz(left)) l += left[i].f * (pos - left[i].s);
	lop(i,sz(right)) r += right[i].f * (right[i].s - pos);
	if(l == r) cout<<"balance\n";
	else if(l > r) cout<<"left\n";
	else cout<<"right\n";

	return 0;
}