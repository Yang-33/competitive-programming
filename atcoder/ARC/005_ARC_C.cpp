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

/* -----  2019/04/05  Problem: ARC 005 C / Link: http://arc005.contest.atcoder.jp/tasks/arc005_c  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int H, W; cin >> H >> W;
	VS vs(H);
	FOR(i, 0, H) {
		cin >> vs[i];
	}
	PII S, T;
	FOR(i, 0, H) {
		FOR(j, 0, W) {
			if (vs[i][j] == 's') {
				S = PII(i, j);
			}
			else if (vs[i][j] == 'g') {
				T = PII(i, j);
			}
		}
	}
	vector<VVI> m(H, VVI(W, VI(3, 0)));
	m[S.first][S.second][0] = 1;
	using tp = tuple<int, int, int>;
	queue<tp>q;
	q.push(tp(0, S.first, S.second));

	while (q.size()) {
		int d, y, x; tie(d, y, x) = q.front(); q.pop();
		if (PII(y, x) == T)break;
		FOR(k, 0, 4) {
			int ny = y + DY[k];
			int nx = x + DX[k];
			if (0 <= ny && ny < H && 0 <= nx && nx < W) {
				if (d == 2 && vs[ny][nx] == '#')continue;
				if (m[ny][nx][d])continue;
				if (vs[ny][nx] == '#') {
					m[ny][nx][d + 1] = 1;
					q.push(tp(d + 1, ny, nx));
				}
				else {
					m[ny][nx][d] = 1;
					q.push(tp(d, ny, nx));
				}

			}
		}
	}
	FOR(i, 0, 3) {
		if (m[T.first][T.second][i]) {
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << "\n";

	return 0;
}
