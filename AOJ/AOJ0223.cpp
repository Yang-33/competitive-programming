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

/* -----  2019/08/14  Problem: AOJ 0223 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0223  ----- */

int main() {
	while (1) {
		int w, h; cin >> w >> h;
		if (w == 0) return 0;

		int tx, ty, kx, ky; cin >> tx >> ty >> kx >> ky;

		vector<vector<int>> d(h + 2, vector<int>(w + 2, 1));
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				cin >> d[i][j];
			}
		}
		using T = tuple<int, int, int, int>;
		using T2 = tuple<int, int, int, int, int>;
		const int dy[] = { 0, -1, 0, 1 };
		const int dx[] = { 1, 0, -1, 0 };
		map<T, bool> visited;
		visited[T(ty, tx, ky, kx)] = true;

		bool valid = false;
		queue<T2> que;
		que.push(T2(ty, tx, ky, kx, 0));
		while (que.size()) {
			int cy1, cx1, cy2, cx2, cnt;
			tie(cy1, cx1, cy2, cx2, cnt) = que.front();
			que.pop();

			if (100 <= cnt) continue;

			if (cy1 == cy2 && cx1 == cx2) {
				cout << cnt << endl;
				valid = true;
				break;
			}

			for (int i = 0; i < 4; i++) {
				int ny1 = cy1 + dy[i];
				int nx1 = cx1 + dx[i];
				int ny2 = cy2 - dy[i];
				int nx2 = cx2 - dx[i];

				if (d[ny1][nx1] == 0 && d[ny2][nx2] == 0 && !visited[T(ny1, nx1, ny2, nx2)]) {
					visited[T(ny1, nx1, ny2, nx2)] = true;
					que.push(T2(ny1, nx1, ny2, nx2, cnt + 1));
				}
				else if (d[ny1][nx1] == 0 && d[ny2][nx2] == 1 && !visited[T(ny1, nx1, cy2, cx2)]) {
					visited[T(ny1, nx1, cy2, cx2)] = true;
					que.push(T2(ny1, nx1, cy2, cx2, cnt + 1));
				}
				else if (d[ny1][nx1] == 1 && d[ny2][nx2] == 0 && !visited[T(cy1, cx1, ny2, nx2)]) {
					visited[T(cy1, cx1, ny2, nx2)] = true;
					que.push(T2(cy1, cx1, ny2, nx2, cnt + 1));
				}
			}
		}

		if (!valid) {
			cout << "NA" << endl;
		}
	}
}