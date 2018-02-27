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

/* -----  2018/02/27  Problem: 083_arc_b / Link: https://arc083.contest.atcoder.jp/tasks/arc083_b?lang=en  ----- */
/* ------問題------

かつて存在した高橋王国には N 個の都市があり、いくつかの都市の組は道路で双方向に結ばれていました。 道路の構造は以下のようであったことがわかっています。
都市間の移動は道路を通ってのみ行われ、どの都市からどの都市へも必要なら他の都市を経由することで移動できるようになっていた。
道路の長さは道路によって異なっていたかもしれないが、全て正整数であった。
考古学者のすぬけ君は、高橋王国の遺跡で整数からなる N×N の表 A を発見しました。 すぬけ君は、この表は高橋王国における都市間の道路に沿った最短距離を表した表ではないかと考えました。
すべての u,v について、A の u 行目 v 列目の整数 Au,v が都市 u から都市 v への最短経路の長さとなるような 道路の構造が存在するかどうか判定してください。 さらに、存在する場合、そのような道路の構造のうち、存在する道路の長さの和が最小となるようなものについて、その和を求めてください。

-----問題ここまで----- */
/* -----解説等-----

-1の判定はもう一回ワーシャルフロイドをすればよさそう
最小の道路の構成は最短路を考えたとき、ある点を経由してつくられる最短路、
つまり最短路でつくられる最短路は数える必要がない。

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	VVI a(N, VI(N));
	FOR(i, 0, N) {
		FOR(j, 0, N) {
			cin >> a[i][j];
		}
	}
	VVI m_use(N, VI(N, 1));
	FOR(k, 0, N)FOR(i, 0, N)FOR(j, 0, N) {
		if (a[i][j] > a[i][k] + a[k][j]) {
			cout << -1 << endl;
			return 0;
		}
		if ((!((i==j)||(j==k)||(k==i))) &&a[i][j] == a[i][k] + a[k][j]) {
			m_use[i][j] = 0;
		}
	}
	FOR(i, 0, N) {
		FOR(j, i, N) {
			ans += m_use[i][j] * a[i][j];
		}
	}

	cout << ans << "\n";

	return 0;
}
