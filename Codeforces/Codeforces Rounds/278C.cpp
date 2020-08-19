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
#define ord0(s) (int)(s-'0')
#define orda(s) (int)(s-'a')
#define ordA(s) (int)(s-'A')

const ll OO = (ll)(4e18)+9;
const ll MOD = (ll)(1e9)+7;
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

ll poww(ll num, ll p , ll md){
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

struct UnionFind {
//private:
	vi p, rank, setSize; //p stands for Parent
	int forests;
//public:
	UnionFind(int N) {
		setSize.assign(N, 1);
		rank.assign(N, 0);
		p.assign(N, 0);
		forests = N;
		for (int i = 0; i < N; i++) p[i] = i;
	}
	int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); } //Dynamic Programming ^_^
	bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
	bool unionSet(int i, int j) {
		bool flag = !isSameSet(i, j);
		if (flag) { // if from different set
			int x = findSet(i), y = findSet(j);
			if (rank[x] > rank[y]) setSize[x] += setSize[y], swap(x,y); // rank keeps the tree short
			else setSize[y] += setSize[x];
			p[x] = y;
			if (rank[x] == rank[y]) rank[y]++;
			forests--;
		}
		return flag;
	}
	int numDisjointSets() { return forests; }
	int sizeOfSet(int i) { return setSize[findSet(i)]; }
};


int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n,m,cnt,l,num=0;
    sc(n), sc(m);
    vvi know(n), known(m+1);
    lop(i,n){
        sc(cnt);
        num += !cnt;
        lop(j,cnt) sc(l), know[i].PB(l),known[l].PB(i);
    }
    UnionFind uf(n);
    lop(i,n){
        lop(j,sz(know[i])){
            lop(k,sz(known[know[i][j]])) uf.unionSet(i,known[know[i][j]][k]);
        }
    }
    cout<<max(num,uf.numDisjointSets()-1)<<endl;



    return 0;
}