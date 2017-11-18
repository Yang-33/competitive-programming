#include "bits/stdc++.h"
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

/* -----  2017/11/18  Problem: yukicoder362 / Link: https://yukicoder.me/problems/no/362  ----- */
/* ------問題------

'0'から'9'までの文字からなる文字Sと、正の整数Mが与えられます。
1文字以上の部分列であって10進数として解釈したものがMの倍数となるようなものの総数をmod 1,000,000,007=109+7で出力してください。
ここで、文字列Sの部分列とは、
1≤a1<a2<⋯<ak≤|S|
なる(ai)を用いてS[a1]S[a2]⋯S[ak]と表せる文字列のことです。(S[i]はSのi番目の文字)
位置が異なり文字列としては同じ部分列は異なるものとして扱います。例えばS="110"の場合、 1文字目と3文字目からなる部分列"10"と 2文字目と3文字目からなる部分列"10"は別々に数えます。
また、部分列が2文字以上の場合は0から始まるものは数えません。例えばS="02",M=2の場合、"02"は2の倍数とはみなしません。

-----問題ここまで----- */
/* -----解説等-----

dp(i,j):= i番目の文字を見たときにmod Mでjとなる、leading zeroとならない組合せをとればよい。
前から見て数え上げをすればよい。
AOJでよくやるメモリ節約をすればよい。

----解説ここまで---- */


LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string S; cin >> S;
	int M; cin >> M;

	VVL dp(2, VL(20004, 0));
	int zero = 0;
	FOR(i, 0, SZ(S)) {
		FOR(j, 0, M)
			dp[!(i & 1)][j] = dp[i & 1][j];

		FOR(j, 0, M) {
			dp[!(i & 1)][(10 * j + (S[i] - '0')) % M] += dp[i & 1][j];
			dp[!(i & 1)][j] %= MOD;
		}
		if (S[i] == '0')zero++;
		else dp[!(i & 1)][(S[i]-'0')%M]++;
	}
	ans = dp[SZ(S) & 1][0] + zero;
	ans %= MOD;

	cout << ans << "\n";

	return 0;
}
