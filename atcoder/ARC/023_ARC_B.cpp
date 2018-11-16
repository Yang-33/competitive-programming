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

/* -----  2018/11/16  Problem: ARC 023 B / Link: http://arc023.contest.atcoder.jp/tasks/arc023_b  ----- */
/* ------問題------

高橋君は謎の人物Xに連れ去られてしまい、謎の施設に閉じ込められてしまいました。この施設の床には R 行 C 列 のマス目が書かれていて、それぞれのマスには 1 つずつ数字が書かれています。高橋君はこのマス目の 1 行目の 1 列目のマスにいます。
長い時間閉じ込められていたので、高橋君はお腹が減ってきました。謎の人物Xによると、「隣のマスに移動する」ということをちょうど D 回行った後に高橋君がいるマスに書いてある数字と同じ値段のたこ焼きを用意してくれるそうです。あるマスの「隣のマス」とは、そのマスと辺を共有するマスのことを指します。高橋君は出来るだけ値段の高いたこ焼きが食べたいと思ったので、最大でいくらのたこ焼きを食べることが出来るかを考えることにしました。

-----問題ここまで----- */
/* -----解説等-----

D以内で到達できてかつ、パリティが一致すればどのマスにも移動可能なので、
その中での最大値を取れば良い。

----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int H, W, D; cin >> H >> W >> D;
	// 到達可能な任意のパリティが一致する場所に移動可能
	VVI a(H, VI(W));
	FOR(i, 0, H) {
		FOR(j, 0, W) {
			cin >> a[i][j];
		}
	}
	int d = D & 1;
	FOR(i, 0, H) {
		FOR(j, 0, W) {
			int dist = i + j;
			int oe = (i + j) & 1;
			if (dist <= D && (oe == d))ans = max(ans, (LL)a[i][j]);
		}
	}

	
	
	cout << ans << "\n";

	return 0;
}
