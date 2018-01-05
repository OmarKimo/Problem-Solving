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
const double PI=acos(-1.0);

//Geometry
typedef complex<double> point;
#define X real()
#define Y imag()
#define angle(a)  (atan2((a).imag(), (a).real()))
#define vec(a,b)  ((b)-(a))
#define length(a) (hypot((a).imag(), (a).real()))
#define norm(a) (a)/length(a)
#define dProd(a,b) ( (conj(a)*(b)).real() ) //Dot Product = |a|*|b|Cos(T)
#define cProd(a,b) ( (conj(a)*(b)).imag() ) //Cross Product = |a|*|b|Sin(T)
#define isSame(p1,p2) (dProd(vec(p1,p2), vec(p1,p2)) < EPS)
#define lengthsqr(a)   dProd(a,a)
#define rotateO(p,ang) ( (p)*exp(point(0,ang)) )
#define rotateA(p,ang,about) ( rotateO(vec(about,p), ang)+about )
#define reflectO(v,m) ( conj((v)/(m))*(m) ) //reflect vector v around m
#define reflectA(p,p0,p1) ( conj(vec(p0,p)/vec(p0,p1))*vec(p0,p1) + p0 ) //Reflect point p around p0p1
// line(-oo,oo), Ray(p,oo), LineSegment(p1,p2)
#define isCollinear(a,b,c) ( cProd(vec(a,b),vec(a,c)) < EPS ) // if 3 points on a line, they are called collinear points
#define isPointOnRay(a,b,c) ( (length(vec(a,c)) < EPS) || isSame(norm(vec(a,b)), norm(vec(a,c))) ) // is c on ray a-b
#define isPointOnSegment(a,b,c) ( isPointOnRay(a,b,c) && isPointOnRay(b,a,c)  )
#define distToLine(p0,p1,p2) ( fabs(cProd(vec(p0,p1), vec(p0,p2))/length(vec(p1,p0))) ) // distance from p2
//distance from point p2 to segment p0-p1
double distToSegment( point p0, point p1, point p2 ) {
	double d1, d2;
	point v1 = p1-p0, v2 = p2-p0;
	if( (d1 = dProd(v1, v2) ) <= 0)	return length(p2-p0);
	if( (d2 = dProd(v1, v1) ) <= d1)	return length(p2-p1);
	double t = d1/d2;
	return length(p2 - (p0 + v1*t) );
}

//enum dir { u, r, d, l };
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

//enum diR { d, r, u, l , dr, ur, dl, ul };
int dX[] = { 1, 0, -1, 0, 1, -1, 1, -1 };
int dY[] = { 0, 1, 0, -1, 1, 1, -1, -1 };

char letters[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

//Compare Double Numbers
int dcmp(ld d1,ld d2){ return fabs(d1-d2)<=EPS?0:d1>d2?1:-1; }
ll gcd (ll x, ll y){ return !y ? x : gcd(y, x%y); }
ll lcm (ll a, ll b) { return a * (b / gcd(a, b)); }
int ord(int r,int c,int nCol) { return (nCol*r) + c + 1; } //convert index from 2D matrix to 1D array. (Zero-indexed)



int main()
{
	//p378
	int n;
	cin>>n;
	point p1,p2,p3,p4;
	cout<<"INTERSECTING LINES OUTPUT\n";
	while(n--){
		int fx1,fy1,c1,fx2,fy2,c2;
		double x,y;
		cin>>x>>y;
		point p1(x,y);
		cin>>x>>y;
		point p2(x,y);
		cin>>x>>y;
		point p3(x,y);
		cin>>x>>y;
		point p4(x,y);

		fx1 = p1.Y - p2.Y;
		fy1 = p2.X - p1.X;
		c1 = cProd(p1,p2);

		fx2 = p3.Y - p4.Y;
		fy2 = p4.X - p3.X;
		c2 = cProd(p3,p4);
		if(fx1 < 0) fx1*=-1,fy1*=-1,c1*=-1;
		if(fx2 < 0) fx2*=-1,fy2*=-1,c2*=-1;
		int lcmX = (fx1 && fx2) ? lcm(fx1,fx2) : 0, lcmY = (fy1 && fy2) ? lcm(abs(fy1), abs(fy2)) : 0;
		if(!lcmX && !lcmY) {
			if(!fx1) y = double(-c1)/fy1;
			if(!fx2) y = double(-c2)/fy2;
			if(!fy1) x = double(-c1)/fx1;
			if(!fy2) x = double(-c2)/fx2;
			if(!x) x = 0;
			if(!y) y = 0;
			printf("Point %0.2f %0.2f\n", x,y);
		} 
		else if(!lcmX){
			if(!fx1 && fx2){
				y = double(-c1)/fy1;
				x = double(-c2 - y*fy2)/fx2;
				if(!x) x = 0;
				if(!y) y = 0;
				printf("Point %0.2f %0.2f\n", x,y);
			}
			else if(!fx2 && fx1){
				y = double(-c2)/fy2;
				x = double(-c1 - y*fy1)/fx1;
				if(!x) x = 0;
				if(!y) y = 0;
				printf("Point %0.2f %0.2f\n", x,y);
			}
			else{
				if(!dcmp(double(-c1)/fy1, double(-c2)/fy2)) cout<<"LINE\n";
				else cout<<"NONE\n";
			}
		}
		else{
			if(fy1 < 0) fx1*=-1,fy1*=-1,c1*=-1;
			if(fy2 < 0) fx2*=-1,fy2*=-1,c2*=-1;
			int lcmY = (fy1 && fy2) ? lcm(fy1,fy2) : 0;
			if(!lcmY){
				if(!fy1 && fy2){
					x = double(-c1)/fx1;
					y = double(-c2 - x*fx2)/fy2;
					if(!x) x = 0;
				if(!y) y = 0;
					printf("Point %0.2f %0.2f\n", x,y);
					continue;
				}
				else if(!fy2 && fy1){
					x = double(-c2)/fx2;
					y = double(-c1 - x*fx1)/fy1;
					if(!x) x = 0;
					if(!y) y = 0;
					printf("Point %0.2f %0.2f\n", x,y);
					continue;
				}
				else{
					if(!dcmp(double(-c1)/fx1, double(-c2)/fx2)) cout<<"LINE\n";
					else cout<<"NONE\n";
					continue;
				}
			}

			fx1 *= (lcmY / fy1), c1 *= (lcmY / fy1), fy1 = lcmY;
			fx2 *= (lcmY / fy2), c2 *= (lcmY / fy2), fy2 = lcmY;
			if(!(fx1-fx2) && !(fy1-fy2) && !(c1-c2)) { cout<<"LINE\n"; continue; }
			else if(!(fx1-fx2) && !(fy1-fy2)) { cout<<"NONE\n"; continue; }
			else if(!(fx1-fx2)) { y = double(c2-c1)/(fy1-fy2), x = double(-c1 - y*fy1)/fx1; }
			else{ x = double(c2-c1)/(fx1-fx2), y = double(-c1 - x*fx1)/fy1; }

			if(!x) x = 0;
			if(!y) y = 0;
			printf("Point %0.2f %0.2f\n", x,y);
		}
	}
	cout<<"END OF OUTPUT\n";

	return 0;
}