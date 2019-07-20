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

/* -----  2019/07/20  Problem: ABC 134 D / Link: http://abc134.contest.atcoder.jp/tasks/abc134_d  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;
	VL a(N);
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
	}


	auto  divn = [](LL n) {
		vector<LL> res;
		for (LL i = 1; i*i <= n; i++) {
			if (n%i == 0) {
				res.push_back(i);
				if (n / i != i)res.push_back(n / i);
			}
		}
		SORT(res);
		return res;
	};

	VI ans;
	VI cnt(N + 1);
	for (int x = N; x >= 1; x--) {
		LL n = x;
		int idx = x - 1;
		if (cnt[n] % 2 == a[idx])continue;

		auto divs = divn(n);
		ans.emplace_back(n);
		for (auto d : divs) {
			cnt[d]++;
		}
	}
	bool corner = 1;
	FOR(i, 0, N) {
		corner &= a[i] == 0;
	}
	if (SZ(ans) < 1 && !corner) {
		cout << -1 << "\n";
		return 0;
	}

	cout << SZ(ans) << "\n";
	FOR(i, 0, SZ(ans)) {
		cout << ans[i] << " \n"[i + 1 == SZ(ans)];
	}


	return 0;
}

