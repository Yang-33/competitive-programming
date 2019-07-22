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

/* -----  2019/07/23  Problem: AOJ 0155 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0155  ----- */


int main() {
	int N;
	while (cin >> N, N) {
		VI b(N), x(N), y(N);
		VI revb(N + 1);
		FOR(i, 0, N) {
			cin >> b[i] >> x[i] >> y[i];
			revb[b[i]] = i;
		}
		vector<vector<LL>>dist(N, vector<LL>(N, LINF)); {
			FOR(i, 0, N)dist[i][i] = 0;
			auto d = [&](int i, int j) {
				int xx = x[i] - x[j];
				int yy = y[i] - y[j];
				return sqrt(xx*xx + yy * yy);
			};
			FOR(i, 0, N) {
				FOR(j, 0, N) {
					if (i == j)continue;
					if (d(i, j) <= 50)dist[i][j] = d(i, j);
				}
			}
		}
		VVI next_to(N, VI(N)); {
			FOR(i, 0, N)FOR(j, 0, N)next_to[i][j] = j;
		}
		FOR(k, 0, N) {
			FOR(i, 0, N) {
				if (dist[i][k] == LINF)continue;
				FOR(j, 0, N) {
					if (dist[k][j] == LINF)continue;
					if (dist[i][j] > dist[i][k] + dist[k][j]) {
						dist[i][j] = dist[i][k] + dist[k][j];
						next_to[i][j] = next_to[i][k];
					}
					else if (k != i && dist[i][k] + dist[k][j] == dist[i][j]) {
						next_to[i][j] = min(next_to[i][j], next_to[i][k]);
					}
				}
			}
		}

		int Q; cin >> Q;
		FOR(_, 0, Q) {
			int s, t; cin >> s >> t;
			s = revb[s], t = revb[t];
			if (dist[s][t] == LINF)cout << "NA" << "\n";
			else
			{ // restore path
				VI path;
				for (int current = s; current != t; current = next_to[current][t]) {
					path.push_back(current);
				}
				path.push_back(t);
				FOR(i, 0, SZ(path)) {
					cout << b[path[i]] << " \n"[i + 1 == SZ(path)];
				}
			}
		}

	}
}