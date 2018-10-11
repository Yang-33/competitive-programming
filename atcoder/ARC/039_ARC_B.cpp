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

/* -----  2018/10/13  Problem: ARC 039 B / Link: http://arc039.contest.atcoder.jp/tasks/arc039_b  ----- */
/* ------問題------

高橋君は幼稚園の先生です。高橋君は N 人の児童にちょうど K 個のキャンディを配り切ることにしました。
ここで、全体の幸福度を、各児童が貰ったキャンディの個数の積として定義します。
高橋君は N 人の児童にキャンディを配り切ったときの、全体の幸福度を最大化したいと思っています。 全体の幸福度を最大化するようなキャンディの分配方法が何通りあるかを数えてください。答えは大きくなる可能性があるので答えを 1,000,000,007(109+7) で割った余りを出力してください。
各児童に配られたキャンディの個数が 1 つでも異なっていれば、配り方は区別されます。児童は区別され、キャンディは区別されません。また、定義からキャンディを 1 つも貰えない児童が 1 人でもいると、全体の幸福度は 0 になることに気をつけてください。

-----問題ここまで----- */
/* -----解説等-----

相加相乗平均を考えたり、積の対数を考える。
すると均等に配るのが良いことを示すことができるので均等に配る。あまりの分配の組合せだけ求めれば良い。
そもそも全員に配れないときは重複組合せをやればよい。

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

long long nPr(int n, int r) {
	if (n < r || n < 0 || r < 0) return 0;
	return fact[n] * inv_fact[n - r] % mod;
}

long long nCr(int n, int r) {
	if (n < r || n < 0 || r < 0) return 0;
	return fact[n] * inv_fact[r] % mod * inv_fact[n - r] % mod;
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, K; cin >> N >> K;
	init_fact(N + K);
	LL ans = 0;
	if (N <= K) {
		int left = K % N;
		// leftを割り振る
		ans = nCr(N, left);
	}
	else {
		ans = nCr(N + K - 1, K);
	}
	cout << ans << endl;
	return 0;
}