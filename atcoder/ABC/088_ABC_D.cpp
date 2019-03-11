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
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2019/03/11  Problem: ABC 088 D / Link: http://abc088.contest.atcoder.jp/tasks/abc088_d  ----- */

inline bool IN(int y, int x, int H, int W) { return (0 <= y && y < H && 0 <= x && x < W); }

int bfs2D(pair<int, int> s, pair<int, int> t, int Height, int Width, VS & masu) {
	vector<vector<int> > d(Height, vector<int>(Width, 1e9));


	d[s.first][s.second] = 0;
	queue<pair<int, pair<int, int>>>q;
	q.push(make_pair(0, s));

	while (!q.empty()) {
		pair<int, pair<int, int>>a = q.front(); q.pop();
		int dist = a.first; pair<int, int> pos = a.second;
		if (d[pos.first][pos.second] < dist)continue;
		FOR(k, 0, 4) { //辺が存在するかはチェックしてないよ
			int ny = pos.first + DY[k]; int nx = pos.second + DX[k];
			if (IN(ny, nx, Height, Width)) {
				if (masu[ny][nx] == '.')// 辺の チェックしてるよ
					if (d[ny][nx] > d[pos.first][pos.second] + 1) {
						d[ny][nx] = d[pos.first][pos.second] + 1;
						q.push(make_pair(d[ny][nx], pair<int, int>(ny, nx)));
					}
			}
		}
	}

	return d[t.first][t.second]; // (int)
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL H, W; cin >> H >> W;
	vector<string> a(H);
	for (int i = 0; i < H; ++i) {
		cin >> a[i];
	}

	
	LL ans = 0LL;
	FOR(i, 0, H) {
		FOR(j, 0, W) {
			if (a[i][j] == '.')ans++;
		}
	}
	
	int res = bfs2D(PII(0, 0), PII(H - 1, W - 1), H, W, a);
	ans -= res+1;
	
	cout << (res==1e9?-1:ans) << "\n";

	return 0;
}
