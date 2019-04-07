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

/* -----  2019/04/07  Problem: ABC 030 C / Link: http://abc030.contest.atcoder.jp/tasks/abc030_c  ----- */

// [L,R] 
int intervalScheduling(vector<PLL>& sc, bool duplicate = 0) {
	sort(sc.begin(), sc.end(), [](const PLL& L, const PLL & R) {
		if (L.second == R.second) {
			return L.first < R.first;
		}
		else {
			return L.second < R.second;
		}
	});

	int ret = 0;
	int Rpos = 0;
	FOR(i, 0, SZ(sc)) {
		if (Rpos < sc[i].first + duplicate) {
			ret++;
			Rpos = sc[i].second;
		}
	}

	return ret;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, M; cin >> N >> M;
	LL X, Y; cin >> X >> Y;
	vector<LL> a(N);
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
	}
	vector<LL> b(M);
	for (int i = 0; i < M; ++i) {
		cin >> b[i];
	}
	vector<PLL>interval;
	FOR(i, 0, N) {
		int bidx = lower_bound(ALL(b), a[i] + X) - b.begin();
		if (bidx == M)continue;
		LL at = b[bidx] + Y;
		interval.push_back(PLL(a[i], at));
	}
	int ans = intervalScheduling(interval, 1);


	cout << (ans) << "\n";

	return 0;
}
