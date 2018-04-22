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

/* -----  2018/04/20  Problem: yukicoder 091  / Link: http://yukicoder.me/problems/no/091  ----- */
/* ------問題------

赤、緑、青の3種類の石を1つずつ使って1つのアクセサリーができる。
石は同じ色の石2個を別の色の石1個に交換することができる。
最初に持っている赤、緑、青の石から最大何個のアクセサリーを作ることができるか？

-----問題ここまで----- */
/* -----解説等-----

f(x):=さらにx個増やせるか？
として二分探索すればよい。

----解説ここまで---- */

LL N;

LL ans = 0LL;




int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	VI a(3);
	FOR(i, 0, 3)cin >> a[i];
	int ret = *min_element(ALL(a));
	FOR(i, 0, 3) {
		a[i] -= ret;
	}
	ans = ret;
	auto f = [=](int x) {// 追加でx個
		int lack = 0;
		FOR(i, 0, 3) {
			if (a[i] > x)lack -= (a[i] - x) / 2;
			else lack += x - a[i];
		}

		return lack <= 0;
	};
	int l = 0; int r = INF;
	while (r - l > 1) {
		int mid = (l + r) / 2;
		if (f(mid)) {
			l = mid;
		}
		else r = mid;
	}
	ans += l;
	cout << ans << "\n";

	return 0;
}