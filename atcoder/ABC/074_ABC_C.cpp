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

/* -----  2019/03/19  Problem: ABC 074 C / Link: http://abc074.contest.atcoder.jp/tasks/abc074_c  ----- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL A, B, C, D, E, F; cin >> A >> B >> C >> D >> E >> F;
	auto  f = [](int a, int b) {
		VI dp(3001, 0);
		dp[0] = 1;
		FOR(i, a, 3001) {
			if (dp[i - a])dp[i] = 1;
		}
		FOR(i, b, 3001) {
			if (dp[i - b])dp[i] = 1;
		}
		return dp;
	};
	auto usew = f(100 * A, 100 * B);
	auto uses = f(C, D);
	// どちらもokな集合のとき、check
	LL answ = INF;
	LL anss = 0;
	FOR(w, 0, 3001) {
		FOR(s, 0, 3001) {
			if (usew[w] && uses[s]) {
				if (w + s <= F) {
					// Eまで溶ける
					if (s*(100 + E) <= E * (w + s)) {
						if (anss*(w + s) <= s * (answ + anss)) {
							answ = w;
							anss = s;
						}
					}
				}
			}
		}
	}
	if (answ == INF)answ = 0;
	cout << answ + anss << " " << anss << endl;

	return 0;
}
