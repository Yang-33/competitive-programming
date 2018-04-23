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

/* -----  2018/04/23  Problem: yukicoder 109  / Link: http://yukicoder.me/problems/no/109  ----- */
/* ------問題------

N!modMを求めよ。
1≤T≤100
1≤M≤10^9
max(0,Mi−10^5)≤Ni≤10^9

-----問題ここまで----- */
/* -----解説等-----

場合分け
1:N≧Mは0
2:N≦2e5はシュミレーション
3:そうでない場合、Mが素数でないならば合成数の大きい数字はN以下であるから(M/2≦N)0,  
Mが素数のときwillsonの定理から(N-1)! ≡ N-1 (modulo M)で、逆元をN!になるまでかければ良い。


----解説ここまで---- */

bool is_prime(long long  n) {
	if (n < 2) return false;
	for (long long i = 2; i * i <= n; ++i) {
		if (n % i == 0) return false;
	}
	return true;
}
long long modpow(long long a, long long b, long long mod) {
	if (b == 0) return 1;
	return modpow(a * a % mod, b / 2, mod) * (b & 1 ? a : 1) % mod;
}

long long modinv(long long a, long long mod) {
	return modpow(a, mod - 2, mod);
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int T; cin >> T;
	FOR(t, 0, T) {
		LL N, M; cin >> N >> M;
		LL ans = 0LL;

		if (N >= M)ans = 0;
		else if (N <= 2e5) {
			ans = 1 % M;
			FOR(i, 1, N + 1) {
				ans *= i;
				ans %= M;
			}
		}
		else { // 3*10^5<N, N! mod M, N < M
			if (!is_prime(M))ans = 0;
			else {
				ans = 1 % M;
				ans *= M - 1;
				FOR(i, N + 1, M) {
					ans *= modinv(i, M);
					ans %= M;
				}
			}
		}
		cout << ans << "\n";
	}

	return 0;
}
