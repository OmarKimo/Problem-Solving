#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

#define sc(x)  scanf("%d",&x)
#define all(v) v.begin(),v.end()
#define lop(i,n) for(int i=0; i<n; i++)
#define rlop(i,n) for(int i=n-1; i>=0; i--)
#define f first
#define s second

bool my1(pair<ii,int> p1, pair<ii,int> p2){
	if(p1.f.f == p2.f.f) return p1.f.s < p2.f.s;
	return p1.f.f < p2.f.f;
}

bool my2(pair<ii,int> p1, pair<ii,int> p2){
	return p1.f.s < p2.f.s;
}

int main()
{	
	//282B
	int flag = 0, n,sum1=0,sum2=0;
	cin>>n;
	vector<pair<ii,int>> sec(n);
	lop(i,n) sc(sec[i].f.f),sc(sec[i].f.f),sum2+=sec[i].f.f,sec[i].f.s=i,sec[i].s=2;
	sort(all(sec),my1);
if(n==1 && sec[0].f.f > 500) return puts("A");
else if(n==1) return puts("G");
	rlop(i,n){
		sum2 -= sec[i].f.f;
		sum1 += 1000 - sec[i].f.f;
		sec[i].s = 1;
		if(abs(sum2-sum1) <= 500) { flag=1; break; }
	}
	if(!flag) return puts("-1");
	sort(all(sec),my2);
	lop(i,n){
		if(sec[i].s == 1) cout<<'A';
		else cout<<'G';
	}
	cout<<endl;

	return 0;
}