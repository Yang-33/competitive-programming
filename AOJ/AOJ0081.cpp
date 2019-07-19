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

/* -----  2019/07/19  Problem: AOJ 0081 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0081  ----- */

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

// ノルム
Double norm(const Point& a) {
	return a.x * a.x + a.y * a.y;
}
// サイズ
Double abs(const Point& a) {
	return sqrt(norm(a));
}
// 内積
Double dot(const Vector& a, const Vector& b) {
	return a.x * b.x + a.y * b.y;
}

// 直線、線分構造体
typedef struct Line {
	Point s, e;
	Line(Point s_, Point e_) : s(s_), e(e_) {}
} Segment;

Point project(Segment s, Point p) {
	Vector base = s.e - s.s;
	double r = dot(p - s.s, base) / norm(base);
	return s.s + base * r;
}

Point reflect(Segment s, Point p) {
	return p + (project(s, p) - p)*2.0;
}

stringstream deletecommma(string line) {
	istringstream ss(line);
	string s;
	stringstream input;
	while (getline(ss, s, ',')) {
		input << s; input << " ";
	}
	return input;
}

int main() {
	string in;
	while (cin >> in) {
		auto input = deletecommma(in);
		double x1, y1, x2, y2, A, B;
		input >> x1 >> y1 >> x2 >> y2 >> A >> B;
		Line L(Point(x2, y2), Point(x1, y1));
		Point Q(A, B);
		Point R = reflect(L, Q);
		cout << fixed << setprecision(10) << R.x << " " << R.y << "\n";
	}
}