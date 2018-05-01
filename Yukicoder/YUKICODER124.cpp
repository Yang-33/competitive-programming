#include <bits/stdc++.h>
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

/* -----  2018/04/26  Problem: yukicoder 124  / Link: http://yukicoder.me/problems/no/124  ----- */
/* ------問題------

前回の門松列の傾向と対策問題で、出そうと思っていた門松列問題を当てられたので万事休すかとおもいきや、１次元列を離れ２次元グリッドに飛び出す事になりました。

ここ最近何度も出てますが「門松列」とは、「3つの竹の長さの降順で2番目が、左または右側になっているもの」、「3つの長さはすべて異なる」という条件を満たすものである。

ここで、W×Hの平面グリッドで各マスは1から9の数値が書かれたマスが与えられます。
それらのマスを現在地から1ステップごとに上下左右1マス（マンハッタン距離1)だけ進むことができます。
ただし、直近2回のいた場所と新しいマスの数値の順番が、門松列をなしてなければなりません。

つまり、 Aを到達したマスの数値の履歴としてAiをi番目に通ったマスの数値とし、
isKadomatsuSequenceを門松列かどうか判定する関数だとすると。
isKadomatsuSequence(Ai−2,Ai−1,Ai)
が、i≥3ですべてtrueになる経路にならなくてはならない。
(最初の2ステップまでは、値が3つないので門松列が成り立ってなくても良い）

左上(1,1)がスタート地点とし、右下(W,H)がゴール地点であるときに、
ゴール地点にたどり着くまでの最短ステップ数を出力してください。
この条件でゴールできなければ -1を出力してください。

-----問題ここまで----- */
/* -----解説等-----

二次元平面上でダイクストラ法、遷移のために前2回目の情報が必要なので、dist[H][W][2回前の数字][1回前の数字]で持ってやると良い。
また、このことからdist[H][W][4]でもよい。

遷移してきたから前の点の情報いらないじゃん…汗

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int W, H; cin >> W >> H;
	VVI  a(H, VI(W));
	FOR(i, 0, H) {
		FOR(j, 0, W) {
			cin >> a[i][j];
		}
	}

	int dist[102][102][10][10];
	fill(***dist, ***dist + 102 * 102 * 10 * 10, INF);
	using tp = tuple<int, int, int, int, int>;
	queue<tp>pq;
	dist[0][0][0][a[0][0]] = 0;
	pq.push(tp(0, 0, 0, 0, a[0][0])); // dist, y, x, prepre, pre
	auto f = [&](int c, int b, int a) {// 
		bool ok = 0;
		if (a<b&&b>c&&a != c)ok = 1;
		if (a > b&&b < c&&a != c)ok = 1;
		if (a == 0 || b == 0)ok = 1;
		return ok;

	};
	while (!pq.empty()) {
		int d, y, x, a_2, a_1;
		tie(d, y, x, a_2, a_1) = pq.front(); pq.pop();
		if (dist[y][x][a_2][a_1] < d)continue;
		FOR(k, 0, 4) {
			int ny = y + DY[k], nx = x + DX[k];
			if (0 <= ny&&ny < H && 0 <= nx&&nx < W) {
				if (f(a[ny][nx], a_1, a_2)) {
					//cout << a_2 << "," << a_1 << "," << a[ny][nx]<< endl;
					if (dist[ny][nx][a_1][a[ny][nx]] > dist[y][x][a_2][a_1] + 1) {
						dist[ny][nx][a_1][a[ny][nx]] = dist[y][x][a_2][a_1] + 1;
						pq.push(tp(d, ny, nx, a_1, a[ny][nx]));
					}
				}
			}
		}
	}

	int ans = INF;
	FOR(i, 1, 10) {
		FOR(j, 1, 10) {
			ans = min(ans, dist[H - 1][W - 1][i][j]);
		}
	}
	cout << (ans < INF ? ans : -1) << "\n";

	return 0;
}
