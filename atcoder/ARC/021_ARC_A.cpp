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

/* -----  2018/11/15  Problem: ARC 021 A / Link: http://arc021.contest.atcoder.jp/tasks/arc021_a  ----- */
/* ------問題------

あなたは友人の高橋君からとあるゲームを熱烈にオススメされている。
このゲームは 4×4 のグリッド状に区切られた 16 個のセルと、その上に置かれた数が書かれたタイルを使ってプレーする。1 回の操作では上下左右の 4 方向のうちいずれかを指定することができ、指定した方向に向かってセル上のタイルが滑っていく。このとき、同じ数の書かれたタイル 2 枚がぶつかるとその 2 枚はグリッド上から取り除かれ、代わりに数を 2 倍した別のタイルが 1 枚新たに置かれる。
次の図は盤面の状態と、そこから右に向かって 1 回操作を行った後の盤面の例である。

-----問題ここまで----- */
/* -----解説等-----

隣接を見ればよいです

----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N = 4;
	VVI a(N, VI(4, 0));
	FOR(i, 0, 4) {
		FOR(j, 0, 4) {
			cin >> a[i][j];
		}
	}
	// 隣接を見れば良い
	auto in = [](int a, int b, int c) {
		return a <= b && b < c;
	};
	ans = 0;
	FOR(i, 0, N) {
		FOR(j, 0, N) {
			FOR(k, 0, 4) {
				int ni = i + DY[k];
				int nj = j + DX[k];
				if (in(0, ni, N) && in(0, nj, N)) {
					if (a[i][j] == a[ni][nj])ans = 1;
				}
			}
		}
	}

	cout << (ans ? "CONTINUE" : "GAMEOVER") << "\n";

	return 0;
}