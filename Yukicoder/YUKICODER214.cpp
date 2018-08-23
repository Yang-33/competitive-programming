#include <bits/stdc++.h>
using namespace std;

using VS = vector<string>;    using LL = long long;
using VI = vector<int>;       using VVI = vector<VI>;
using PII = pair<int, int>;   using PLL = pair<LL, LL>;
using VL = vector<LL>;        using VVL = vector<VL>;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define SZ(a) (long long)((a).size())
#define SORT(c) sort(ALL((c)))
#define RSORT(c) sort(RALL((c)))
#define UNIQ(c) (c).erase(unique(ALL((c))), end((c)))
#define FOR(i, s, e) for (int(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (int(i) = (s); (i) > (e); (i)--)
#define debug(x) cerr << #x << ": " << x << endl
const int INF = 1e9;                          const LL LINF = 1e16;
const int MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/08/21  Problem: yukicoder 214  / Link: http://yukicoder.me/problems/no/214  ----- */
/* ------問題------

素数サイコロとはそれぞれの面に 2,3,5,7,11,13 の整数が書かれているサイコロである。
合成数サイコロとはそれぞれの面に 4,6,8,9,10,12 の整数が書かれているサイコロである。
あるスゴロクでは、0 のマスからスタートし、N のマスに辿り着いたらゴールである。
各ターン、P 個の素数サイコロと C 個の合成数サイコロを振り、出た目の和を x として、今いるマスが k ならば min(k+x,N) のマスに移動する。
それぞれ素数サイコロと合成数サイコロは区別できないとして、ゴールする方法のパターン数を mod 1000000007 (109+7) で求めるプログラムを書いて下さい。

-----問題ここまで----- */
/* -----解説等-----

http://yosupo.hatenablog.com/entry/2015/03/27/025132
https://twitter.com/search?f=tweets&vertical=default&q=%E3%81%8D%E3%81%9F%E3%81%BE%E3%81%95%E6%B3%95&src=typd
https://www.slideshare.net/kmjp/yukicoder-no194?ref=http://kmjp.hatenablog.jp/entry/2015/04/27/0900
http://tosaka2.hatenablog.com/entry/2018/02/04/211431

テストケース激弱そう

----解説ここまで---- */

// きたまさ法 N項間漸化式のK項目の行列累乗の高速化、O(N^2logK)
struct Kitamasa {
	VL C;
	Kitamasa(VL& p):C(p) {}
	VL mul(VL& u, VL& v) {
		int S = u.size();
		VL ret(2 * S - 1, 0);
		FOR(i, 0, S) {
			FOR(j, 0, S) {
				ret[i + j] += u[i] * v[j];
				ret[i + j] %= MOD;
			}
		}
		for (int i = 2 * S - 2; i >= S; i--) {
			FOR(j, 0, S) {
				ret[i - 1 - j] += ret[i] * C[j];
				ret[i - 1 - j] %= MOD;
			}
		}
		ret.resize(S);
		return ret;
	}
	// 1に対して次の遷移がNになるような行列という意味
	// A*xのxは、降順
	VL calcA_N(LL N) { // companion行列のmat[0][*]のみを計算し、N乗のものを返す(実際にはN-1乗)
		LL EXP = N - 1;
		int S = SZ(C);
		VL a(S, 0), b(S, 0);
		a[0] = 1;
		b[1] = 1;
		while (EXP > 0) {
			if (EXP&1) {
				a = mul(a, b);
			}
			b = mul(b, b);
			EXP /= 2;
		}
		return a;
	}
};

int solve(LL N, LL P, LL C) {
	VI pdice = { 2,3,5,7,11,13 };
	VI cdice = { 4,6,8,9,10,12 };

	auto makeDP = [](int n, const VI&dice) {
		VVI dp(n + 1, VI(dice.back() * n + 1, 0));
		dp[0][0] = 1;
		for (int d : dice) {
			FOR(i, 0, n) {
				FOR(x, 0, dice.back() * (i + 1) + 1 - d) {
					(dp[i + 1][x + d] += dp[i][x]) %= MOD;
				}
			}
		}
		return dp.back();
	};
	VI Pdp = makeDP(P, pdice);
	VI Cdp = makeDP(C, cdice);
	LL sz = P * pdice.back() + C * cdice.back();
	VL cmtable(sz + 1, 0);
	FOR(i, 0, P*pdice.back() + 1) {
		FOR(j, 0, C*cdice.back() + 1) {
			(cmtable[i + j] += Pdp[i] * Cdp[j]) %= MOD;
		}
	}

	vector<LL> a(sz, 0), x(sz, 1);
	FOR(i, 0, sz)a[i] = cmtable[i + 1];// , cout << i << ", " << a[i] << endl;
	Kitamasa mt(a);
	VL res = mt.calcA_N(N + sz);
	LL ans = 0;
	FOR(i, 0, sz) {
		ans += res[i];
		ans %= MOD;
	}
	return ans;
}

signed main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	//LL N, P, C; cin >> N >> P >> C;
	//cout << solve(N, P, C) << endl;
	//return 0;
	assert(solve(1, 1, 1) == 36);
	assert(solve(1, 2, 0) == 21);
	assert(solve(5, 2, 0) == 41);
	assert(solve(6, 2, 0) == 61);
	assert(solve(1, 10, 10) == 9018009);
	assert(solve(100000, 8, 12) == 144097395);

	return 0;
}
