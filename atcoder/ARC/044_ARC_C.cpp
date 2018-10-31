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
//#pragma GCC optimize ("-O3") 
#ifdef YANG33
#include "mydebug.hpp"
#else
#define DD(x) 
#endif
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/10/30  Problem: ARC 044 C / Link: http://arc044.contest.atcoder.jp/tasks/arc044_c  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

XY独立になるところに気づけなかった。
気づいてしまえばDPできそう。
DPするとO(TW)で厳しい。
しかし更新点がINFで塗りつぶされるとするならば、その周りに伝播させるだけで良い。
これいいなあ

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL W, H, Q; cin >> W >> H >> Q;
	const int tsz = 1e5 + 10;
	vector<VVI> query(2, VVI(tsz));
	FOR(i, 0, Q) {
		int t, d, x; cin >> t >> d >> x;
		x--;
		query[d][t].push_back(x);
	}
	// 幅Wについてクエリを処理する
	auto solve = [&tsz](int W, VVI& query) {
		VL dp(W, 0);
		FOR(t, 0, tsz) {
			if (SZ(query[t]) == W)return LINF;
			SORT(query[t]);
			for (int pos : query[t]) {
				if (pos < W - 1) {
					dp[pos+1] = min(dp[pos+1], dp[pos] + 1);
				}
			}
			reverse(ALL(query[t]));
			for (int pos : query[t]) {
				if (pos > 0) {
					dp[pos-1] = min(dp[pos-1], dp[pos] + 1);
				}
			}

			for (int pos : query[t]) {
				dp[pos] = LINF;
			}
			DD(de(t); De(query[t], dp));
		}
		return *min_element(ALL(dp));
	};

	LL ansa = solve(W, query[0]);
	LL ansb = solve(H, query[1]);
	DD(de(ansa, ansb));
	LL ans = ansa + ansb;
	if (ans >= LINF) {
		ans = -1;
	}
	cout << ans << "\n";

	return 0;
}
