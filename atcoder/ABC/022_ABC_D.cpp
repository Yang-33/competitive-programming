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

/* -----  2019/04/09  Problem: ABC 022 D / Link: http://abc022.contest.atcoder.jp/tasks/abc022_d  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; cin >> N;
	vector<double>ax(N), ay(N), bx(N), by(N);
	double gax = 0, gay = 0, gbx = 0, gby = 0;
	FOR(i, 0, N) {
		cin >> ax[i] >> ay[i];
		gax += ax[i]; gay += ay[i];
	}
	FOR(i, 0, N) {
		cin >> bx[i] >> by[i];
		gbx += bx[i]; gby += by[i];
	}
	gax = gax / N;
	gay = gay / N;
	gbx = gbx / N;
	gby = gby / N;

	double a = 0.0, b = 0.0;

	FOR(i, 0, N) {
		a += ((gax - ax[i])*(gax - ax[i]) + (gay - ay[i])*(gay - ay[i]));
		b += ((gbx - bx[i])*(gbx - bx[i]) + (gby - by[i])*(gby - by[i]));
	}
	double ans = sqrt(b / a);
	cout << fixed << setprecision(10) << ans << endl;

	return 0;
}
