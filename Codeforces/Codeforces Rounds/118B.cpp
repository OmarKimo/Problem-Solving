#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>
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

const ll OO = (4e18) + 9;
const int MOD = (1e9) + 7;
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

int dcmp(ld d1, ld d2) { return fabs(d1 - d2) <= EPS ? 0 : d1 > d2 ? 1 : -1; } //Compare Double Numbers
ll gcd(ll x, ll y) { return !y ? x : gcd(y, x%y); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
//convert index from 2D matrix to 1D array. (Zero-indexed)
int ord(int r, int c, int nCol) { return (nCol*r) + c + 1; }
//convert index from 1D array to 2D matrix . (One-indexed)
ii rord(int n, int nCol) {
	int r = n%nCol, c = n / nCol;
	if (n%nCol == 0) c--, r = nCol;
	return ii(r, c);
}

ll poww(ll num, ll p, ll md = MOD) {
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



int main()
{
#ifndef ONLINE_JUDGE

#else
	//freopen("pyramid.in", "r", stdin);
#endif
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0, sp = 2*n; i < n; i++, sp-=2) {
		lop(j, sp) cout << ' ';
		lop(j, i + 1) {
			cout << j;
			if (j != i)cout << ' ';
		}
		rlop(j, i) {
			if(j == i-1) cout << ' ';
			cout << j;
			if (j) cout << ' ';
		}
		cout << endl;
	}
	lop(i, n + 1) cout << i<<' ';
	rlop(i, n) {
		cout << i;
		if (i) cout << ' ';
	}
	cout << endl;
	for (int i = n-1, sp = 2; i >= 0; i--, sp+=2) {
		lop(j, sp) cout << ' ';
		lop(j, i + 1) {
			cout << j;
			if (j != i)cout << ' ';
		}
		rlop(j, i) {
			if (j == i - 1) cout << ' ';
			cout << j;
			if (j) cout << ' ';
		}
		cout << endl;
	}


	return 0;
}