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
#define debug(x) cerr << #x << ": " << x << endl
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };


/* -----  2017/06/17  Problem: CodeForces419 D div2 / Link: http://codeforces.com/contest/816/problem/D  ----- */
/* ------問題------

数列{a}が与えられる。+/-の二つの演算子を交互につないでいき、できる数列を{b}とする。
またこれにも続いて+/-をかけ合わせていく。
最終的に値は一つになるがその値は？
N≦10^5 a[i]≦10^9 mod=10^9+7

-----問題ここまで----- */
/* -----解説等-----

実験をするとN%4で周期的な値をとっている気がする。
もっとよく見ると、N%4==1のときに値はcombinationであらわされている感じになる。まずはこれをシュミレーションで作成する。

サイズの大きいNに対してこの列を考えたとき、これはa[i]* N/2 C i 、ただしiは偶数
とみえるのでこれを出力する。

----解説ここまで---- */

#define	inv_N 1000000 
long long  fact[inv_N];
long long  inv[inv_N];
long long  factinv[inv_N];
void make_fact(long long  n, long long  mod) {
	fact[0] = 1;
	FOR(i, 1, n + 1) {
		fact[i] = fact[i - 1] * i%mod;
	}
}

// 逆元テーブル作成 Ｏ(N)
void make_inv(long long  n, long long  mod) {
	inv[1] = 1;
	FOR(i, 2, n + 1) {
		inv[i] = inv[mod%i] * (mod - mod / i) % mod;
	}
}

// 階乗の逆元テーブル作成 Ｏ(N)
void make_factinv(long long  n, long long   mod) {
	factinv[0] = 1;
	FOR(i, 1, n + 1) {
		factinv[i] = (factinv[i - 1] * inv[i]) % mod;
	}
}

// 二項係数 nCk mod を返却 Ｏ(N)
long long  choose(long long  n, long long  k, long long  mod) {
	if (!(0 <= k && k <= n)) return 0;
	return (((fact[n] * factinv[k]) % mod)* factinv[n - k]) % mod;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<LL> a(N);
	FOR(i, 0, N)cin >> a[i];

	LL oprt = 1;
	while (N % 4 != 1) {//調整
		vector<LL>b(N - 1);
		FOR(i, 0, N - 1) {
			b[i] = (a[i] + oprt*a[i + 1] + MOD) % MOD;
			oprt *= -1;
		}
		swap(a, b);
		N--;
	}

	/*FOR(i, 0, N) {
		cout << a[i] << " ";
	}*/
	make_fact(N, MOD);
	make_inv(N, MOD);
	make_factinv(N, MOD);
	LL ans = 0;

	FOR(i, 0, N / 2 + 1) {
		ans = (MOD + ans + a[2 * i] * choose(N / 2, i, MOD)) % MOD;
	}



	cout << ans << endl;

	return 0;
}