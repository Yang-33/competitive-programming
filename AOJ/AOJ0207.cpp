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

/* -----  2019/08/04  Problem: AOJ 0207 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0207  ----- */

int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };
inline bool IN(int y, int x, int H, int W) { return (0 <= y && y < H && 0 <= x && x < W); }

bool bfs2D(pair<int, int> s, pair<int, int> t, int Height, int Width, vector<vector<int> > & masu) {
	vector<vector<int> > d(Height, vector<int>(Width, INF));

	queue<pair<int, pair<int, int>>>q;
	if (masu[s.first][s.second]) {
		d[s.first][s.second] = 0;
		q.push(make_pair(0, s));
	}

	while (!q.empty()) {
		pair<int, pair<int, int>>a = q.front(); q.pop();
		int dist = a.first; pair<int, int> pos = a.second;
		if (d[pos.first][pos.second] < dist)continue;
		FOR(k, 0, 4) { //辺が存在するかはチェックしてないよ
			int ny = pos.first + DY[k]; int nx = pos.second + DX[k];
			if (IN(ny, nx, Height, Width)) {
				if (masu[ny][nx] == 1)// 辺の チェックしてるよ
					if (d[ny][nx] > d[pos.first][pos.second] + 1) {
						d[ny][nx] = d[pos.first][pos.second] + 1;
						q.push(make_pair(d[ny][nx], pair<int, int>(ny, nx)));
					}
			}
		}
	}

	return d[t.first][t.second] != INF;
}


int main() {

	int H, W;
	while (cin >> W >> H, W) {
		PII s; cin >> s.second >> s.first;
		s.second--, s.first--;
		PII t; cin >> t.second >> t.first;
		t.second--, t.first--;
		int N; cin >> N;
		VVI masuCOL(H, VI(W, 0));
		FOR(_, 0, N) {
			int col, di, x, y;
			cin >> col >> di >> x >> y;
			x--, y--;
			if (di == 0) {
				// (x,y)->(x+4,y+2)
				FOR(i, 0, 2) {
					FOR(j, 0, 4) {
						masuCOL[i + y][j + x] = col;
					}
				}
			}
			else {
				// (x,y)->(x+2,y+4)
				FOR(i, 0, 4) {
					FOR(j, 0, 2) {
						masuCOL[i + y][j + x] = col;
					}
				}

			}
		}
		bool ok = 0;
		FOR(col, 1, 5 + 1) {
			VVI masu(H, VI(W, 0));
			FOR(i, 0, H) {
				FOR(j, 0, W) {
					if (masuCOL[i][j] == col) {
						masu[i][j] = 1;
					}
				}
			}
			ok |= bfs2D(s, t, H, W, masu);
		}
		if (!ok)puts("NG");
		else puts("OK");
	}

	return 0;
}
