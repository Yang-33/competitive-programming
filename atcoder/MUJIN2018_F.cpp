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
const LL mod = 998244353;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/08/04  Problem: mujin2018 F / Link: __CONTEST_URL__  ----- */
/* ------問題------

N 人を、それぞれの人がただ 1 つのチームに属するようにチーム分けを行います。
しかし、人によっては多くの人が属するチームに属したくないと考えています。
この条件は N 要素からなる整数列 a で表され、i 番目の人は ai 人以下から成るチームに配属されることになります。
チーム分けをするに当たってこのようなチーム分けは何通り考えられるのかを計算したくなりました。答えは非常に大きくなることがあるので、998244353 で割ったあまりを出力してください。ただし、2 つのチーム分けが異なるとは、ある 2 人が存在して、片方のチーム分けでは同じチームに属するがもう片方のチーム分けでは違うチームに属する、という場合を表します。

-----問題ここまで----- */
/* -----解説等-----

N人について、割り振ったか割り振っていないかどうかの情報が大事
挿入DPっぽさはここからきていそう
dp[i][j]:=i人グループまでを作っていて、まだ割り振っていない人がj人いる
とする。
O(N^3)っぽいが、これは値の大きい方からしか遷移できず、調和級数なのでO(N^2logN)でできる。
dp遷移はgrouping(atcoder)に似ているし、挿入dpっぽく条件を保持していけばcombinationと和のdpができる。
この組合せはできないとだめだなあ…
あとsizeでdpをもつのが適切はそれはそうっぽそう

----解説ここまで---- */

long long modpow(long long a, long long b) { //a==0の処理は問題次第
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

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;
	VI a(N);
	FOR(i, 0, N) {
		cin >> a[i];
	}
	VI aval(1005, 0);
	FOR(i, 0, N) {
		aval[a[i]]++;
	}
	init_fact(2005);
	VVL dp(1005, VL(1005, 0));

	dp[N+1][0] = 1;
	FORR(i, N, 1 - 1) {
		FOR(j, 0, 1005) {
			if (dp[i + 1][j] == 0)continue;
			LL sumOfsend = aval[i] + j;
			// send
			for (int k = 0; i*k <= sumOfsend; k++) {
				LL ret = (nCr(sumOfsend, i*k)*fact[i*k]) % mod;
				ret *= inv_fact[k];
				ret %= mod;
				ret *= modpow(inv_fact[i], k);
				ret %= mod;
				dp[i][sumOfsend - i*k] += (dp[i + 1][j] * ret) % mod;
				dp[i][sumOfsend - i*k] %= mod;
			}
		}

	}
	LL ans = dp[1][0];

	cout << ans << "\n";

	return 0;
}
