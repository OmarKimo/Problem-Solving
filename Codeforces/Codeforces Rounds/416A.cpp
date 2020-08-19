#include <bits/stdc++.h>
using namespace std;

#define lop(i,n) for(int i=0; i<n; i++)

const int oo = 2147483647;

int main()
{	
	int n,num, mnLim=oo, mxLim=oo;
	cin>>n;
	string op,yn;
	lop(i,n){
		cin>>op>>num>>yn;
		if(op == ">"){
			if(yn == "Y") mnLim = (mnLim == oo) ? num : (max(mnLim,num));
			else mxLim = (mxLim == oo) ? num+1 : (min(mxLim,num+1));
		}
		else if(op == ">="){
			if(yn == "Y") mnLim = (mnLim == oo) ? num-1 : (max(mnLim,num-1));
			else mxLim = (mxLim == oo) ? num : (min(mxLim,num));
		}
		else if(op == "<"){
			if(yn == "N") mnLim = (mnLim == oo) ? num-1 : (max(mnLim,num-1));
			else mxLim = (mxLim == oo) ? num : (min(mxLim,num));
		}
		else{
			if(yn == "N") mnLim = (mnLim == oo) ? num : (max(mnLim,num));
			else mxLim = (mxLim == oo) ? num+1 : (min(mxLim,num+1));
		}
	}
	if(mnLim != oo && mxLim != oo && (mnLim >= mxLim || mnLim == mxLim-1)) cout<<"Impossible\n";
	else if(mnLim == oo) cout<<mxLim - 1<<endl;
	else cout<<mnLim+1<<endl;

	return 0;
}