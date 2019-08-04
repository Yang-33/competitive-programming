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

/* -----  2019/08/04  Problem: AOJ 0204 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0204  ----- */

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
// 距離
Double distance(const Point& a, const Point& b) {
	return abs(a - b);
}
// 直行判定
bool is_vertical(const Vector& a, const Vector& b) {
	return fabs(dot(a, b)) < EPS;
}
// 平衡判定
bool is_parrallel(const Vector& a, const Vector& b) {
	return fabs(cross(a, b)) < EPS;
}

// 単位ベクトル
Vector unit_vector(const Vector& a) {
	return a / abs(a);
}
// 法線ベクトル
pair<Vector, Vector> normal_vectors(const Vector& a) {
	return make_pair(Vector(a.y, -a.x), Vector(-a.y, a.x));
}
// 単位法線ベクトル
pair<Vector, Vector> normal_unit_vectors(const Vector& a) {
	return make_pair(unit_vector(Vector(a.y, -a.x)), unit_vector(Vector(-a.y, a.x)));
}

// ベクトルa,bのなす角のサイン値
Double sign(const Vector& a, const Vector& b) {
	return cross(a, b) / (abs(a) * abs(b));
}
// ベクトルa,bのなす角のコサイン値
Double cosign(const Vector& a, const Vector& b) {
	return dot(a, b) / (abs(a) * abs(b));
}

// degree to radian
Double degToRadian(Double deg) {
	return (deg) / 180 * acos(-1.0);
}

// a,b,c,  s=b-a,t=c-bとして
// radianToDeg(acos(cosign(s,t)))等で求める
// radian to degree
Double radianToDeg(Double radian) {
	return radian * 180 / acos(-1.0);
}


// 三角形の辺B,C間の角度
Double angle(Double _a, Double _b, Double _c) {
	return acos((_b * _b + _c * _c - _a * _a) / (2.0 * _b * _c));
}

// 回転
Point rotate(const Vector& v, Double rad) {
	return Vector(v.x * cos(rad) - v.y * sin(rad),
		v.x * sin(rad) + v.y * cos(rad));
}

