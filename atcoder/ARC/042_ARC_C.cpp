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

/* -----  2018/10/06  Problem: ARC 042 C / Link: http://arc042.contest.atcoder.jp/tasks/arc042_c  ----- */
/* ------問題------

高橋くんは遠足に持って行くおやつを選んでいます。 この遠足には合計で P 円までのおやつを持って行くことができます。 ただし、担任のけんしょう先生はやさしいので、どの 1 つのおやつについても、そのおやつがなければ合計が P 円以下になるのであれば許してくれます。
例えば、100 円まで持って行くことができる時に、値段がそれぞれ 30 円、40 円、50 円のおやつを持って行くと、どの 1 つのおやつを取り除いても合計が 100 円以下になるので許してくれます。 しかし、40 円、50 円、60円のおやつを持って行くと、40 円のおやつがなかったとしても合計は 110 円となり 100 円を超えているので、やさしいけんしょう先生もこれは許してくれません。
高橋くんが持って行きたいおやつは N 種類あり、それぞれに値段と満足度があります。 高橋くんはそれぞれの種類のおやつについて最大でも 1 つしか遠足に持って行きません。 けんしょう先生が許してくれるおやつの選び方のうち、満足度の合計が最も大きくなるように選んだ時の満足度の合計を求めてください。

-----問題ここまで----- */
/* -----解説等-----

最後にi番目のもので蓋をするイメージをすると、O(N^2P)のDPができそう。
これだと間に合わないのでいい感じの順番を定めるのが良さそう。
和がP以下の集合に最後に一番小さいもので蓋をするとすると、矛盾が生じなくなる。
よって降順に並べてDPをすれば矛盾のないDPをO(NP)でできる。

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, P; cin >> N >> P;
	vector<PII>s(N);
	FOR(i, 0, N) {
		cin >> s[i].first >> s[i].second;
	}
	SORT(s);
	VI dp(P + 200, 0); // 満足度の最大値

	int ans = 0;
	// 超えている状態からaddみたいなのを防げば良い
	FORR(i, N - 1, 0 - 1) {
		FORR(p, P, 0 - 1) {
			if (dp[p] || !p) {
				int Okane = p + s[i].first;
				dp[Okane] = max(dp[Okane], dp[p] + s[i].second);
			}
		}
	}
	FOR(i, 0, P + 101) {
		ans = max(ans, dp[i]);
	}


	cout << ans << "\n";

	return 0;
}