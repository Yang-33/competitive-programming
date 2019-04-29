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

/* -----  2019/04/29  Problem: AOJ 2847 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/2847  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; cin >> N;

	//登場回数2回のものが端
	int M = 2 * N*N - 2 * N;
	VI cnt(N*N);
	VVI edge(N*N);
	FOR(i, 0, M) {
		int a, b; cin >> a >> b;
		a--, b--;
		edge[a].push_back(b);
		edge[b].push_back(a);
		cnt[a]++, cnt[b]++;
	}
	VVI a(N, VI(N, -1));
	vector<int>ps;
	FOR(i, 0, N*N) {
		if (cnt[i] == 2)ps.push_back(i);
	}
	// s:psから構築すると決まる
	for (auto s : ps) {
		a[0][0] = s;
		VI used(N*N);
		used[s] = 1;
		FOR(i, 0, N) {
			FOR(j, 0, N) {
				if (i + j == 0)continue;
				const int DY[] = { 0,-1,0,1 };
				const int DX[] = { -1,0,1,0 };
				auto isin = [](int a, int b, int c) {
					return a <= b && b < c;
				};

				// 隣接項を集める
				map<int,int> around;
				int arcnt = 0; {
					FOR(k, 0, 2) {
						int ny = i + DY[k], nx = j + DX[k];
						if (isin(0, ny, N) && isin(0, nx, N)) {
							DD(de(ny, nx, a[ny][nx]))
								arcnt++;
							for (auto it : edge[a[ny][nx]]) {
								around[it]++;
							}
						}
					}
				}

				int t = 0; {
					FOR(k, 0, 4) {
						int ny = i + DY[k], nx = j + DX[k];
						if (isin(0, ny, N) && isin(0, nx, N)) {
							t++;
						}
					}
				}
				DD(de(i,j,t,around))
				// ar: aroundの次数とtが一致すればそれ
				for (auto it : around) {
					int ar = it.first;
					int arc = it.second;
					if (arcnt != arc)continue;
					if (cnt[ar] == t && !used[ar]) {
						used[ar] = 1;
						a[i][j] = ar;
						break;
					}
				}

			}
		}

		if (accumulate(ALL(used), 0) == N * N) {
			break;
		}
	}
	auto output = [](VVI& a) {
		for (auto it : a) {
			FOR(i, 0, SZ(it)) {
				cout << it[i] + 1 << " \n"[i == SZ(it) - 1];
			}
		}
	};
	output(a);

	return 0;
}
