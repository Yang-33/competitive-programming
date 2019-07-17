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

/* -----  2019/07/14  Problem: HUPC2019day1 G / Link: __CONTEST_URL__  ----- */

inline int in() { int in; scanf("%d", &in); return in; }
inline void outint(int out, bool endl = 1) { printf("%d%c", out, " \n"[endl]); }

// O(nW)
void solve_light_merge(int N, int W, VI value, VI a, VI b, VI c) {
	vector<vector<PII>>G(N); {
		FOR(i, 0, N - 1) {
			G[a[i]].emplace_back(b[i], c[i]);
			G[b[i]].emplace_back(a[i], c[i]);
		}
	}
	LL ans = 0;

	function<VL(int, int, VL)> dfs = [&](int v, int p, VL dp) {
		VL renketu = dp;
		for (auto it : G[v]) {
			int nx = it.first; int cost = it.second;
			if (nx == p)continue;
			VL chi = dfs(nx, v, renketu);
			FORR(w, W, 0 - 1) {
				if (w + cost <= W) {
					renketu[w + cost] = max(renketu[w + cost], chi[w]);
				}
			}
		}
		FORR(w, W, 0 - 1) {
			renketu[w] += value[v];
		}
		if (dp[W] == 0) { // only first heavy path!
			FOR(i, 0, W + 1) {
				ans = max(ans, renketu[i]);
			}
		}
		return renketu;
	};

	LL ans2 = 0;
	function<VL(int, int, VL)> dfs2 = [&](int v, int p, VL dp) {
		VL renketu = dp;
		for (auto it : G[v]) {
			int nx = it.first; int cost = it.second;
			if (nx == p)continue;
			VL chi = dfs2(nx, v, renketu);
			FORR(w, W, 0 - 1) {
				if (w + cost <= W) {
					renketu[w + cost] = max(renketu[w + cost], chi[w]);
				}
			}
		}
		FORR(w, W, 0 - 1) {
			renketu[w] += value[v];
		}
		if (dp[W] == 0) {
			FOR(i, 0, W + 1) {
				ans2 = max(ans2, renketu[i]);
			}
		}
		return renketu;
	};

	VL x(W + 1, 0);
	dfs(0, -1, x);
	dfs2(0, -1, x);
	if (ans != ans2) {
		DD(De(N, W, a, b, c, value, ans, ans2));
		exit(0);
	}
	//cout << ans << "\n";
	//cout << ans2 << "\n";
}

void solve1() {
	const int N = in(), W = in();
	vector<int> value(N); {
		for (int i = 0; i < N; ++i) {
			value[i] = in();
		}
	}
	vector<vector<PII>>G(N); {
		FOR(i, 0, N - 1) {
			int a = in() - 1, b = in() - 1, c = in();
			G[a].emplace_back(b, c);
			G[b].emplace_back(a, c);
		}
	}
	VI sub(N,1);
	function<void(int, int)> dfs_sz = [&](int v, int p) {
		for (auto &u : G[v]) {
			if (u.first == p) continue;
			dfs_sz(u.first, v);
			sub[v] += sub[u.first];
			if (sub[u.first] > sub[G[v][0].first]) swap(u, G[v][0]);
		}
	};
	dfs_sz(0, -1);
	using P = pair<VL, VL>;
	VL INIT(W + 1, -LINF); INIT[0] = 0;
	function<P(int, int, VL&)> RecDP = [&](int v, int p, VL& X) {
		VL Xs = X;
		VL Xf = INIT;
		const bool EMPTY = X == INIT;
		int cnt = 0;
		for (auto it : G[v]) {
			int nx = it.first, cost = it.second;
			if (nx == p)continue;
			P Y = RecDP(nx, v, Xs);
			if (cnt&&EMPTY) {
				P Z = RecDP(nx, v, INIT);
				FOR(w, 0, W + 1)Xf[w] = max({ Xf[w], Z.first[w], Z.second[w] });
			}
			else if (cnt == 0) {
				FOR(w, 0, W + 1)Xf[w] = max({ Xf[w], Y.first[w], Y.second[w] });
			}
			FOR(w, 0, W - cost + 1) {
				Xs[w + cost] = max(Xs[w + cost], Y.first[w]);
			}
			cnt++;
		}

		FOR(w, 0, W + 1)Xs[w] += value[v];
		return P(Xs, Xf);
	};

	auto res = RecDP(0, -1, INIT);
	LL ans = max(*max_element(ALL(res.first)), *max_element(ALL(res.second)));
	cout << ans << "\n";
}


int main() {
	//solve_light_merge();
	solve1();
	// solve2();
	return 0;
}
