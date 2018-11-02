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

/* -----  2018/11/03  Problem: ARC 028 A / Link: http://arc028.contest.atcoder.jp/tasks/arc028_a  ----- */
/* ------問題------

アリの Ant さんと Bug くんは小石を取るゲームをしています。このゲームのルールは以下の通りです。

最初、N 個の小石が袋に入っています。
Ant さん、Bug さん、Ant さん・・・の順番で交互に袋から小石を取っていきます。
Ant さんは１回につきちょうど A 個の小石を取ります。ただし、袋の中の小石が A 個未満である場合は、袋の中の全ての小石だけを取ります。
Bug くんは１回につきちょうど B 個の小石を取ります。ただし、袋の中の小石が B 個未満である場合は、袋の中の全ての小石だけを取ります。
自分のターンで袋を空にすると勝ちとなります。
Ant さんはどちらがこのゲームに勝つかを計算してみることにしました。

-----問題ここまで----- */
/* -----解説等-----

やっていく

----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; cin >> N;
	VI a(2); FOR(i, 0, 2)cin >> a[i];
	for (;;) {
		FOR(i, 0, 2) {
			if (N > a[i])N -= a[i];
			else {
				ans = i;
				goto EEE;
			}
		}
	}
EEE:;
	cout << (ans == 0 ? "Ant" : "Bug") << "\n";

	return 0;
}