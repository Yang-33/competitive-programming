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

/* -----  2019/04/05  Problem: ABC 039 D / Link: http://abc039.contest.atcoder.jp/tasks/abc039_d  ----- */


const int DY[9] = { 1, -1, 0, 0, 1, -1, 1, -1 ,0 };
const int DX[9] = { 0, 0, 1, -1, 1, 1, -1, -1 ,0 };


int main() {
	cin.tie(0);

	LL H, W; cin >> H >> W;
	vector<string> a(H);
	for (int i = 0; i < H; ++i) {
		cin >> a[i];
	}
	vector<string> origin_state(H, string(W, '#'));
	FOR(i, 0, H) {
		FOR(j, 0, W) {
			if (a[i][j] == '.') {
				auto is_in = [](int a, int b, int c) { return a <= b && b < c; };
				FOR(k, 0, 9) {
					int ny = i + DY[k], nx = j + DX[k];
					if (is_in(0, ny, H) && is_in(0, nx, W)) {
						origin_state[ny][nx] = '.';
					}
				}

			}
		}
	}
	// 復元2
	vector<string> b(H, string(W, '.'));
	FOR(i, 0, H) {
		FOR(j, 0, W) {
			if (origin_state[i][j] == '#') {
				auto is_in = [](int a, int b, int c) { return a <= b && b < c; };
				FOR(k, 0, 9) {
					int ny = i + DY[k], nx = j + DX[k];
					if (is_in(0, ny, H) && is_in(0, nx, W)) {
						b[ny][nx] = '#';
					}
				}

			}
		}
	}
	bool ok = 1;
	FOR(i, 0, H) {
		FOR(j, 0, W) {
			ok &= a[i][j] == b[i][j];
		}
	}
	auto print_possible = [](bool ok, int mode = 0) {
		if (mode == 0) {
			cout << ((ok ? "possible\n" : "impossible\n"));
		}
		else if (mode == 1) {
			cout << ((ok ? "Possible\n" : "Impossible\n"));
		}
		else if (mode == 2) {
			cout << ((ok ? "POSSIBLE\n" : "IMPOSSIBLE\n"));
		}
		else {
			assert(0);
		}
	};
	print_possible(ok, 0);
	if (ok) {
		FOR(i, 0, H) {
			cout << origin_state[i] << endl;
		}
	}

	return 0;
}
