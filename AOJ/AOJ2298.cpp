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

/* -----  2019/05/26  Problem: AOJ 2298 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/2298  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int n, k, t, u, v, l;
	cin >> n >> k >> t >> u >> v >> l;
	int i, j;
	set<int> s;
	for (i = 0; i < n; i++) {
		cin >> j;
		s.insert(j);
	}
	// 距離ベースでシュミレーションする
	// 人参1つでTVメートルのコストが変化する
	int p = 0, h = 0, left = 0;
	double ans = 0;
	for (i = 1; i <= l; i++) {
		if (left == 0) {
			if (h > 0) {
				left = v * t - 1; h--;
				ans += 1.0 / v;
			}
			else ans += 1.0 / u;
		}
		else {
			ans += 1.0 / v;
			left--;
		}
		if (s.find(i) != s.end())
			if (h < k) h++;
			else left = v * t;
	}
	printf("%.9lf\n", ans);

	return 0;
}
