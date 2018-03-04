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

/* -----  2018/03/03  Problem: dwango-challenge3-final_a / Link: https://dwacon2017-honsen.contest.atcoder.jp/tasks/dwango2017final_a?lang=en  ----- */
/* ------問題------

ニコニコテレビちゃんは、頭の体操として簡単な計算をすることにしました。 ところでニコニコテレビちゃんは人間ではないので、逆ポーランド記法で計算をします。
具体的には、0 ~ 9, -, + からなる文字列 S について、以下の規則に従い計算をします。

まず、最初の時点では空の、無限に長いスタックを 1 つ持っていると考える。そして、S の文字を前から見ていく。
もし0 ~ 9が出てきたら、そのままスタックへ積む。
もし+が出てきたら、スタックから1個取り出し a、もう1個取り出し b とする。そして b+a をスタックへ積む。
もし-が出てきたら、スタックから1個取り出し a、もう1個取り出し b とする。そして b−a をスタックへ積む。
最後に、スタックの中身が 1 個ならばそれが答えである
もし 1 個ではなかったり、途中で取り出そうとしたがスタックが空だったりした場合は S は正しい式ではない。
ニコニコテレビちゃんは、適当に文字列 S を書きました。 これに対してただ計算するだけではつまらないので、以下の問題を解くことにしました。

この文字列を K 文字まで書き換えて、正しい式にできるか？また、出来るならば正しい式のうち、計算した答えの最大値はいくつか？
しかしこれは難しすぎたので、あなたが代わりに解いて助けてあげてください。

-----問題ここまで----- */
/* -----解説等-----

したいことを書くと区間DPで、これを頑張って書く
状態はL，R以外にあと何回書き換えることができるかのみで、dp[L][R][K][0/1]:=最小値と最大値
として区間DPをそのまま書けば良い

----解説ここまで---- */

LL N, K;

LL ans = 0LL;

int dp[54][54][54][2];
bool memo[54][54][54];

void f(int L, int R, int k, string &s) {
	if (memo[L][R][k])return;
	memo[L][R][k] = 1;

	dp[L][R][k][0] = -INF;
	dp[L][R][k][1] = INF;


	if (L == R) {
		if (k > 0) {// opt
			dp[L][R][k][0] = max(dp[L][R][k][0], 9);
			dp[L][R][k][1] = min(dp[L][R][k][1], 0);
		}
		if (isdigit(s[L])) { //埋め込む
			dp[L][R][k][0] = max(dp[L][R][k][0], s[L] - '0');
			dp[L][R][k][1] = min(dp[L][R][k][1], s[L] - '0');
		}
	}

	{// +
		int left = k;
		if (s[R] != '+')left--;
		FOR(i, L, R) {
			FOR(j, 0, left + 1) {
				f(L, i, j, s);
				f(i + 1, R - 1, left - j, s);
				if (dp[L][i][j][0] > -INF && dp[i + 1][R - 1][left - j][0] > -INF) {
					
					dp[L][R][k][0] = max(dp[L][R][k][0],
						dp[L][i][j][0] + dp[i + 1][R - 1][left - j][0]);
					
					dp[L][R][k][1] = min(dp[L][R][k][1],
						dp[L][i][j][1] + dp[i + 1][R - 1][left - j][1]);
				}

			}
		}
	}

	{ // -
		int left = k;
		if (s[R] != '-')left--;
		FOR(i, L, R) {
			FOR(j, 0, left + 1) {
				f(L, i, j, s);
				f(i + 1, R - 1, left - j, s);
				if (dp[L][i][j][0] > -INF && dp[i + 1][R - 1][left - j][0] > -INF) {
					
					dp[L][R][k][0] = max(dp[L][R][k][0],
						dp[L][i][j][0] - dp[i + 1][R - 1][left - j][1]);
					
					dp[L][R][k][1] = min(dp[L][R][k][1],
						dp[L][i][j][1] - dp[i + 1][R - 1][left - j][0]);
				}

			}
		}
	}

}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> K;
	string s; cin >> s;
	N = SZ(s);
	f(0, N - 1, K, s);
	if (dp[0][N - 1][K][0] == -INF) {
		cout << "NG" << endl;
	}
	else {
		cout << "OK" << endl;
		cout << dp[0][N - 1][K][0] << "\n";
	}


	return 0;
}
