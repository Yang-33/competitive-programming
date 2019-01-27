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

/* -----  2019/01/26  Problem: CodeForces449 D div1 / Link: http://codeforces.com/contest/896/problem/D  ----- */
/* ------問題------

50円のチケットを販売．N人の客がいて，50,100,freeの人がいる．
お釣りを返す必要がある人が100の人で，お釣りを切らさず，最終的におつりが[L:R]であるような並び方の総数は?
N,L,R≦10^5, mod≦2*10*9

-----問題ここまで----- */
/* -----解説等-----

まずmodを考慮せず解く．
noteに記した通りのように，カタラン数の反射原理を用いると，n回0未満にならないように移動して(n,2h)に移動する経路数はC(n,h)-C(n,h+1)とかである．
これをへんけいすれば解ける．

modがクソ．素因数分解してそれぞれ求める．O(N*d(mod) + N*d(mod))等で解ける．
経路数の求め方や問題パターンはそこまで多くないので結構まとめることができた．

----解説ここまで---- */


struct Combtable {
	int mod, n, tot; vector<int> inv, fac, p; vector<vector<int>> t; int isinit = 0;
	int phi(int k) {
		int s = k;
		for (int i = 2; i * i <= k; i++) {
			if (k % i == 0) s = s / i * (i - 1);
			while (k % i == 0) k /= i;
		}
		if (k > 1) s = s / k * (k - 1);
		return s;
	}

	int fastpow(int a, long long b) {
		int res = 1;
		while (b) {
			if (b & 1) res = (1LL * res * a) % mod;
			b >>= 1; a = (1LL * a * a) % mod;
		}
		return res;
	}

	void init(int _n, int _mod) {
		mod = _mod;
		n = _n + 5;
		tot = 0;

		inv.resize(n);
		fac.resize(n);
		p.resize(n);
		t.resize(n, vector<int>(20));

		long long x = mod;
		int Phi = phi(mod);
		for (int i = 2; 1LL * i*i <= x; i++) {
			if (x%i) continue;
			while (x%i == 0) x /= i;
			p[++tot] = i;
		}
		if (x > 1) p[++tot] = x;
		inv[0] = inv[1] = 1;
		fac[0] = fac[1] = 1;
		for (int i = 2; i < n; i++) {
			x = i;
			for (int j = 1; j <= tot; j++) {
				t[i][j] = t[i - 1][j];
				if (x%p[j]) continue;
				while (x%p[j] == 0) x /= p[j], t[i][j]++;
			}
			fac[i] = (1LL * fac[i - 1] * x) % mod;
			inv[i] = fastpow(fac[i], Phi - 1);
		}
		isinit = 1;
	}



	int C(int n, int m) {
		assert(isinit == 1 && "Please init!!");
		int res = 0;
		if (mod == 1)return 0;
		if (n < m || m < 0) return 0;
		if (m == 0) return 1;
		res = ((1LL * fac[n] * inv[m]) % mod*inv[n - m]) % mod;
		for (int i = 1; i <= tot; i++)
			res = (1LL * res * fastpow(p[i], t[n][i] - t[m][i] - t[n - m][i])) % mod;
		return res;
	}
};


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, P, L, R; cin >> N >> P >> L >> R;
	Combtable ct;
	ct.init(N,P);
	LL ans = 0;
	L--;
	FOR(i, 0, N + 1) {
		LL n = N - i;
		LL C = (ct.C(n, (n - L + 1) / 2 - 1) + P - ct.C(n, (n - R + 1) / 2 - 1)) % P;
		C = (C*ct.C(N, n) % P);
		ans = (ans + C) % P;
	}
	
	cout << ans << "\n";

	return 0;
}
