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

/* -----  2019/06/29  Problem: ABC 132 E / Link: http://abc132.contest.atcoder.jp/tasks/abc132_e  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, M; cin >> N >> M;
	VVI G(N);
	FOR(i, 0, M) {
		int a, b; cin >> a >> b;
		a--, b--;
		G[a].push_back(b);
	}
	using tp = tuple<LL, LL, LL>;
	priority_queue<tp, vector<tp>, greater<tp>>pq;
	VVL dist(N, VL(3, LINF));
	auto IFPUSH = [&](LL d, int mod, int nx) {
		if (dist[nx][mod] > d) {
			dist[nx][mod] = d;
			pq.push(tp(d, mod, nx));
		}
	};
	int S, T; cin >> S >> T;
	S--, T--;
	IFPUSH(0, 0, S);

	while (!pq.empty()) {
		LL di, m, v;
		tie(di, m, v) = pq.top(); pq.pop();
		if (dist[v][m] < di)continue;
		for (auto nx : G[v]) {
			LL nxd = di + (m % 3 == 0);
			LL nxm = (m + 1) % 3;
			IFPUSH(nxd, nxm, nx);
		}
	}
	LL ans = dist[T][0];
	if (ans == LINF)ans = -1;
	cout << ans << "\n";
	return 0;
}
