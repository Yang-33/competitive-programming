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

/* -----  2018/06/10  Problem: AOJ 2595 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2595  ----- */
/* ------問題------

N枚のクッキーがある。
D日以内に食べたい。
一日にX枚未満しか食べれないが、食べ方の組み合わせはどれだけか。
食べない日があっても良い。

-----問題ここまで----- */
/* -----解説等-----

食べない日のことを考えると、食べる日だけの組み合わせを考えて、Kにちたべるとしたら
comb(D,K)*(K日でN枚食べる組み合わせ)
を計算すればいいことになる。
愚直なDPを考えるとO(KNX)となる。
dp[k][n]=k日毎日食べて、n枚食べる組み合わせ
だがdp[k+1][n]+=dp[k][n-x]の部分は範囲和なので、適切に扱うことでO(logX)なりO(1)になる。
したがって解ける。
最後のcombinationの部分は、大きい組み合わせを小さい方のオーダーでやるテクで解決できる。(Dは大きいけどmin=2*0^3なので)

----解説ここまで---- */


const long long mod = 1e9 + 7;

long long modpow(long long a, long long b) { //a==0の処理は問題次第
	if (b == 0) return 1;
	return modpow(a * a % mod, b / 2) * (b & 1 ? a : 1) % mod;
}

long long modinv(long long a) {
	return modpow(a, mod - 2);
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, D, X;

	while (cin >> N >> D >> X, N || D || X) {

		VVL dp(N + 1, VL(N + 1, 0));
		dp[0][0] = 1;
		FOR(i, 0, N) { // i日食べる日がある
			// X:固定param
			LL sum = 0;
			FOR(n, 1, N + 1) {
				sum += dp[i][n - 1], sum %= MOD;
				if (n >= X)sum -= (dp[i][n - X]) % MOD, sum += MOD, sum %= MOD;
				dp[i + 1][n] += sum;
				dp[i + 1][n] %= MOD;
			}
		}
		LL ans = 0;
		LL comb = 1;
		FOR(i, 1, N + 1) {
			comb *= ((D - i + 1+mod)%mod);
			comb %= mod;
			comb *= modinv(i);
			comb %= mod;
			LL ret = dp[i][N] * comb;
			ans += ret%MOD;
			ans %= MOD;
		}
		cout << ans << "\n";
	}

	return 0;
}
