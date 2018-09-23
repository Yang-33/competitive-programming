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

/* -----  2018/09/19  Problem: yukicoder 268  / Link: http://yukicoder.me/problems/no/268  ----- */
/* ------問題------

yuki君は友人に渡すプレゼント入れた箱をリボンでラッピングすることにした。
プレゼントはとても重いので、念のため箱にはリボンを何周も巻こうと考えている。

yuki君は直方体の箱を以下のようにラッピングする。
- 赤いリボンは、直方体のうち上・奥・下・手前の4面をR周するように巻く。
- 青いリボンは、直方体のうち上・左・下・右の4面をB周するように巻く。
- 黄色いリボンは、直方体のうち手前・右・奥・左の4面をY周するように巻く。

各リボンは直方体の辺の中点を通り、かつたわみの無いように巻くことにする。リボンは非常に薄いため、厚さは無視してよい。
下記の図はラッピングの例を示している。


箱の向きは自由に回転できる。
箱の３辺の長さとリボンを巻く回数が与えられるとき、ラッピングに必要な３色のリボンの長さの和の最小値を答えよ。

---- - 問題ここまで---- - */
/* -----解説等-----

3!試せば良さそう。

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N = 3;
	VI a(N);
	FOR(i, 0, N) {
		cin >> a[i];
	}
	VI b(N);
	FOR(i, 0, N) {
		b[i] = 2 * (a[i] + a[(i + 1) % 3]);
	}
	VI roll(N);
	FOR(i, 0, N) {
		cin >> roll[i];
	}
	LL ans = LINF;
	VI order(N);
	FOR(i, 0, N) {
		order[i] = i;
	}

	do {
		LL ret = 0;
		FOR(i, 0, N) {
			ret += b[order[i]] * roll[i];
		}
		ans = min(ans, ret);
	} while (next_permutation(ALL(order)));

	cout << ans << endl;


	return 0;
}