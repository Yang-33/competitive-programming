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

/* -----  2018/09/19  Problem: yukicoder 269  / Link: http://yukicoder.me/problems/no/269  ----- */
/* ------問題------

学校で募金活動をすることになり、N人のクラスでS円を集め寄付することにした。
生徒は出席番号順に寄付金額（０以上の整数）を決めていく。

このクラスの生徒は皆見栄っ張りであり、出席番号順が１つ前の生徒に比べてK円以上高い金額を寄付しないと気が済まず不満になるようだ。
（最初に金額を決める生徒は比べる相手がいないので何円寄付しても良い。0円でも構わない）

不満な生徒が現れることなく、クラスの合計寄付金額がちょうどS円となるような各生徒の寄付金額の組み合わせは何通りあるか。
組み合わせ数を10^9+7で割った余りを答えよ。

-----問題ここまで----- */
/* -----解説等-----

dpで数え上げることができる。
まずK円以上という条件から、必ずK*N*(N-1)/2円は必要。
あとは、金額を割り振ることを考える。
一人が払うと他の人達も払わないとダメなのでこれをお金についてdpすればよく、
dp[i人目][全体でs円払うことが確約された]:=組み合わせ数

えーなんか遅かったので考え直した

1.純粋にDP遷移を高速にする

2.全単射なものを取ることができる。
これは分割数に帰着できるので(これすごくないか)割と速くできる。

----解説ここまで---- */




LL slow(LL N, LL S, LL K) {
	VVL dp(N + 1, VL(S + 1, 0));
	dp[0][0] = 1;

	FOR(i, 0, N) {
		FOR(k, 0, S + 1) {
			FOR(s, 0, S + 1 - (N - i)*k) {
				(dp[i + 1][s + (N - i)*k] += dp[i][s]) %= MOD;
			}
		}
	}
	return dp[N][S];
}

// N人でS円
LL fast(LL N, LL S) {
	VVL dp(N + 1, VL(S + 1, 0));
	dp[0][0] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= S; j++) {
			if (j - i >= 0) {
				dp[i][j] = (dp[i - 1][j] + dp[i][j - i]) % MOD;
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	return dp[N][S];
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, S, K; cin >> N >> S >> K;

	S -= K * N* (N - 1) / 2;
	LL ans = 0;
	if (S >= 0) {
//		ans = slow(N,S,K);
		ans = fast(N,S);
	}

	cout << ans << "\n";

	return 0;
}
