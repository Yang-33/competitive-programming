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

/* -----  2019/08/04  Problem: AOJ 0200 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0200  ----- */

int main() {

	int M, N;
	while (cin >> M >> N, M) {
		VVI dist_c(N, VI(N, INF));
		VVI dist_t(N, VI(N, INF));
		FOR(i, 0, N)dist_c[i][i] = 0;
		FOR(i, 0, N)dist_t[i][i] = 0;
		FOR(_, 0, M) {
			int a, b, c, t; cin >> a >> b >> c >> t;
			a--, b--;
			dist_c[b][a] = dist_c[a][b] = min(dist_c[a][b], c);
			dist_t[b][a] = dist_t[a][b] = min(dist_t[a][b], t);
		}
		FOR(k, 0, N)FOR(i, 0, N)FOR(j, 0, N)dist_c[i][j] = min(dist_c[i][j], dist_c[i][k] + dist_c[k][j]);
		FOR(k, 0, N)FOR(i, 0, N)FOR(j, 0, N)dist_t[i][j] = min(dist_t[i][j], dist_t[i][k] + dist_t[k][j]);
		int Q; cin >> Q;
		FOR(_, 0, Q) {
			int a, b, c; cin >> a >> b >> c;
			a--, b--;
			if (c == 0) {
				cout << dist_c[a][b] << "\n";
			}
			else {
				cout << dist_t[a][b] << "\n";
			}
		}
	}
	return 0;
}
