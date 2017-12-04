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

/* -----  2017/12/04  Problem: codefestival2017_team_relay A / Link: https://cf17-relay-open.contest.atcoder.jp/tasks/relay2_a  ----- */
/* ------問題------

ButCoder株式会社 は、プログラミングコンテストサイト「ButCoder」を運営しています。このサイトでは、ユーザーにはレーティングという技量を表す整数値が与えられ、その値はユーザーがコンテストに参加するたびに変動します。新規ユーザーのレーティングの初期値は 0 であり、レーティングが K 以上に達したユーザーは 皆伝 と呼ばれます。なお、レーティングは負になることもあります。
低橋くんというユーザーが ButCoder に新たに登録しました。彼のレーティングは、彼が奇数回目に参加するコンテスト（1 回目、3 回目、5 回目…）では毎回 A 増加し、偶数回目に参加するコンテスト（2 回目、4 回目、6 回目…）では毎回 B 減少することが予測されます。
この予測によると、彼が初めて皆伝になるのは何回のコンテストに参加した直後でしょうか、もしくは彼は永遠に皆伝になれないでしょうか？

-----問題ここまで----- */
/* -----解説等-----

最初だけで達成されてしまうのが場合分けの対象で、あとは適当にかさ増ししてやればよい。

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL K, A, B;
	cin >> K >> A >> B;
	if (A <= B) {
		if (K <= A) { cout << 1 << endl; }
		else cout << -1 << endl;
	}
	else {
		ans = 2 * (K / abs(A - B)) - 100;
		LL taka = abs(A - B)*(ans / 2);
		while (taka < K) {
			taka += A; ans++;
			if (taka >= K)break;
			taka -= B; ans++;
		}
		cout << ans << "\n";
	}

	return 0;
}
