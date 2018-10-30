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

/* -----  2018/10/30  Problem: ARC 044 B / Link: http://arc044.contest.atcoder.jp/tasks/arc044_b  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

はいこれクソ面白い
まず高さが同じ頂点は完全グラフを張っても張らなくても良いので2^perf,
1つ違いのものに対しては2^(上のモノ)-1通りあるので(必ず1つは選択しないとダメなので)
これをその高さ回選択なのでx^(高さの個数)とする。

----解説ここまで---- */

const long long mod = 1e9 + 7;
long long modpow(long long a, long long b) {
	if (b == 0) return 1;
	return modpow(a * a % mod, b / 2) * (b & 1 ? a : 1) % mod;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; cin >> N;
	VI a(N);

	FOR(i, 0, N) {
		cin >> a[i];
	}
	// 連続性∧0はa[0]の1個
	bool f = 1;
	f &= a[0] == 0;
	SORT(a);
	VI b = a;
	FOR(i, 1, N) {
		f &= a[i] != 0;
	}
	UNIQ(a);
	int fir = 1;
	FOR(i, 1, SZ(a)) {
		if (a[i] == fir) {
			fir++;
		}
		else {
			f &= 0;
		}
	}

	LL ans = 0;
	if (!f) {
		ans = 0;
	}
	else {
		ans = 1;
		VL cnt(N, 0);
		FOR(i, 0, N) {
			cnt[b[i]]++;
		}
		DD(De(fir, cnt));
		FOR(i, 1, fir) {
			LL perfect = cnt[i] * (cnt[i] - 1) / 2;
			ans *= modpow(2, perfect);
			ans %= mod;
		}
		FOR(i, 1, fir) {
			LL ret = modpow(2, cnt[i - 1]) + mod - 1;
			ret %= mod;
			DD(de(ret));
			ret = modpow(ret, cnt[i]);
			DD(de(ret));
			ret %= mod;
			ans *= ret;
			ans %= mod;
			DD(de(ans));
		}
	}


	cout << ans << "\n";

	return 0;
}
