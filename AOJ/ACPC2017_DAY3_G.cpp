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

/* -----  2017/09/20  Problem: ACPC2017_day3_g  / Link:   ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

まず最悪なDPとしてＯ(NMK)が考えられる。
しかしこれは絶対に通らないので、考察を進める。
各kについて考えると、前の状態からの遷移と後の状態からの遷移は同じであることが分かる。
したがってK回、同じ次の状態に移動するDPとみることができる。
これは(N*N)の正方遷移行列Aを用いて A^K * (1,0,0,0,0,...,0)^tをすればいいことになる。
A^Kの部分は行列累乗で計算を加速させることができて、Ｏ(N^3logK)になる。しかしN≦800であるからTLE.
行列Aについてみてみるとなんだかひとつづつずれているように見える。これは巡回行列である。
巡回行列A,巡回行列Bの積は巡回行列Cであることを考えると、行列の1行だけを持てばいいことになる。
これによってA^Kの計算は1*Nの行列をＡとしてもよいことになり、Ｏ(N^2logK)まで計算量が落ちてうれしい気持ちになり、ACできる。
Nを落とすパートが2分前に完成してACできたのでオンサイト1位(online 2位)。うれしいね

----解説ここまで---- */

using ll = long long;

const ll mod = 1e9 + 7;

using vl = vector<ll>;
using mat = vector<ll>;

mat mul(const mat &a, const mat &b)
{
	int n = a.size();
	mat c(n);

	FOR(i, 0, n) {
		c[i] = 0;
		FOR(j, 0, n)
			c[i] = (a[j] * b[(i - j + n) % n] + c[i]) % mod;
	}
	return c;
}

vl mul_v(const mat &a, const vl &b)
{
	int n = a.size();
	vl ret(n);
	FOR(i, 0, n) {
		FOR(j, 0, n) {
			ret[i] += (a[(j + i) % n] * b[j]) % mod;
			ret[i] %= mod;
		}
	}

	return ret;
}


mat pow(const mat &a, int n)
{
	int N = a.size();
	mat r(N); // 1*N
	r[0] = 1;

	mat p(a);
	while (n) {
		if (n & 1) r = mul(r, p);
		p = mul(p, p);
		n >>= 1;
	}

	return r;
}

int main()
{
	int n, m, k;
	scanf(" %d %d %d", &n, &m, &k);

	mat A(n);//巡回行列*巡回行列 = 巡回行列
	A[0] = 1;

	FOR(i, 0, m) {
		int p;
		scanf(" %d", &p);

		++A[p%n];
	}

	mat P = pow(A, k);
	vl b(n);
	b[0] = 1;

	//vl ans = mul_v(P, b);

	FOR(i, 0, n)
		printf("%lld\n", P[i]);
	return 0;
}