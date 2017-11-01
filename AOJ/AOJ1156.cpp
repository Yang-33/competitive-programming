#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define FOR(i,s,e) for(int(i)=(s);(i) < (e);(i)++)
#define debug(x) cout << #x << ": " << x << endl
/* -----  2017/11/01  Problem: AOJ1156  / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1156  ----- */
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

マスに移動してきたときに以前の情報が必要なので、ダイクストラをするときに頂点を増やしてやればよい。

----解説ここまで---- */
const int INF = 1e9;
const ll LINF = 1e16;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
bool is_in(int x, int y, int h, int w) {
	return (0 <= x&&x < w && 0 <= y&&y < h);
}

int masu[35][35];
int dist[35][35][5];
int co[4];

int main() {
	cin.tie(0); ios::sync_with_stdio(false);


	while (true) {
		FOR(i, 0, 35)FOR(j, 0, 35)masu[i][j] = -1;
		FOR(i, 0, 35)FOR(j, 0, 35)FOR(k, 0, 4)dist[i][j][k] = INF;

		int H, W;
		cin >> W >> H;
		if (W == 0 && H == 0)break;
		FOR(i, 0, H) {
			FOR(j, 0, W) {
				cin >> masu[i][j];
			}
		}
		FOR(i, 0, 4)cin >> co[i];

		//cost,y,x,dirct
		using Ty = tuple<int, int, int, int>;
		priority_queue<Ty, vector<Ty>, greater<Ty>>q;
		q.push(Ty(0, 0, 0, 0));
		dist[0][0][0] = 0;

		while (!q.empty()) {
			Ty a = q.top(); q.pop();
			int x, y, cost, dir, dir2;
			tie(cost, y, x, dir) = a;
			dir2 = dir;
			if (dist[y][x][dir] < cost)continue;
			int command = masu[y][x];
			
			
			if (command == 0) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if (is_in(nx, ny, H, W))
				if (dist[ny][nx][dir] > cost) {
					dist[ny][nx][dir] = cost;
					q.push(Ty(cost, ny, nx, dir));
				}
			}
			else if (command == 1) {
				dir2 = (dir + 1) % 4;
				int nx = x + dx[dir2];
				int ny = y + dy[dir2];
				if (is_in(nx, ny, H, W))
				if (dist[ny][nx][dir2] > cost) {
					dist[ny][nx][dir2] = cost;
					q.push(Ty(cost, ny, nx, dir2));
				}
			}
			else if (command == 2) {
				dir2 = (dir + 2) % 4;
				int nx = x + dx[dir2];
				int ny = y + dy[dir2];
				if (is_in(nx, ny, H, W))
				if (dist[ny][nx][dir2] > cost) {
					dist[ny][nx][dir2] = cost;
					q.push(Ty(cost, ny, nx, dir2));
				}
			}
			else if (command == 3) {
				dir2 = (dir - 1 + 4) % 4;
				int nx = x + dx[dir2];
				int ny = y + dy[dir2];
				if (is_in(nx, ny, H, W))
				if (dist[ny][nx][dir2] > cost) {
					dist[ny][nx][dir2] = cost;
					q.push(Ty(cost, ny, nx, dir2));
				}
			}
			else if (command == 4) {
				;
			}
			//cost

			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (is_in(nx, ny, H, W)) {
				if (dist[ny][nx][dir] > cost + co[0]) {
					dist[ny][nx][dir] = cost + co[0];
					q.push(Ty(dist[ny][nx][dir], ny, nx, dir));
				}
			}
			dir2 = (dir + 1) % 4;
			 nx = x + dx[dir2];
			 ny = y + dy[dir2];
			if (is_in(nx, ny, H, W)) {
				if (dist[ny][nx][dir2] > cost + co[1]) {
					dist[ny][nx][dir2] = cost + co[1];
					q.push(Ty(dist[ny][nx][dir2], ny, nx, dir2));

				}
			}
			dir2 = (dir + 2) % 4;
			 nx = x + dx[dir2];
			 ny = y + dy[dir2];
			if (is_in(nx, ny, H, W)) {
				if (dist[ny][nx][dir2] > cost + co[2]) {
					dist[ny][nx][dir2] = cost + co[2];
					q.push(Ty(dist[ny][nx][dir2], ny, nx, dir2));

				}
			}
			dir2 = (dir - 1 + 4) % 4;
			 nx = x + dx[dir2];
			 ny = y + dy[dir2];
			if (is_in(nx, ny, H, W)) {
				if (dist[ny][nx][dir2] > cost + co[3]) {
					dist[ny][nx][dir2] = cost + co[3];
					q.push(Ty(dist[ny][nx][dir2], ny, nx, dir2));
				}
			}
		}

		ll ans = LINF;
		FOR(i, 0, 4) {
			ans = min(ans, (ll)dist[H - 1][W - 1][i]);
		}
		cout << ans << endl;
	}


	return 0;
}