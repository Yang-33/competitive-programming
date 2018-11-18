#include <bits/stdc++.h>
using namespace std;

using VS = vector<string>;    using LL = __int128;
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

/* -----  2018/11/18  Problem: ARC 051 C / Link: http://arc051.contest.atcoder.jp/tasks/arc051_c  ----- */
/* ------問題------

N 個の整数 a1,a2,…,aN が与えられるので、一番小さいものを A 倍する、という操作を B 回行います。
この結果できた整数たちを昇順に並べ、順番に出力してください。
ただし出力するときは、出力したい数を 109+7 で割ったあまりを出力するようにしてください。
なお、109+7 で割ったあまりを昇順に並べる、というわけではないことに注意してください。

-----問題ここまで----- */
/* -----解説等-----

ある程度やると、巡回するだけになる。
その状態にたどり着くまで、N*log(MAX)ぐらいなので、適当にやれば良い。
出力順番は累乗する回数が少ない∧もとの値が小さい順であることに注意。
どっかがoverflowしたので128bitにした。

----解説ここまで---- */
const LL mod = MOD;
long long modpow(LL a, LL b) {
	if (b == 0) return 1;
	return modpow(a * a % mod, b / 2) * (b & 1 ? a : 1) % mod;
}
long long mul(LL a, LL b) {
	return (a * b) % mod;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	long long Nin, Ain, Bin; cin >> Nin >> Ain >> Bin;
	LL N = Nin, A = Ain, B = Bin;
	VL a(N);
	FOR(i, 0, N) {
		long long ain; cin >> ain;
		a[i] = ain;
	}
	if (A == 1) {
		SORT(a);
		FOR(i, 0, N) {
			cout << (long long)a[i] << " \n"[i == N - 1];
		}
	}
	else {
		// 愚直
		// N*30
		auto add = [&]() {
			while (B) {
				PLL b = PLL(LINF, -1);
				FOR(i, 0, N) {
					b = min(b, PLL(a[i], i));
				}
				B--;
				a[b.second] *= A;
				auto it = minmax_element(ALL(a));
				if (*it.first*A > *it.second)break;
			}
		};
		add();
		if (B) {
			LL divs = B / N;
			SORT(a);
			LL modulo = B - (B / N) * N;
			FOR(i, 0, N) {
				if (i < modulo) {
				}
				else {
					cout << mul(a[i], modpow(A, divs)) << endl;
				}
			}
			FOR(i, 0, modulo) {
				cout << mul(a[i], modpow(A, divs + 1)) << endl;
			}
		}
		else {
			SORT(a);
			FOR(i, 0, N) {
				cout << (long long)(a[i] % MOD) << endl;
			}
		}

	}

	return 0;
}
