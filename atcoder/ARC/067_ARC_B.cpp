#include <bits/stdc++.h>
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

/* -----  2018/02/27  Problem: 067_arc_b / Link: https://abc052.contest.atcoder.jp/tasks/arc067_b?lang=en  ----- */
/* ------問題------

東西方向にのびる直線上に、N 個の町があります。 町には、西から順に 1 から N までの番号がついています。 直線上には座標が設定されていて、東に行くほど座標が大きくなります。 町 i の座標は Xi です。
あなたは今、町 1 にいて、これからほかの全ての町を訪れたいです。 移動する手段は次の 2 種類あります。
直線上を歩いて移動する。 東西どちらに歩いても、1 移動する度に疲労度が A 上がります。
好きな場所へテレポートする。 テレポートをすると、移動した距離によらず疲労度が B 上がります。
この 2 種類の移動を繰り返して全ての町を最適に回った時、疲労度の上昇値の合計の最小値がいくつになるか求めてください。

-----問題ここまで----- */
/* -----解説等-----

サンプルに答えが書いてある問題
総移動距離は一緒なので隣に移動していくとして、
最適なほうを取っていけば良い。

----解説ここまで---- */

LL N,A,B;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N>>A>>B;
	VL a(N);
	FOR(i, 0, N) {
		cin >> a[i];
	}
	FOR(i, 0, N - 1) {
		LL val = (a[i + 1] - a[i])*A;
		ans += min(val, B);
	}

	cout << ans << "\n";

	return 0;
}
