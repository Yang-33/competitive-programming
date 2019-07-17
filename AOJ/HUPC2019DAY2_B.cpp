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

/* -----  2019/07/15  Problem: HUPC2019day2 A / Link: __CONTEST_URL__  ----- */


LL solve(vector<PII> in) {
	const int K = 2;
	VL a(1 << K, -LINF);
	int N = SZ(in);
	FOR(i, 0, N) {
		VL xs(K);
		xs[0] = in[i].first;
		xs[1] = in[i].second;

		FOR(s, 0, 1 << K) {
			LL  y = 0;
			FOR(j, 0, K) {
				if (s & 1 << j) {
					y += xs[j];
				}
				else {
					y -= xs[j];
				}
			}
			a[s] = max(a[s], y);
		}
	}
	LL ans = -LINF;
	for (unsigned s = 0; s < (1 << K); s++) {
		unsigned t = ~s & ((1 << K) - 1);
		//cerr << s << "," << t << endl;
		ans = max(ans, a[s] + a[t]);
	}
	return ans;
}


LL solve2(vector<PII> in) {
	const int K = 2;
	VL amax(1 << K, -LINF);
	VL amin(1 << K, LINF);
	int N = SZ(in);
	FOR(i, 0, N) {
		VL xs(K);
		xs[0] = in[i].first;
		xs[1] = in[i].second;

		FOR(s, 0, 1 << K) {
			LL  y = 0;
			FOR(j, 0, K) {
				if (s & 1 << j) {
					y += xs[j];
				}
				else {
					y -= xs[j];
				}
			}
			amax[s] = max(amax[s], y);
			amin[s] = min(amin[s], y);
		}
	}
	LL ans = -LINF;
	FOR(s, 0, 1 << K) {
		ans = max(ans, amax[s] - amin[s]);
	}
	return ans;
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL H, W; cin >> H >> W;
	vector<string> s(H);
	for (int i = 0; i < H; ++i) {
		cin >> s[i];
	}

	LL ans = 0LL;
	vector<PII>p;
	FOR(i, 0, H) {
		FOR(j, 0, W) {
			if (s[i][j] == 'B') {
				p.emplace_back(i, j);
			}
		}
	}
	cout << solve2(p) << endl;
	return 0;
	for (auto it : p) {
		for (auto it2 : p) {
			LL cost = abs(it.first - it2.first) + abs(it.second - it2.second);
			ans = max(ans, cost);
		}
	}



	cout << (ans) << "\n";

	return 0;
}
