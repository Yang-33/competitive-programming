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
#define DEBUG(x) 
#endif
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/10/19  Problem: ARC 038 A / Link: http://arc038.contest.atcoder.jp/tasks/arc038_a  ----- */
/* ------問題------

N 枚のカードがあり、i(1≦i≦N) 枚目のカードには整数 Ai が書かれています。ゲーム好きの兄妹はこれらのカードを使ってゲームをしようとしています。

最初に全てのカードを、カードに書かれた整数が見えるようにテーブルの上に並べる。
プレイヤーは自分のターンに、テーブルの上にあるカードからちょうど 1 枚のカードを選んで取る。
テーブルの上にカードがなくなるまで、交互にターンを繰り返す。
最終的に、自分が取ったカードに書かれた整数の和がプレイヤーの スコア となる。
2 人ともが自分のスコアを出来るだけ大きくしようとしたとき、先手のスコアはいくつになるでしょうか？

-----問題ここまで----- */
/* -----解説等-----



----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N;
	cin >> N;
	VL a(N);
	FOR(i, 0, N)cin >> a[i];
	RSORT(a);
	FOR(i, 0, N) {
		if (i % 2 == 0)ans += a[i];
	}

	cout << ans << "\n";

	return 0;
}