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

/* -----  2019/04/06  Problem: ABC 033 D / Link: http://abc033.contest.atcoder.jp/tasks/abc033_d  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; cin >> N;
	vector<double> x(N), y(N);
	for (int i = 0; i < N; ++i) {
		cin >> x[i] >> y[i];
	}

	LL tl90, t90, tg90;
	tl90 = N * (N - 1)*(N - 2) / 6;
	t90 = tg90 = 0;
	const double eps = 1e-10;
	FOR(i, 0, N) {
		vector<double>v;
		FOR(j, 0, N) {
			if (i == j)continue;
			double thi = atan2(y[j] - y[i], x[j] - x[i]);
			v.push_back(thi);
			v.push_back(thi + 2 * PI);
		}
		SORT(v);
		FOR(j, 0, SZ(v) / 2) {
			// 90
			LL nt90 = lower_bound(ALL(v), v[j] + PI / 2 + eps) - lower_bound(ALL(v), v[j] + PI / 2 - eps);
			LL ntg90 = lower_bound(ALL(v), v[j] + PI) - lower_bound(ALL(v), v[j] + PI / 2 + eps);

			DD(de(nt90, ntg90));
			t90 += nt90;
			tg90 += ntg90;

		}
	}
	tl90 -= (t90 + tg90);
	cout << tl90 << " " << t90 << " " << tg90 << endl;

	return 0;
}
