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

/* -----  2018/09/19  Problem: yukicoder 266  / Link: http://yukicoder.me/problems/no/266  ----- */
/* ------問題------

P 君は、とあるソーシャルゲームで遊んでいます。
ゲームで使用するカードの強化と進化に関する問題です。

あるキャラクターのカードは最終形態になるまでに N 回進化します。
進化させたいカードに素材を[進化合成]することでカードは進化します。
一回進化するのに必要な素材は、そのキャラクターの未進化形態のカード一枚です。

また、カードには潜在能力があり、k 番目の進化状態のカードの潜在能力は Sk 個です。
潜在能力は、同じ進化状態のカードを素材として[強化合成]することで[覚醒]することができます。
新たに[覚醒]する潜在能力の数は、素材として使用するカードが現状で[覚醒]している潜在能力の合計数に 1 加えた数です。
ただし、[強化合成]した結果、[覚醒]している潜在能力が、その形態で[覚醒]できる最大の潜在能力を超えた場合、その最大潜在能力数になります。

進化時には、進化するカードが[覚醒]している潜在能力の数は増減しないまま、ひとつ上の形態になります。
進化の素材として使用するカードがいくらかの潜在能力を[覚醒]していても、
[進化合成]では潜在能力の新たな[覚醒]は行われないことに注意しましょう。

上記を踏まえ、ゲームにおいて入手できるのは潜在能力が[覚醒]していない未進化の形態のカードだけであるとする場合、
最終形態のカードを作成するためにはカードを最低何枚入手する必要があるか、
最終形態の[覚醒]している潜在能力の数ごとに求めてください。

-----問題ここまで----- */
/* -----解説等-----

問題文が結構わかりにくかった。
dp[level][潜在能力]:=最小枚数として適当に再帰します。

----解説ここまで---- */

int dp[11][11];
int s[11];
int f(int level, int P) {
	if (dp[level][P])return dp[level][P];
	if (s[level] < P)return INF;
	int res = INF;
	if (level)res = min(res, f(level - 1, P)) + 1;
	if (P) {
		FOR(k, 0, P) {
			int Q = P - 1 - k;
			res = min(res, f(level, k) + f(level, Q));
		}
	}

	return dp[level][P] = res;
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;
	FOR(i, 0, N + 1) {
		cin >> s[i];
	}
	dp[0][0] = 1;
	FOR(i, 0, s[N] + 1) {
		cout << f(N, i) << " \n"[i == s[N]];
	}
	return 0;
}
