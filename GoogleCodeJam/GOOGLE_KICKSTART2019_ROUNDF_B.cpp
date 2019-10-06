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

/* -----  2019/09/30  Problem: GOOGLE_KICKSTART2019_ROUNDF B / Link: https://codingcompetitions.withgoogle.com/kickstart/about  ----- */


// Flattening(11pts, 25pts)


void solve(int testcasenum) {
	LL ans = 0;
	LL N, K; cin >> N >> K;
	vector<LL> a(N);
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
	}

	auto solve_small = [&]() {
		ans = INF;
		// f(vec): get cost from vec
		map<PII, int>range_memo;
		auto f = [&](VL& se) { // se: ids
			int front = se.front();
			int back = se.back();
			if (range_memo.find({ front,back }) != range_memo.end()) {
				return range_memo[{front, back}];
			}
			map<LL, int>ma;
			for (auto it : se) {
				ma[a[it]]++;
			}
			int highcnt = 0;
			for (auto it : ma) {
				highcnt = max(highcnt, it.second);
			}
			return range_memo[{front, back}] = SZ(se) - highcnt;
		};
		VL range_vec;
		FOR(state, 0, 1 << N) {
			if (state & 1)continue;

			int popcnt = __builtin_popcount(state);
			if (popcnt > K)continue;
			LL costsum = 0;
			FOR(i, 0, N) {
				if (state & 1 << i) {
					costsum += f(range_vec);
					range_vec.clear();
					if (ans < costsum)break;
				}
				range_vec.push_back(i);
			}
			costsum += f(range_vec);
			range_vec.clear();
			ans = min(ans, costsum);
		}

	};

	auto solve_large = [&]() {
		VVI cost(N, VI(N));
		FOR(i, 0, N) {
			VI cnt(1001, 0);
			int mxval = 0;
			FOR(j, i, N) {
				++cnt[a[j]];
				mxval = max(mxval, cnt[a[j]]);
				cost[i][j] = j - i + 1 - mxval;
			}
		}

		VVI dp(N + 1, VI(N + 1, INF));
		dp[0][0] = 0;// k,[-x,i)
		FOR(k, 0, N) {
			FOR(i, 1, N + 1) {
				FOR(j, i, N + 1) {
					dp[k + 1][j] = min(dp[k + 1][j], dp[k][i-1] + cost[i - 1][j - 1]);
				}
			}
		}
		K++;
		K = min(K, N);
		//FOR(i, 0, N + 1) {
		//	cout << dp[K][i] << ", ";
		//}
		ans = dp[K][N];
	};

	//solve_small();

	solve_large();

	cout << "Case #" << testcasenum << ": ";
	cout << ans << "\n";
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int T; cin >> T;
	FOR(t, 0, T) {
		solve(t + 1);
	}

	return 0;
}

/*
[1 input]:
4
8 2
300 100 300 300 200 100 800 500
5 3
100 100 100 100 3
7 3
10 20 40 10 10 30 30
10 2
30 30 60 60 90 90 60 60 30 30
[1 output]:
Case #1: 3
Case #2: 0
Case #3: 1
Case #4: 2

*/
