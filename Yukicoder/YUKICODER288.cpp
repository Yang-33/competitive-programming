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

/* -----  2018/09/27  Problem: yukicoder 288  / Link: http://yukicoder.me/problems/no/288  ----- */
/* ------問題------

貯金箱さんは A 国に住んでいます．この国では通貨の単位は円と呼ばれ，A1 円玉，A2 円玉，…，AN 円玉の，N 種類の硬貨が使われています．
貯金箱さんは硬貨を貯めに貯めて，どの硬貨も 10100 枚持っています．あるとき，ゆきうさぎさんが現れ，M 円の貯金をしたいと言いました．ゆきうさぎさんは，今，A1 円玉を K1 枚，A2 円玉を K2 枚，…，AN 円玉を KN 枚持っています．貯金箱さんは，貯金後にゆきうさぎさんが持っていることになる硬貨の枚数を最小にしてあげようと思いました．このために，ゆきうさぎさんに一旦多めに貯金してもらってからお釣りを返すという方法をとることにしました．正確には，非負整数 x を選び，まずゆきうさぎさんが貯金箱さんに M+x 円を硬貨でちょうど支払ってから，貯金箱さんがゆきうさぎさんに x 円を硬貨でちょうど支払います．
貯金後にゆきうさぎさんの持っていることになる硬貨の枚数の最小値をプログラムを求めてください．ただし，ちょうど M 円を貯金することが不可能ならば，それを指摘してください．

-----問題ここまで----- */
/* -----解説等-----

これすき
まず全部払う。(←これよい…)
すると、sum-M円を貯金箱さんが払う問題になる。
したがってこの問題はこの値が小さいときは適当なDPで解けることがわかる。
大きい時を考える。ある適当な組み合わせで支払えていたとすると、a.back()以外の値A'について、
これはa.back()枚以上払っていることになる。
これは、a.back()で代用できるため、交換すれば最小枚数に近づく事ができる。
以上のことから、a.back()*a.back()枚以上の支払いは、a.back()で代用できるため、それ以下の数字のみをやれば良い。

貯金箱の問題は毎回良い問題が多くて勉強になる…

解説を見た
鳩ノ巣原理っぽくもみれるらしい(よくわかってない)

----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, M; cin >> N >> M;
	VL a(N);
	FOR(i, 0, N) {
		cin >> a[i];
	}
	VL k(N);
	FOR(i, 0, N) {
		cin >> k[i];
	}
	LL sum = 0;
	FOR(i, 0, N) {
		sum += a[i] * k[i];
	}
	if (sum < M) {
		ans = -1;
	}
	else {
		// 全額払うと、適当に最小化してくれる
		// そのdpをすればよい
		int upper = a.back()*a.back();
		LL Pay = sum - M;
		// Payを払うための最小枚数を求める
		LL cnt = max(0LL,(Pay - upper+ a.back()) / a.back());
		Pay -= cnt * a.back();
		ans += cnt;
		// ここでDP
		VL dp(upper + 1, LINF);
		dp[0] = 0;
		FOR(i, 0, N) {
			FOR(u, 0, upper + 1 - a[i]) {
				dp[u+a[i]] = min(dp[u+a[i]], dp[u]+1);
			}
		}
		if (dp[Pay] == LINF)ans = -1;
		else ans += dp[Pay];
	}

	cout << ans << "\n";

	return 0;
}
