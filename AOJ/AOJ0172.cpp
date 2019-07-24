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

/* -----  2019/07/23  Problem: AOJ 0172 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0172  ----- */


int main() {
	int N, M;
	while (cin >> N >> M, N || M) {
		VVI G(N); {
			FOR(i, 0, M) {
				int a, b; cin >> a >> b;
				a--, b--;
				G[a].push_back(b);
				G[b].push_back(a);
			}
		}
		int init_state = 0; {
			FOR(i, 0, N) {
				int l; cin >> l;
				init_state |= (l) << i;
			}
		}
		VVI sw(N); {
			FOR(i, 0, N) {
				int k; cin >> k;
				FOR(_, 0, k) {
					int x; cin >> x;
					x--;
					sw[i].push_back(x);
				}
				SORT(sw[i]);
			}
		}
		using tp = tuple<int, int, int>;
		queue<tp>q;
		VVI dist(1 << N, VI(N, INF));
		vector<vector<PII>> rev(1 << N, vector<PII>(N));

		dist[init_state][0] = 0;
		q.emplace(0, init_state, 0);
		while (!q.empty()) {
			int d, st, v;
			tie(d, st, v) = q.front(); q.pop();
			{ // 電気
				for (int room : sw[v]) {
					if (room == v) continue;
					int nstate = (st & 1 << room ? (st&~(1 << room)) : (st | (1 << room)));
					if (dist[nstate][v] > d + 1) {
						dist[nstate][v] = d + 1;
						rev[nstate][v] = { st,v };
						q.emplace(d + 1, nstate, v);
					}
				}
			}
			{ // 移動
				for (int nv : G[v]) {
					// 移動可能か?
					if (st & 1 << nv) {
						if (dist[st][nv] > d + 1) {
							dist[st][nv] = d + 1;
							rev[st][nv] = { st,v };
							q.emplace(d + 1, st, nv);
						}
					}
				}
			}
		}
		if (dist[1 << (N - 1)][N - 1] != INF) {
			// OK !!
			cout << "You can go home in " << dist[1 << (N - 1)][N - 1] << " steps.\n";
			DD(de("home step"));
			VS ans; {
				auto maskid = [](int mask) {
					return __builtin_ctz(mask);
				};
				int st = 1 << (N - 1);
				int v = N - 1;
				while (st != init_state || v != 0) {

					int pst = rev[st][v].first;
					int pv = rev[st][v].second;
					if (pst != st) { // swtch
						// on
						string fm = "Switch ";
						fm += (st > pst ? "on" : "off");
						fm += " room ";
						fm += to_string(maskid(st^pst) + 1);
						// off
						ans.emplace_back(fm);
					}
					else { // move
						string fm = "Move to room " + to_string(v + 1);
						ans.emplace_back(fm);
					}
					st = pst;
					v = pv;
				}
			}

			reverse(ALL(ans));
			for (auto it : ans) {
				cout << it << ".\n";
			}

		}
		else {
			int ans = INF;
			FOR(st, 0, 1 << N) {
				ans = min(ans, dist[st][N - 1]);
			}
			if (ans != INF) {
				puts("You can not switch off all lights.");
			}
			else {
				puts("Help me!");
			}
		}
	}

	return 0;
}
