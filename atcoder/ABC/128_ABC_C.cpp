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

/* -----  2019/05/26  Problem: ABC 128 C / Link: http://abc128.contest.atcoder.jp/tasks/abc128_c  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, M; cin >> N >> M;

	VVI s(M);
	FOR(i, 0, M) {
		int k; cin >> k;
		FOR(j, 0, k) {
			int a; cin >> a;
			a--;
			s[i].push_back(a);
		}
	}
	VI p(M);
	FOR(i, 0, M) {
		cin >> p[i];
	}
	LL ans = 0;
	FOR(state, 0, 1 << N) {
		int cnt = 0;
		FOR(i, 0, M) {
			int c = 0;
			for (auto it : s[i]) {
				if (state & 1 << it)c++;
			}
			if (c % 2 == p[i])cnt++;
		}
		if (cnt == M)ans++;
	}


	cout << (ans) << "\n";

	return 0;
}
