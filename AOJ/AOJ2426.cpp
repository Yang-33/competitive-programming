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

/* -----  2018/06/14  Problem: AOJ 2426 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2426  ----- */
/* ------問題------

太郎君はある広場にお宝を探しにやってきました。
この広場にはたくさんのお宝が埋められていますが、太郎君は最新の機械を持っているので、
どこにお宝が埋まっているかをすべて知っています。
広場はとても広いので太郎君は領域を決めてお宝を探すことにしましたが、
お宝はたくさんあるためどのお宝がその領域の中にあるかすぐにわかりません。
そこで太郎君はその領域の中にあるお宝の数を数えることにしました。

-----問題ここまで----- */
/* -----解説等-----

2Dimos + 座標圧縮すれば良い
クエリも読みたくなるが多いのでやめる。
これは解決可能で、半開区間でやれば良い

----解説ここまで---- */

int idx(int i, VI &c) {
	return lower_bound(ALL(c), i) - c.begin();
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	VI xs(N), ys(N);
	FOR(i, 0, N) {
		cin >> xs[i] >> ys[i];
	}

	VI x = xs; VI y = ys;
	SORT(x), UNIQ(x);
	SORT(y), UNIQ(y);
	VVI sum(5010, VI(5010, 0));

	FOR(i, 0, N) {
		int compx = idx(xs[i], x);
		int compy = idx(ys[i], y);
		sum[compy + 1][compx + 1]++;
	}
	FOR(i, 0, SZ(y) + 1) {
		FOR(j, 0, SZ(x) + 1) {
			sum[i + 1][j + 1] += sum[i][j + 1] + sum[i + 1][j] - sum[i][j];
		}
	}
	FOR(i, 0, M) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		x1 = idx(x1, x);
		y1 = idx(y1, y);
		x2 = idx(x2 + 1, x);
		y2 = idx(y2 + 1, y);
		LL ret = sum[y2][x2] - sum[y2][x1] - sum[y1][x2] + sum[y1][x1];
		cout << ret << endl;
	}

	return 0;
}