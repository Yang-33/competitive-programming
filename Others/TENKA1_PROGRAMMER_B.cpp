#include "bits/stdc++.h"
using namespace std;

using VS = vector<string>;    using LL = long long;
using VI = vector<int>;       using VVI = vector<VI>;
using PII = pair<int, int>;   using PLL = pair<LL, LL>;
using VL = vector<LL>;        using VVL = vector<VL>;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define EB emplace_back
#define MP make_pair
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

/* -----  2017/10/04  Problem: Nagoya_univ_contest_17_c  / Link: https://abc074.contest.atcoder.jp/tasks/abc074_b  ----- */
/* ------問題------

xy 平面上に N 個のボールがあります。このうち i 番目のボールの位置は (xi,i) です。 したがって、N 本の直線 y=1, y=2, …, y=N の上にそれぞれ 1 個ずつボールがあることになります。
すぬけ君は、これらのボールを回収するために、タイプ A, B のロボットを N 台ずつ用意しました。 さらに、タイプ A のロボットのうち i 台目のものを位置 (0,i) に、タイプ B のロボットのうち i 台目のものを位置 (K,i) に設置しました。 したがって、N 本の直線 y=1, y=2, …, y=N の上にそれぞれ 1 台のタイプ A のロボットと、1 台のタイプ B のロボットが設置されたことになります。
それぞれのタイプのロボットは起動されると以下のように動作します。
タイプ A のロボットは、位置 (0,a) で起動されると、直線 y=a 上にあるボールの位置まで移動し、ボールを回収してもとの位置 (0,a) に戻って停止する。そのようなボールが存在しない場合は何もせずに停止する。
タイプ B のロボットは、位置 (K,b) で起動されると、直線 y=b 上にあるボールの位置まで移動し、ボールを回収してもとの位置 (K,b) に戻って停止する。そのようなボールが存在しない場合は何もせずに停止する。
これら 2N 台のロボットのうちいくつかを起動してボールをすべて回収するとき、ロボットの移動距離の総和として考えられる値のうち最小のものを求めてください。

-----問題ここまで----- */
/* -----解説等-----

各y座標について、x=0かx=Kからその点に対して移動して帰ってくる。
短い方をとればよい。

----解説ここまで---- */

LL N,K;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N>>K;
	FOR(i, 0, N) {
		int x; cin >> x;
		ans += min((int)abs(K-x),(int)x);
	}
	ans *= 2;
	cout << ans << "\n";

	return 0;
}