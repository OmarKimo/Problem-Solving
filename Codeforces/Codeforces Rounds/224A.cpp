#include <bits/stdc++.h>
using namespace std;

int main()
{	
	int a1,a2,a3;
	cin>>a1>>a2>>a3;
	cout<<4*(sqrt((a1*a2)/a3) + sqrt((a3*a2)/a1) + sqrt((a1*a3)/a2))<<endl;

	return 0;
}