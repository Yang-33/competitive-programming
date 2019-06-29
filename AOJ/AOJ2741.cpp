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

/* -----  2019/06/03  Problem: AOJ 2741 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/2741  ----- */



LL dp[51][51][51][51][2][2];
int main() {
	FOR(i, 0, 51)FOR(j, 0, 51)FOR(k, 0, 51)FOR(l, 0, 51)FOR(a, 0, 2) {
		dp[i][j][k][l][0][a] = -LINF;
		dp[i][j][k][l][1][a] = LINF;
	}

	int N, M; cin >> N >> M;
	vector<int> a(N);
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
	}
	vector<int> b(M);
	for (int i = 0; i < M; ++i) {
		cin >> b[i];
	}

	function<LL(int, int, int, int, bool, bool, LL, LL)>
		f = [&](
			int As, int At, int Bs, int Bt,
			bool player, bool passcnt, LL Asum, LL Bsum) {
		LL& ret = dp[As][At][Bs][Bt][player][passcnt];
		if (player == 0 && ret != -LINF)return ret;
		if (player == 1 && ret != LINF)return ret;
		if (player == 0) { // to max
			if (At < N) {
				if (a[At] > 0) {
					ret = max(ret, f(As, At + 1, Bs, Bt, !player, 0, Asum + a[At], Bsum));
				}
				else { // -1
					ret = max(ret, f(As, At + 1, Bs, Bt, !player, 0, Asum, 0));
				}
			}
			if (As == At && Bs == Bt) {
				if (passcnt == 0) {
					ret = max(ret, f(As, At, Bs, Bt, !player, 1, 0, 0));
				}
				else {
					ret = max(ret, 0LL);
				}
			}
			else {
				ret = max(ret, f(At, At, Bt, Bt, !player, 0, 0, 0) + Asum - Bsum);
			}

		}
		else { // to min
			if (Bt < M) {
				if (b[Bt] > 0) {
					ret = min(ret, f(As, At, Bs, Bt+1, !player, 0, Asum, Bsum + b[Bt]));
				}
				else { // -1
					ret = min(ret, f(As, At, Bs, Bt+1, !player, 0, 0, Bsum));
				}
			}
			if (As == At && Bs == Bt) {
				if (passcnt == 0) {
					ret = min(ret, f(As, At, Bs, Bt, !player, 1, 0, 0));
				}
				else {
					ret = min(ret, 0LL);
				}
			}
			else {
				ret = min(ret, f(At, At, Bt, Bt, !player, 0, 0, 0) + Asum - Bsum);
			}
		}
		return ret;
	};
	LL ans = f(0, 0, 0, 0, 0, 0, 0, 0);
	cout << ans << endl;

	return 0;
}
