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

/* -----  2018/06/10  Problem: AOJ 1193 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1193  ----- */
/* ------問題------

皆さんはあるパズルに取り組んでいる． このパズルには，下図に示すような，H 行，5 列のセルからなる，直立した盤を使う． 各セルには1から9までの数字が1つ刻まれた石が配置されている． 3個以上の水平に隣り合うセルに同じ数字を彫った石があれば，これらの石は消滅する． 石が消滅したセルの上方のセルに石があれば，それらは順次落ちて空きを埋める．
パズルは以下のステップに従って進行する．

3個以上の水平に隣り合うセルに同じ数字を彫った石があれば，これらの石は消滅する．こうした石群の消滅はすべて同時に起きる．
石が消滅したセルの上方のセルに石があれば，空きを埋めるように石が落下する．
すべての石の落下完了後に，消滅の条件を満たすようになった石群があれば，ステップ1に戻って繰り返す．
このパズルのスコアは消滅した石の数字の合計である．

与えられた石の配置で獲得できるスコアを計算するプログラムを作れ．

-----問題ここまで----- */
/* -----解説等-----

頑張るしかない

----解説ここまで---- */
template<class T> using V = vector<T>; template<class T> using VV = V<V<T>>;

void solve() {
	LL H;
	while (cin >> H, H) {
		//V<string>vs(H);
		VV<int> vs(H, V<int>(5));
		FOR(i, 0, H) {
			FOR(j, 0, 5) {
				cin >> vs[i][j];
			}
		}
		// 下から見ることに注意

		LL ans = 0;
		int update = 1;
		while (update) {
			update = 0;
			for (int i = H - 1; i >= 0; i--) {
				FOR(j, 0, 3) {
					int k = j;
					if (vs[i][j]) {
						while (k + 1 < 5 && vs[i][j] == vs[i][k + 1]) {
							k++;
						}
						// 計算して消す		
						if (k - j >= 2) {
							ans += (k - j + 1)*vs[i][j];
							FOR(x, j, k + 1) {
								vs[i][x] = 0;
							}
						}
					}
				}
			}
			for (int i = H - 1; i >= 0; i--) {
				FOR(j, 0, 5) {
					if (vs[i][j] == 0) {
						// swapでよかった
						for (int k = i - 1; k >= 0; k--) {
							if (vs[k][j]) {
								vs[i][j] = vs[k][j];
								vs[k][j] = 0;
								update = 1;
								break;
							}
						}
					}
				}
			}
		}
		cout << ans << endl;
	}

}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	solve();

	return 0;
}