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

/* -----  2018/08/26  Problem: yukicoder 243  / Link: http://yukicoder.me/problems/no/243  ----- */
/* ------問題------

N人の生徒がいるクラスがあります。生徒はS0君からSN−1君までいます。
それぞれの生徒に0からN−1までの出席番号を割り振りたいです。
しかし、それぞれの生徒には嫌いな数が1つあり出席番号にしたくありません。
どの生徒にも嫌いな数が当たらないような出席番号の割り振り方は何通りあるか mod 109+7 で答えよ。

-----問題ここまで----- */
/* -----解説等-----

挿入DPがつくれない　なぜ

とても時間がかかった。

包除原理で解く。求める状態は1つも禁止される番号が選ばれていないもの。
ある数字Xのみに着目し、禁止パターンになるものを考えると、b[X]*(N-1)!的な感じになる。
これらは独立しているのでまとめることができるので和のDPを考えることができる。
dp(i,j):=i番目までみて、j個禁止される数字が選択される組み合わせとして、
dp[0]*(N!) - dp[1]*((N-1)!) + ...をする。

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;
	VI a(N);
	FOR(i, 0, N) {
		cin >> a[i];
	}
	VI b(5000);
	FOR(i, 0, N)b[a[i]]++;

	VL dp(N + 1, 0);

	dp[0]= 1; 
	FOR(i, 0, N) {
		VL nx(N + 1, 0);
		FOR(j, 0, i + 1) {
			(nx[j] += dp[j])%=MOD;
			(nx[j+1] += dp[j]*b[i]%MOD)%=MOD;
		}
		dp.swap(nx);
	}
	VL fact(N + 1, 0);
	fact[0] = 1;
	FOR(i, 0, N) {
		fact[i + 1] = (i + 1)*fact[i] % MOD;
	}
	LL ans = 0;
	FOR(i, 0, N + 1) {
		int sign = (i & 1 ? -1 : 1);
		LL ret = (dp[i]*fact[N-i]) % MOD;
		if (sign == -1)ret = -ret + MOD;
		(ans += ret) %= MOD;
	}



	//// dp( i , j ):=[-,i)まで数字を決定して、まだj個きめてないときの組み合わせ数
	// ダメそう
	//dp[0][N] = 1;
	//FOR(i, 0, N) {// 今iを決める
	//	FOR(j, 0, N + 1) {
	//		int left = j -b[i];
	//		if (left > 0 && j) {
	//			(dp[i + 1][j - 1] += left * dp[i][j] % MOD) %= MOD;
	//		}
	//	}
	//}

	//FOR(i, 0, N + 1) {
	//	FOR(j, 0, N + 1) {
	//		cout << "dp[" << i << "][" << j << "]:=" << dp[i][j] << ",\t";
	//	}cout << endl;
	//}
	//LL ans = dp[N][0];



	cout << ans << "\n";

	return 0;
}
