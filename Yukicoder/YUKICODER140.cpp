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

/* -----  2018/05/02  Problem: yukicoder 140  / Link: http://yukicoder.me/problems/no/140  ----- */
/* ------問題------

N 組の夫婦、計(2×N)人で旅行に行くことにした。
(2×N)人は幾つかのグループに別れ、それぞれグループメンバの車で移動することになった。

各夫婦は皆大型車を持っており、グループに１台車があればグループ全員が移動できる。
ただし、各夫婦が車を使わせてくれるのは、夫婦が同一のグループにいる場合だけである。
すなわち、各グループが無事に車で旅行に行くためには、グループに１組以上夫婦のペアが含まれていなければならない。

条件を満たすグループの分け方が何通りあるかを答えよ。
答えは非常に大きくなる可能性があるので、109+7の剰余を取った値を答えること。

-----問題ここまで----- */
/* -----解説等-----

第二種スターリングさんを覚えた。
Xグループ作るときは、夫婦が何組くっついているか、何組バラバラなのかを区別していれば良い。
したがってX組をYグループに分け、N-X組をバラバラに配置する組合せを求めれば良い。
区別できる集合から区別できないグループに分ける組み合わせ数はnSrで表現できる。(組合せすごい)
区別できる集合の選択はnCrでできるので、これらを組み合わせるとできる。
☆3マジ？ってなった。
先に手で組合せを試してみて何を区別したいのかを考えると見通しが良くなった。

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
	fact[0] = 1;
	for (int i = 1; i < n; i++) {
		fact[i] = i * fact[i - 1] % mod;
	}
	inv_fact.resize(n);
	inv_fact[n - 1] = modinv(fact[n - 1]);
	for (int i = n - 2; i >= 0; i--) {
		inv_fact[i] = (i + 1) * inv_fact[i + 1] % mod;
	}
}

long long nCr(int n, int r) {
	if (n < r || n < 0 || r < 0) return 0;
	return fact[n] * inv_fact[r] % mod * inv_fact[n - r] % mod;
}

vector<vector<long long>> S;

void stirling_number(int n) {
	S.resize(n, vector<long long>(n, 0));
	for (int i = 1; i < n; i++) {
		S[i][1] = S[i][i] = 1;
		for (int j = 2; j < i; j++) {
			S[i][j] = (S[i - 1][j - 1] + j*S[i - 1][j]) % mod;
		}
	}
}

long long nSr(int n, int r) { // 区別できるn個のものを区別できないrグループに分類する場合の数
	return S[n][r];
}

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	init_fact(N + 1);
	stirling_number(N + 1);
	// 
	FOR(i, 1, N + 1) {
		FOR(j, 1, i + 1) { // 集合の選択 -> 分類 -> 重複せず配布
			ans += (nCr(N,i) * nSr(i,j)%MOD * modpow(j*(j-1),N-i)) % MOD;
			ans %= MOD;
		}
	}
	cout << ans << "\n";

	return 0;
}
