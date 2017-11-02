#include <bits/stdc++.h>
using namespace std;
typedef unsigned int uint;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef pair<ll,ll> llll;
typedef vector<int> vi ;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<ii> vii;
typedef vector<llll> vllll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vb> vvb;
typedef vector<vc> vvc;
typedef vector<vii> vvii;
typedef map<int,int> mii;
typedef map<string,int> msi;
typedef map<int,string> mis;
typedef map<string,string> mss;
typedef map<int,char> mic;
typedef map<char,int> mci;

#define sc(x)  scanf("%d",&x)
#define scl(x) scanf("%I64d",&x)
#define all(v) v.begin(),v.end()
#define mem(arr,val) memset(arr,val,sizeof arr)
#define sz(v) (int)v.size()
#define rsz(v) v.resize
#define clr(v) v.clear()
#define rev(v) reverse(all(v))
#define lop(i,n) for(int i=0; i<n; i++)
#define rlop(i,n) for(int i=n-1; i>=0; i--)
#define loop(i,start,n) for(int i=start; i<n; i++)
#define rloop(i,end,n) for(int i=n-1; i>=end; i--)
#define PB push_back
#define pb pop_back
#define mP make_pair
#define f first
#define s second
#define ord0(s) (int)(s-'0')
#define orda(s) (int)(s-'a')
#define ordA(s) (int)(s-'A')


const ll OO = (ll)1e18+9;
const int oo = 2147483647;
const double EPS = 1e-9;
const double PI=acos(-1.0);

//enum dir { u, r, d, l };
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

//enum diR { d, r, u, l , dr, ur, dl, ul };
int dX[] = { 1, 0, -1, 0, 1, -1, 1, -1 };
int dY[] = { 0, 1, 0, -1, 1, 1, -1, -1 };

char letters[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};


int n,m,cnt=0,idx=0;
char grid[1010][1010];
int vis[1010][1010];
map<ii,int> mp;
vi ans;

bool valid(int x, int y){ return x>=0 && y>=0 && x<n && y<m; }

void dfs(int x, int y){
	vis[x][y]=1;  mp[mP(x,y)] = idx;
	lop(i,4){
		if(valid(x+dx[i], y+dy[i]) && grid[x+dx[i]][y+dy[i]] == '*') cnt++;
		else if(valid(x+dx[i], y+dy[i]) && !vis[x+dx[i]][y+dy[i]] && grid[x+dx[i]][y+dy[i]] == '.') dfs(x+dx[i],y+dy[i]);
	}
}



int main()
{
	
	//598D
	int k,a,b;
	cin>>n>>m>>k;
	mem(vis,0);
	lop(i,n) lop(j,m) cin>>grid[i][j];

	lop(i,k){
		cin>>a>>b;
		cnt=0;
		if(!vis[a-1][b-1]) {
			dfs(a-1,b-1);
			ans.PB(cnt);
			idx++;
		}
		cout<<ans[mp[mP(a-1,-1+b)]]<<endl;
	}
	return 0;
}