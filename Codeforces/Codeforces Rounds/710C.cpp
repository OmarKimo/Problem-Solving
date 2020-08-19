// Easy things to check:
// - LONG LONGS (WA)
// - const int N is correct (WA, RTE) CHECK IF IT SHOULD BE 2*N!!!!
// - .size()-k underflow (WA, RTE, TLE)
// - small n edge cases (WA)

// Rare mistakes made in the past:
// - division by 0 (WA)
// - negative arithmetic, ceiling division, modulo (WA)
// - setprecision (WA)
// - INF not big enough using ll (WA)
// - setting max to 0 instead of -INF/min to 0 instead of INF (WA)
// - outputting debug (WA)
// - allocating too much memory (locRTE, MLE)
// - stack size (locRTE)
// - round announcements (WA)
// - multiset::erase (WA)
// - forgetting to rename recursive call when copy/pasting recursive function (WA)
// - not clearing DS between test cases EVEN FOR INPUT (WA, RTE, TLE, MLE)

#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>
#include <random>
using namespace std;

typedef unsigned int uint;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mii;
typedef map<string, int> msi;
typedef map<int, string> mis;
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

const ll OO = (ll)(4e18) + 9;
const int MOD = 998244353;
const int oo = 2147483647;
const double EPS = 1e-8;
const double PI = acos(-1.0);

//enum dir { d, r, u, l , dr, ur, dl, ul };
int dx[] = { 1, 0, -1, 0, 1, -1, 1, -1 };
int dy[] = { 0, 1, 0, -1, 1, 1, -1, -1 };

string abc = "abcdefghijklmnopqrstuvwxyz";
string vowels = "aeiouy"; //and sometimes "aeiouy"

template<typename X, typename Y> bool ckmin(X& a, Y b) { return a > b ? a = b, true : false; }
template<typename X, typename Y> bool ckmax(X& a, Y b) { return a < b ? a = b, true : false; }
bool ckcmp(string& a, string b) {
if(b == "") return false;
if(a == "") return a = b, true;
if(sz(b) < sz(a)) return a = b, true;
if(sz(a) < sz(b)) return false;
if(a < b) return false;
return a = b, true;
} 

int dcmp(ld d1, ld d2) { return fabs(d1 - d2) <= EPS ? 0 : d1 > d2 ? 1 : -1; } //Compare Double Numbers
ll gcd(ll x, ll y) { return !y ? x : gcd(y, x%y); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
//convert index from 2D array to 1D array. (Zero-indexed)
int conv_2_1(int r, int c, int nCol) { return (nCol*r) + c + 1; }
//convert index from 1D array to 2D array. (Zero-indexed)
ii conv_1_2(int n, int nCol) {
	int r = n / nCol, c = n % nCol;
	return ii(r, c);
}

void inter(string s) {
	cout << s << endl;
	fflush(stdout);
}


struct mi {
	ll v; explicit operator ll() const { return v; }
	mi() { v = 0; }
	mi(ll _v) {
		v = (-MOD < _v && _v < MOD) ? _v : _v % MOD;
		if (v < 0) v += MOD;
	}
	friend bool operator==(const mi& a, const mi& b) {
		return a.v == b.v;
	}
	friend bool operator!=(const mi& a, const mi& b) {
		return !(a == b);
	}
	friend bool operator<(const mi& a, const mi& b) {
		return a.v < b.v;
	}

	mi& operator+=(const mi& m) {
		if ((v += m.v) >= MOD) v -= MOD;
		return *this;
	}
	mi& operator-=(const mi& m) {
		if ((v -= m.v) < 0) v += MOD;
		return *this;
	}
	mi& operator*=(const mi& m) {
		v = v*m.v%MOD; return *this;
	}
	mi& operator/=(const mi& m) { return (*this) *= inv(m); }
	friend mi pow(mi a, ll p) {
		mi ans = 1; assert(p >= 0);
		for (; p; p /= 2, a *= a) if (p & 1) ans *= a;
		return ans;
	}
	friend mi inv(const mi& a) {
		assert(a.v != 0);
		return pow(a, MOD - 2);
	}

	mi operator-() const { return mi(-v); }
	mi& operator++() { return *this += 1; }
	mi& operator--() { return *this -= 1; }
	mi operator++(int) { mi temp; temp.v = v++; return temp; }
	mi operator--(int) { mi temp; temp.v = v--; return temp; }
	friend mi operator+(mi a, const mi& b) { return a += b; }
	friend mi operator-(mi a, const mi& b) { return a -= b; }
	friend mi operator*(mi a, const mi& b) { return a *= b; }
	friend mi operator/(mi a, const mi& b) { return a /= b; }
	friend ostream& operator<<(ostream& os, const mi& m) {
		os << m.v; return os;
	}
	friend istream& operator >> (istream& is, mi& m) {
		ll x; is >> x;
		m.v = x;
		return is;
	}
};

const int NN = 2e6 + 10;
mi fact[NN];
mi facInv[NN];

void init() {
	fact[0] = facInv[0] = 1;
	for (int i = 1; i < NN; ++i) fact[i] = (fact[i - 1] * 1LL * i), facInv[i] = inv(fact[i]);
}

mi nCr(mi n, mi r) {
	ll a = (ll)n, b = (ll)r;
	if (b > a or a < 0 or b < 0) return 0;
	return fact[a] * facInv[b] * facInv[a - b];
}

int get1(int a) { return (a == 1 ? 2 : 1);} 

int get2(int a, int b) {
if(a>b) swap(a, b);
if(a == 1 and b == 2) return 3;
else if(a == 1 and b == 3) return 2;
return 1;
} 

int main()
{
int t = 1;
//cin>>t;
while(t--) {
int n;
cin>>n;
vvi ans(n, vi(n));
int o = 1, e = 2;
lop(i, n/2){
int cnt = n/2 - i;
lop(j, cnt) ans[i][j] = e, e+= 2;
rloop(j, n, n - cnt) ans [i][j] = e, e+=2;
loop(j, cnt, n-cnt) ans[i][j] = o, o+=2;
}
lop(i, n) ans[n/2][i] = o, o+=2;
rloop(i, n, 1 + n/2){
int cnt = n/2 - (n-i-1);
lop(j, cnt) ans[i][j] = e, e+= 2;
rloop(j, n, n - cnt) ans [i][j] = e, e+=2;
loop(j, cnt, n-cnt) ans[i][j] = o, o+=2;
}
lop(i,n) lop(j, n) cout<<ans[i][j]<<" \n" [j == n-1];
} 

	return 0;
}