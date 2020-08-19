#include <bits/stdc++.h>
using namespace std;

#define sz(v) (int)v.size()
#define lop(i,n) for(int i=0; i<n; i++)

bool iSBeautiful(string str){
	int cnt=0;
	lop(i,sz(str)) {
		if(str[i] == '1') cnt++;
		if(str[i] != '1' && str[i] != '0') return false;
	}
	if(cnt > 1) return false;
	return true;
}

int cnt0(string str){
	int flag=0,ret=0;
	lop(i,sz(str)){
		if(!flag && str[i]=='0') continue;
		flag = 1;
		if(str[i]=='0') ret++;
	}
	if(!flag) return -1;
	return ret;
}

int main()
{	// NoS Read Think Code Debug Diff. Type
	//608B: 4 3 10 6 10 2.5 impl.

	//614B
	int flag=0,n,zero=0,cnt=0; string str,no;
	cin>>n;
	lop(i,n){
		cin>>str;
		if(iSBeautiful(str)) {
			int ret = cnt0(str);
			if(ret==-1) { zero=1; continue; }
			cnt+=ret;
		}
		else no = str;
	}
	if(zero) return puts("0");
	lop(i,sz(no)){
		if(!flag && no[i]=='0') continue;
		flag=1; cout<<no[i];
	}
if(!flag) cout<<1;
	lop(i,cnt) cout<<0;
	cout<<endl;


	return 0;
}