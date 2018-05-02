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

/* -----  2018/05/02  Problem: yukicoder 135  / Link: http://yukicoder.me/problems/no/135  ----- */
/* ------問題------

数直線上の整数座標上にN個の点がある。
その中から同じ座標ではない2点を選んで、その2点の距離を求める。
距離は、i番目の点の座標をXi、j番目の点の座標をXjとすると 、
絶対値|Xi−Xj|とする。

この時、最小の距離となる2点を選ぶとして、選んだ2点間の最小距離を求めてください。
条件にあう2点を選べなかったら0を出力してください。

-----問題ここまで----- */
/* -----解説等-----

やっていく

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;
	VI x(N);
	FOR(i, 0, N) {
		cin >> x[i];
	}
	SORT(x);
	UNIQ(x);
	int ans = INF;
	if (SZ(x) < 2)ans = 0;
	else {
		FOR(i, 0, SZ(x) - 1) {
			ans = min(ans, x[i + 1] - x[i]);
		}
	}
	cout << ans << "\n";

	return 0;
}
