#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <bitset>
#include <string>
#include <stack>
#include <queue>
#include <cstring>
#include <iomanip>
#include <valarray>
#include <sstream>
#include <fstream>
#include <functional>
#include <utility>
#include <numeric>
#include <iterator>

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

/*#define sc(x)  scanf("%d",&x)
#define scl(x) scanf("%lld",&x)*/
#define all(v) v.begin(),v.end()
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


const ll OO = 1000000000;
const double EPS = 1e-9;
const double PI=acos(-1.0);

int dot(int x, int y, int x2, int y2) {return x * x2 + y * y2; }
ll gcd (ll x, ll y){ return !y ? x : gcd(y, x%y); }
//Compare Double Numbers
int cmpDouble(ld d1,ld d2){ return fabs(d1-d2)<=EPS?0:d1>d2?1:-1; }



int main()
{

	//TOE2
	int t,x,o,winX=0,winO=0,overWinX=0,overWinO=0;
	vvc game(3,vc(3));
	cin>>game[0][0]>>game[0][1]>>game[0][2];
	while(game[0][0]!='e'){
		
		vi WinX(3,0),WinO(3,0);
		x=0,o=0,winX=0,winO=0,overWinX=0,overWinO=0;

		lop(i,3) { if(game[0][i]=='X') x++; else if(game[0][i]=='O') o++; }
		loop(i,1,3) lop(j,3) { cin>>game[i][j]; if(game[i][j]=='X') x++; else if(game[i][j]=='O') o++; }

		if(game[0][0] == game[0][1] && game[0][1] == game[0][2] && game[0][0]!='.') { if(game[0][0]=='X') winX=1,WinX[0]++; else winO=1,WinO[0]++; }
		if(game[1][0] == game[1][1] && game[1][1] == game[1][2] && game[1][1]!='.') { if(game[1][1]=='X') winX=1,WinX[0]++; else winO=1,WinO[0]++; }
		if(game[2][0] == game[2][1] && game[2][1] == game[2][2] && game[2][2]!='.') { if(game[2][2]=='X') winX=1,WinX[0]++; else winO=1,WinO[0]++; }
		if(game[0][0] == game[1][0] && game[1][0] == game[2][0] && game[0][0]!='.') { if(game[0][0]=='X') winX=1,WinX[1]++; else winO=1,WinO[1]++; }
		if(game[0][1] == game[1][1] && game[1][1] == game[2][1] && game[1][1]!='.') { if(game[1][1]=='X') winX=1,WinX[1]++; else winO=1,WinO[1]++; }
		if(game[2][2] == game[0][2] && game[1][2] == game[0][2] && game[0][2]!='.') { if(game[0][2]=='X') winX=1,WinX[1]++; else winO=1,WinO[1]++; }
		if(game[0][2] == game[1][1] && game[0][2] == game[2][0] && game[0][2]!='.') { if(game[0][2]=='X') winX=1,WinX[2]++; else winO=1,WinO[2]++; }
		if(game[0][0] == game[1][1] && game[1][1] == game[2][2] && game[0][0]!='.') { if(game[0][0]=='X') winX=1,WinX[2]++; else winO=1,WinO[2]++; }

		if(WinX[0]>1 || WinX[1]>1) overWinX=1;
		if(WinO[0]>1 || WinO[1]>1) overWinO=1;

		if(abs(x-o)>1 || o>x || overWinO || overWinX || (winX && o>=x) || (winO && o!=x) || (winO && winX) || (!winO && !winX && (x+o)!=9)) puts("invalid");
		else puts("valid");
		
		cin>>game[0][0]>>game[0][1]>>game[0][2];
	}
	return 0;
}