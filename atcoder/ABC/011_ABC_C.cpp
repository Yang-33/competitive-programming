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

/* -----  2019/04/11  Problem: ABC 011 C / Link: http://abc011.contest.atcoder.jp/tasks/abc011_c  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; cin >> N;
	VI ng(301, 0);
	FOR(i, 0, 3) {
		int a; cin >> a;
		ng[a] = 1;
	}
	auto chmax = [](LL& a, const LL b) {
		a = max(a, b);
	};

	VL dp(N + 1, -1);
	dp[N] = (ng[N] ? 0 : 100);
	FORR(n, N, 0) {
		FOR(sub, 1, 3 + 1) {
			int nx = n - sub;
			if (nx >= 0 && !ng[nx]) {
				chmax(dp[nx], dp[n] - 1);
			}
		}
	}
	auto print_yesno = [](LL yes, int mode = 0) {
		if (mode == 0) {
			cout << (yes ? "yes" : "no") << endl;
		}
		else if (mode == 1) {
			cout << (yes ? "Yes" : "No") << endl;
		}
		else if (mode == 2) {
			cout << (yes ? "YES" : "NO") << endl;
		}
		else assert(0);
	};
	DD(de(dp[0]))
		print_yesno(dp[0] >= 0, 2);
	return 0;
}
