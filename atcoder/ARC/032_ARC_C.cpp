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

/* -----  2019/07/10  Problem: ABC 0R2 C / Link: http://arc032.contest.atcoder.jp/tasks/arc032_c  ----- */

inline int in() { int in; scanf("%d", &in); return in; }
inline void outint(int out, bool endl = 1) { printf("%d%c", out, " \n"[endl]); }


int main() {
	int N = in();
	vector<int> L(N), R(N);
	int mx = 1000001;
	vector<vector<PII>>lineLto(mx);
	for (int i = 0; i < N; ++i) {
		L[i] = in(), R[i] = in();
		lineLto[L[i]].emplace_back(R[i], i);
	}
	auto maxcnt_minid = [&](PII& a, const PII &b, int id) {
		if (a.first < b.first + 1) {
			a.first = b.first + 1; a.second = id;
		}
		else if (a.first == b.first + 1) {
			a.second = min(a.second, id);
		}
	};

	// [L,R)
	vector<PII>dp(mx + 1, PII(0, INF));
	FORR(L, mx - 1, 0 - 1) {
		dp[L] = dp[L + 1];
		for (auto it : lineLto[L]) {
			int R = it.first;
			int id = it.second;
			maxcnt_minid(dp[L], dp[R], id);
		}
	}
	vector<int>ans; {
		int now = 0;
		while (1) {
			int id = dp[now].second;
			if (id == INF)break;
			ans.emplace_back(id);
			now = R[id];
		}
	}

	outint(SZ(ans), 1);
	FOR(i, 0, SZ(ans)) {
		outint(ans[i] + 1, i + 1 == SZ(ans));
	}


	return 0;
}
