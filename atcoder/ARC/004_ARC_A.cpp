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

/* -----  2018/12/13  Problem: ARC 004 A / Link: http://arc004.contest.atcoder.jp/tasks/arc004_a  ----- */
/* ------問題------

平面上に N 個の点があり、それぞれ 0 から N−1 までの番号が付けられており、それぞれの点について x 座標と y 座標が与えられています。
その N 点のうち 2 点を選び結んで得られる線分のうち、最も長くなる線分の長さを求めてください。

-----問題ここまで----- */
/* -----解説等-----

全探索!

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; 
	cin >> N;
	vector<double>x(N), y(N);
	FOR(i, 0, N) {
		cin >> x[i] >> y[i];
	}
	double ans = 0;
	FOR(i, 0, N) {
		FOR(j, 0, N) {
			auto f = [](double x) {
				return x * x;
			};
			double ret =sqrt(f(x[i]-x[j])+f(y[i]-y[j]));
			ans = max(ans, ret);
		}
	}
	cout << fixed << setprecision(10) << ans << endl;

	return 0;
}
