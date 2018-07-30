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

/* -----  2018/07/30  Problem: yukicoder 181  / Link: http://yukicoder.me/problems/no/181  ----- */
/* ------問題------

(A⇈N)modMを求めよ。
ただし、整数a>0,n≥0に対してa⇈nを次のように定義する。

a⇈n={1a(a⇈(n−1))(n=0)(otherwise)

-----問題ここまで----- */
/* -----解説等-----

f(a,n,m) = a^^n mod mとする。
nが大きいので厳しいが、a^x mod m= a^(x mod φ(m)) mod mであることをいかしたい。
φ関数はy=xより小さいので、mod = 0になるまで関数を展開したときに0or1を返す。
あとはこれを再帰すればよい。

----解説ここまで---- */

VI euler;
void get_euler_phi(int n) {
	euler = VI(n + 1);
	for (int i = 0; i <= n; i++) {
		euler[i] = i;
	}
	for (int i = 2; i <= n; i++) {
		if (euler[i] == i) {
			for (int j = i; j <= n; j += i) {
				euler[j] = euler[j] / i * (i - 1);
			}
		}
	}
}

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

LL g(LL A, LL N) { // A^^N
	if (A == 1 || N == 0)return 1;
	if (N == 1)return A;
	if (N == 2)return A*A;
	return INF;
}

LL f(LL a, LL n, LL m) {// A^^N mod m
	if (m == 1)return 0;
	if (n == 0)return 1;
	if (g(a, n - 1) < euler[m]) {
		return powmod(a, f(a, n - 1, euler[m]), m);
	}
	else {
		return powmod(a, f(a, n - 1, euler[m]) + euler[m], m);
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL A, N, M; cin >> A >> N >> M;
	get_euler_phi(M + 1);
	LL ans = f(A, N, M);

	cout << ans << "\n";

	return 0;
}
