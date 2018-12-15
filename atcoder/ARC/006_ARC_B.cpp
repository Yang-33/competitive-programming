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

/* -----  2018/12/15  Problem: ARC 006 B / Link: http://arc006.contest.atcoder.jp/tasks/arc006_b  ----- */
/* ------問題------

　高橋君は学校で班のリーダーを決めなければいけなくなったので、あみだくじを用いて決めることにしました。
 　あみだくじとは、複数の縦線から 1 本を選び、その上端から下端へと辿っていき、途中で横線があれば、その横線を通り繋がっている隣接する縦線へと移動し、また下へと進みます。
  　今日はたまたま手元に紙がなかったので、パソコン上で |、-、o を用いて以下のようなあみだくじを作りました。
   | | | | | | | | |
   |-| | |-| | |-| |
   | | |-| | |-| | |
   | |-| | | | | |-|
   | | | |-| | | |-|
   | | |-| |-| | | |
   |-| | |-| | |-| |
   | | | | | |-| | |
   o
   　o がある位置に到達した人がリーダーになります。
	　実は高橋君はリーダーになりたかったので、どの縦線を選べば o に辿り着くのか知りたいです。

	 　左から何番目の縦線を選べばリーダーになれるのかを求めなさい。

-----問題ここまで----- */
/* -----解説等-----

シュミレーションすればよい。

----解説ここまで---- */

LL ans = 0LL;

int main() {
	LL N, L; cin >> N >> L;
	cin.ignore();
	VS vs(L);
	FOR(i, 0, L) {
		getline(cin, vs[i]);
	}
	string tar; getline(cin, tar);
	int pos = -1;
	FOR(i, 0, SZ(tar)) {
		if (tar[2 * i] == 'o')pos = 2 * i;
	}

	FORR(y, L - 1, 0 - 1) {
		DD(de(pos, SZ(vs[y]), y, vs[y][pos - 1], vs[y][pos], vs[y][pos + 1]));
		if (pos&&vs[y][pos - 1] == '-') {
			pos -= 2;
		}
		else if (vs[y][pos + 1] == '-') {
			pos += 2;
		}
	}

	ans = pos / 2 + 1;


	cout << ans << "\n";

	return 0;
}
