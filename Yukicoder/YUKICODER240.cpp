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

/* -----  2018/08/25  Problem: yukicoder 240  / Link: http://yukicoder.me/problems/no/240  ----- */
/* ------問題------

チェスのナイトが無限に広いXY座標上を散歩をする。
ナイトの移動方法で1回動くのを1歩とする。
散歩なのでせいぜい3歩が限度である。
XY座標の(0,0)をスタートして3歩以内で目標の座標に着けるか判定せよ。

※チェスのナイトは現在の位置を(x,y)とすると1回で(x-2,y-1),(x-2,y+1),(x-1,y-2),(x-1,y+2),(x+1,y-2),(x+1,y+2),(x+2,y-1),(x+2,y+1)の8カ所のいずれかに移動できる駒である。

-----問題ここまで----- */
/* -----解説等-----

3まで全部移動してみれば良い

----解説ここまで---- */

int DX[8] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int DY[8] = { -1, 1, -2, 2, -2, 2, -1, 1 };

bool f(int cnt, int x, int y, int tx, int ty) {
	if (x == tx && y == ty)return 1;
	if (cnt == 3)return 0;
	FOR(k, 0, 8) {
		int nx = DX[k] + x, ny = DY[k] + y;
		if (f(cnt + 1, nx, ny, tx, ty))return 1;
	}
	return 0;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int X, Y; cin >> X >> Y;
	cout << (f(0, 0, 0, X, Y) ? "YES" : "NO") << "\n";

	return 0;
}
