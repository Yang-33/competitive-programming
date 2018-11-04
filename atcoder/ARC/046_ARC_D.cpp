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
//#pragma GCC optimize ("-O3") 
#ifdef YANG33
#include "mydebug.hpp"
#else
#define DD(x) 
#endif
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/11/04  Problem: ARC 046 D / Link: http://arc046.contest.atcoder.jp/tasks/arc046_d  ----- */
/* ------問題------

H 行、W 列のマス目があります。第 i (0≦i≦H−1) 行、第 j (0≦j≦W−1) 列のマスを (i, j) と表します。
最初、マス (0, 0) にうさぎがいます。うさぎは以下の操作を繰り返します。
今いるマスに色が塗られていれば、操作を終了する。
今いるマスに色が塗られていなければ、今いるマスに色を塗り、今いるマス (i, j) から ((i+1) mod H, j) または (i, (j+1) mod W) へ移動する。
うさぎがすべてのマスに色を塗った後、マス (0, 0) で操作を終了するような方法は何通りでしょうか？ 109+7 で割った余りを求めてください。
ただし、うさぎの辿った経路が異なるとき、またそのときのみ、2 つの方法は異なるものとします。

-----問題ここまで----- */
/* -----解説等-----

解説の通り。
まず全マス移動する際に、あるマスの方向を決めるとする。
すると、その周りのマスに移動するためには他の周りのマスの方向が一意に定まる。
これはある間隔を保ち独立しており、gcd(H,W)で独立。
ということはgcd(H,W)個を列にして、これをH*W/(gcd(H,W))回繰り返せば良さそう。
このうち、ダメなものも含まれていて、gcd(H,W)の列で小さなグループができると、全マスに移動する前に(0,0)に到達しうることがわかる。
これを取り除くために、x+y=gcd(H,W)として計算をすればよい。

----解説ここまで---- */

long long  gcd(long long  a, long long  b) { return b ? gcd(b, a%b) : a; }
long long  lcm(long long  a, long long  b) { return a / gcd(a, b) * b; }
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
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL H, W; cin >> H >> W;
	init_fact(H + W + 1);
	LL ans = 0;
	LL di = gcd(H, W);
	LL cycle = (H * W) / di;
	FOR(x, 1, di + 1) {
		LL y = di - x;
		LL cx = W / gcd(W, x);
		LL cy = H / gcd(H, y);
		if (lcm(cx, cy) == cycle) { //少ないのはダメ
			ans += nCr(di, x);
			ans %= mod;
		}
	}

	cout << ans << "\n";

	return 0;
}
