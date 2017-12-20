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
#define debug(x) cout << #x << ": " << x << endl
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2017/12/20  Problem: AOJ 0363 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0363  ----- */
/* ------問題------

会津海上運送会社に、新たな積み荷の輸送依頼が舞い込んだ。今回依頼された荷物は、すべて同じ大きさで、横幅が２ｍ、縦幅が２ｍである。
貨物室は長方形で、横幅が４ｍで固定されているが、縦幅はさまざまである。
また、荷物は横と縦それぞれ１ｍを単位とした区画の境界に合わせて置く必要があり（５０ｃｍずらしたりなどはできない）、傾けて置いたり、重ねて置いたりすることはできない。また、荷物が置けない区画もある。
現在使える船の貨物室に荷物をできるだけ積んで輸送したいが、最大でいくつ積めるかを知りたい。
貨物室の縦の長さと、その中で荷物が置けない区画が与えられたとき、最大でいくつの荷物が積めるかを報告するプログラムを作成せよ。

-----問題ここまで----- */
/* -----解説等-----

前の列だけの情報があれば埋められるスーパー典型bitDPなため、できる
また、AOJ特有のMLE制限がアレなときは、メモリはswapする典型のアレでアレできる。

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int H; cin >> H >> N;
	VI x(N, 0);
	VI y(N, 0);
	FOR(i, 0, N) {
		cin >> x[i] >> y[i];
	}
	//VVI dp(H + 1, VI(1<<4, 0));
	VI dp(1 << 4, 0);
	VVI masu(H + 1, VI(4, 0));
	FOR(i, 0, N) {
		masu[y[i]][x[i]] = 1;
	}

	FOR(i, 0, H - 1) {
		VI next(1 << 4, 0);
		FOR(bit, 0, 1 << 4) {
			next[0] = max(next[0], dp[bit]);
			if (!masu[i][0] && !masu[i][1] && !masu[i + 1][0] && !masu[i + 1][1] &&
				(bit & 0b1100) == 0)next[0b1100] = max(next[0b1100], dp[bit] + 1);
			if (!masu[i][1] && !masu[i][2] && !masu[i + 1][1] && !masu[i + 1][2] &&
				(bit & 0b0110) == 0)next[0b0110] = max(next[0b0110], dp[bit] + 1);
			if (!masu[i][2] && !masu[i][3] && !masu[i + 1][2] && !masu[i + 1][3] &&
				(bit & 0b0011) == 0)next[0b0011] = max(next[0b0011], dp[bit] + 1);
			if (!masu[i][0] && !masu[i][1] && !masu[i + 1][0] && !masu[i + 1][1] &&
				!masu[i][2] && !masu[i][3] && !masu[i + 1][2] && !masu[i + 1][3] &&
				(bit & 0b1111) == 0)next[0b1111] = max(next[0b1111], dp[bit] + 2);
		}
		next.swap(dp);
	}
	FOR(i, 0, 1 << 4) {
		ans = max(ans, (LL)dp[i]);
	}
	cout << ans << endl;
	return 0;
}
