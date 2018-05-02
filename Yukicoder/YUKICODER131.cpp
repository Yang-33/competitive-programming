#include <bits/stdc++.h>
using namespace std;

using VS = vector<string>;    using LL = long long;
using VI = vector<int>;       using VVI = vector<VI>;
using PII = pair<int, int>;   using PLL = pair<LL, LL>;
using VL = vector<LL>;        using VVL = vector<VL>;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
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

/* -----  2018/05/02  Problem: yukicoder 131  / Link: http://yukicoder.me/problems/no/131  ----- */
/* ------問題------

点(x1,y1),点(x2,y2)間のマンハッタン距離は|x1−x2|+|y1−y2|で表される。
(0,0),(x,0),(0,y),(x,y)の4点に囲まれる長方形の範囲内に、 (0,0)からのマンハッタン距離がdの格子点がいくつあるか求めよ。

-----問題ここまで----- */
/* -----解説等-----

理想的なときは、d+1個あるのであとは場合分けで取り除く。

----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL x, y, d; cin >> x >> y >> d;
	ans = max(0LL, d + 1 - (x < d ? d - x : 0) - (y < d ? d - y : 0));
	cout << ans << "\n";

	return 0;
}
