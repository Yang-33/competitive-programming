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

/* -----  2017/10/06  Problem: CodeForces439 B div2 / Link: http://codeforces.com/contest/869/problem/B  ----- */
/* ------問題------

B!/A!の一の位は？(A,B≦10^18)

-----問題ここまで----- */
/* -----解説等-----

2,5の倍数がはいると10の倍数になる。
したがってBの手前10個を全探索

----解説ここまで---- */

LL a,b;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> a>>b;
	ans = 1;
	if (b - a >= 10)ans = 0;
	else {
		LL t = b - a;
		LL small = (a+1) % 10;
		FOR(i, 0, t) {
			ans *= ((small + i) % 10);
		}
	}
	cout << ans%10 << "\n";

	return 0;
}