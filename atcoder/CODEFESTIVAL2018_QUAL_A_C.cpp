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

/* -----  2018/09/22  Problem: codefestival2018_qual_a C / Link: __CONTEST_URL__  ----- */
/* ------問題------

長さ N の整数列 A1,A2,…,AN が与えられます。 この数列に以下の操作をちょうど K 回施します。

添字 i (1≤i≤N) を一つ選ぶ。Ai を 2 で割る。ただし商は整数単位で計算し、あまりは切り捨てる。
K 回の操作のあとの数列としてありうるものの個数を 109+7 で割ったあまりを求めてください。

-----問題ここまで----- */
/* -----解説等-----

なんで解けなかったんだろうね
まずそれぞれの数字は独立。次にこの数は2^xの形にできる。すると、3000回ぐらい以上操作しても意味がないことに気づくことができる。

各数は独立しているので、dpでできる。
区別すればよいのは、0を生成できたかどうか。また、何回操作したか。
よってdp(i,k,s):=ith,k回やった、0/1:s:=0をつくったか の総数
とできる。遷移を考えるのに2時間かかったのでダメだった。
codeの// !!を書き足すとただしい。(バカすぎる)

----解説ここまで---- */

LL N;

LL ans = 0LL;

LL dp[52][6100][2];


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL K;
	cin >> N >> K;
	VL a(N);
	FOR(i, 0, N) {
		cin >> a[i];
	}
	VL cpa = a;
	VL b(N, 0);

	FOR(i, 0, N) {
		while (cpa[i]) {
			cpa[i] /= 2;
			b[i]++;
		}
	}



	dp[0][0][0] = 1;
	FOR(i, 0, N) {
		FOR(k, 0, 3001) {
			for (LL bb = 0; bb < b[i]; bb++) {
				// 使用回数
				(dp[i + 1][k + bb][1] += dp[i][k][1]) %= MOD;
				(dp[i + 1][k + bb][0] += dp[i][k][0]) %= MOD;
			}
			(dp[i + 1][k + b[i]][1] += dp[i][k][0]) %= MOD;
			(dp[i + 1][k + b[i]][1] += dp[i][k][1]) %= MOD; // !
		}
	}

	ans = 0;
	FOR(k, 0, min(K + 1, 3001LL)) {
		ans += dp[N][k][1];
		ans %= MOD;
	}
	//debug(ans);
	if (K <= accumulate(ALL(b), 0)) {
		ans += dp[N][K][0];
		ans %= MOD;
	}



	//FOR(i, 0, N + 1) {
	//	cout << i << "th +:";
	//	FOR(k, 0, min(K + 1, 31LL)) {
	//		cout << k << ":=" << dp[i][k][0] << " " << dp[i][k][1] << "|| ";
	//	}
	//	cout << endl;
	//}

	cout << ans << "\n";

	return 0;
}
