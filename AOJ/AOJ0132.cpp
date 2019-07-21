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

/* -----  2019/07/21  Problem: AOJ 0132 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0132  ----- */

VS rotate2dR(const VS & a) { // rorateToR
	VS res(a[0].size(), string(a.size(), 1));
	FOR(i, 0, (int)a.size())FOR(j, 0, (int)a[0].size())res[j][a.size() - i - 1] = a[i][j];
	return res;
}

// n<=10, rot -> 40
int main() {
	int H, W;
	while (cin >> H >> W, H || W) {
		int target_space = 0;
		VS target(H); {
			FOR(i, 0, H) {
				cin >> target[i];
				FOR(j, 0, W) {
					if (target[i][j] == '.')target_space++;
				}
			}
		}
		int N; cin >> N;
		VI h(4 * N), w(4 * N);
		vector<VS> piece(4 * N);
		VI sz(4 * N);
		FOR(i, 0, N) {
			cin >> h[i] >> w[i];
			VS a(h[i]); {
				int black = 0;
				FOR(y, 0, h[i]) {
					cin >> a[y];
					FOR(x, 0, w[i]) {
						if (a[y][x] == '#')black++;
					}
				}
				sz[i] = black;
			}
			piece[i] = a;

			// rotate i -> N+i -> 2*N+i -> 3*N+i
			FOR(k, 1, 4) {
				piece[i + k * N] = rotate2dR(piece[i + (k - 1)*N]);
				h[i + k * N] = w[i + (k - 1)*N];
				w[i + k * N] = h[i + (k - 1)*N];
				sz[i + k * N] = sz[i + (k - 1)*N];
			}
		}
		if (0) {
			FOR(i, 0, N) {
				cout << "-----------" << endl;
				FOR(k, 0, 4) {
					cout << "!!!!!!!!!!" << endl;
					int id = i + k * N;
					FOR(y, 0, h[id]) {
						cout << piece[id][y] << endl;
					}
				}
			}
			return 0;
		}
		int Q; cin >> Q;
		FOR(_, 0, Q) {
			int qn; cin >> qn;
			int blacksum = 0;
			VI query(qn);
			FOR(i, 0, qn) {
				cin >> query[i];
				query[i]--;
				blacksum += sz[query[i]];
			}

			// big sort
			sort(ALL(query), [&](const int a, const int b) {
				return sz[a] > sz[b];
			});
			function<bool(int)>f = [&](int idx) {
				//DD(de(idx));
				if (idx == qn) {
					return true;
				}

				{ // check
					VVI masu(H, VI(W, 0));
					FOR(i, 0, H) {
						FOR(j, 0, W) {
							// まだ置いていなくて，置く可能性もないっぽい
							if (target[i][j] == '.' && !masu[i][j]) {
								FOR(ids, idx, qn) {
									FOR(k, 0, 4) {
										int id = query[ids] + k * N;
										// 以降でぬれるかをチェック
										for (int y = max(0, i - h[id] + 1); y <= i && y + h[id] <= H; y++) {
											for (int x = max(0, j - w[id] + 1); x <= j && x + w[id] <= W; x++) {
												FOR(a, 0, h[id])FOR(b, 0, w[id]) {
													if (piece[id][a][b] == '#' && target[y + a][x + b] == '#') goto FAIL;
												}
												//DD(de("put check", ids, k));
												FOR(a, 0, h[id]) FOR(b, 0, w[id]) {
													if (piece[id][a][b] == '#') masu[y + a][x + b] = 1;
												}
											FAIL:;
											}
										}
									}
								}
								// このマスをぬれる人が誰もいない
								if (!masu[i][j])return false;
							}
						}
					}

				}

				{ // put
					FOR(k, 0, 4) {
						int id = query[idx] + k * N;
						FOR(y, 0, H - h[id] + 1) {
							FOR(x, 0, W - w[id] + 1) {
								bool can_set = 1;
								[&] { // check whether we put
									FOR(i, 0, h[id]) {
										FOR(j, 0, w[id]) {
											if (target[y + i][x + j] == '#'&&piece[id][i][j] == '#') {
												can_set = 0;
												return;
											}
										}
									}
								}();
								if (can_set) {
									FOR(i, 0, h[id]) { // put
										FOR(j, 0, w[id]) {
											if (piece[id][i][j] == '#') {
												target[y + i][x + j] = '#';
											}
										}
									}
									//DD(de("put", idx, k));
									bool res = f(idx + 1);

									FOR(i, 0, h[id]) { // restore
										FOR(j, 0, w[id]) {
											if (piece[id][i][j] == '#') {
												target[y + i][x + j] = '.';
											}
										}
									}
									if (res)return true;
								}
							}
						}
					}
				}
				return false;

			};


			cout << (blacksum == target_space && f(0) ? "YES" : "NO") << "\n";
		}

	}

	return 0;
}
