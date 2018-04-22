#include <bits/stdc++.h>
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

/* -----  2018/04/19  Problem: yukicoder 098  / Link: http://yukicoder.me/problems/no/098  ----- */
/* ------問題------

A君は円を描こうとしています。
ここで円を描く際の条件があります。

・描く円の中心はXY平面上の原点にあります。
・描く円の直径はかならず整数cmでなければなりません。
・指定された整数座標の点P(Xp,Yp)がかならず円の内側にあること。

内側とは円の線とは重ならない内側のことです。
描ける円の最小の直径を求めよ。

-----問題ここまで----- */
/* -----解説等-----

点を通る直径について、切り上げなり、切り捨てなりすれば良い。

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int xp, yp; cin >> xp >> yp;
	ans = ceil(2 * sqrt(xp*xp + yp*yp)+1e-6);
	cout << ans << "\n";

	return 0;
}
