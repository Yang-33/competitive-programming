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

/* -----  2018/10/28  Problem: ARC 030 A / Link: http://arc030.contest.atcoder.jp/tasks/arc030_a  ----- */
/* ------問題------

このグラフは，頂点 1 と頂点 2を結ぶ辺，頂点 2 と頂点 3，...，頂点 n−1 と頂点 n，そして頂点 n と頂点 1 を結ぶ辺から構成されています．
あなたは，このグラフからいくつかの頂点を取り除く(*)ことでグラフを分断し最終的に k 個の連結成分のみが残ったグラフにしたいと思っています． 実際に頂点を取り除き始める前に，そのような取り除き方が本当に存在するかどうかを判定してください．
(*) ある頂点を取り除くと，その頂点に直接繋がっている辺も取り除かれます．また，必要がなければ 1 つも頂点を取り除かなくても構いません．

-----問題ここまで----- */
/* -----解説等-----

1回で必ず1個頂点を消費するので、1..N/2個までは可能。

----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, K; cin >> N >> K;
	if (N >= 2 * K) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}

	return 0;
}
