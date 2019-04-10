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

/* -----  2019/04/10  Problem: ABC 016 D / Link: http://abc016.contest.atcoder.jp/tasks/abc016_d  ----- */

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
// 外積
Double cross(const Vector& a, const Vector& b) {
	return a.x * b.y - a.y * b.x;
}

// counter clockwise
int ccw(const Point& a, const Point& b, const Point&  c) {
	Vector ba = b - a, ca = c - a;
	if (cross(ba, ca) > EPS) return +1; // ccw
	if (cross(ba, ca) < -EPS) return -1; // cw
	if (dot(ba, ca) < -EPS) return +2; // c-a-b
	if (abs(ba) + EPS < abs(ca)) return -2; // a-b-c
	return 0; // a-c-b
}

// 直線、線分構造体
typedef struct Line {
	Point s, e;
	Line(Point s_, Point e_) : s(s_), e(e_) {}
} Segment;

// 線分の交差判定
bool is_crossss(const Segment& a, const Segment& b) {
	return (ccw(a.s, a.e, b.s) * ccw(a.s, a.e, b.e) <= 0
		&& ccw(b.s, b.e, a.s) * ccw(b.s, b.e, a.e) <= 0);
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	Double ax, ay, bx, by;
	cin >> ax >> ay >> bx >> by;
	Point a(ax, ay), b(bx, by);
	Segment seg(a, b);

	int N; cin >> N;
	vector<double> x(N), y(N);
	for (int i = 0; i < N; ++i) {
		cin >> x[i] >> y[i];
	}

	LL ans = 0LL;
	FOR(i, 0, N) {
		Segment seg2(Point(x[i],y[i]), Point(x[(i+1)%N],y[(i + 1) % N]));
		ans += is_crossss(seg, seg2);
	}

	ans = ans / 2 + 1;
	
	cout << (ans) << "\n";

	return 0;
}
