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

/* -----  2018/04/19  Problem: yukicoder 097  / Link: http://yukicoder.me/problems/no/097  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

乱数列Aがあり、最大値を求めたい。Nが小さいときはやればよい。
一方、Nが大きいときはO(QN)となり不可能になる。  
求める答えをXとしたとき、X = q*A[i]であり、剰余の世界ではA[i] = Xq^{-1}である。答えXが存在するとき、この様なA[i]が存在すれば良いので、これを高速に判定すれば良さそう。
qは毎回変わることを考えるとこれは不可能で、最大値の発見から愚直にやるだけで間に合う。(乱数列なので、sqrt(N)回以内にだいたい発見できる。)
よってsqrt(N)で解法を分ければ良い。


O(Qsqrt(N))
学びのある問題

----解説ここまで---- */

unsigned xor128_x = 123456789, xor128_y = 362436069, xor128_z = 521288629, xor128_w = 88675123;
unsigned xor128() {
	unsigned t = xor128_x ^ (xor128_x << 11);
	xor128_x = xor128_y; xor128_y = xor128_z; xor128_z = xor128_w;
	return xor128_w = xor128_w ^ (xor128_w >> 19) ^ (t ^ (t >> 8));
}
void generateA(int N, VL &A) {
	for (int i = 0; i < N; ++i)
		A[i] = xor128() % 100003;
}
const long long mod = 100003;

long long modpow(long long a, long long b) {
	if (b == 0) return 1;
	return modpow(a * a % mod, b / 2) * (b & 1 ? a : 1) % mod;
}

long long modinv(long long a) {
	return modpow(a, mod - 2);
}
LL N;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int Q; cin >> N >> Q;
	VL a(N);
	generateA(N, a);
	VI have(mod, 0);
	FOR(i, 0, N) {
		have[a[i]] = 1;
	}
	FOR(i, 0, Q) {
		LL q; cin >> q;
		LL ans = 0;
		if (q == 0) {// ...
			ans = 0;
		}
		else if (sqrt(mod) >= N) { // hitしにくい
			FOR(j, 0, N) {
				ans = max(ans, (q*a[j]) % mod);
			}
		}
		else {// hitしやすい
			LL invq = modinv(q);
			FORR(x, mod - 1, 0 - 1) {
				if (have[(x*invq) % mod]) {
					ans = x;
					break;
				}
			}
		}
		cout << ans << endl;
	}

	return 0;
}
