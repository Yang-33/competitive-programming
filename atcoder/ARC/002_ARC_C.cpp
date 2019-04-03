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

/* -----  2019/04/03  Problem: ARC 002 C / Link: http://arc002.contest.atcoder.jp/tasks/arc002_c  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; cin >> N;
	string s; cin >> s;

	LL ans = LINF;
	// 同じものもOK
	string base = "ABXY";
	VS vs;
	FOR(i, 0, 4) {
		FOR(j, 0, 4) {
			string s = string(1, base[i]) + string(1, base[j]);
			vs.push_back(s);
		}
	}
	auto chmin = [](LL &a, const LL b) {
		a = min(a, b);
	};
	for (auto L : vs) {
		for (auto R : vs) {
			VL dp(N + 1, LINF);
			dp[0] = 0;
			FOR(i, 0, N) {
				for (auto it : { L,R,string(1,'A'),string(1,'B'),string(1,'X'),string(1,'Y') }) {
					if (i + SZ(it) > SZ(s))continue;
					bool ok = 1;
					FOR(k, 0, SZ(it)) {
						ok &= s[i + k] == it[k];
					}
					if (ok) {
						chmin(dp[i + SZ(it)], dp[i] + 1);
					}
				}
			}

			ans = min(ans, dp[N]);
		}
	}

	cout << (ans) << "\n";

	return 0;
}
