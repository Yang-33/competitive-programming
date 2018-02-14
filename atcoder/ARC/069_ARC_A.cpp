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

/* -----  2018/02/14  Problem: 069_arc_a / Link: https://abc055.contest.atcoder.jp/tasks/arc069_a?lang=en ----- */
/* ------問題------

すぬけくんはパズルが好きです。
今日は 'S' と 'c' の形をしたピースを使ったパズルで遊んでいます。 このパズルでは図のように 'c' 型のピースを 2 つ組み合わせて 'S' 型のピースを 1 つ作ることができます。
すぬけくんは 'S' 型のピースを 1 つ、'c' 型のピースを 2 つ組み合わせて 'Scc' という組を可能な限り多く作ることにしました。
すぬけくんが N 個の 'S' 型のピースと M 個の 'c' 型のピースを持っているとき、'Scc' という組を最大でいくつ作ることが可能か求めなさい。


-----問題ここまで----- */
/* -----解説等-----

Sが多いときはC/2で、
Cが多いときはSCCを作った後、C4個でSCCを作成すれば良い。

----解説ここまで---- */

LL N,M;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N>>M;
	if (2 * N <= M) {
		ans = N;
		M -= 2 * N;
	}
	else {
		ans = M / 2;
		M = 0;
	}
	if (M > 0) {
		ans += M / 4;
	}
	cout << ans << "\n";

	return 0;
}
