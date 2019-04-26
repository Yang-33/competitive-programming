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

/* -----  2019/04/17  Problem: ABC 008 D / Link: http://abc008.contest.atcoder.jp/tasks/abc008_d  ----- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL W, H; cin >> W >> H;
	int N; cin >> N;
	vector<int> x(N), y(N);
	for (int i = 0; i < N; ++i) {
		cin >> x[i] >> y[i];
		x[i]--, y[i]--;
	}

	auto isin = [&](int idx, int sy, int sx, int ty, int tx) {
		return sy <= y[idx] && y[idx] < ty && sx <= x[idx] && x[idx] < tx;
	};

	using tp = tuple<int, int, int, int>;
	map<tp, LL>memo;
	function<LL(int, int, int, int)>
		f = [&](int sy, int sx, int ty, int tx) {
		// memo
		if (memo.find(tp(sy, sx, ty, tx)) != memo.end()) {
			return memo[tp(sy, sx, ty, tx)];
		}
		LL ret = 0;
		FOR(i, 0, N) {
			if (!isin(i, sy, sx, ty, tx))continue;
			ret = max(ret,
				ty - sy + tx - sx - 1
				+ f(sy, sx, y[i], x[i])
				+ f(y[i] + 1, sx, ty, x[i])
				+ f(sy, x[i] + 1, y[i], tx)
				+ f(y[i] + 1, x[i] + 1, ty, tx));
		}
		return memo[tp(sy, sx, ty, tx)] = ret;
	};

	LL ans = f(0, 0, H, W);


	cout << ans << "\n";

	return 0;
}
