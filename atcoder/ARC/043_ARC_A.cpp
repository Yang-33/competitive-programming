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

/* -----  2018/10/28  Problem: ARC 043 A / Link: http://arc043.contest.atcoder.jp/tasks/arc043_a  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----



----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, A, B; cin >> N >> A >> B;
	VL a(N);
	FOR(i, 0, N) {
		cin >> a[i];
	}
	LL Max = *max_element(ALL(a));
	LL Min = *min_element(ALL(a));
	if (Max == Min) {
		if (B == 0) { // B>=1だった…
			double P = A / (accumulate(ALL(a), 0.0) / N);
			cout << fixed << setprecision(10) << P << " " << 0 << endl;
		}
		else {
			cout << -1 << endl;
		}
	}
	else {
		double P = 1.0*B / (Max - Min);
		double Q = 1.0*A - accumulate(ALL(a), 0.0)*P / N;
		cout << fixed << setprecision(10) << P << " " << Q << endl;
	}

	return 0;
}
