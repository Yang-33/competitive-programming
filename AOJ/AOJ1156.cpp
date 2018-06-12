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
#define debug(x) cerr << #x << ": " << x << endl
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);

/* -----  2018/06/12  Problem: AOJ 1156 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1156  ----- */
/* ------問題------

ロボットを使ったゲームをしよう． ロボットが 1 台，マス目状に区切られた長方形の盤面上に置かれている（図 D-1）． ロボットは，最初北西隅にあるスタート地点のマスに東方向を向いて配置されている． ゲームの目的は，ロボットを南東隅にあるゴールのマスまで誘導することである．
ロボットは，次の 5 種類の命令を実行することができる．
「直進 (Straight)」:
現在の進行方向のまま，次のマスに前進する．
「右折 (Right)」:
進行方向を 90 度右に変えて，次のマスに前進する．
「反転 (Back)」:
進行方向を 180 度変えて，次のマスに前進する．
「左折 (Left)」:
進行方向を 90 度左に変えて，次のマスに前進する．
「停止 (Halt)」:
現在のマスで止まって，ゲームを終了する．
各マスには，上述の命令のいずれかが割り当てられている（例：図 D-2）． 代わりに実行すべき別の命令をプレイヤーが与えない限り， ロボットは，現在いるマスの命令を実行する． プレイヤーが明示的に命令を与える際は，その都度， 命令の種類に応じたコストを支払う必要がある．
ロボットは，同じ場所を何度も訪れることが許されている． 一方で，ロボットが盤面外に前進するような命令を実行した場合や， ゴールに着く前に停止命令を実行した場合は，失格となる．
あなたの仕事は， ロボットをスタート地点からゴール地点に誘導するために必要な最小コストを求めるプログラムを書くことである．

-----問題ここまで----- */
/* -----解説等-----

前どこから来たかをもって、やる
方向行列は回転できるようにする

----解説ここまで---- */

bool is_in(int x, int y, int h, int w) {
	return (0 <= x && x < w && 0 <= y && y < h);
}
int nxtstep(int cmd,int dir) {
	if (cmd == 0)return dir;
	if (cmd == 1)return (dir+1)%4;
	if (cmd == 2)return (dir+2)%4;
	if (cmd == 3)return (dir+3)%4;
	assert(0);
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int W, H;
	int DY[8] = { 0, 1, 0, -1 };
	int DX[8] = { 1, 0, -1, 0 };

	while (cin >> W >> H, W) {
		VVI masu(H, VI(W));
		FOR(i, 0, H) {
			FOR(j, 0, W) {
				cin >> masu[i][j];
			}
		}
		VI co(4);
		FOR(i, 0, 4) {
			cin >> co[i];
		} // straight,ri,rev,le
		vector<VVI>dist(H, VVI(W, VI(4, INF)));
		using tp = tuple<int, int, int, int>;
		priority_queue<tp, vector<tp>, greater<tp>>q;
		dist[0][0][0] = 0;
		q.push(tp(0, 0, 0, 0));
		while (!q.empty()) {
			int x, y, cost, dir, nxdir;
			tie(cost, y, x, dir) = q.top(); q.pop();
			nxdir = dir;
			if (dist[y][x][dir] < cost)continue;
			int command = masu[y][x];

			if (command >= 0 && command <= 3) {
				nxdir = nxtstep(command, dir);
				int ny = y + DY[nxdir];
				int nx = x + DX[nxdir];
				if (is_in(nx, ny, H, W)) {
					if (dist[ny][nx][nxdir] > cost) {
						dist[ny][nx][nxdir] = cost;
						q.push(tp(cost, ny, nx, nxdir));
					}
				}
			}
			// change
			FOR(i, 0, 4) {
				nxdir = nxtstep(i, dir);
				int ny = y + DY[nxdir];
				int nx = x + DX[nxdir];
				if (is_in(nx, ny, H, W)) {
					if (dist[ny][nx][nxdir] > cost + co[i]) {
						dist[ny][nx][nxdir] = cost + co[i];
						q.push(tp(dist[ny][nx][nxdir], ny, nx, nxdir));

					}
				}
			}
		}
		int ans = INF;
		FOR(i, 0, 4) {
			ans = min(ans, dist[H - 1][W - 1][i]);
		}
		cout << ans << "\n";
	}

	return 0;
}
