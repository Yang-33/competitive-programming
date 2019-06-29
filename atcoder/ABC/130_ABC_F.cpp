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

/* -----  2019/06/16  Problem: ABC 130 F / Link: http://abc130.contest.atcoder.jp/tasks/abc130_f  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; cin >> N;
	// 散文探索だとアレ?2*tの整数しかないので。。。
	using tp = tuple<LL, LL, char>;
	vector<tp>p(N);
	FOR(i, 0, N) {
		LL x, y; cin >> x >> y;
		char d; cin >> d;
		p[i] = tp(x, y, d);
	}

	auto f = [&](double t) {
		double xmn = LINF, xmx = -LINF;
		double ymn = LINF, ymx = -LINF;
		FOR(i, 0, N) {
			LL x, y;
			char d;
			tie(x, y, d) = p[i];
			if (d == 'L' || d == 'R') {
				double dx;
				if (d == 'L')dx = x - t;
				else dx = x + t;
				ymn = min(ymn, (double)y);
				ymx = max(ymx, (double)y);
				xmn = min(xmn, dx);
				xmx = max(xmx, dx);
			}
			else {
				double dy;
				if (d == 'D')dy = y - t;
				else dy = y + t;
				xmn = min(xmn, (double)x);
				xmx = max(xmx, (double)x);
				ymn = min(ymn, dy);
				ymx = max(ymx, dy);

			}
		}
		return (xmx-xmn)*(ymx-ymn);

	};
	double L = 0, R = 1e9;
	FOR(i, 0, 200) {
		double mid1 = (2 * L + R) / 3;
		double mid2 = (L + 2 * R) / 3;
		double s1 = f(mid1);
		double s2 = f(mid2);
		if (s1 < s2) {
			R = mid2;
		}
		else {
			L = mid1;
		}
	}
	cout << fixed << setprecision(10) << f(L) << endl;

	//using tp = tuple<LL, bool>;
	//vector<tp>yoko, tate;
	//LL Wmn = LINF, Wmx = -LINF;
	//LL Hmn = LINF, Hmx = -LINF;
	//FOR(i, 0, N) {
	//	LL x, y; cin >> x >> y;
	//	char d; cin >> d;
	//	if (d == 'R' || d == 'L') {
	//		Hmn = min(Hmn, y);
	//		Hmx = max(Hmx, y);
	//		yoko.push_back(tp(x, d == 'R'));
	//	}
	//	else {
	//		Wmn = min(Wmn, x);
	//		Wmx = max(Wmx, x);
	//		tate.push_back(tp(y, d == 'U'));
	//	}
	//}

	//auto f = [](const vector<tp>&a, LL mn, LL mx) {
	//	// [mn,mx]に入ればOK
	//	for (auto it : a) {
	//		LL p; bool up;
	//		tie(p, up) = it;
	//		if (up) {
	//			if (mx < p)mx = p;
	//		}
	//		else {
	//			if (p < mn)mn = p;
	//		}
	//	}
	//	return mx - mn;
	//};
	//LL ans = f(yoko, Wmn, Wmx)*f(tate, Hmn, Hmx);


	//cout << (ans) << "\n";

	return 0;
}
