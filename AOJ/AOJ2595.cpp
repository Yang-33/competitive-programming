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
#define debug(x) cerr << #x << ": " << x 
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2017/11/08  Problem: NU_26 A / Link: __CONTEST_URL__  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----



----解説ここまで---- */

long long  powmod(long long  x, long long  n, long long  mod) {
	long long  res = 1;
	while (n > 0) {
		if (n & 1) {
			res = (res*x) % mod;
		}
		x = (x*x) % mod;
		n >>= 1;
	}
	return res;
}
LL F[10005], R[10005];
void make() {
	F[0] = 1;
	for (long long i = 1; i < 10005; i++) F[i] = F[i - 1] * i%MOD;
	for (long long i = 0; i < 10005; i++) R[i] = powmod(F[i], MOD - 2, MOD);
}
LL N, D, X;

LL ans = 0LL;
inline long long  inverse(long long  a, long long  m) {
	long long  b = m, u = 1, v = 0;
	while (b) {
		long long  t = a / b;
		swap(a -= t * b, b);
		swap(u -= t * v, v);
	}
	return (u % m + m) % m;
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	make();
	while (cin >> N >> D >> X) {
		if (N == 0)break;
		if (X == 1) {
			cout << 0 << endl;
			continue;
		}
		ans = 0;
		VVL dp(N + 1, VL(N + 1, 0));
		dp[0][0] = 1;
		FOR(p, 1, N + 1) {
			LL sum = 0;
			FOR(j, 1, N + 1) {// dp part 
				sum = (sum + dp[p - 1][j - 1]) % MOD;
				dp[p][j] = sum;
				if (j - X + 1 >= 0)sum = (sum - dp[p - 1][j - X + 1] + MOD) % MOD;
			}
		}
		//FOR(i, 0, N + 1) {
		//	FOR(j, 0, N + 1) {
		//		debug(dp[i][j]) << " ";
		//	}cout << endl;
		//}
		ans = 0;
		LL DCJ = 1;
		FOR(i, 1, min(D, N) + 1) {
			DCJ = (DCJ*((D - (LL)i + 1LL+MOD) % MOD) % MOD) % MOD;//mul
			//DCJ = (DCJ*R[i] % MOD) % MOD;// div
			DCJ = (DCJ*inverse(i,MOD) % MOD) % MOD;// div
			ans += dp[i][N] * DCJ%MOD;
			ans %= MOD;
			//debug(DCJ) << endl;
			//debug(dp[i][N]) << endl;
		}

		ans %= MOD;
		ans = ans%MOD;
		cout << ans << "\n";

	}

	return 0;
}
