#include "bits/stdc++.h"
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
#define debug(x) cerr << #x << ": " << x << endl
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/09/29  Problem: yukicoder 302  / Link: http://yukicoder.me/problems/no/302  ----- */
/* ------問題------

1 から 6 までの整数が等確率にでる普通のサイコロがあります．
このサイコロを独立に N 回振った時に，出目の和が L 以上 R 以下となる確率を求めるプログラムを書いて下さい．

-----問題ここまで----- */
/* -----解説等-----

https://cpprefjp.github.io/reference/cmath/erf.html
CPPのサイトに答えが書いてあるため…

まず小さいときはDPのでできる。
多きいときは、正規分布を思い出すとできる。

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; cin >> N;
	LL L, R; cin >> L >> R;
	L = max(N, L);
	R = min(6 * N, R);
	double ans = 0;
	if (N <= 5000) {
		vector<double>dp(6*N+10,0);
		dp[0] = 1;
		FOR(_, 0, N) {
			vector<double>nx(6*_+10,0);
			FORR(i, 6*(_), _-1) {
				FOR(k, 1, 6 + 1) {
					nx[i + k] += dp[i] / 6.0;
				}
			}
			nx.swap(dp);
		}
		for (LL i = L; i <= R; i++) {
			if (i <= 6 * N)
				ans += dp[i];
		}
	}
	else { // exp
		double ave = 3.5*N;
		double sigma = sqrt(N * 35.0 / 12.0);
		auto f = [&ave,&sigma](double x) {
			return 1 / 2.0*(1 + erf((x-ave)/(sqrt(2)*sigma)));
		};
		ans = f(R+0.5) - f(L-0.5);
	}




	cout << fixed << setprecision(15) << ans << "\n";

	return 0;
}
