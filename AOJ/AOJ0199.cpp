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
//const LL MOD = 1000000007;                    const double PI = acos(-1.0);

/* -----  2019/07/27  Problem: AOJ 0199 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0199  ----- */

int main() {
	int N, M;
	while (cin >> N >> M, N || M) {
		string seat(N, '#');
		FOR(_, 0, M) {
			char c; cin >> c;
			if (c == 'A') {
				FOR(i, 0, N) {
					if (seat[i] == '#') {
						seat[i] = c;
						break;
					}
				}
			}
			else if (c == 'B') {
				bool upd = 0;
				FORR(i, N - 1, 0 - 1) {
					if (seat[i] == '#') {
						bool ok = 1;
						if (i - 1 >= 0)ok &= seat[i - 1] != 'A';
						if (i + 1 < N)ok &= seat[i + 1] != 'A';
						if (ok) {
							seat[i] = c;
							upd = 1;
							break;
						}
					}
				}
				if (!upd) {
					FOR(i, 0, N) {
						if (seat[i] == '#') {
							seat[i] = c;
							break;
						}
					}
				}
			}
			else if (c == 'C') {
				bool upd = 0;
				if (_ == 0) {
					seat[N / 2] = c;
					upd = 1;
				}

				if (!upd) {

					FOR(i, 0, N) {
						if (seat[i] != '#') {
							if (i + 1 < N && seat[i + 1] == '#') { seat[i + 1] = c; upd = 1; break; }
							if (i - 1 >= 0 && seat[i - 1] == '#') { seat[i - 1] = c; upd = 1; break; }
						}
					}
				}
				if (!upd) {
					FOR(i, 0, N) {
						if (seat[i] == '#') {
							if (i + 1 < N) {
								if (seat[i + 1] != '#') {
									seat[i] = c;
									upd = 1;
									break;
								}
							}
						}
					}
				}
			}
			else if (c == 'D') {
				if (_ == 0) {
					seat[0] = c;
					continue;
				}
				VI dist(N, INF);
				// ->
				{
					FOR(i, 0, N) {
						if (seat[i] != '#') {
							dist[i] = 0;
						}
						else if (i) {
							dist[i] = min(dist[i], dist[i - 1] + 1);
						}

					}
				}
				// <-
				{
					FORR(i, N - 1, 0 - 1) {
						if (seat[i] != '#') {
							dist[i] = 0;
						}
						else if (i + 1 < N) {
							dist[i] = min(dist[i], dist[i + 1] + 1);
						}

					}
				}
				int mx = *max_element(ALL(dist));
				int id = 0;
				FOR(i, 0, N) {
					if (dist[i] == mx && seat[i] == '#') {
						id = i;
						break;
					}
				}
				seat[id] = c;
			}
		}
		cout << seat << "\n";
	}
}