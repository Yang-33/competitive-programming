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

/* -----  2018/07/28  Problem: yukicoder 174  / Link: http://yukicoder.me/problems/no/174  ----- */
/* ------問題------

A君とB君はカードゲームが好きである．
このカードゲームでは 1 から 1000 までの整数が 1 つずつ書かれた 1000 枚のカードが存在する．
最初にA君とB君にはそれぞれ N 枚ずつカードが配られる．
ゲームはとってもとってもとっても簡単である．
ゲームは N 試合からなる．
各試合では自由にカードを 1 枚出して書かれている整数の大きい方がその試合の勝者で，出された 2 枚のカードに書かれている整数の和が得点として得られる．
試合で 1 度出したカードは 2 度使えない．
N 試合が終わった後で得られた合計得点が大きい方がこのゲームの勝者となる（同点なら勝者なし）．
カードはすでに配られた状態でA君に配られたカードは A1,A2,…,AN で，B君に配られたカードは B1,B2,…,BN ある．
A君がこのゲームで勝つ確率を計算…すると哀れすぎるので，勝ち負けはどうでもいいので，A君がこのゲームで得られる合計得点の期待値を求めて下さい．
ただし，A君もB君も小さいカードを早めに使用する癖があり，以下の様な方法で各試合に出すカードを選ぶものとする．
A君もB君も，使えるカードが 1 枚しかない場合は，必ずそのカードを出す．
A君は，使えるカードが 2 枚以上ある場合は，その中で最も小さい整数が書かれたカードを確率 PA で出し，その他のカードを選ぶ確率は全て等しい．
B君は，使えるカードが 2 枚以上ある場合は，その中で最も小さい整数が書かれたカードを確率 PB で出し，その他のカードを選ぶ確率は全て等しい．
A君も，B君も，今までのゲームの結果，現在のカードの状況等に出すカードは影響されず，それらと独立に出すカードを選ぶ．

-----問題ここまで----- */
/* -----解説等-----

まず、あるターンtにおけるithを選択する確率を求められれば嬉しい。
dp[turn][i]を考えるが、遷移が重複してしまうので厳しい。
submitを見ると3msで通している人がいるので多項式で解ける(指数はできる)のでこれを考える。

dp[x]:=ith未満のカードがx枚ある確率　とすると、
あるi以外については独立になる。遷移はO(N^2)なので全体でO(N^3)になる。
これよく考えたくなる気がするので要復習。

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;
	double PA, PB; cin >> PA >> PB;
	VI a(N), b(N);
	FOR(i, 0, N) {
		cin >> a[i];
	}
	FOR(i, 0, N) {
		cin >> b[i];
	}

	double ans = 0;

	SORT(a), SORT(b);


	auto f = [&N](double P) {
		vector<vector<double>>ret(N, vector<double>(N, 0));

		// dp[x]:=i基準としてx枚、更に小さいものが存在する確率
		// これをeach iでもとめる

		FOR(i, 0, N) {
			vector<double>dp(N, 0);
			dp[i] = 1;
			FOR(turn, 0, N) {
				if (turn == N - 1) {
					ret[turn][i] = dp[0];
					continue;
				}
				int nonMin = N - turn - 1;
				double q = (1.0 - P) / nonMin;
				FOR(x, 0, N) {
					if (x == 0) {
						ret[turn][i] = P*dp[0];
						dp[0] *= (q)*nonMin;
					}
					else {
						ret[turn][i] += q*dp[x];
						dp[x - 1] += dp[x] * (P + q*(x - 1));
						if (nonMin - x >= 0)
							dp[x] *= q*(nonMin + 1 - (x + 1));
					}
				}


			}
		}


		return ret;
	};

	vector<vector<double>>ap = f(PA);
	vector<vector<double>>bp = f(PB);
	FOR(i, 0, N) {
		FOR(j, 0, N) {
			if (a[i] > b[j]) {
				FOR(t, 0, N) {
					ans += (a[i] + b[j])*(ap[t][i] * bp[t][j]);
				}
			}
		}
	}

	cout << fixed << setprecision(10) << ans << "\n";

	return 0;
}
