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
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/06/15  Problem: AOJ 1194 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1194  ----- */
/* ------問題------

C氏はバンパイアである．太陽の光を直接浴びると灰になってしまうのだが，昨夜， 不死者と死人のプログラマー同好会(ICPC)に参加していたら，帰宅が夜明けに近い時間になってしまった． 幸いなことに，C氏の自宅周辺には背の高いビルが多く，太陽の光がビルにさえぎられている間は安全に動き回ることができる． いま太陽の上端が地平線にかかったところだが，C氏が安全に棺桶に入るまでにあと何秒の猶予があるだろうか?
簡単のため，東の空をx 軸が水平，y 軸が垂直方向の2次元 x-y 平面で表し，建物のシルエットはこの平面上の長方形， 太陽は円で近似するものとする．
x 軸が地平線を表す．時刻をt で表し，現在の時刻をt=0とする．太陽は半径 r で，時刻 t=0 における中心は (0, -r) にあり，x-y平面上を 毎秒 (0, 1) の等速直線運動を しているものとする．
太陽(境界線を含む)の全体が，シルエット(境界線を含む)および地平線以下の領域(y ≤ 0)の和集合に含まれていれば，太陽の光はさえぎられている．
太陽の光がさえぎられている最後の瞬間の時刻を計算するプログラムを書け．
次の図は，後に示す Sample Input 中の最初のデータセットに対応するシルエットの配置と 太陽の光がさえぎられている最後の瞬間 (t=0) を示す． このように，時刻 t=0 が太陽の光がさえぎられている最後の瞬間であることもありうる．

-----問題ここまで----- */
/* -----解説等-----

えーなんで昔これできなかったんや
範囲が狭いので全探索すれば低いやつがわかる。
N=0に注意する。

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, R;
	while (cin >> R >> N, N || R) {
		VI h(100, 0);
		int Base = 50;
		FOR(i, 0, N) {
			int l, r, th;
			cin >> l >> r >> th;
			FOR(x, l, r) {
				int a = Base + x;
				h[a] = max(h[a], th);
			}
		}
		double ans = INF;
		FOR(i, Base - R + 1, Base + R) {
			int H = min(h[i], h[i - 1]);
			double t = R + H - sqrt(R*R - (Base - i)*(Base - i));
			ans = min(ans, t);
		}

		cout << fixed << setprecision(4) << ans << endl;
	}

	return 0;
}