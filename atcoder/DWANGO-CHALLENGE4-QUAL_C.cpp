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

/* -----  2018/03/03  Problem: dwango-challenge4-qual_c / Link: https://dwacon2018-prelims.contest.atcoder.jp/tasks/dwacon2018_prelims_c?lang=en  ----- */
/* ------問題------

dwango社員のニワンゴくんはゲームが大好きです。ニワンゴくんは「なんとかトゥーン」というゲームを遊んでいます。
このゲームはチーム戦で、N 人のプレイヤーからなるAチームと、M 人のプレイヤーからなるBチームに分かれて戦闘を行います。各プレイヤーは戦闘の間、相手チームのプレイヤーに対して「攻撃」を行うことができます。あるプレイヤーからあるプレイヤーに対する攻撃が成立すると、攻撃したプレイヤーの「キル数」が 1 加算され、同時に攻撃されたプレイヤーの「デス数」が 1 加算されます。どちらのプレイヤーも攻撃の後も戦闘を継続でき、攻撃したりされたりすることが可能です。あるプレイヤーが同じプレイヤーを複数回攻撃することもありえます。しかし、同じチームのプレイヤーを攻撃することはできません。戦闘の開始時点で、すべてのプレイヤーのキル数とデス数は 0 に設定されています。
ニワンゴくんは、戦闘が終わるとその結果を記録しています。ニワンゴくんの記録は以下の様なものです。まず、Aチームのプレイヤーをキル数の多い順（同じ場合デス数の少ない順）に並べ、それらのキル数を killA=[killA1,killA2,…,killAN] 、デス数を deathA=[deathA1,deathA2,…,deathAN] とします。同様にしてBチームのプレイヤーからも数列 killB=[killB1,killB2,…,killBM] および deathB=[deathB1,deathB2,…,deathBM] を定義します。ニワンゴくんは killA と killB のみを記録します。
ニワンゴくんは、 killA と killB から必ずしも一意に deathA と deathB を復元できないことに気が付きました。与えられた killA と killB に矛盾しない deathA と deathB の組み合わせは何通りあるでしょうか？答えは非常に大きくなりうるので、 1,000,000,007(109+7) で割った余りを出力してください。

-----問題ここまで----- */
/* -----解説等-----

天啓DP?
killが同じ時はdeathが昇順になっていなければならない

この昇順みたいな条件からグループを作っておけばあとは適当なDPができる。
同じ人からもってこればよい。

DP(i):=条件を満たしているときに残りi人のdeathを割り振っていない状態の組み合わせ数

----解説ここまで---- */


LL ans = 0LL;

LL solve(VI &a, LL sumB) {
	int n = SZ(a);

	VL t(n, 0);
	t[n - 1] = 1;
	FORR(i, n - 2, 0 - 1) {
		if (a[i] == a[i + 1])t[i] = t[i + 1] + 1;
		else t[i] = 1;
	}

	VL dp(sumB + 1, 0);
	dp[sumB] = 1;
	FOR(i, 0, n) {
		FORR(j, sumB - t[i], 0 - 1) {
			dp[j] = (dp[j] + dp[j + t[i]]) % MOD;
		}
	}
	return dp[0];
}
LL N, M;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	VI killA(N);
	VI killB(M);
	LL sumA = 0, sumB = 0;
	FOR(i, 0, N) {
		cin >> killA[i];
		sumA += killA[i];
	}
	FOR(i, 0, M) {
		cin >> killB[i];
		sumB += killB[i];
	}
	ans = (solve(killA, sumB)* solve(killB, sumA)) % MOD;


	cout << ans << "\n";

	return 0;
}
