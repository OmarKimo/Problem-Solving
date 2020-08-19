#include <bits/stdc++.h>
using namespace std;
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
#define ord(i) (int)(8*(i.f-1)+i.s)


const ll OO = 9223372036854775807;
const int oo = 2147483647;
const double EPS = 1e-9;
const double PI=acos(-1.0);

//enum dir { d, r, u, l };
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

//enum diR { d, r, u, l , dr, ur, dl, ul };
int dX[] = { 1, 0, -1, 0, 1, -1, 1, -1 };
int dY[] = { 0, 1, 0, -1, 1, 1, -1, -1 };


int dot(int x, int y, int x2, int y2) {return x * x2 + y * y2; }
ll gcd (ll x, ll y){ return !y ? x : gcd(y, x%y); }
//Compare Double Numbers
int cmpDouble(ld d1,ld d2){ return fabs(d1-d2)<=EPS?0:d1>d2?1:-1; }

vvc game(8,vc(8));
bool solve(int x, int y, vii SS){
	if(x < 0 || x>=8 || y<0 || y>=8 || find(all(SS), mP(x,y)) != SS.end()) return false;
	int flag=1;
	lop(i,sz(SS)) { SS[i].first++; if(SS[i].first<8) flag=0; }
	if(find(all(SS), mP(x,y)) != SS.end()) return false;
	if(flag || !sz(SS) || (!x && y==7)) return true;
	
	return solve(x,y,SS) || solve(x+dX[0],y+dY[0],SS) || solve(x+dX[1],y+dY[1],SS) || solve(x+dX[2],y+dY[2],SS) || solve(x+dX[3],y+dY[3],SS) || solve(x+dX[4],y+dY[4],SS) || solve(x+dX[5],y+dY[5],SS) || solve(x+dX[6],y+dY[6],SS) || solve(x+dX[7],y+dY[7],SS);
}

int main()
{

	//128A
	vii statues;
	lop(i,8) lop(j,8) { cin>>game[i][j]; if(game[i][j]=='S') statues.PB(mP(i-1,j)); }

	if(solve(7,0,statues)) cout<<"WIN\n";
	else cout<<"LOSE\n";
	return 0;
}