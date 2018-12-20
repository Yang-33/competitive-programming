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

/* -----  2018/12/21  Problem: codefestival2015_team_relay D / Link: __CONTEST_URL__  ----- */
/* ------問題------

二等辺三角形の形をしたピザを切って N 人に配分します。
ピザは底辺と平行な等間隔の直線で切ります。 すると各ピースの面積比は 1:3:5:… となります。 それぞれの人にいくつかのピースを配って同じ面積になるようにした時、ピザは少なくともいくつのピースに分割する必要があるか求めてください。

-----問題ここまで----- */
/* -----解説等-----

N=1はサンプルに置かないほうが悪魔的で良い気がする。
カットが必要なときは2の倍数あれば端を取る戦略でそれぞれの和が一定になる。

----解説ここまで---- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL ans = 0;
	LL N; cin >> N;
	if (N == 1)ans = 1;
	else ans = 2 * N;


	cout << ans << endl;

	return 0;
}