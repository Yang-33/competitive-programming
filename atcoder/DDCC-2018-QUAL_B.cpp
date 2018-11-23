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

/* -----  2018/11/23  Problem: DDCC-2018-qual B / Link: __CONTEST_URL__  ----- */
/* ------問題------

写真撮影のプロの DISTO 君は, 黒い正方形のチップの写真を撮り, 下の図のように映った.
ただし, 茶色の枠の内側のみが実際の写真である. また, 緑色の矢印で指した箇所ではチップの頂点が写真の端と接しており、写真の辺を 2 等分している.
DISTO 君は, 写真をより小さな画像データに圧縮しようと思った. 圧縮後の画像データは, N×N のマス目として表される.
圧縮後の画像データの各マスの色は次のように決まる: 写真の縦と横をそれぞれ N 等分して N×N 個の領域に分割したとき, 完全に黒であるような領域に対応するマスのみが黒, そうでないマスは白である.
圧縮後の画像データを構成する N2 個のマスのうち, 黒いマスは何個あるか？

-----問題ここまで----- */
/* -----解説等-----

一般項が分かる。
思考停止OEISでも良さそう。

----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N;
	cin >> N;
	N -= 2;
	int m = N % 2 ? -1 : 1;
	ans = (2 * N*(N + m + 1) - m + 1) / 4;
	cout << ans << "\n";

	return 0;
}
