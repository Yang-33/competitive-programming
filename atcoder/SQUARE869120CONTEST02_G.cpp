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

/* -----  2019/07/02  Problem: square869120Contest02 G / Link: https://atcoder.jp/contests/s8pc-2/tasks/  ----- */

// あんまり引けない
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

Double norm(const Point& a) {
	return a.x * a.x + a.y * a.y;
}
Double abs(const Point& a) {
	return sqrt(norm(a));
}
Double dot(const Vector& a, const Vector& b) {
	return a.x * b.x + a.y * b.y;
}
Double cross(const Vector& a, const Vector& b) {
	return a.x * b.y - a.y * b.x;
}

int ccw(const Point& a, const Point& b, const Point&  c) {
	Vector ba = b - a, ca = c - a;
	if (cross(ba, ca) > EPS) return +1;
	if (cross(ba, ca) < -EPS) return -1;
	if (dot(ba, ca) < -EPS) return +2;
	if (abs(ba) + EPS < abs(ca)) return -2;
	return 0;
}
struct Polygon {
	vector< Point > vert;
	Polygon(int n = 3) : vert(n, Point(0, 0)) {}

	Double area() const {
		Double res = 0;
		int v_size = size();

		FOR(i, 0, v_size) res += cross(at(i), at(i + 1));

		return fabs(res) / 2.;
	}

	Point at(int i) const {
		i %= size();
		return vert[i];
	}

	int size() const { return SZ(vert); }
};
Polygon convex_hull_on(vector< Point > vp) {
	if (SZ(vp) < 3) {
		Polygon ret;
		ret.vert = vp;
		return ret;
	}
	int n = SZ(vp);
	sort(ALL(vp));
	Polygon u; u.vert = { vp[0], vp[1] };
	Polygon l; l.vert = { vp[n - 1],vp[n - 2] };
	for (int i = 2; i < n; i++) {
		for (int j = (int)u.size(); j >= 2 && ccw(u.vert[j - 2], u.vert[j - 1], vp[i]) >= 0; j--)u.vert.pop_back();
		u.vert.push_back(vp[i]);
	}
	for (int i = n - 3; i >= 0; i--) {
		for (int j = (int)l.size(); j >= 2 && ccw(l.vert[j - 2], l.vert[j - 1], vp[i]) >= 0; j--)l.vert.pop_back();
		l.vert.push_back(vp[i]);
	}
	reverse(l.vert.begin(), l.vert.end());
	for (int i = (int)u.size() - 2; i >= 1; i--)l.vert.push_back(u.vert[i]);
	return l;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; cin >> N;
	vector<Point>P;
	FOR(i, 0, N) {
		int x, y; cin >> x >> y;
		P.push_back(Point(x, y));
	}
	if (N == 1) {
		cout << 0 << endl;
	}
	else if (N == 2) {
		cout << 1 << endl;
	}
	else if (N == 3) {
		cout << 3 << endl;
	}
	else {
		auto poc = convex_hull_on(P);
		LL out = SZ(poc);
		LL in = N - SZ(poc);
		DD(de(out, in));
		LL ans = out;
		if (in == 0) {
			ans += out - 3;
		}
		else { // in > 0
			ans += out;
			if (in > 1) {
				ans += (in - 1) * 3;
			}
		}

		cout << (ans) << "\n";
	}

	return 0;
}
