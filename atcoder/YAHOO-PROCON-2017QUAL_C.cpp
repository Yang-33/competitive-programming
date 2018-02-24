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

/* -----  2018/02/23  Problem: yahoo-procon-qual_c / Link: https://yahoo-procon2017-final-open.contest.atcoder.jp/tasks/yahoo_procon2017_final_a  ----- */
/* ------問題------

高橋君は，文字列 S を持っています． 高橋君は yahoo という文字列が好きなので，S を編集することで yahoo の繰り返しで得られる文字列に変えようとしています． ここで，yahoo の繰り返しで得られる文字列とは，yahoo を 0 個以上つなげてできる文字列です．これらは，短いほうから順に (空文字列)，yahoo，yahooyahoo，… となります．
高橋君は 1 回の操作で次のうちいずれかを行うことができます．
S の任意の 1 文字を選んで，それを任意の英小文字に書き換える．
S の任意の 1 文字を選んで，その文字を S から取り除く．
S の任意の位置に，任意の英小文字を挿入する．
高橋君が S を yahoo の繰り返しで得られる文字列にするために，必要な操作の回数の最小値を求めてください．

-----問題ここまで----- */
/* -----解説等-----

まに合わないなあと思うけどDP配列を使いまわせて、
dp[i][j]: S[1..i] を YahooYahoo…YahooYahoo （最後はYahoo び先頭 j 文字）にするのにかかる最小操作数 として DPする


----解説ここまで---- */

LL N;

LL ans = 0LL;
LL dp[100005][11];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	string yahoo = "yahoo";
	FOR(i, 0, SZ(s) + 1) {
		FOR(j, 0, 11 )dp[i][j] = INF;
	}

	dp[0][0] = 0;
	FOR(i, 0, SZ(s)) {

		FOR(j, 0, 11) {
			int cost = (s[i] == yahoo[j % 5]) ? 0 : 1;
			dp[i + 1][(j + 1) % 5] = min({ dp[i + 1][j % 5] + 1 ,dp[i][(j + 1) % 5] + 1,dp[i][j % 5] + cost });
		}
	}
	ans = dp[SZ(s)][0];

	cout << ans << "\n";

	return 0;
}
