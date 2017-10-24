#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
#define FORR(i,s,e) for(ll (i)=(s);(i)>(e);(i)--)
#define debug(x) cout<<#x<<": "<<x<<endl
#define mp make_pair
#define pb push_back
const ll MOD = 1000000007;
const int INF = 1e9;
const ll LINF = 1e16;
const double PI = acos(-1.0);
int dx[8] = { 0,0,1,-1,1,1,-1,-1 };
int dy[8] = { 1,-1,0,0,1,-1,1,-1 };

/* -----  2017/06/17  Problem: CodeForces419 A div2 / Link: http://codeforces.com/contest/816/problem/A  ----- */
/* ------問題------

現在時刻が与えられる。
回文的な時刻になるのは何分後か。

-----問題ここまで----- */
/* -----解説等-----

全探索してもよいので上手に実装する。

----解説ここまで---- */

ll N;
int h, s;

ll ans = 0LL;
void f() {

	if(s==60){
		s = 0;
		h++;
	}
	if (h == 24)h = 0;
}

bool g() {
	string hs = to_string(h);
	hs = "0" + hs;
	string ss = to_string(s);
	ss = "0" + ss;
	int hsize = hs.size();
	int ssize = ss.size();
	if (hs[hsize-2]==ss[ssize-1]&& hs[hsize - 1] == ss[ssize - 2])return 1;
	else return 0;
}


int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
   
	scanf("%d:%d", &h, &s);
	
	int cnt = 0;
	for (;;) {
		
		if (g())break;
		cnt++;
		s++;
		f();

	}
	ans = cnt;
	cout<<ans<<endl;

	return 0;
}