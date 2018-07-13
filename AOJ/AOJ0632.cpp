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

/* -----  2018/07/23  Problem: AOJ 0632 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0632  ----- */
/* ------問題------

世界的なプログラミングコンテストが日本で開催されることになり，現在会場の設営が行われている．この会場は南北方向に N マス，東西方向に M マスのマス目状に区切られており，いくつかのマスには競技用の機材が置かれている．
このコンテストでは，選手が競技中に休憩するために，軽食や飲み物などを置いた休憩スペースを 1 箇所会場内に設けることになった．休憩スペースは南北方向または東西方向に連続した D マスでなければならない．ただし，機材の置かれたマス目に休憩スペースを設けることはできない．
会場内に休憩スペースを設ける方法は何通りあるかを求めるプログラムを作成せよ．

-----問題ここまで----- */
/* -----解説等-----

N^3が許されるので一点を角においたときを全部調べる。

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int H, W, D;
	cin >> H >> W >> D;
	VS vs(100);
	FOR(i, 0, H) {
		cin >> vs[i];
	}
	int ans = 0;
	FOR(i, 0, H) {
		FOR(j, 0, W) {
			int ok1 = 0, ok2 = 0;
			// yoko
			for (int k = 0; k < D && j + k < W; k++) {
				ok1 += (vs[i][j + k] == '.');
			}
			// tate
			for (int k = 0; k < D && i + k < H; k++) {
				ok2 += (vs[i + k][j] == '.');
			}
			ans += (ok1 == D);
			ans += (ok2 == D);
		}
	}

	cout << ans << endl;

	return 0;
}