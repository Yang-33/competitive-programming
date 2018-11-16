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

/* -----  2018/11/16  Problem: ARC 023 C / Link: http://arc023.contest.atcoder.jp/tasks/arc023_c  ----- */
/* ------問題------

高橋君が謎の人物Xからもらったたこ焼きを庭に植えると、たこ焼きの木が生えてきました。高橋君はその木に「タコヤ木」という名前をつけて大切に育てていました。ある日、高橋君はタコヤ木にたこ焼きの実がなっているのを見つけました。そこで高橋君はタコヤ木になったたこ焼きの実の個数を毎日数え、「今までになったたこ焼きの実の個数の合計」を記録していくことにしました。
記録を付け始めてから N 日が経ったある日、高橋君がたこ焼きの実をうっかり記録帳に落としてしまい、N 日分の記録のうちの一部が汚れて読めなくなってしまいました。高橋君はこの記録をなんとか復元したいと思い、まずは何通りの記録がありうるのかを計算してみることにしました。

-----問題ここまで----- */
/* -----解説等-----

○と｜を並び替える組合せ数に帰着できる。
階乗ベースのnCrは間に合わないのでr-smallのnCrを書く。

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

long long nCrS(int n, int r) {
	if (n < r || n < 0 || r < 0) return 0;
	long long ret = 1;
	for (long long x = n; x >= n - r + 1; x--) {
		ret *= x; ret %= mod;
	}
	ret *= inv_fact[r];
	return ret % mod;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N;
	cin >> N;
	init_fact(2 * N + 1);
	VI a(N);
	FOR(i, 0, N) {
		cin >> a[i];
	}
	LL ans = 1;
	auto f = [](int L, int R, int X) {
		return nCrS(R-L+X,X);
	};
	int F = a[0];
	int cnt = 0;
	FOR(i, 1, N) {
		if (a[i] == -1) {
			cnt++;
		}
		else {
			if (cnt) {
				ans *= f(F,a[i],cnt);
				ans %= mod;
				cnt = 0;
				F = a[i];
			}
			else {
				F = a[i];
			}
		}
	}

	cout << ans << "\n";

	return 0;
}
