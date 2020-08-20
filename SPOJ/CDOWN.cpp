#include <iostream>
#include <stdio.h>
#include <limits.h>
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

//#define sc(x)  scanf("%d",&x)
//#define scl(x) scanf("%lld",&x)
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
#define ord(i) (int)(8*(i.f-1)+i.s)


//const ll OO = 9223372036854775807i64;
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

struct classcomp {
	bool operator() (const pair<int,string>& lhs, const pair<int,string>& rhs) const
	{
		if(lhs.f==rhs.f) return lhs.s<rhs.s;
		return lhs.f>rhs.f;}
};

set<pair<int,string>, classcomp> ans;
vvi graph(1010);
msi mp; mis pm;
int d;

int BFS(int src) {
	int no=0;
	vi len(sz(graph), oo);
	queue<ii> q;
	q.push(mP(src,0)), len[src] = 0;

	int cur, dep=0;

	while(!q.empty() && dep<=d) {
		ii p = q.front();	 q.pop();
		cur = p.first, dep = p.second;

		lop(i, sz(graph[cur])) { if (len[graph[cur][i]] == oo){
			q.push(mP(graph[cur][i], dep+1)), len[graph[cur][i]] = dep+1; if(len[graph[cur][i]]==d) no++; }
		}
	}
	return no;
}

int main()
{
	//
	int t,n,count=1;
	cin>>t;

	while(t--){
		clr(mp), clr(pm), clr(graph), rsz(graph)(1010), clr(ans);
		string st,nd; int cnt,num=1;
		cin>>n>>d;

		//Building tree

		lop(i,n){
			cin>>st>>cnt;
			if(!mp[st]) pm[num]=st,mp[st]=num++;
			lop(j,cnt){
				cin>>nd;
				if(!mp[nd]) pm[num]=nd,mp[nd]=num++;
				graph[mp[st]].push_back(mp[nd]);
			}
		}

		loop(i,1,num) { int no = BFS(i); if(no) ans.insert(mP(no, pm[i]));}

		printf("Tree %d:\n",count++);
		int i=0,val=-1; auto it = ans.begin();
		for(; it!=ans.end() && i<3; i++,it++ ){
			cout<<(*it).second << ' '<<(*it).first<<endl;
			val = (*it).first;
		}
		if(it != ans.end() && val!=-1 && (*it).first == val) {
			for(; it!=ans.end() && (*it).first == val; it++) cout<<(*it).second << ' '<<(*it).first<<endl;
		}
	}
	





	return 0;
}