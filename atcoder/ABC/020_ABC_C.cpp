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

/* -----  2019/04/10  Problem: ABC 020 C / Link: http://abc020.contest.atcoder.jp/tasks/abc020_c  ----- */
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };
inline bool IN(int y, int x, int H, int W) { return (0 <= y && y < H && 0 <= x && x < W); };

LL bfs2D(pair<int, int> s, pair<int, int> t, int Height, int Width, vector<string > & masu, LL X) {
	vector<vector<LL> > d(Height, vector<LL>(Width, LINF));

	d[s.first][s.second] = 0;
	queue<pair<LL, pair<int, int>>>q;
	q.push(make_pair(0, s));

	while (!q.empty()) {
		pair<LL, pair<int, int>>a = q.front(); q.pop();
		LL dist = a.first; pair<int, int> pos = a.second;
		if (d[pos.first][pos.second] < dist)continue;
		FOR(k, 0, 4) {
			int ny = pos.first + DY[k]; int nx = pos.second + DX[k];
			if (IN(ny, nx, Height, Width)) {
				LL c = (masu[ny][nx] == '#' ? X : 1);
				if (d[ny][nx] > d[pos.first][pos.second] + c) {
					d[ny][nx] = d[pos.first][pos.second] + c;
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

	LL H, W, T; cin >> H >> W >> T;
	vector<string > s(H);
	for (int i = 0; i < H; ++i) {
		cin >> s[i];
	}
	PII ss, st;
	FOR(i, 0, H) {
		FOR(j, 0, W) {
			if (s[i][j] == 'S')ss = PII(i, j);
			if (s[i][j] == 'G')st = PII(i, j);
		}
	}
	LL L = 0, R = 1e12;
	while (R - L > 1) {
		LL mid = (R + L) / 2;
		if (bfs2D(ss, st, H, W, s, mid) <= T) {
			L = mid;
		}
		else {
			R = mid;
		}
	}
	assert(L > 0);

	LL ans = L;


	cout << (ans) << "\n";

	return 0;
}
