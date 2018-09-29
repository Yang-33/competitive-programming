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

/* -----  2018/09/29  Problem: yukicoder 298  / Link: http://yukicoder.me/problems/no/298  ----- */
/* ------問題------

友達同士で話をしていると,別の友達どうしが,同じ話題で話し始めることがあります。これを競プロっぽくモデル化してみましょう。
N個の友達グループがあり,これらのグループはそれぞれ数字0からN−1までの番号がつけられています。
また,これらの友達グループ同士には,合計でM個の関係があり,それぞれは整数A, B, Cで表されるとします。これは「グループAがある話題を話していると,グループBの人たちはCパーセントの確率でその話題を始める」ということを表しています。

今グループ0の人達がyukicoderについて会話を始めました。
この時,グループN−1の人達がyukicoderについて話し始める確率を求めてください。

-----問題ここまで----- */
/* -----解説等-----

むずかしい
https://yukicoder.me/submissions/57858
まず、トポロジカル順序でやろうとすると重複を削除できなくて詰む。
そこで制約をいかして2^Nのなにかを生やそうと試みる。
"グループiが話題を話すか否か"とする。
すると、適当な辺について、遷移を決定することができる。
各状態は独立(全列挙したのでそれはそう)なので、これでOK
遷移はゆっくり考えないとわからない。
結局、この生やした状態について、p[i]:=iで話さないようになる確率
を求めることができるので、あとは状態から話す確率を計算できる。

これむずかしくないですか＞

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, M; cin >> N >> M;

	using PLD = pair<LL, double>;
	vector<vector<PLD>>G(N);
	FOR(i, 0, M) {
		int a, b; double c;
		cin >> a >> b >> c;
		G[a].push_back(PLD(b, c / 100));
	}
	double ans = 0;
	FOR(state, 0, 1 << N) {
		if (state & 1 && state&(1 << (N - 1))) {
			vector<double>p(N, 1);
			FOR(i, 0, N) {
				if (state & 1 << i) {
					for (auto e : G[i]) {
						p[e.first] *= 1 - e.second;
					}
				}
			}
			double pp = 1;
			FOR(i, 1, N) {
				if (state & 1 << i) {
					pp *= 1 - p[i];
				}
				else {
					pp *= p[i];
				}
			}

			ans += pp;
		}
	}

	cout << fixed << setprecision(10) << ans << "\n";

	return 0;
}
