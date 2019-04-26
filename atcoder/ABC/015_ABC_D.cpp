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

/* -----  2019/04/11  Problem: ABC 015 D / Link: http://abc015.contest.atcoder.jp/tasks/abc015_d  ----- */

LL dp[52][52][10004];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	auto chmax = [](LL& a, const LL b) {
		a = max(a, b);
	};

	// 幅Wまでk個まで選択可能な最大重み
	int W, N, K; cin >> W >> N >> K;
	vector<LL> a(N), b(N);
	for (int i = 0; i < N; ++i) {
		cin >> a[i] >> b[i];
	}
	FOR(i, 0, N) {
		FORR(k, N - 1, 0 - 1) {
			FOR(w, 0, W + 1) {
				if (w + a[i] <= W)
					chmax(dp[i + 1][k + 1][w + a[i]], dp[i][k][w] + b[i]);
				chmax(dp[i + 1][k][w], dp[i][k][w]);
			}
		}
	}
	LL ans = 0;
	FOR(i, 0, K + 1) {
		FOR(w, 0, W + 1) {
			chmax(ans, dp[N][i][w]);
		}
	}

	cout << ans << "\n";

	return 0;
}
