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
#define debug(x) cerr << #x << ": " << x << endl
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/10/06  Problem: ARC 042 B / Link: http://arc042.contest.atcoder.jp/tasks/arc042_b  ----- */
/* ------問題------

アリの高橋くんは凸多角形状の板の上にいます。 高橋くんは向いている方向にまっすぐ歩いていきますが、どの方向を向いているかはわかりません。 高橋くんは板の周囲にたどり着くと落ちてしまいます。 高橋くんの位置と板を構成する凸多角形の頂点の位置が与えられるので、高橋くんが板から落ちるまでに歩く最短の距離を求めてください。位置は全て２次元座標で与えられます。

-----問題ここまで----- */
/* -----解説等-----

何も考えません　貼ります

----解説ここまで---- */

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
typedef struct Line {
	Point s, e;
	Line(Point s_, Point e_) : s(s_), e(e_) {}
} Segment;
Double dist_point_line(const Point& p, const Line& l) {
	return fabs(cross(p - l.s, l.e - l.s)) / abs(l.e - l.s);
}
Double dist_point_seg(const Point& p, const Segment& s) {
	if (dot(s.e - s.s, p - s.s) < EPS) return abs(p - s.s);
	if (dot(s.s - s.e, p - s.e) < EPS) return abs(p - s.e);
	return dist_point_line(p, s);
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int x, y; cin >> x >> y;
	Point p(x, y);
	Double ans = INF;
	vector<Point>poly;

	int N; cin >> N;
	FOR(i, 0, N) {
		int px, py; cin >> px >> py;
		poly.push_back(Point(px, py));
	}
	FOR(i, 0, N) {
		Segment s(poly[i], poly[(i + 1) % N]);
		Double ret = dist_point_seg(p, s);
		ans = min(ans, ret);
	}

	cout << fixed << setprecision(15) << ans << "\n";

	return 0;
}