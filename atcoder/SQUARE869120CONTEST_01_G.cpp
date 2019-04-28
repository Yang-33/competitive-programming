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
const int INF = 1e9;                          const LL LINF = 1e14;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);

/* -----  2019/04/28  Problem: square869120Contest_01 G / Link: __CONTEST_URL__  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, M; cin >> N >> M;
	vector<vector<PLL>> dp(1 << N, vector<PLL>(N, PLL(LINF, 0)));
	using tp = tuple < LL, LL, LL>;
	vector<vector<tp>>edge(N);
	FOR(i, 0, M) {
		LL s, t, d, time; cin >> s >> t >> d >> time;
		s--, t--;
		edge[s].push_back(tp(t, d, time));
		edge[t].push_back(tp(s, d, time));
	}
	dp[0][0] = PLL(0, 1);
	// (所要時間,総数)
	FOR(state, 0, 1 << N) {
		FOR(s, 0, N) {
			if (dp[state][s] == PLL(LINF, 0))continue;
			if (state & 1 << s || (state == 0 && s == 0)) {
				for (auto it : edge[s]) {
					LL t, d, time;
					tie(t, d, time) = it;
					if (state & 1 << t)continue;
					if (dp[state][s].first + d > time)continue;

					LL T = dp[state][s].first;
					int nxstate = state | (1 << t);
					LL nxT = dp[nxstate][t].first;
					if (nxT > T + d) {
						dp[nxstate][t].first = dp[state][s].first + d;
						dp[nxstate][t].second = dp[state][s].second;
					}
					else if (nxT == T + d) {
						dp[nxstate][t].second += dp[state][s].second;
					}

				}
			}
		}
	}
	PLL ans = (dp[(1 << N) - 1][0]);
	if (ans.second == 0) {
		cout << "IMPOSSIBLE" << endl;
	}
	else {
		cout << ans.first << " " << ans.second << endl;
	}


	return 0;
}
