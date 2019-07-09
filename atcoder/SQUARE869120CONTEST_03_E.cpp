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

/* -----  2019/07/09  Problem: SQUARE869120CONTEST_03 E / Link: https://atcoder.jp/contests/s8pc-3/  ----- */


LL N, K;
double theta;
double calc(int a, int b, int c) {
	return (sin(a*theta) + sin(b*theta) + sin(c*theta)) / 2;
}
LL count(double s) {
	LL cntsum = 0;
	FOR(a, 1, N - 1) {
		int lef = N - a;
		double ac = (2 * s - sin(a*theta)) / 2.0 / sin(lef*theta / 2);
		int tmp = 0;
		if (ac >= 1) {
			tmp = lef - 1;
		}
		else if (ac < -1) {

		}
		else {
			double t = acos(ac);
			int x = ceil(t / theta + lef / 2.0);
			if (x < lef) tmp = (lef - x) * 2;
		}
		cntsum += tmp;
	}
	return cntsum * 2;
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> K;
	theta = 2 * PI / N;
	K = (K - 1) * 6 / N;
	double ub = 1.3, lb = 0;
	FOR(_, 0, 40) {
		double m = (ub + lb) / 2;
		if (count(m) > K) ub = m;
		else lb = m;
	}
	cout << fixed << setprecision(10) << ub << endl;
}