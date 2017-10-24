#include "bits/stdc++.h"
using namespace std;

using VS = vector<string>;    using LL = long long;
using VI = vector<int>;       using VVI = vector<VI>;
using PII = pair<int, int>;   using PLL = pair<LL, LL>;
using VL = vector<LL>;        using VVL = vector<VL>;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(a) int((a).size())
#define SORT(c) sort(ALL((c)))
#define RSORT(c) sort(RALL((c)))
#define UNIQ(c) (c).erase(unique(ALL((c))), end((c)))
#define FOR(i, s, e) for (int(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (int(i) = (s); (i) > (e); (i)--)
#define debug(x) cerr << #x << ": " << x << endl
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2017/10/18  Problem: 20_c  / Link: http://joi2012yo.contest.atcoder.jp/tasks/joi2012yo_e  ----- */
/* ------問題------

JOI 社の建物は図のような 1 辺 1 メートルの正六角形をつなぎ合わせた形である．クリスマスが近づいているので，JOI 社では建物の壁面をイルミネーションで飾り付けることにした．ただし，外から見えない部分にイルミネーションを施すのは無駄なので，イルミネーションは外から建物の中を通らずに行くことのできる壁面にのみ飾り付けることにした．
上の図は上空から見た JOI 社の建物の配置の例である．正六角形内の数字は座標を表す．灰色の正六角形は建物がある場所を表し，白色の正六角形は建物がない場所を表す．この例では，赤の実線で示される部分がイルミネーションで飾り付けを行う壁面となり，その壁面の長さの合計は 64 メートルとなる．
JOI 社の建物の配置を表す地図が与えられたとき，飾り付けを行う壁面の長さの合計を求めるプログラムを作成せよ．ただし，地図の外側は自由に行き来できるものとし，隣接した建物の間は通ることはできないものとする．

-----問題ここまで----- */
/* -----解説等-----

問題文をちゃんと読めばわかるよね
六角座標はライブラリに入れてもいいかも。

----解説ここまで---- */

LL W, H;

LL ans = 0LL;
int dx[2][6] = { { 1,0,-1,-1,-1,0 } ,{ 1,1,0,-1,0,1 } };
int dy[2][6] = { { 0,-1,-1,0,1,1 } ,{ 0,-1,-1,0,1,1 } };


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> W >> H;
	VVI masu(H + 2, VI(W + 2, 0));
	FOR(i, 1, H + 1) {
		FOR(j, 1, W + 1) {
			cin >> masu[i][j];
		}
	}
	queue<PII>q;
	q.push(PII(0, 0));
	const int OUT = -1;
	masu[0][0] = OUT;
	while (!q.empty()) {
		int x, y;
		y = q.front().first; x = q.front().second; q.pop();
		FOR(k, 0, 6) {
			int ny = y + dy[y % 2][k]; int nx = x + dx[y % 2][k];
			if (ny<0 || ny>H + 1 || nx<0 || nx>W + 1)continue;
			if (masu[ny][nx] == 1 || masu[ny][nx] == OUT)continue;
			masu[ny][nx] = OUT;
			q.push(PII(ny, nx));
		}
	}

	FOR(i, 1, H + 1) {
		FOR(j, 1, W + 1) {
			if (masu[i][j] == 1) {
				FOR(k, 0, 6) {
					int ny = i + dy[i % 2][k]; int nx = j + dx[i % 2][k];
					if (masu[ny][nx] == OUT)ans++;
				}
			}
		}
	}

	cout << ans << "\n";

	return 0;
}