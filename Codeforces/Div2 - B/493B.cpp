#include <iostream>
#include <stdio.h>
#include <limits.h>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <complex>
#include <bitset>
#include <string>
#include <stack>
#include <queue>
#include <deque>
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
typedef unsigned int uint;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef vector<int> vi ;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vb> vvb;
typedef vector<vc> vvc;
typedef map<int,int> mii;
typedef map<string,int> msi;
typedef map<int,string> mis;
typedef map<string,string> mss;
typedef map<int,char> mic;
typedef map<char,int> mci;
typedef pair<int, ii> edge;


#define sc(x)  scanf("%d",&x)
#define scl(x) scanf("%lld",&x)
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

const ll OO = (ll)(1e18)+9;
const ll MOD = (ll)(1e9)+7;
const int oo = 2147483647;
const double EPS = 1e-8;
const double PI = acos(-1.0);

/*Sequence X = x_1 ... x_|X| is lexicographically larger than sequence Y = y_1 ... y_|Y| , if either |X| > |Y| and
x_1 = y_1 , ... , x_|X| = y_|Y| , or there is such number r (r < |X|, r < |Y|), that x_1 = y_1 , ... , x_r = y_r and x_r+1 > y_r+1.
We use notation |a| to denote length of sequence a.*/
int lexicographic(vi seq1, vi seq2){
	lop(i,min(sz(seq1),sz(seq2))){
		if(seq1[i] == seq2[i]) continue;
		return (seq1[i] > seq2[i]) ? 1 : -1;
	}
	if(sz(seq1) == sz(seq2)) return 0;
	return (sz(seq1) > sz(seq2)) ? 1 : -1;
}

int main()
{
	//493B
	int n,num,fl;
	ll pts1 = 0, pts2 = 0;
	cin>>n;
	vi A,B;
	lop(i,n){
		cin>>num;
		if(num > 0) fl=1,pts1 +=num, A.PB(num);
		else fl=2,pts2 +=abs(num), B.PB(abs(num));
	}
	if(pts1 > pts2) return puts("first");
	if(pts1 < pts2) return puts("second");
	num = lexicographic(A,B);
	if(num == 1) return puts("first");
	if(num == -1) return puts("second");
	if(fl == 1) return puts("first");
	return puts("second");

	return 0;
}