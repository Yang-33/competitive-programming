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

/* -----  2019/05/26  Problem: ABC 128 D / Link: http://abc128.contest.atcoder.jp/tasks/abc128_d  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, K; cin >> N >> K;
	vector<LL> a(N);
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
	}

	LL ans = 0LL;
	FOR(k, 1, K + 1) {
		// k回とる
		int modosu = K - k; // 戻せる回数// 全部見る

		FOR(L, 0, k + 1) {
			int R = k - L;
			// k = L + R
			// 交わるときに注意
			VI use(N, 0);
			priority_queue<LL, VL, greater<LL>>minq;
			LL subsum = 0;
			FOR(i, 0, min(L, N)) {
				use[i] = 1;
				minq.push(a[i]);
				subsum += a[i];
			}
			FOR(revi, 0, min(R, N)) {
				int i = N - 1 - revi;
				if (use[i])continue;
				minq.push(a[i]);
				subsum += a[i];
			}

			// 戻す
			LL sum = 0;
			ans = max(ans, subsum);
			FOR(i, 0, modosu) {
				if (SZ(minq)) {
					LL v = minq.top(); minq.pop();
					subsum -= v;
					ans = max(ans, subsum);
				}
			}

			ans = max(ans, sum);
		}
	}


	cout << (ans) << "\n";

	return 0;
}
