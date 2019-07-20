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

/* -----  2019/07/20  Problem: AOJ 0122 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0122  ----- */

int main() {
	const int day[] = { 0,1,1,1,0,-1,-1,-1,0 };
	const int dax[] = { -1,-1,0,1,1,1,0,-1,0 };
	const int dby[] = { -1,0,1,2,2,2,1,0,-1,-2,-2,-2 };
	const int dbx[] = { -2,-2,-2,-1,0,1,2,2,2,1,0,-1 };
	while (1) {
		VVI mas(10, VI(10, 0));
		int sx, sy; cin >> sy >> sx;
		if (sx == 0 && sy == 0)break;
		int N; cin >> N;
		vector<pair<int, int>>data(N);
		FOR(i, 0, N) {
			int a, b; cin >> a >> b;
			data[i].second = a;
			data[i].first = b;
		}
		function<bool(int, int, int)>dfs = [&](int x, int y, int d) {
			if (d == N) return true;
			FOR(i, 0, 12) {
				int nx = x + dbx[i], ny = y + dby[i];
				if (nx >= 0 && nx <= 9 && ny >= 0 && ny <= 9) {
					FOR(j, 0, 9) {
						int sx = data[d].first + dax[j], sy = data[d].second + day[j];
						if (sx >= 0 && sx <= 9 && sy >= 0 && sy <= 9) {
							if (nx == sx && ny == sy) {
								if (dfs(nx, ny, d + 1) == true) return true;
							}
						}
					}
				}
			}
			return false;
		};

		cout << (dfs(sx, sy, 0) == true ? "OK" : "NA") << endl;
	}
}