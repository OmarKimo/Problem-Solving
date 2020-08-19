#include <bits/stdc++.h>
using namespace std;

int main(){

int x1,x2,y1,y2,x3,x4,y3,y4;
	cin>>x1>>y1>>x2>>y2;
	if(x1 == x2) x3 = x4 = x1 + abs(y1-y2), y3 = y1, y4 = y2;
	else if(y1 == y2) y3 = y4 = y1 + abs(x1-x2), x3 = x1, x4 = x2;
	else{
		int dis = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
		int sq = sqrt(dis/2);
		if(dis%2 || sq*sq != dis/2 || abs(x1-x2) != abs(y1-y2)) return puts("-1");
		x3 = x1, y3 = y2;
		x4 = x2, y4 = y1;
	}
	printf("%d %d %d %d\n",x3,y3,x4,y4);

return 0;
}