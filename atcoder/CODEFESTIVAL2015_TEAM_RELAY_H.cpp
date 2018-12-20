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

/* -----  2018/12/21  Problem: codefestival2015_team_relay H / Link: __CONTEST_URL__  ----- */
/* ------問題------

縦 H 行、横 W 列のマス目があり、左上のマスを (1,1) 、右下のマスを (H,W) という座標で表す。それぞれのマスには色 1 から色 9 の 9 色のうちいずれかの色が塗られている。
あなたはこのマス目に対して、9 色のうちのいずれかで「塗りつぶす」操作を何回か行うことが出来る。塗りつぶす操作とは、 (1,1) から連結している同じ色のマスを全て選んだ色に変える操作である。 2 つのマスが連結しているとは、辺を共有する同じ色のマスを通じてお互いに到達できることである。以下に塗りつぶす操作の例を示す。（図は入力例1に対応している。）
H×W のマス目の初期状態が与えられるので、 (1,1) と (H,W) を連結にするために必要な塗りつぶす操作の回数の最小値を答えよ。

-----問題ここまで----- */
/* -----解説等-----

最初よく分からなかった。ダイクストラをする。おわり

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int H, W; cin >> H >> W;
	VS vs(H);
	FOR(i, 0, H) {
		cin >> vs[i];
		FOR(j, 0, W) {
			vs[i][j] -= '0';
		}
	}

	VVI d(H, VI(W, INF));
	using tp = tuple<int, int, int>;
	priority_queue<tp, vector<tp>, greater<tp>>pq;
	pq.push(tp(0, 0, 0));
	d[0][0] = 0;
	while (!pq.empty()) {
		int dd, y, x; tie(dd, y, x) = pq.top(); pq.pop();
		if (d[y][x] > dd) continue;
		FOR(k, 0, 4) {
			int ny = y + DY[k], nx = x + DX[k];
#define IN(a,b) (0<=a&&a<b)
			if (IN(ny, H) && IN(nx, W)) {
				if (d[ny][nx] > d[y][x] + (vs[y][x] != vs[ny][nx])) {
					d[ny][nx] = d[y][x] + (vs[y][x] != vs[ny][nx]);
					pq.push(tp(d[ny][nx], ny, nx));
				}
			}
		}
	}
	cout << d[H - 1][W - 1] << endl;
}