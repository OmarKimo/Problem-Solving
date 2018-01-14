#include <bits/stdc++.h>
using namespace std;
 
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
 
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
#define rsz(v) v.resize
#define clr(v) v.clear()
#define lop(i,n) for(int i=0; i<n; i++)
#define PB push_back
 
//enum dir { u, r, d, l };
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
 
vs maze; int cnt; char c;
vvi vis(100,vi(100,0));
void solve(int i, int j){
	if(i < 0 || j>=sz(maze[i]) || j < 0 || i>=cnt || (maze[i][j] != ' ' && maze[i][j] != '*') || vis[i][j]) return;
	vis[i][j] = 1;
	maze[i][j] = '#';
	lop(k,4) solve(i+dx[k], j+dy[k]);
	vis[i][j] = 0;
}
 
 
int main()
{	
	//p784
	string in;
	int t,first=1;
	cin>>t;
	while(t-- && first++){
		clr(maze),clr(vis),rsz(vis)(100,vi(100,0));
		int sx,sy;
		cnt = 0; if(first == 2) cin.get();
		while(getline(cin,in)) { cnt++,maze.PB(in); if(in[0]=='_')break; }
		c= maze[0][0];
		lop(i,cnt) lop(j,sz(maze[i])) if(maze[i][j] == '*') sx = i, sy = j;
		solve(sx,sy);
		lop(i,cnt) { lop(j,sz(maze[i])) cout<<maze[i][j]; cout<<endl; }
	}

	return 0;
}