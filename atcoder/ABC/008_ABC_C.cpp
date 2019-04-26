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

/* -----  2019/04/17  Problem: ABC 008 C / Link: http://abc008.contest.atcoder.jp/tasks/abc008_c  ----- */

// c_iの約数をもつ列の順列
// 自身の左にある個数
// これはおなじだけ存在: 一定
// C+1個ある
// このうち左にあるものの個数のmod2が表裏
// S+1:偶数 左の個数/2だけありうる
// . . . . X .
// . . X . . .
// X . . . . . 
// (S+1)/2/(S+1)
//
// S+1:奇数
// . . . . . . X
// . . . . X . . 
// . . X . . . . 
// X . . . . . . '
// (S+1+2-1)/2/(S+1)
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N;
	cin >> N;
	vector<LL> a(N);
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
	}
	double ans = 0;
	FOR(i, 0, N) {
		LL cnt = 0;
		FOR(j, 0, N) {
			if (a[i] % a[j] == 0)cnt++;
		}
		LL p = (cnt + 1) / 2;
		DD(de(a[i], cnt, p))
			ans += p / (1.0*cnt);
	}
	cout << fixed << setprecision(10) << ans << endl;

	return 0;
}
