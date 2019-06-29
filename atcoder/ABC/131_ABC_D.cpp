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

/* -----  2019/06/22  Problem: ABC 131 D / Link: http://abc131.contest.atcoder.jp/tasks/abc131_d  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; cin >> N;
	vector<PLL>seg(N);
	FOR(i, 0, N) {
		LL a, b; cin >> a >> b;
		seg[i] = PLL(a, b);
	}

	sort(ALL(seg), [](const PLL& a, const PLL &b) {
		if (a.second == b.second) {
			return a.first > b.first;
		}
		else {
			return a.second < b.second;
		}
	});
	bool ok = 1;
	LL nowt = 0;
	FOR(i, 0, N) {
		if (seg[i].first + nowt > seg[i].second)ok=0;
		else {
			nowt += seg[i].first;
		}
	}

	cout << (ok ? "Yes" : "No") << endl;

	return 0;
}
