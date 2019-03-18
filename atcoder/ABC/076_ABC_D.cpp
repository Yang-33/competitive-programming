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

/* -----  2019/03/16  Problem: ABC 076 D / Link: http://abc076.contest.atcoder.jp/tasks/abc076_d  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N;
	cin >> N;
	vector<double> t(N);
	for (int i = 0; i < N; ++i) {
		cin >> t[i];
	}
	vector<double> limit_v(N);
	for (int i = 0; i < N; ++i) {
		cin >> limit_v[i];
	}

	vector<double>de_min(N + 1, 0);
	double now_v = 0;
	FOR(i, 0, N) {
		now_v = min(now_v + t[i], limit_v[i]);
		de_min[i + 1] = now_v;
	}
	de_min[N] = 0;
	now_v = 0;
	FORR(i, N - 1, 0 - 1) {
		now_v = min(now_v + t[i], limit_v[i]);
		de_min[i] = min(de_min[i], now_v);
	}

	double ans = 0;
	FOR(i, 0, N) {
		double virtual_v = max(de_min[i], de_min[i + 1]) + (t[i] - abs(de_min[i] - de_min[i + 1])) / 2;
		double virtual_s = (de_min[i] + virtual_v)*(virtual_v - de_min[i]) / 2 + (de_min[i+1] + virtual_v)*(virtual_v - de_min[i + 1]) / 2;
		if (virtual_v < limit_v[i])ans += virtual_s;
		else {
			ans += virtual_s - (virtual_v-limit_v[i])*(virtual_v - limit_v[i]);
		}
	}
	cout << fixed << setprecision(10) << (ans) << "\n";

	return 0;
}
