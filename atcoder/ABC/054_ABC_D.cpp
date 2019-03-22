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

/* -----  2019/03/22  Problem: ABC 054 D / Link: http://abc054.contest.atcoder.jp/tasks/abc054_d  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, ta, tb; cin >> N >> ta >> tb;
	vector<LL>a(N), b(N), c(N);
	for (int i = 0; i < N; ++i) {
		cin >> a[i] >> b[i] >> c[i];
	}
	auto chmin = [](LL &a, const LL b) {
		a = min(a, b);
	};
	vector<VVL>dp(N + 1, VVL(421, VL(421, LINF)));
	dp[0][0][0] = 0;
	FOR(i, 0, N) {
		FOR(ap, 0, 401) {
			FOR(bp, 0, 401) {
				chmin(dp[i + 1][ap][bp], dp[i][ap][bp]);
				chmin(dp[i + 1][ap + a[i]][bp + b[i]], dp[i][ap][bp] + c[i]);
			}
		}
	}
	LL ans = LINF;
	FOR(i, 1, 401) {
		int aa = ta * i, bb = tb * i;
		if (aa <= 400 && bb <= 400)
			chmin(ans, dp[N][aa][bb]);
	}

	cout << (ans==LINF?-1:ans) << "\n";

	return 0;
}
