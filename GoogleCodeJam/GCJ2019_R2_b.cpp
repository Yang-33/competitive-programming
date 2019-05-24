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

/* -----  2019/05/18  Problem: GCJ2019_R2 B / Link: __CONTEST_URL__  ----- */


// name:
void solve_small(int testcasenum) {
	int N; cin >> N;
	VI a(N), b(N);
	FOR(i, 0, N) {
		cin >> a[i] >> b[i];
	}

	int X = INF, Y = INF;
	FOR(x, 1, 201) {
		FOR(y, 1, 201) {
			bool ok = 1;
			VI res;
			res.push_back(0);
			FOR(i, 0, N) {
				int c = x * a[i] + y * b[i];
				if (res.back() >= c)ok = 0;
				res.push_back(c);
			}
			if (ok) {
				X = x, Y = y;
				goto En;
			}
		}
	}

En:;
	cout << "Case #" << testcasenum << ": ";
	if (X == INF) {
		cout << "IMPOSSIBLE" << endl;
	}
	else {
		cout << X << " " << Y << endl;
	}
}


void calc(LL lx, LL ly, LL rx, LL ry, LL mix, LL miy, LL max, LL may) {
	LL x = lx + rx;
	LL y = ly + ry;
	if (y * mix <= x * miy) calc(x, y, rx, ry, mix, miy, max, may);
	else if (y * max >= x * may) calc(lx, ly, x, y, mix, miy, max, may);
	else {
		cout << x << " " << y << endl;
	}
}
void solve_large(int testcasenum) {
	cout << "Case #" << testcasenum << ": ";

	int N; cin >> N;
	VL x(N), y(N);
	FOR(i, 0, N) {
		cin >> x[i] >> y[i];
	}

	const string no = "IMPOSSIBLE";

	LL max = 0, may = 1;
	LL mix = 1, miy = 0;
	FOR(i, 0, N - 1) {
		LL dx = x[i + 1] - x[i];
		LL dy = y[i + 1] - y[i];
		if (dx <= 0 && dy <= 0) {
			cout << no << endl;
			return;
		}
		if (dx > 0 && dy < 0) { // 下領域の∧
			dy *= -1;
			LL d = __gcd(dx, dy);
			dx /= d;
			dy /= d;
			if (dx * max < dy * may) {
				max = dy;
				may = dx;
			}
		}
		else if (dx < 0 && dy > 0) { // 上領域の∧
			dx *= -1;
			LL d = __gcd(dx, dy);
			dx /= d;
			dy /= d;
			if (dx * mix > dy * miy) {
				mix = dy;
				miy = dx;
			}
		}
	}
	if (mix * may <= max * miy) { //ない
		cout << no << endl;
		return;
	}
	// なんちゃら木でたどっていく
	calc(1, 0, 0, 1, mix, miy, max, may);

}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);


	int T; cin >> T;
	FOR(c, 0, T) {
		//solve_small(c + 1);
		solve_large(c + 1);
	}

	return 0;
}