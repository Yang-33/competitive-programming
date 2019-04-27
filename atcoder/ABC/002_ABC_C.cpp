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

/* -----  2019/04/22  Problem: ABC 002 C / Link: http://abc002.contest.atcoder.jp/tasks/abc002_c  ----- */

using Double = long double;
const double EPS = 1e-9;

typedef struct Point {
	Double x, y;
	Point(Double x_, Double y_) : x(x_), y(y_) {}
	bool operator < (const Point& a) const {
		return fabs(x - a.x) < EPS ? y + EPS < a.y : x + EPS < a.x;
	}
	bool operator > (const Point& a) const {
		return a < *this;
	}
	bool operator == (const Point& a) const {
		return !(a < *this) && !(a > *this);
	}
	Point operator + (const Point& a) const {
		return Point(x + a.x, y + a.y);
	}
	Point operator - (const Point& a) const {
		return Point(x - a.x, y - a.y);
	}
	Point operator * (const Point& a) const {
		return Point(x * a.x, y * a.y);
	}
	Point operator / (const Point& a) const {
		return Point(x / a.x, y / a.y);
	}
	Point operator * (const Double& d) const {
		return Point(x * d, y * d);
	}
	Point operator / (const Double& d) const {
		return Point(x / d, y / d);
	}
} Vector;

Double cross(const Vector& a, const Vector& b) {
	return a.x * b.y - a.y * b.x;
}

Double area_of_tri(const Point& a, const Point& b, const Point& c) {
	Vector ac = a - c, bc = b - c;
	return abs(cross(ac, bc) / 2.);
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	double a, b, c, d, e, f; cin >> a >> b >> c >> d >> e >> f;
	Point A(a, b), B(c, d), C(e, f);
	cout << fixed << setprecision(10) << area_of_tri(A, B, C) << endl;

	return 0;
}
