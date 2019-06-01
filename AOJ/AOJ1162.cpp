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

/* -----  2019/05/30  Problem: AOJ 1162 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/1162  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);


	LL N, E;
	while (cin >> N >> E, N) {

		int S, T; cin >> S >> T;
		S--, T--;
		using tp = tuple<int, int, int>;
		vector<vector<tp>>G(N);
		FOR(i, 0, E) {
			int a, b, c, d; cin >> a >> b >> c >> d;
			a--, b--;
			G[a].push_back(tp(b, c, d));
			G[b].push_back(tp(a, c, d));
		}
		using VD = vector<double>;
		using VVD = vector<VD>;
		vector<VVD>d(N, VVD(31, VD(N, INF)));
		using TP = tuple<double, int, int, int>;
		priority_queue<TP, vector<TP>, greater<TP>>q;
		auto IFPUSH = [&](int nx, int speed, int v, double c) {
			if (d[nx][speed][v] > c) {
				d[nx][speed][v] = c;
				q.push(TP(c, nx, speed, v));
			}
		};

		IFPUSH(S, 0, S, 0);
		while (!q.empty()) {
			double di;
			int v, speed, pre;
			tie(di, v, speed, pre) = q.top(); q.pop();
			if (d[v][speed][pre] < di)continue;
			FOR(addspeed, -1, 1 + 1) {
				int nspeed = speed + addspeed;
				if (nspeed < 1)continue;
				for (auto nxn : G[v]) {
					int nx, edge, seigen;
					tie(nx, edge, seigen) = nxn;
					if (seigen < nspeed)continue;
					if (pre == nx)continue;
					double cost = (1.0*edge) / nspeed;
					IFPUSH(nx, nspeed, v, cost + di);
				}
			}
		}
		double ans = INF;
		FOR(i, 0, N) {
			ans = min(ans, d[T][1][i]);
		}
		if (ans > INF - 1) {
			cout << "unreachable" << endl;
		}
		else {
			cout << fixed << setprecision(10) << ans << endl;
		}
	}

	return 0;
}
