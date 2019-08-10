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

/* -----  2019/08/04  Problem: AOJ 0213 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0213  ----- */


template<typename F>
struct FixPoint : F {
	FixPoint(F&& f) noexcept :F(forward<F>(f)) {}
	template<typename... Args>
	constexpr decltype(auto) operator()(Args&&... args) const noexcept {
		return F::operator()(*this, forward<Args>(args)...);
	}
};

template<typename F>
static inline constexpr decltype(auto) FUNC(F&& f) noexcept {
	return FixPoint<F>{forward<F>(f)};
}





int main() {
	LL  H, W, N;
	while (cin >> W >> H >> N, W + H + N) {
		VI boxsize(N); {
			FOR(i, 0, N) {
				int a, b; cin >> a >> b;
				a--;
				boxsize[a] = b;
			}
		}
		vector<PII> platepos(N); {
			FOR(i, 0, H) {
				FOR(j, 0, W) {
					int a; cin >> a;
					if (a) {
						a--;
						platepos[a] = PII(i, j);
					}
				}
			}

		}
		VVI masu(H, VI(W, 0));
		VVI ans(H, VI(W, 0));
		int anscnt = 0;
		auto func = FUNC([&](auto f, int idx)->void {
			if (idx == N) {
				// check
				int sum = 0;
				FOR(i, 0, H) {
					FOR(j, 0, W) {
						sum += masu[i][j] != 0;
					}
				}
				if (sum == H * W) {
					anscnt++;
					if (anscnt == 1) {
						ans = masu;
					}
				}
				return;
			}

			// idx+1でぬる
			FOR(h, 1, boxsize[idx] + 1) {
				int w = boxsize[idx] / h;
				if (boxsize[idx] != h * w)continue;
				int cys = platepos[idx].first - h+1;
				int cxs = platepos[idx].second - w+1;
				FOR(ys, 0, h) {
					FOR(xs, 0, w) {
						bool ok = 1;
						{
							FOR(y, 0, h) {
								FOR(x, 0, w) {
									int ny = cys + ys + y;
									int nx = cxs + xs + x;
									if (!(0 <= ny && ny < H && 0 <= nx && nx < W)) { ok = 0; break; }
									if (masu[ny][nx]) { ok = 0; break; };
								}
							}
						}
						if (ok) {
							// fill
							FOR(y, 0, h) {
								FOR(x, 0, w) {
									int ny = cys + ys + y;
									int nx = cxs + xs + x;
									masu[ny][nx] = idx + 1;
								}
							}

							f(idx + 1);
							// recover
							FOR(y, 0, h) {
								FOR(x, 0, w) {
									int ny = cys + ys + y;
									int nx = cxs + xs + x;
									masu[ny][nx] = 0;
								}
							}
						}
					}
				}
			}
			return;
		});

		func(0);
		if (anscnt == 1) {
			FOR(i, 0, H) {
				FOR(j, 0, W) {
					cout << ans[i][j] << " \n"[j + 1 == W];
				}
			}
		}
		else {
			puts("NA");
		}

	}

	return 0;
}
