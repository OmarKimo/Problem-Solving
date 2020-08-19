#include <bits/stdc++.h>
using namespace std;

int main(){
int r1,r2,c1,c2;
cin>>r1>>c1>>r2>>c2;
int rook = (r1 == r2 || c1 == c2) ? 1 : 2;
int bishop = ((r1+c1)%2 == (r2+c2)%2) ? ((r1+c1 == r2+c2 || r1-c1 == r2-c2) ? 1 : 2) : 0;
int king = max(abs(r1-r2), abs(c1-c2));
printf("%d %d %d\n", rook, bishop, king);

return 0;
}