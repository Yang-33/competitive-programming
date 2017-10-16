#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
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

/* -----  2017/10/16  Problem: nagoya_19_13 JOI2008本戦 5 / Link: http://joi2008ho.contest.atcoder.jp/tasks/joi2008ho_e  ----- */
/* ------問題------

情報オリンピックの宣伝のために，長方形のベニヤ板にペンキを塗り看板を制作
したい．ベニヤ板には色を塗りたくないところにあらかじめ何枚かの長方形のマス
キングテープが貼られている．そこでマスキングテープで区切られた領域ごとに別々
の色を使いペンキを塗ることにした．例えば，図 5-1 の場合は 5 色のペンキを使う．
図 5-1 看板の例
入力としてマスキングテープを貼る位置が与えられた時，使うペンキの色の数を
求めるプログラムを作成せよ．ただし，ベニヤ板全体がマスキングテープで覆われる
ことはなく，全てのマスキングテープの辺はベニヤ板のいずれかの辺に平行である．

-----問題ここまで----- */
/* -----解説等-----

要素数が1000なので座圧でいけそう。
はじめてclangに祈るやつをした。
座標圧縮を行うとマスがかなり小さくなり、普通にHWが通る。
したがってあとは短形和を累積和などで管理し、BFS的なことをしながら色塗りをしていけばよい。

----解説ここまで---- */


LL ans = 0LL;
int compress(int *x1, int *x2, int w, int n) {
	vector<int>xs;
	FOR(i, 0, n) {
		for (int d = -1; d <= 1; d++) {
			if (x1[i] + d >= 0 && x1[i] + d < w)xs.push_back(x1[i] + d);
			if (x2[i] + d >= 0 && x2[i] + d < w)xs.push_back(x2[i] + d);
		}
	}
	SORT(xs);
	UNIQ(xs);
	FOR(i, 0, n) {
		x1[i] = lower_bound(ALL(xs), x1[i]) - xs.begin();
		x2[i] = lower_bound(ALL(xs), x2[i]) - xs.begin();
	}
	return SZ(xs);
}


int main() {

	int x1[1000], x2[1000], y1[1000], y2[1000];
	int H, W, N;
	scanf("%d%d%d", &W, &H, &N);
	FOR(i, 0, N) {
		scanf("%d%d%d%d", &x1[i], &y1[i], &x2[i], &y2[i]);
	}

	W = compress(x1, x2, W, N);
	H = compress(y1, y2, H, N);
	short int **masu = new short int*[H + 1];
	FOR(i, 0, H + 1) {
		masu[i] = new short int[W + 1];
		FOR(j, 0, W + 1)masu[i][j] = 0;
	}

	FOR(i, 0, N) {//ここが遅かった！累積和ではやくなる
		masu[y1[i]][x1[i]]++;
		masu[y1[i]][x2[i]]--;
		masu[y2[i]][x1[i]]--;
		masu[y2[i]][x2[i]]++;
	}
	FOR(i, 0, H + 1) {
		FOR(j, 0, W + 1) {
			masu[i][j] += (i>0?masu[i-1][j]:0) + (j>0?masu[i][j-1]:0) - (i>0&&j>0?masu[i-1][j-1]:0);
		}
	}

	ans = 0;
	FOR(y, 0, H) {
		FOR(x, 0, W) {
			if (masu[y][x])continue;
			ans++;
			queue<PII >Q;
			Q.push(PII(y, x));
			masu[y][x] = true;
			while (!Q.empty()) {
				int sy = Q.front().first, sx = Q.front().second;
				Q.pop();
				FOR(i, 0, 4) {
					int ty = sy + DY[i], tx = sx + DX[i];
					if (ty < 0 || ty >= H || tx < 0 || tx >= W)continue;
					if (masu[ty][tx] >= 1)continue;
					Q.push(PII(ty, tx));
					masu[ty][tx] = true;
				}

			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}
