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

/* -----  2018/11/22  Problem: ARC 016 C / Link: http://arc016.contest.atcoder.jp/tasks/arc016_c  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----



----解説ここまで---- */



int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, M; cin >> N >> M;
	VI CN(M), cost(M);
	VVI who(M), p(M);
	FOR(i, 0, M) {
		cin >> CN[i] >> cost[i];
		who[i] = VI(CN[i]);
		p[i] = VI(CN[i]);
		FOR(j, 0, CN[i]) {
			cin >> who[i][j] >> p[i][j];
			who[i][j]--;
		}
	}
	vector<double>dp(1 << N, LINF);
	dp[0] = 0;
	// getする際のアレをして良いが、
	// 遷移がループするタイプの確率dpなので sE = p1*sE+p2*sP + costを変形して
	// sE = (p2*sP+cost)/(1-p1) とする(多分)
	FOR(state, 0, 1 << N) {
		FOR(i, 0, M) {
			double sumE = 0.0;
			double p1 = 0.0;
			FOR(j, 0, SZ(who[i])) {
				int personId = who[i][j];
				double p2 = p[i][j] / 100.0;
				if (state & 1 << personId) {
					sumE += p2 * dp[state ^ (1 << personId)];
				}
				else {
					p1 += p2;
				}
			}
			if (p1 > 0.999) continue;

			dp[state] = min(dp[state], (sumE + cost[i]) / (1.0 - p1));

		}
	}

	cout << fixed << setprecision(10) << dp[(1 << N) - 1] << endl;

	return 0;
}
