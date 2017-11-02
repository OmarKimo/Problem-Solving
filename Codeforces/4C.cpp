typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

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

#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
#define rsz(v) v.resize
#define clr(v) v.clear()
#define vi vector<int>
#define ii pair<int, int>
#define vii vector<ii>
#define vvi vector<vi>
#define vb vector<bool>
#define vvb vector<vb>
#define vc vector<char>
#define vvc vector<vc>
#define vs vector<string>
#define lop(i,n) for(int i=0; i<n; i++)
#define rlop(i,n) for(int i=n-1; i>=0; i--)
#define loop(i,start,n) for(int i=start; i<n; i++)
#define rloop(i,start,n) for(int i=n-1; i>=end; i--)
#define PB push_back
#define pb pop_back
#define f first
#define s second

const ll OO = 1e8;

void PrintVector(vi v){
if(!sz(v)) { cout<<endl; return; }
lop(i, sz(v)-1) cout<<v[i]<<' ';
cout <<v [sz (v)-1]<<endl;
}

void sor(vii& v){
int size=sz (v),min,tmpx,tmpy;
for (int i=0; i <size; i++){
min=i;
for (int j=i+1; j <size; j++){
if (v [j].f <v [min].f)  min=j;
else if (v [j].f == v [min].f && v [j].s >= v [min].s) min=j;
}
tmpx=v [i].f, tmpy=v [i].s;
v [i].f = v [min].f, v [i].s = v [min].s;
v [min].f=tmpx, v [min].s=tmpy;
}
}


int main ()
{
int n;
cin>>n;
map <string,int> m;
set <string> s;
string x;
lop(i,n){
cin>>x;
int size=sz(s);
s.insert(x);
if(size!=sz(s)) {m[x]=1; cout<<"OK\n";}
else { m[x]++; cout<<x<<m[x]-1<<endl;}
}


return 0;
}