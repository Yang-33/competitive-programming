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

/* -----  2018/04/08  Problem: yukicoder 016  / Link: http://yukicoder.me/problems/no/016  ----- */
/* ------問題------

Maliaは、与えられた数式を計算しようとしている。
数式は一つの変数xのみで構成されており、各i項はxのai乗で構成されている。
ここで xnはxのn乗を表すことにすると
xa1+xa2+⋯+xaN
という形になっている。
xの累乗を計算するのは大変だと気づいたあなたは、代わりに計算してあげることになりました。

xと各ai (1≤i≤n)が与えられた時の計算値を求めてください。
答えの値が非常に大きくなるので計算値に対して1,000,003 で割ったあまりを求めてください。

計算途中の値が32ビットに収まらないことが有ります。

-----問題ここまで----- */
/* -----解説等-----

繰り返し2乗法をやればよい

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
LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL x;
	cin >>x>> N;
	const LL mod = 1000003;

	FOR(i, 0, N) {
		LL a; cin >> a;
		ans += powmod(x, a, mod);
		ans %= mod;
	}
	cout << ans << "\n";

	return 0;
}
