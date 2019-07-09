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

/* -----  2019/04/05  Problem: ABC 040 C / Link: http://abc040.contest.atcoder.jp/tasks/abc040_c  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; cin >> N;
	vector<LL> a(N);
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
	}
	auto chmin = [](LL &a, const LL b) {
		a = min(a, b);
	};
	auto chmax = [](LL& a, const LL b) {
		a = max(a, b);
	};

	VL dp(N, LINF);
	dp[0] = 0;
	FOR(i, 0, N) {
		FOR(j, 1, 2 + 1) {
			int nx = i + j;
			if (nx < N) {
				chmin(dp[nx], dp[i] + abs(a[i] - a[nx]));
			}
		}
	}
	LL ans = dp[N - 1];
	cout << (ans) << "\n";

	return 0;
}
