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

/* -----  2018/04/23  Problem: yukicoder 105  / Link: http://yukicoder.me/problems/no/105  ----- */
/* ------問題------

毎年の六角ボルトの検査の時間がやって来ました．
あなたは締めた六角ボルトがどれぐらい緩んでしまったかを調べなくてはいけません．
調べなくてはいけない数が多く，写真を画像解析し，六角形の各頂点の座標 (Xk,Yk), k=1,2,3,4,5,6 を割り出しました．
六角ボルトは最初は各頂点は，座標 (1,0),(12,3√2),(−12,3√2),(−1,0),(−12,−3√2),(12,−3√2) でした．
それが原点を中心に反時計回りにどれぐらいの角度だけ緩んでしまったかを求めてください．
六角ボルトはそう簡単には緩まないので，緩んだ角度は 0 度以上 50 度未満であると仮定できます．
また，画像解析した結果の座標 Xk,Yk は誤差を含んでいるかもしれませんが，その誤差は絶対誤差で 10−12 以下であると仮定できます．
ただし，6 個の頂点のうち，(Xk,Yk) がどのような順番に対応するかは不明です．
（反時計回りとは，原点中心に座標 (1,0) の点を反時計回りちょっと回転すると y 座標の値が増える方向です）

(ヒント逆三角関数を使います。誤差に注意してください。）

-----問題ここまで----- */
/* -----解説等-----

誤差1e-12、[0,50]度の間で、当てはまるものを発見したら、atan2に投げればよい。

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	FOR(i, 0, N) {
		double tx = 0, ty = 0;

		FOR(j, 0, 6) {
			double a, b; cin >> a >> b;
			if (cos(PI*50/180) + 1e-12 <= a &&-1e-12 <= b &&  b<=sin(PI*50/180) + 1e-12) {
				tx = a;
				ty = b;
			}
		}
		// 
		double ans = 0;
		ans = atan2(ty,tx)/PI * 180;

		cout << fixed << setprecision(10) << ans << "\n";
	}

	return 0;
}
