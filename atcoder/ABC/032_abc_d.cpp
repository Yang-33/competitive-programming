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

/* -----  2019/04/06  Problem: ABC 032 D / Link: http://abc032.contest.atcoder.jp/tasks/abc032_d  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, W; cin >> N >> W;
	vector<LL> v(N), w(N);
	for (int i = 0; i < N; ++i) {
		cin >> v[i] >> w[i];
	}
	auto chmin = [](LL &a, const LL b) {
		a = min(a, b);
	};
	auto chmax = [](LL& a, const LL b) {
		a = max(a, b);
	};

	LL ans = 0;
	if (N <= 30) {
		int n1 = N / 2;
		vector<PLL>se;
		FOR(s, 0, 1 << n1) {
			LL vsum = 0, wsum = 0;
			FOR(i, 0, n1) {
				if (s & 1 << i) {
					vsum += v[i];
					wsum += w[i];
				}
			}
			se.push_back(PLL(wsum, vsum));
		}
		SORT(se);
		// vの昇順でないものは削除
		vector<PLL>new_se; new_se.push_back(se.front());
		for (auto it : se) {
			if (new_se.back().second < it.second) {
				new_se.push_back(it);
			}
		}
		int n2 = N - n1;
		FOR(s, 0, 1 << n2) {
			LL vsum = 0, wsum = 0;
			FOR(j, 0, n2) {
				if (s & 1 << j) {
					int i = j + n1;
					vsum += v[i];
					wsum += w[i];
				}
			}
			// W-wsum以下の集合のうち，最大値をもつvsum'を検索
			{
				auto it = lower_bound(ALL(new_se), PLL(W - wsum + 1, -LINF));
				if (it != new_se.begin()) {
					it--;
					ans = max(ans, vsum + it->second);
				}
			}

		}
	}
	else if (*max_element(ALL(w)) <= 1000) {
		// vmaxのdp
		const int dpsz = accumulate(ALL(w), 0LL);
		VL dp(dpsz + 1, -1);
		dp[0] = 0;
		FOR(i, 0, N) {
			VL nx = dp;
			FOR(ww, 0, dpsz - w[i] + 1) {
				if (dp[ww] != -1) {
					chmax(nx[ww + w[i]], dp[ww] + v[i]);
				}
			}
			nx.swap(dp);
		}
		LL ret = 0;
		FOR(i, 0, min((LL)dpsz, W) + 1) {
			chmax(ret, dp[i]);
		}

		ans = ret;
	}
	else
	{ // max v <= 1000
		// 価値がv*nのうち，最小の重さdp
		const int dpsz = accumulate(ALL(v), 0LL);
		VL dp(dpsz + 1, LINF);
		dp[0] = 0;
		FOR(i, 0, N) {
			VL nx = dp;
			FOR(vv, 0, dpsz - v[i] + 1) {
				if (dp[vv] == LINF)continue;
				chmin(nx[vv + v[i]], dp[vv] + w[i]);
			}
			nx.swap(dp);
		}
		LL ret = 0;
		FOR(i, 0, dpsz + 1) {
			if (dp[i] <= W) {
				ret = i;
			}
		}

		ans = ret;
	}


	cout << (ans) << "\n";

	return 0;
}
