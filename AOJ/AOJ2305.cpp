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

/* -----  2018/06/23  Problem: AOJ 2305 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2305  ----- */
/* ------問題------

列aが与えられる。
これをいくつか適当に変更して、a[i]はj<iなjについてa[j]の倍数であるようにしたい。
この際変更点を (pre-new)/preとする。
変更点の最大値を最小化せよ。

-----問題ここまで----- */
/* -----解説等-----

最後までわからないので、明らかにDP。
連続性から、dp[i][state]:=ithまでみたときにithをstateにするときの最大値の最小値
とする。i-2とかは見る必要がない。(そろっているので)

調和級数まで一瞬だったけど、コードを書かずにもう一個MAXがつくと思ってしまった。
まずはコードを書いてみても良かったんじゃないでしょうか…(正答の計算量間違い)

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	VI a(N);
	FOR(i, 0, N) {
		cin >> a[i];
	}
	vector<double>dp(2e5, INF);
	FOR(i, 1, 2e5) {
		dp[i] = fabs(a[0] - i) / a[0];
	}
	FOR(i, 1, N) {
		vector<double>nx(2e5,INF);
		FOR(state, 1, 2e5) {
			if (dp[state] != INF) {
				for (int x = state; x < 2e5; x += state) {
					nx[x] = min(nx[x], max(dp[state], fabs(a[i] - x) / a[i]));
				}
			}
		}
		dp.swap(nx);
	}
	double ans = LINF;
	FOR(i, 0, 2e5) {
		ans = min(ans, dp[i]);
	}
	cout << fixed << setprecision(10) << ans << endl;


	return 0;
}

