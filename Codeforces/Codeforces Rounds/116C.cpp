#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
#define lop(i,n) for(int i=0; i<n; i++)
#define PB push_back

vvi graph(2010);
vi vis(2010,0); int mx = 0;
void dfs(int nod, int lev){
	vis[nod]=1; mx = max(mx,lev);
	lop(i,sz(graph[nod])) if(!vis[graph[nod][i]]) dfs(graph[nod][i],lev+1);
}

int main()
{	
	//116C
	int n,num;
	cin>>n;
	vi no;
	lop(i,n){
		cin>>num;
		if(num == -1) no.PB(i+1);
		else graph[num].PB(i+1);
	}
	lop(i,sz(no)) dfs(no[i],0);
	cout<<mx+1<<endl;


	return 0;
}