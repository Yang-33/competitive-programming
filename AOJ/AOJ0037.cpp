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

/* -----  2019/07/13  Problem: AOJ 0037 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0037  ----- */


int main() {
	int N = 9;
	vector<vector<vector<PII>>>G(N, vector<vector<PII>>(N)); {
		int y = 0;
		FOR(i, 0, 9) {
			string s; cin >> s;
			if (i % 2 == 0) {
				FOR(j, 0, SZ(s)) { // -
					if (s[j] == '0')continue;
					G[y][j].emplace_back(y, j + 1);
					G[y][j + 1].emplace_back(y, j);
				}
			}
			else {
				FOR(j, 0, SZ(s)) { // |
					if (s[j] == '0')continue;
					G[y][j].emplace_back(y + 1, j);
					G[y + 1][j].emplace_back(y, j);

				}
				y++;
			}
		}
	}

	// やっていく
	// backが最後になるようにする
	int y = 0, x = 0, d = 0;
	const int DY[] = { 0,1,0,-1 };
	const int DX[] = { 1,0,-1,0 };
	const string D = "RDLU";
	string ans = "";
	while (1) {
		y += DY[d]; x += DX[d];
		ans += D[d];
		if (y == 0 && x == 0)break;
		[&] {
			FOR(i, 0, 4) {
				int nxd = (d + i + 3) % 4;
				for (auto nv : G[y][x]) {
					if (nv == make_pair(y + DY[nxd], x + DX[nxd])) {
						d = nxd;
						return;
					}
				}
			}
		}();

	}
	cout << ans << endl;

	return 0;
}
