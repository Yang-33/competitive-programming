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

/* -----  2019/03/19  Problem: ABC 067 D / Link: http://abc067.contest.atcoder.jp/tasks/abc067_d  ----- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; cin >> N;
	VVI G(N);
	FOR(i, 0, N - 1) {
		int a, b; cin >> a >> b;
		a--, b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	VL dist0(N, INF), distN(N, INF);
	function<void(int, int, int, const VVI&, VL&) > dfs = [&](int v, int p, int d, const VVI& G, VL &dist) {
		dist[v] = d;
		for (auto nx : G[v]) {
			if (nx == p)continue;
			dfs(nx, v, d + 1, G, dist);
		}
	};
	dfs(0, -1, 0, G, dist0);
	dfs(N - 1, -1, 0, G, distN);
	LL ans = 0;
	FOR(i, 0, N) {
		if (dist0[i] <= distN[i])ans++;
		else ans--;
	}
	cout << (ans > 0 ? "Fennec" : "Snuke") << endl;

	return 0;
}
