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

/* -----  2018/03/12  Problem: 067_arc_c / Link: https://arc067.contest.atcoder.jp/tasks/arc067_c?lang=en  ----- */
/* ------問題------

1 から N までの番号のついた N 人の人がいます。 以下の二つの条件を満たすように、彼らをいくつかのグループに分けたいです。
どのグループも、そのグループに含まれる人数が A 人以上 B 人以下である。
ちょうど i 人の人が含まれるようなグループの数を Fi で表したとき、 すべての i について、Fi=0 または C≦Fi≦D が成り立っている。
このようなグループ分けが何通りあり得るか求めてください。 ただし、ある二つのグループ分けが異なるとは、二人の人の組であって、 片方のグループ分けでは同じグループに含まれ、他方では同じグループに含まれないようなものが存在することを意味します。 なお、答えは非常に大きくなることがあるので、109+7 で割った余りを出力してください。

-----問題ここまで----- */
/* -----解説等-----

グループと総人数についてDPをする。
dp[i][j] := i人未満のグループを作ってきたとき、現在j人割り振りが完了しているときの食合せ数
これは1グループやるときから式を書かないとわからない。
総人数はA-Bの範囲かつC-Dグループいることから上手に管理すれば調和級数のアレでO(N^2 log N)


----解説ここまで---- */

const long long mod = 1e9 + 7;

long long modpow(long long a, long long b) {
	if (b == 0) return 1;
	return modpow(a * a % mod, b / 2) * (b & 1 ? a : 1) % mod;
}

long long modinv(long long a) {
	return modpow(a, mod - 2);
}
vector<long long> fact, inv_fact;

void init_fact(int n) {
	fact.resize(n);
	fact[0]= 1;
	for (int i = 1; i < n; i++) {
		fact[i] = i * fact[i - 1] % mod;
	}
	inv_fact.resize(n);
	inv_fact[n - 1] = modinv(fact[n - 1]);
	for (int i = n - 2; i >= 0; i--) {
		inv_fact[i] = (i + 1) * inv_fact[i + 1] % mod;
	}
}

long long nPr(int n, int r) {
	if (n < r || n < 0 || r < 0) return 0;
	return fact[n] * inv_fact[n - r] % mod;
}

long long nCr(int n, int r) {
	if (n < r || n < 0 || r < 0) return 0;
	return fact[n] * inv_fact[r] % mod * inv_fact[n - r] % mod;
}

long long nHr(int n, int r) {
	if (n == 0 && r == 0) return 1;
	return nCr(n + r - 1, r);
}

LL N, A, B, C, D;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);


	init_fact(3003);

	cin >> N >> A >> B >> C >> D;
	VVL dp(B + 2, VL(N + 1, 0));
	FOR(i, 0, B + 2)dp[i][0] = 1;

	// dp[i][j] := i人未満のグループを作ったときに、これまでj人を割り振ったときの組み合わせ数
	// dp[i][j] -> dp[i+1][j]
	// dp[i][j] -> dp[i+1][j + i*k]
	FOR(i, A, B + 1) {
		FOR(j, 0, N + 1) {
			if (!dp[i][j])continue;
			if (j) { //a人は割り振らない
				dp[i + 1][j] += dp[i][j];
				dp[i + 1][j] %= mod;
			}
			LL x = 1;
			FOR(k, 1, D + 1) {
				if (j + k*i > N)break;
				x *= (nCr(N - j - (i)*(k - 1), i) * modinv(k)) % mod;
				x %= mod;
				if (C <= k && k <= D) {
					dp[i + 1][j + k*i] += (dp[i][j] * x) % mod;
					dp[i + 1][j + k*i] %= mod;
				}
			}
		}
	}
	ans = dp[B + 1][N];
	cout << ans << "\n";

	return 0;
}
