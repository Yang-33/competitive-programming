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

/* -----  2018/11/12  Problem: EDU054 C / Link: __CONTEST_URL__  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----



----解説ここまで---- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
#define double long double
	LL ta; cin >> ta;
	const double EPS = 1e-6;
	auto check = [&](double a, double b, double D) {
		return a >= 0 && b >= 0 && abs(a + b - a * b) <= EPS && abs((a + b) - D) <= EPS;
	};
	FOR(_, 0, ta) {
		LL D; cin >> D;
		{
			double a = 1;
			double b = -D;
			double c = D;
			double dd = b * b - 4 * a*c;
			int f = 0;
			if (dd >= 0) {
				for (int i = -1; i <= 1; i += 2) {
					double x = -b + i * sqrt(dd);
					x /= (2 * a);
					double y = D - x;
					if (!f&&check(x, y, D)) {
						x = abs(x);
						cout <<fixed<<setprecision(10)<< "Y " << x << " " << y << endl;
						f = 1;
					}
				}
			}
			if (!f) {
				cout << "N" << endl;
			}

		}
	}

	return 0;
}
