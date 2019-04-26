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

/* -----  2019/04/11  Problem: ABC 012 D / Link: http://abc012.contest.atcoder.jp/tasks/abc012_d  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);


	int N, M; cin >> N >> M;
	VVL dist(N, VL(N, LINF));
	auto chmin = [](LL &a, const LL b) {
		a = min(a, b);
	};
	auto chmax = [](LL& a, const LL b) {
		a = max(a, b);
	};

	FOR(i, 0, M) {
		LL a, b, c; cin >> a >> b >> c;
		a--, b--;
		chmin(dist[a][b], c);
		chmin(dist[b][a], c);
	}
	FOR(i, 0, N) {
		dist[i][i] = 0;
	}
	FOR(k, 0, N)FOR(i, 0, N)FOR(j, 0, N)chmin(dist[i][j], dist[i][k] + dist[k][j]);

	LL ans = LINF;
	FOR(i, 0, N) {
		LL ret = 0;
		FOR(j, 0, N) {
			if (i == j)continue;
			chmax(ret, dist[i][j]);
		}
		chmin(ans, ret);
	}

	cout << ans << "\n";

	return 0;
}
