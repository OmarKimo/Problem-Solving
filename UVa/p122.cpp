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

pair<int,string> filter(string in){
	int num; char c; string str;
	stringstream ss(in);
	ss>>c;
	ss>>num;
	ss>>c;
	ss>>str;
	str.erase(str.end()-1,str.end());
	return mP(num,str);
}

int ext=0;
bool my(const pair<int,string> &p1, const pair<int,string> &p2){
	if(sz(p1.second) == sz(p2.second)){
		lop(i,sz(p1.second)){
			if(p1.second[i] != p2.second[i]) return p1.second[i] == 'L';
		}
		ext = 1;
		return true;
	}
	return sz(p1.second) < sz(p2.second);
}

int main()
{
	//p122
	string in; char c;
	while(cin>>in && in != ""){
		vector<pair<int,string>> input; ext = 0;
		input.PB(filter(in));
		cin>>in;
		while(in != "()"){
			input.PB(filter(in));
			cin>>in;
		}
		sort(all(input),my);
		if(ext) { cout<<"not complete\n"; continue; }
		lop(i,sz(input)){
			int flag = 0, sz = sz(input[i].s);
			if(!sz) continue;
			sz--;
			string str = input[i].s;
			str.erase(str.end()-1,str.end());
			rlop(j,i){
				if(sz(input[j].s) < sz) break;
				if(input[j].s == str) { flag=1; break; }
			}
			if(!flag) { ext = 1; break; }
		}
		if(ext) cout<<"not complete\n";
		else { lop(i,sz(input)-1) cout<<input[i].f<<' '; cout<<input[sz(input)-1].f<<endl; }
	}




	return 0;
}