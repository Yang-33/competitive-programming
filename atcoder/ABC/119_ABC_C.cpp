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

/* -----  2019/02/24  Problem: ABC 119 C / Link: http://abc119.contest.atcoder.jp/tasks/abc119_c  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

よくわからないのでまず4つの集合に切り分ける．(A|B|C|未使用)
それぞれについて合体させてから差分を伸ばしたり縮めたりする感じにする．
O(4^N)で解ける．

----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	LL N; cin >> N;
	VL target(3);
	FOR(i, 0, 3) {
		cin >> target[i];
	}
	VL a(N);
	FOR(i, 0, N) {
		cin >> a[i];
	}
	LL S = 1;
	FOR(i, 0, N)S *= 4;

	auto f = [](const VL& a, LL A) {
		if (SZ(a)) {
			return (SZ(a) - 1) * 10 + abs(A - accumulate(ALL(a), 0LL));
		}
		else {
			return LINF;
		}
	};
	ans = LINF;
	FOR(s, 0, S) {
		LL ss = s;
		VVL se(4);
		FOR(i, 0, N) {
			se[ss % 4].push_back(a[i]);
			ss /= 4;
		}
		LL ret = 0;
		FOR(i, 0, 3) {
			ret += f(se[i], target[i]);
		}
		if (SZ(se[3]) != N)
			ans = min(ans, ret);
	}
	cout << ans << "\n";

	return 0;
}
