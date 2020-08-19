#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;

#define sc(x)  scanf("%d",&x)
#define all(v) v.begin(),v.end()
#define lop(i,n) for(int i=0; i<n; i++)
#define loop(i,start,n) for(int i=start; i<n; i++)
#define mP make_pair
#define f first
#define s second

int main()
{	
	int x1,x2,n;
	cin>>n;
	vii p(n-1);
	cin>>x1;
	lop(i,n-1) sc(x2),p[i] = mP(min(x1,x2), max(x1,x2)), x1=x2;
	sort(all(p));
	lop(i,n-2) loop(j,i+1,n-1) if(p[j].f > p[i].f && p[j].f < p[i].s && p[j].s > p[i].s) return puts("yes");
	cout<<"no\n";

	return 0;
}