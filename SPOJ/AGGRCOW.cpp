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
#define f first
#define s second
#define ord0(s) (int)(s-'0')
#define orda(s) (int)(s-'a')
#define ordA(s) (int)(s-'A')


const ll OO = 1e8;
const double EPS = 1e-5;
const double PI=acos(-1.0);

vi v; ll c,n;

bool fun(ll x){
	ll pos=v[0],cnt=1;
	for(int i=1; i<n; i++){
		if((v[i]-pos) >= x) { pos=v[i]; if(++cnt == c) return true; }
	}
	return false;
}

int main(){

ll t,mid,l,r;
	cin>>t;
	while(t--){
		cin>>n>>c;
		clr(v),rsz(v)(n);
		lop(i,n) cin>>v[i];
		sort(all(v));
		l=1,r=v[n-1]-v[0]+1;
		while(l<r){
			mid=l+(r-l+1)/2;
			if(fun(mid)) l=mid;
			else r=mid-1;
		}
		if(fun(mid))cout<<mid<<endl;
		else cout<<mid-1<<endl;
	}

return 0;
}