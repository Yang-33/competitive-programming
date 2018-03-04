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

/* -----  2018/03/03  Problem: colocon-2018-qual_d / Link: https://colopl2018-qual.contest.atcoder.jp/tasks/colopl2018_qual_d?lang=en  ----- */
/* ------問題------

あなたは、「すぬけそだて」を楽しんでいます。愛しのすぬけ君をできるだけ賢いねこにしたいあなたは、すぬけ君の知力トレーニングをすることにしました。
「すぬけそだて」では、あなたは「スタミナ」を消費してすぬけ君の知力をトレーニングすることができます。スタミナを 1 消費するごとに、すぬけ君の知力は 1 だけ上がります。
スタミナは、1 単位時間に 1 だけ、最大で X まで回復します。スタミナが上限 X に達している場合、時間経過でスタミナが回復することはありません。 また、スタミナを 0 未満にすることはできません。初期状態、すなわち時刻 O において、スタミナは満タンに、すなわち X だけ溜まっています。
もちろん、スタミナが溜まったらすぐに消費するのが最も効率的なのですが、残念なことにあなたには現実世界での用事があり、 四六時中「すぬけそだて」を遊んでいるというわけにはいきません(現実の生活というのは、往々にして融通の利かないものです)。
それでも、あなたは多忙な生活の合間を縫って、「すぬけそだて」を起動できる時間の候補を N 個ひねり出しました。i 個目の候補は時刻 Ti です。 あなたは多忙なため、一度ゲームを起動したら、一瞬のうちにスタミナの消費を終えてゲームを終了しなければなりません。 すなわち、時刻 Ti にスタミナが s だけ残っていた場合、あなたはスタミナを s 以下の任意の非負整数量消費し、消費した分だけすぬけ君の知力を上げる操作をすることができますが、 それ以外の操作はできません。
現実の予定というのはなかなか決まらないもので、あなたは自分がこれから先しばらくどれほど忙しいのかを読み切れずにいます。そこで、各 K=1,2,…,N について、 N 個のゲームの起動時刻の候補のうち K 個以下を選んでゲームを起動する場合に、最終的にすぬけ君の知力が最大でいくつになるのかを計算することにしました。 これらの N 個の値をすべて求めてください。

-----問題ここまで----- */
/* -----解説等-----

ソシャゲやってないけどソシャゲ脳する
dp(i,j):=i番目までの時間で、j回ゲームをしたときに得られる最大知力
この時愚直な更新はO(N^3)だが、ソシャゲ脳的には、Xをこえる一歩手前と一歩後をみればよい。

----解説ここまで---- */

LL N, X;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> X;
	VI t(N);
	FOR(i, 0, N) {
		cin >> t[i];
	}
	VVL dp(N + 1, VL(N + 1, -LINF));

	dp[0][1] = X;
	FOR(i, 0, N) {
		{ // 溜まるギリギリ
			int nxt = -1;
			FOR(j, i + 1, N) {
				if (t[j] - t[i] <= X)nxt = j;
			}
			if (nxt != -1) {
				FOR(j, 0, N) {
					dp[nxt][j + 1] = max(dp[nxt][j + 1], dp[i][j] + t[nxt] - t[i]);
				}
			}
		}
		{ // 溜まったギリギリ
			int nxt = -1;
			FORR(j, N-1, i) {
				if (t[j] - t[i] >= X)nxt = j;
			}
			if (nxt != -1) {
				FOR(j, 0, N) {
					dp[nxt][j + 1] = max(dp[nxt][j + 1], dp[i][j] +X);
				}
			}
		}
	}
	FOR(k, 1, N + 1) {
		FOR(i, 0, N) {
			ans = max(ans, dp[i][k]);
		}
		cout << ans << "\n";
	}


	return 0;
}
