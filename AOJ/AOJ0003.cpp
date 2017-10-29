#include "bits/stdc++.h"
using namespace std;

using VS = vector<string>;    using LL = long long;
using VI = vector<int>;       using VVI = vector<VI>;
using PII = pair<int, int>;   using PLL = pair<LL, LL>;
using VL = vector<LL>;        using VVL = vector<VL>;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(a) int((a).size())
#define SORT(c) sort(ALL((c)))
#define RSORT(c) sort(RALL((c)))
#define UNIQ(c) (c).erase(unique(ALL((c))), end((c)))
#define FOR(i, s, e) for (int(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (int(i) = (s); (i) > (e); (i)--)
#define debug(x) cerr << #x << ": " << x << endl
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2017/10/03  Problem: AOJ 0003  / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0003&lang=jp ----- */
/* ------問題------

3数の辺からなる三角形が直角三角形かの判定

-----問題ここまで----- */
/* -----解説等-----

ピタゴラス最強

----解説ここまで---- */

LL N;

LL ans = 0LL;

bool check(int a, int b, int c) {
	return ((a*a+b*b==c*c) || (b*b+c*c==a*a) || (c*c+a*a==b*b));
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> N;
	int a, b, c;
	FOR(i, 0, N) {
		cin >> a >> b >> c;
		puts(check(a, b, c) ? "YES" : "NO");
	}
	
	return 0;
}
