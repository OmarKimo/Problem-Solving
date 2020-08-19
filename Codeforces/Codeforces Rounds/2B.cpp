#include <bits/stdc++.h>
using namespace std;

typedef unsigned int uint;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef map<int,int> mii;
typedef map<string,int> msi;
typedef map<int,string> mis;
typedef pair<int, ii> edge;


#define sc(x)  scanf("%d",&x)
#define scl(x) scanf("%lld",&x)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define mem(arr,val) memset(arr,val,sizeof arr)
#define sz(v) (int)v.size()
#define rsz(v) v.resize
#define clr(v) v.clear()
#define rev(v) reverse(all(v))
#define lop(i,end) for(int i=0; i<end; i++)
#define rlop(i,start) for(int i=start-1; i>=0; i--)
#define loop(i,start,end) for(int i=start; i<end; i++)
#define rloop(i,start,end) for(int i=start-1; i>=end; i--)
#define PB push_back
#define pb pop_back
#define mP make_pair
#define f first
#define s second

const ll OO = (4e18)+9;
const int MOD = (1e9)+7;
const int oo = 2147483647;
const double EPS = 1e-8;
const double PI = acos(-1.0);

//enum dir { r, d, l, u };
int dx[] = { 0, 1, 0,-1 };
int dy[] = { 1, 0,-1, 0 };

//enum diR { d, r, u, l , dr, ur, dl, ul };
int dX[] = { 1, 0, -1, 0, 1, -1, 1, -1 };
int dY[] = { 0, 1, 0, -1, 1, 1, -1, -1 };

string abc = "abcdefghijklmnopqrstuvwxyz";
string vowels = "aeiou"; //and sometimes "aeiouy"

int dcmp(ld d1,ld d2){ return fabs(d1-d2)<=EPS?0:d1>d2?1:-1; } //Compare Double Numbers
ll gcd (ll x, ll y){ return !y ? x : gcd(y, x%y); }
ll lcm (ll a, ll b) { return a * (b / gcd(a, b)); }
int ord(int r,int c,int nCol) { return (nCol*r) + c + 1; } //convert index from 2D matrix to 1D array. (Zero-indexed)
ii rord(int n, int nCol){ //convert index from 1D array to 2D matrix . (One-indexed)
    int r = n%nCol,c = n/nCol;
    if(n%nCol == 0) c--, r = nCol;
    return ii(r,c);
}

ll poww(ll num, ll p , ll md = MOD){
    num %= md;
    ll ret = 1;
    while (p > 0) {
        if (p & 1) ret = (ret * num) % md;
        num = (num * num) % md;
        p >>= 1;
    }
    return ret;
}

ll nCr(ll n, ll r) {
    if (n < r)
        return 0;
    if (r == 0)
        return 1;
    return n * nCr(n - 1, r - 1) / r;
}

const int N = 1010;
int n, mat2[N][N], mat5[N][N], dp2[N][N], dp5[N][N];

int solve2(int x = 0, int y = 0){
    if(x >= n || y >= n) return 1e6;
    if(x == n-1 && y == n-1) return mat2[x][y];
    int& ret = dp2[x][y];
    if(~ret) return ret;
    return ret = min(solve2(x+1,y)+mat2[x][y], solve2(x,y+1)+mat2[x][y]);
}

int solve5(int x = 0, int y = 0){
    if(x >= n || y >= n) return 1e6;
    if(x == n-1 && y == n-1) return mat5[x][y];
    int& ret = dp5[x][y];
    if(~ret) return ret;
    return ret = min(solve5(x+1,y)+mat5[x][y], solve5(x,y+1)+mat5[x][y]);
}

string path2,path5;
void getPath2(int x = 0, int y = 0){
    if(x >= n-1 && y >= n-1) return;
    int mn = solve2(x+1,y);
    if(mn + mat2[x][y] == solve2(x,y)) path2 += 'D', getPath2(x+1,y);
    else path2 += 'R', getPath2(x,y+1);
}

void getPath5(int x = 0, int y = 0){
    if(x >= n-1 && y >= n-1) return;
    int mn = solve5(x+1,y);
    if(mn + mat5[x][y] == solve5(x,y)) path5 += 'D', getPath5(x+1,y);
    else path5 += 'R', getPath5(x,y+1);
}


int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    mem(dp2,-1), mem(dp5,-1);
    sc(n);
    int cnt,num,tmp,zx=-1,zy=-1;
    lop(i,n) lop(j,n){
        sc(num);
        if(!num) zx = i, zy = j;
        tmp = num, cnt = 0;
        while(num && !(num%2)) cnt++, num/=2;
        mat2[i][j] = cnt, cnt = 0;
        while(tmp && !(tmp%5)) cnt++, tmp/=5;
        mat5[i][j] = cnt, cnt = 0;
    }
    int ans2 = solve2(), ans5 = solve5();
    if(zx != -1 && min(ans2,ans5) > 0){
        lop(i,zx) path2 += 'D';
        lop(i,zy) path2 += 'R';
        lop(i,n-zx-1) path2 += 'D';
        lop(i,n-zy-1) path2 += 'R';
        return cout<<1<<endl<<path2<<endl, 0;
    }
    getPath2(), getPath5();
    if(ans2 < ans5) cout<<ans2<<endl<<path2<<endl;
    else cout<<ans5<<endl<<path5<<endl;

    return 0;
}