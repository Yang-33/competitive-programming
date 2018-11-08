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

/* -----  2018/11/10  Problem: ARC 025 B / Link: http://arc025.contest.atcoder.jp/tasks/arc025_b  ----- */
/* ------問題------

縦 H マス、横 W マスのチョコレートがある。各マスはブラックチョコかホワイトチョコである。ブラックチョコ同士、ホワイトチョコ同士は辺を共有しない（つまり、チョコレートは市松模様を形成している）。 各マスごとにチョコレートの濃度が定まっている。チョコレートの例を以下に表す（数字は濃度を表す）。
妹はこのチョコレートから、ある長方形領域を切り出して溶かし、チョコクリームを作成することにした。妹はチョコレートの味にこだわりを持っており、チョコクリームに使用されたブラックチョコとホワイトチョコの濃度の合計値（ただし、それぞれ使用されていない場合は濃度の合計値を 0 として扱うものとする）が等しくなければ気が済まない。
妹は条件を満たす切り出し方のうち、使用するチョコレートのマス数が最大でいくつになるのかが知りたい。

-----問題ここまで----- */
/* -----解説等-----

定数倍は1/4だし10^8でも通る。

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int H, W; cin >> H >> W;
	VVI c(H, VI(W));
	FOR(i, 0, H) {
		FOR(j, 0, W) {
			cin >> c[i][j];
		}
	}
	VVI black(H + 1, VI(W + 1));
	VVI white = black;
	auto add = [](VVI& data, int y, int x, int val) {
		data[y + 1][x + 1] += val;
	};
	int ans = 0;
	FOR(i, 0, H) {
		FOR(j, 0, W) {
			if ((i + j) % 2 == 0) { // black
				add(black, i, j, c[i][j]);
			}
			else {
				add(white, i, j, c[i][j]);
			}
		}
	}
	auto build = [&](VVI &data) {
		FOR(i, 0, H)FOR(j, 0, W)data[i + 1][j + 1] += data[i + 1][j];
		FOR(i, 0, H)FOR(j, 0, W)data[i + 1][j + 1] += data[i][j + 1];
	};
	auto Rquery = [](VVI &data, int sy, int sx, int ty, int tx) {
		return data[ty + 1][tx + 1] - data[sy][tx + 1] - data[ty + 1][sx] + data[sy][sx];
	};
	build(white);
	build(black);
	// 2.5 * 10^7
	FOR(sy, 0, H) {
		FOR(sx, 0, W) {
			FOR(ty, sy, H) {
				FOR(tx, sx, W) {
					if (Rquery(white, sy, sx, ty, tx) == Rquery(black, sy, sx, ty, tx)) {
						ans = max(ans, (ty - sy + 1)*(tx - sx + 1));
					}
				}
			}
		}
	}
	cout << ans << "\n";

	return 0;
}