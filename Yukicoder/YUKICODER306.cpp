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

/* -----  2018/09/30  Problem: yukicoder 306  / Link: http://yukicoder.me/problems/no/306  ----- */
/* ------問題------

xy平面の第一象限に点A (xa,ya)、点B (xb,yb)があります。ここでいう第一象限とはx>0かつy>0であるような領域のことです。
|AP|+|PB|が最小になるように、y軸上に点P (0,yp)を置いてください。|AP|、|PB|はそれぞれの点間のユークリッド距離を指します。

-----問題ここまで----- */
/* -----解説等-----

y軸対称なA'をつくればO(1)

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	double x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
	double ans = (y2-y1)/(x1+x2)*x1+y1;


	cout << fixed << setprecision(10) << ans << "\n";

	return 0;
}