// 三角形の面積
Double area_of_tri(const Point& a, const Point& b, const Point& c) {
	Vector ac = a - c, bc = b - c;
	return cross(ac, bc) / 2.;
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
bool checkEQ(Double a, Double b) { return (abs(a - b) < EPS); } // 誤差つき等号判定

																// 直線と直線の交差判定
bool is_crossll(const Line& a, const Line &b) {
	return !checkEQ(cross(a.e - a.s, b.e - b.s), 0.0);
}

// 直線と線分の交差判定
bool is_crossls(const Line&a, const Segment& b) {
	return is_crossll(a, b) && (cross(a.e - a.s, b.s - a.s)*cross(a.e - a.s, b.e - a.s) < EPS);
}

// 直線の平行判定
bool is_parrallel(const Line& a, const Line& b) {
	return is_parrallel(a.s - a.e, b.s - b.e);
}

// 直線の直行判定
bool is_vertical(const Line& a, const Line& b) {
	return is_vertical(a.s - a.e, b.s - b.e);
}


/*** distance ***/
// 点と線の距離
Double dist_point_line(const Point& p, const Line& l) {
	return fabs(cross(p - l.s, l.e - l.s)) / abs(l.e - l.s);
}

// 点と線分の距離
Double dist_point_seg(const Point& p, const Segment& s) {
	if (dot(s.e - s.s, p - s.s) < EPS) return abs(p - s.s);
	if (dot(s.s - s.e, p - s.e) < EPS) return abs(p - s.e);
	return dist_point_line(p, s);
}

// 線分と線分の距離
Double dist_seg_seg(const Segment& a, const Segment& b) {
	if (is_crossss(a, b)) return 0.;
	Double res = dist_point_seg(b.s, a);
	res = min(res, dist_point_seg(b.e, a));
	res = min(res, dist_point_seg(a.s, b));
	res = min(res, dist_point_seg(a.e, b));
	return res;
}

// 直線の交点
Point cross_point(const Line& a, const Line& b) {
	Double d1 = cross(b.e - b.s, b.s - a.s);
	Double d2 = cross(b.e - b.s, a.e - a.s);
	return a.s + (a.e - a.s) * d1 / d2;
}

// 点の直線上判定
bool point_on_line(const Point& p, const Line& l) {
	return ((ccw(l.s, l.e, p) + 2) % 2 == 0);
}

// 点の線分上判定
bool point_on_seg(const Point& p, const Segment& s) {
	return (ccw(s.s, s.e, p) == 0);
}

// line symmetry point
Point symmetry_point(const Point& p, const Line& l) {
	Vector b = p - l.s, c = l.e - l.s, a = b - c;
	double s = angle(abs(a), abs(b), abs(c));
	return l.s + rotate(b, 2 * s);
}
Point project(Segment s, Point p) {
	Vector base = s.e - s.s;
	double r = dot(p - s.s, base) / norm(base);
	return s.s + base * r;
}

Point reflect(Segment s, Point p) {
	return p + (project(s, p) - p)*2.0;
}

// 円構造体
struct Circle {
	Point c; Double r;
	Circle(Point c_, Double r_) : c(c_), r(r_) {}

	Double area() const { return PI * r * r; }
};

// 円の衝突
int circle_intersect(const Circle& a, const Circle& b) {
	Double d = abs(a.c - b.c);
	if (a.r + b.r + EPS < d) return 0; // 0 : outside
	if (b.r + d + EPS < a.r) return -3; // 0 : b in a
	if (a.r + d + EPS < b.r) return -4; // 0 : a in b
	if (fabs(a.r + b.r - d) < EPS) return 1; // 1 : outside
	if (fabs(b.r + d - a.r) < EPS) return 3; // 1 : b in a
	if (fabs(a.r + d - b.r) < EPS) return 4; // 1 : a in b
	return 2; // 2
}

// 2円の交点
vector<Point> cross_point(const Circle& a, const Circle& b) {
	vector<Point> res;
	Point x = unit_vector(b.c - a.c) * a.r;
	int ci = circle_intersect(a, b);

	if (ci > 0) {
		if (ci != 2) {
			res.push_back(a.c + x);
		}
		else {
			Double s = angle(b.r, abs(b.c - a.c), a.r);
			res.push_back(a.c + rotate(x, s));
			res.push_back(a.c + rotate(x, -s));
		}
	}

	return res;
}

// 点が円に含まれるか
bool circle_in(const Circle& c, const Point& p) {
	Double dist = distance(c.c, p);
	return (dist) <= c.r + EPS;
}

// 円と線分の交差判定
bool is_cross_circle_and_segment(const Circle& c, const Segment& s) {
	return (dist_point_seg(c.c, s) < c.r + EPS) && (c.r < abs(c.c - s.s) + EPS || c.r < abs(c.c - s.e) + EPS);
}

// 円と直線の交点
vector<Point> cross_point(const Circle& a, const Line& l) {
	vector<Point> res;
	Point n = normal_vectors(l.s - l.e).first;
	Point p = cross_point(l, Line(a.c, a.c + n));

	if (abs(abs(a.c - p) - a.r) < EPS) {
		res.push_back(p);
	}
	else if (abs(a.c - p) + EPS < a.r) {
		Double len = sqrt(a.r * a.r - norm(a.c - p));
		Point cp = unit_vector(l.s - l.e) * len;
		res.push_back(p + cp);
		res.push_back(p - cp);
	}

	return res;
}

// 2円の共通部分の面積
Double area_of_circle_intersect(const Circle& a, const Circle& b) {
	int ci = circle_intersect(a, b);
	if (ci == 0 || ci == 1) return 0.0;
	if (ci == 3 || ci == -3) return b.area();
	if (ci == 4 || ci == -4) return a.area();

	Double d = abs(a.c - b.c);
	Double s1 = angle(b.r, a.r, d), s2 = angle(a.r, b.r, d);
	Double tri = (a.r * a.r * sin(2.0 * s1) + b.r * b.r * sin(2.0 * s2)) / 2.;
	return a.r * a.r * s1 + b.r * b.r * s2 - tri;
}

// 点pから引いた円cの接線
vector<Line> tangent_line(const Circle& c, const Point& p) {
	vector<Line> res;
	Point a = c.c + unit_vector(p - c.c) * c.r;
	vector<Point> b = cross_point(Circle(c.c, abs(c.c - p)),
		Line(a, a + normal_vectors(c.c - p).first));
	FOR(i, 0, SZ(b)) {
		res.push_back(Line(p, c.c + unit_vector(b[i] - c.c) * c.r));
	}
	return res;
}

// 2円の共通接線
vector<Line> common_tangent_line(Circle a, Circle b) {
	vector<Line> res;
	if (a.c == b.c && fabs(a.r - b.r) < EPS) return res;

	if (a.r + EPS < b.r) swap(a, b);
	Point p = (b.c - a.c) * a.r / (a.r + b.r) + a.c;

	if (abs(a.c - p) + EPS > a.r) res = tangent_line(a, p);

	if (abs(a.r - b.r) < EPS) {
		pair<Point, Point> n = normal_vectors(unit_vector(b.c - a.c) * a.r);
		res.push_back(Line(a.c + n.first, b.c + n.first));
		res.push_back(Line(a.c + n.second, b.c + n.second));
	}
	else {
		p = (b.c - a.c) * a.r / (a.r - b.r) + a.c;
		if (abs(a.c - p) + EPS > a.r) {
			vector<Line> tmp = tangent_line(a, p);
			FOR(i, 0, SZ(tmp)) res.push_back(tmp[i]);
		}
	}

	return res;
}

// 矩形構造体
struct Rect {
	Point lt, rb;
	Rect(Point lt_, Point rb_) : lt(lt_), rb(rb_) {}
};

// 矩形の交差判定
bool rect_intersect(const Rect& a, const Rect& b) {
	return (a.lt.x <= b.rb.x && a.lt.y <= b.rb.y && b.lt.x <= a.rb.x && b.lt.y <= a.rb.y);
}


// 多角形構造体
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

// 点の内包判定
enum { IN, ON, OUT };
int point_in_poly(const Polygon& g, const Point& p) {
	bool in = false;
	int n = SZ(g);

	FOR(i, 0, n) {
		Point a = g.at(i) - p, b = g.at(i + 1) - p;
		if (a.y > b.y) swap(a, b);
		if (a.y <= 0 && 0 < b.y && cross(a, b) + EPS < 0) in = !in;
		if (fabs(cross(a, b)) < EPS && dot(a, b) <= 0) return ON;
	}

	return in ? IN : OUT;
}

// 多角形同士の交差判定 not verified
int poly_touch_poly(const Polygon& a, const Polygon& b) {
	int status = OUT;
	auto update = [&](int &as, int bs) {
		if (bs == IN)as = IN;
		if (bs == ON)as = (as == ON ? ON : IN);
	};
	for (auto p : a.vert) {
		update(status, point_in_poly(b, p));
	}
	for (auto p : b.vert) {
		update(status, point_in_poly(a, p));
	}
	return status;
}

// 凸包
Polygon convex_hull(vector< Point > vp) {
	if (SZ(vp) <= 1) {
		Polygon ret;
		ret.vert = vp;
		return ret;
	}
	int n = SZ(vp), k = 0;
	sort(ALL(vp));
	vector< Point > ch(2 * n, Point(0, 0));

	for (int i = 0; i < n; ch[k++] = vp[i++]) {
		while (k >= 2 && ccw(ch[k - 2], ch[k - 1], vp[i]) <= 0) --k;
	}

	for (int i = n - 2, t = k + 1; i >= 0; ch[k++] = vp[i--]) {
		while (k >= t && ccw(ch[k - 2], ch[k - 1], vp[i]) <= 0) --k;
	}

	Polygon res(k - 1);
	FOR(i, 0, k - 1) res.vert[i] = ch[i];
	return res;
}

// 凸包 line上含む
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

// キャリパー法 凸多角形の最遠点対、距離を得る O(N)
pair< PII, Double > caliper(const Polygon& p) {
	int n = SZ(p);
	if (n == 2) {
		return make_pair(PII(0, 1), abs(p.at(0) - p.at(1)));
	}
	int i = 0, j = 0;
	FOR(k, 0, n) {
		if (!(p.at(i) < p.at(k))) i = k;
		if (p.at(j) < p.at(k)) j = k;
	}
	PII pp(-1, -1);
	Double res = 0;
	int si = i, sj = j;
	while (i != sj || j != si) {
		Double cur = abs(p.at(i) - p.at(j));

		if (res + EPS < cur) {
			res = cur;
			pp = PII(i, j);
		}
		int di = (i + 1) % n;
		int dj = (j + 1) % n;
		if (cross(p.at(di) - p.at(i), p.at(dj) - p.at(j)) < 0) i = di;
		else j = dj;
	}

	return make_pair(pp, res);
}

// 円の内部に多角形が完全に含まれるか?
bool poly_in_circle(const Circle& c, const Polygon& g) {
	bool in = 1;
	for (auto p : g.vert) {
		in &= circle_in(c, p);
	}
	return in;
}

// 多角形の内部に円が完全に含まれるか?
bool circle_in_poly(const Polygon& p, const Circle& c) {
	set<int>ccw_res; {
		FOR(i, 0, SZ(p.vert)) {
			ccw_res.insert(ccw(p.vert[i], p.vert[(i + 1) % SZ(p.vert)], c.c));
		}
	}
	if ((int)ccw_res.size() > 1)return false;
	FOR(i, 0, SZ(p.vert)) {
		Segment seg(p.vert[i], p.vert[(i + 1) % SZ(p.vert)]);
		if (c.r > dist_point_seg(c.c, seg)) {
			return false;
		}
	}
	return true;
}

// 円と多角形の交錯判定
bool is_cross_circle_and_polygon(const Circle& c, const Polygon& g) {
	FOR(i, 0, SZ(g.vert)) {
		if (is_cross_circle_and_segment(c, Segment(g.vert[i], g.vert[(i + 1) % SZ(g.vert)])))return true;
	}
	return false;
}


int main() {
	Double R; int N;
	while (cin >> R >> N, N) {
		vector<int>alive(N, 1);
		vector<Double>v(N);
		vector<Double>dist(N);
		vector<Circle>cs; {
			FOR(i, 0, N) {
				double x, y, r, vv;
				cin >> x >> y >> r >> vv;
				cs.emplace_back(Point(x, y), r);
				v[i] = vv;
				dist[i] = distance(cs.back().c, Point(0, 0));
			}
		}
		// sim
		for (;;) {
			// 1 minutes
			FOR(i, 0, N) {
				dist[i] = max(R - 100, dist[i] - v[i]);
			}

			// find nearest
			Double mndist = LINF;
			int id = -1;
			FOR(i, 0, N) {
				if (!alive[i])continue;
				if (dist[i] < R + EPS)continue;
				if (dist[i] > mndist)continue;
				mndist = dist[i];
				id = i;
			}
			if (id == -1)break;
			Point from(cs[id].c); {
				from = unit_vector(from);
				from.x *= R;
				from.y *= R;
			}
			Point to(from); {
				to.x *= 2000;
				to.y *= 2000;
			}

			Segment seg(from, to);
			FOR(i, 0, N) {
				if (!alive[i])continue;
				if (dist[i] < R + EPS)continue;
				Point a = cs[i].c;
				// ビームとの衝突点
				// - 移動した円を求める
				// - 衝突するかの判定
				a.x /= distance(cs[i].c, Point(0, 0));
				a.y /= distance(cs[i].c, Point(0, 0));
				a.x *= dist[i];
				a.y *= dist[i];
				if (dist_point_seg(a, seg) < EPS + cs[i].r)alive[i] = 0;
			}
		}

		int ans = 0;
		FOR(i, 0, N) {
			if (alive[i])ans++;
		}
		cout << ans << "\n";

	}
}