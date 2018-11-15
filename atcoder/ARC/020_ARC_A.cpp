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

/* -----  2018/11/15  Problem: ARC 020 A / Link: http://arc020.contest.atcoder.jp/tasks/arc020_a  ----- */
/* ------問題------

アリの Ant さんと Bug くんが石を滑らせるゲームで遊んでいます。このゲームには、まっすぐな細長い氷の板と 2 つの小さな石を使います。氷の板には 1 ミリメートルごとに −1,000 から 1,000 までの目盛りが順番についています。
はじめ 2 匹のプレイヤーは 1 つずつ石を持っています。2 匹のプレイヤーは交互に板の端から石を滑らせます。そして、最終的に滑らせた石がより 0 の目盛りに近かった方のプレイヤーがこのゲームの勝者となります。また、2 つの石の 0 の目盛りからの距離が同じ場合は引き分けとなります。
Ant さんと Bug くんのために、2 つの石のある場所の目盛りがそれぞれ与えられた時に勝敗を判定するプログラムを作ってあげて下さい。

-----問題ここまで----- */
/* -----解説等-----

近い方の勝ち

----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int A, B; cin >> A >> B;

	int adiff = abs(A);
	int bdiff = abs(B);
	if (adiff == bdiff) {
		cout << "Draw" << endl;
	}
	else if (adiff < bdiff) {
		cout << "Ant" << endl;
	}
	else {
		cout << "Bug" << endl;
	}

	return 0;
}