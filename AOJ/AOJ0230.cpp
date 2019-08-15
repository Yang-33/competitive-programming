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

/* -----  2019/08/15  Problem: AOJ 0230 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0230  ----- */


int main() {

	int N;
	while (cin >> N, N) {
		vector<int> a(N);
		for (int i = 0; i < N; ++i) {
			cin >> a[i];
		}
		vector<int> b(N);
		for (int i = 0; i < N; ++i) {
			cin >> b[i];
		}
		auto make_edge = [&N](const VI& a) {
			vector<int>to(N); {
				FOR(i, 0, N) {
					to[i] = i;
				}
			}
			{ // ladder
				int bottom = -1;
				FOR(i, 0, N) {
					if (a[i] != 1) {
						if (bottom != -1) {
							FOR(k, bottom, i) {
								to[k] = i - 1;
							}
							bottom = -1;
						}
					}
					if (a[i] == 1) {
						if (bottom == -1)bottom = i;
					}
				}
				if (bottom != -1) {
					FOR(k, bottom, N)to[k] = N - 1;
				}
			}
			{ // down
				int wet = -1;
				FORR(i, N - 1, 0 - 1) {
					if (a[i] != 2) {
						if (wet != -1) {
							FORR(k, wet, i)to[k] = i;
							wet = -1;
						}
					}
					if (a[i] == 2) {
						if (wet == -1)wet = i;
					}
				}
			}
			return to;
		};

		using tp = tuple<int, int, int>;
		priority_queue<tp, vector<tp>, greater<tp>>q;
		vector<VI>edge;
		edge.emplace_back(make_edge(b));
		edge.emplace_back(make_edge(a));
		int ans = INF;
		q.emplace(0, edge[0][0], 0);
		q.emplace(0, edge[1][0], 1);
		VVI checked(2, VI(N, 0));

		while (!q.empty()) {
			int d, v, side;
			tie(d, v, side) = q.top(); q.pop();
			DD(de(d, v, side));
			if (v == N - 1) {
				ans = d;
				break;
			}
			if (checked[side][v])continue;
			checked[side][v] = 1;

			FOR(add, 0, 3) {
				int nv = add + v;
				if (nv >= N)continue;
				int nx = edge[!side][nv];
				q.emplace(d + 1, nx, !side);
			}
		}
		if (ans == INF)puts("NA");
		else cout << ans << "\n";

	}

	return 0;
}
