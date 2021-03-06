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

/* -----  2019/02/28  Problem: ABC 104 C / Link: http://abc104.contest.atcoder.jp/tasks/abc104_c  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----



----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, G; cin >> N >> G;
	vector<LL> x(N), y(N);
	for (int i = 0; i < N; ++i) {
		cin >> x[i] >> y[i];
	}

	ans = LINF;

	FOR(state, 0, 1 << N) {
		LL points = 0;
		LL ret = 0;
		FOR(i, 0, N) {
			if (state & 1 << i) {
				ret += x[i];
				points += x[i] * (100)*(i + 1) + y[i];
			}
		}
		FORR(i, N - 1, 0 - 1) {
			if (points >= G)break;
			if (state & 1 << i)continue;
			FOR(k, 1, x[i] + 1) {
				ret++;
				points += 100 * (i + 1);
				if (x[i] == k)points += y[i];
				if (points >= G)break;
			}
		}


		ans = min(ans, ret);
	}



	cout << ans << "\n";

	return 0;
}
