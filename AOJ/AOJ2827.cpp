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

/* -----  2018/06/23  Problem: AOJ 2827 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2827  ----- */
/* ------問題------

凸多角形柱工業都市 (Industrial Convex Pillar City, ICPC) はいくつかの凸多角形柱の形状をした建物からなる街である．あなたはこの街の中を現在地 S から目的地 T に向けて歩こうとしている．今日は日差しが強いので，出来る限りひなたを通らずに目的地へ向かいたい．あなたが立っている地点と太陽を一直線に結んだ線上に建物がある場合，あなたは建物の陰にいるので日差しを受けずにすむ．また，この街の建物の外周には全てひさしが付いているので，建物の外周に沿って歩いている間は，日が当たる縁に沿って歩いても日差しを受けることはない．あなたは建物の内部以外はこの街をどこでも自由に歩くことができる．
もっとも日差しを受けないように現在地から目的地まで歩いた時の，ひなたを歩く距離を出力するプログラムを作成しなさい．

-----問題ここまで----- */
/* -----解説等-----

本質が射影パートなので最短路をやるだけ。
が、s-tをつなぎ忘れがちなので注意

----解説ここまで---- */


typedef double ld;
typedef complex<ld> Point;
const ld eps = 1e-9, pi = acos(-1.0);
namespace std {
	bool operator<(const Point &lhs, const Point &rhs) {
		if (lhs.real() < rhs.real() - eps) return true;
		if (lhs.real() > rhs.real() + eps) return false;
		return lhs.imag() < rhs.imag();
	}
}
Point input_point() { ld x, y; scanf("%lf%lf", &x, &y); return Point(x, y); } // 点の入力
bool eq(ld a, ld b) { return (abs(a - b) < eps); } // 誤差つき等号判定
ld dot(Point a, Point b) { return real(conj(a) * b); } // 内積
ld cross(Point a, Point b) { return imag(conj(a) * b); } // 外積

// 直線の定義
class Line {
public:
	Point a, b;
	Line() : a(Point(0, 0)), b(Point(0, 0)) {}
	Line(Point a, Point b) : a(a), b(b) {}
	Point operator[](const int _num) {
		if (_num == 0)return a;
		else if (_num == 1)return b;
		else assert(false);
	}
};

// 円の定義
class Circle {
public:
	Point p;
	ld r;
	Circle() : p(Point(0, 0)), r(0) {}
	Circle(Point p, ld r) : p(p), r(r) {}
};

// 垂線の足
Point proj(Line l, Point p) {
	ld t = dot(p - l.a, l.a - l.b) / norm(l.a - l.b);
	return l.a + t * (l.a - l.b);
}

// CCW
int ccw(Point a, Point b, Point c) {
	b -= a; c -= a;
	if (cross(b, c) > eps) return 1;   // a,b,cが反時計周りの順に並ぶ
	if (cross(b, c) < -eps) return -1; // a,b,cが時計周りの順に並ぶ
	if (dot(b, c) < 0) return 2;       // c,a,bの順に直線に並ぶ
	if (norm(b) < norm(c)) return -2;  // a,b,cの順に直線に並ぶ
	return 0;                          // a,c,bの順に直線に並ぶ
}

/* 交差判定 */
// 直線と直線の交差判定
bool isis_ll(Line l, Line m) { return !eq(cross(l.b - l.a, m.b - m.a), 0); }
// 直線と線分の交差判定
bool isis_ls(Line l, Line s) {
	return isis_ll(l, s) &&
		(cross(l.b - l.a, s.a - l.a) * cross(l.b - l.a, s.b - l.a) < eps);
}
// 線分と線分の交差判定
bool isis_ss(Line s, Line t) {
	return ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) <= 0 &&
		ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b) <= 0;
}
// 点の直線上判定
bool isis_lp(Line l, Point p) { return (abs(cross(l.b - p, l.a - p)) < eps); }
// 点の線分上判定
bool isis_sp(Line s, Point p) { return (abs(s.a - p) + abs(s.b - p) - abs(s.b - s.a) < eps); }

/* 距離 */
// 直線と直線の交点
Point is_ll(Line s, Line t) {
	Point sv = s.b - s.a, tv = t.b - t.a;
	assert(cross(sv, tv) != 0);
	return s.a + sv * cross(tv, t.a - s.a) / cross(tv, sv);
}

// 直線と点の距離
ld dist_lp(Line l, Point p) {
	return abs(p - proj(l, p));
}

// 直線と直線の距離
ld dist_ll(Line l, Line m) {
	return isis_ll(l, m) ? 0 : dist_lp(l, m.a);
}

// 直線と線分の距離
ld dist_ls(Line l, Line s) {
	return isis_ls(l, s) ? 0 : min(dist_lp(l, s.a), dist_lp(l, s.b));
}

// 線分と点の距離
ld dist_sp(Line s, Point p) {
	Point r = proj(s, p);
	return isis_sp(s, r) ? abs(r - p) : min(abs(s.a - p), abs(s.b - p));
}

// 線分と線分の距離
ld dist_ss(Line s, Line t) {
	if (isis_ss(s, t)) return 0;
	return min({ dist_sp(s, t.a), dist_sp(s, t.b), dist_sp(t, s.a), dist_sp(t, s.b) });
}

/* 円 */
// 円と円の交点
vector<Point> is_cc(Circle c1, Circle c2) {
	vector<Point> res;
	ld d = abs(c1.p - c2.p);
	ld rc = (d * d + c1.r * c1.r - c2.r * c2.r) / (2 * d);
	ld dfr = c1.r * c1.r - rc * rc;
	if (abs(dfr) < eps) dfr = 0.0;
	else if (dfr < 0.0) return res; // no intersection
	ld rs = sqrt(dfr);
	Point diff = (c2.p - c1.p) / d;
	res.push_back(c1.p + diff * Point(rc, rs));
	if (dfr != 0.0) res.push_back(c1.p + diff * Point(rc, -rs));
	return res;
}
// 円と直線の交点
vector<Point> is_lc(Circle c, Line l) {
	vector<Point> res;
	ld d = dist_lp(l, c.p);
	if (d < c.r + eps) {
		ld len = (d > c.r) ? 0.0 : sqrt(c.r * c.r - d * d); //safety;
		Point nor = (l.a - l.b) / abs(l.a - l.b);
		res.push_back(proj(l, c.p) + len * nor);
		res.push_back(proj(l, c.p) - len * nor);
	}
	return res;
}
// 円と線分の距離
vector<Point> is_sc(Circle c, Line l) {
	vector<Point> v = is_lc(c, l), res;
	for (Point p : v)
		if (isis_sp(l, p)) res.push_back(p);
	return res;
}
// 円と点の接線
//vector<Line> tangent_cp(Circle c, Point p) {
//    vector<Line> ret;
//    Point v = c.p - p;
//    ld d = abs(v);
//    ld l = sqrt(norm(v) - c.r * c.r);
//    if (isnan(l)) { return ret; }
//    Point v1 = v * Point(l / d, c.r / d);
//    Point v2 = v * Point(l / d, -c.r / d);
//    ret.push_back(Line(p, p + v1));
//    if (l < eps) return ret;
//    ret.push_back(Line(p, p + v2));
//    return ret;
//}
//// 円と円の接線
//vector<Line> tangent_cc(Circle c1, Circle c2) {
//    vector<Line> ret;
//    if (abs(c1.p - c2.p) - (c1.r + c2.r) > -eps) {
//        Point center = (c1.p * c2.r + c2.p * c1.r) / (c1.r + c2.r);
//        ret = tangent_cp(c1, center);
//    }
//    if (abs(c1.r - c2.r) > eps) {
//        Point out = (-c1.p * c2.r + c2.p * c1.r) / (c1.r - c2.r);
//        vector<Line> nret = tangent_cp(c1, out);
//        ret.insert(ret.end(), nret.begin(), nret.end());
//    }
//    else {
//        Point v = c2.p - c1.p;
//        v /= abs(v);
//        Point q1 = c1.p + v * Point(0, 1) * c1.r;
//        Point q2 = c1.p + v * Point(0, -1) * c1.r;
//        ret.push_back(Line(q1, q1 + v));
//        ret.push_back(Line(q2, q2 + v));
//    }
//    return ret;
//}

/* 多角形 */
typedef vector<Point> Polygon;
// 面積
ld area(const Polygon &p) {
	ld res = 0;
	int n = (int)p.size();
	for (int j = 0; j < n; j++) res += cross(p[j], p[(j + 1) % n]);
	return res / 2;
}
// 多角形の回転方向
bool is_counter_clockwise(const Polygon &poly) {
	ld angle = 0;
	int n = (int)poly.size();
	for (int i = 0; i < n; i++) {
		Point a = poly[i], b = poly[(i + 1) % n], c = poly[(i + 2) % n];
		angle += arg((c - b) / (b - a));
	}
	return angle > eps;
}
// 凸性判定
bool isConvex(const Polygon &poly) {
	int n = (int)poly.size();
	if (n < 3) return false;
	int s = -3;
	for (int i = 0; i < n; i++) {
		int r = ccw(poly[(i + n - 1) % n], poly[i%n], poly[(i + 1) % n]);
		if (r == 1 && s == -3) s = r;
		if (s*r == -1) return false;
	}
	return true;
}
// 点の内外判定
//  0 => out : 1 => on : 2 => in
int is_in_polygon(const Polygon &poly, Point p) {
	ld angle = 0;
	int n = (int)poly.size();
	for (int i = 0; i < n; i++) {
		Point a = poly[i], b = poly[(i + 1) % n];
		if (isis_sp(Line(a, b), p)) return 1;
		angle += arg((b - p) / (a - p));
	}
	return eq(angle, 0) ? 0 : 2;
}

// 凸包 : 凸多角形のある一辺上にある点を含まない
Polygon convex_hull(vector<Point> ps) {
	int n = (int)ps.size();
	int k = 0;
	sort(ps.begin(), ps.end());
	Polygon ch(2 * n);
	for (int i = 0; i < n; ch[k++] = ps[i++])
		while (k >= 2 && ccw(ch[k - 2], ch[k - 1], ps[i]) <= 0) --k;
	for (int i = n - 2, t = k + 1; i >= 0; ch[k++] = ps[i--])
		while (k >= t && ccw(ch[k - 2], ch[k - 1], ps[i]) <= 0) --k;
	ch.resize(k - 1);
	return ch;
}
// 凸包 : 凸多角形のある一辺上にある点も含む
Polygon convex_hull2(vector<Point> ps) {
	int n = (int)ps.size();
	if (n < 3) return ps;
	sort(ps.begin(), ps.end());
	Polygon u = { ps[0], ps[1] }, l = { ps[n - 1],ps[n - 2] };
	for (int i = 2; i < n; i++) {
		for (int j = (int)u.size(); j >= 2 && ccw(u[j - 2], u[j - 1], ps[i]) >= 0; j--)u.pop_back();
		u.push_back(ps[i]);
	}
	for (int i = n - 3; i >= 0; i--) {
		for (int j = (int)l.size(); j >= 2 && ccw(l[j - 2], l[j - 1], ps[i]) >= 0; j--)l.pop_back();
		l.push_back(ps[i]);
	}
	reverse(l.begin(), l.end());
	for (int i = (int)u.size() - 2; i >= 1; i--)l.push_back(u[i]);
	return l;
}
using pll = PLL;
// 凸多角形の直径
pair<pll, ld> convex_diameter(const Polygon& poly) {
	int n = (int)poly.size();
	if (n == 2) return make_pair(pll(0, 1), abs(poly[0] - poly[1]));
	int ii = 0, jj = 0;
	for (int i = 1; i < n; i++) {
		if (poly[i].imag() > poly[ii].imag())ii = i;
		if (poly[i].imag() < poly[jj].imag())jj = i;
	}
	pll resp = make_pair(-1, -1);
	ld resd = 0;

	int i, maxi, j, maxj;
	i = maxi = ii; j = maxj = jj;
	while (i != maxj || j != maxi) {
		ld cur = abs(poly[i] - poly[j]);
		if (resd + eps < cur) { resd = cur; resp = pll(i, j); }
		int di = (i + 1) % n, dj = (j + 1) % n;
		if (cross(poly[di] - poly[i], poly[dj] - poly[j]) < 0) i = di;
		else j = dj;
	}
	return make_pair(resp, resd);
}
// 凸カット
Polygon convex_cut(const Polygon &ps, Line l) {
	int n = (int)ps.size();
	Polygon Q;
	for (int i = 0; i < n; i++) {
		Point A = ps[i], B = ps[(i + 1) % n];
		Line m = Line(A, B);
		if (ccw(l.a, l.b, A) != -1) Q.push_back(A);
		if (ccw(l.a, l.b, A) * ccw(l.a, l.b, B) < 0 && isis_ll(l, m))
			Q.push_back(is_ll(l, m));
	}
	return Q;
}

// 円と多角形の共通部分
double area_of_polygon_and_circle(const Polygon& poly, const Circle c) {
	int n = (int)poly.size();
	ld r = 0;
	for (int i = n - 1, j = 0; j < n; i = j++) {
		Point v = abs(poly[j] - poly[i]) / (poly[j] - poly[i]);
		if (poly[j] == poly[i])continue;
		assert(poly[j] != poly[i]);
		Point a = (poly[i] - c.p)*v, b = (poly[j] - c.p)*v;
		ld d = norm(c.r) - norm(a.imag());
		if (abs(a.imag()) < eps) continue;
		if (d < 0)d = 0;
		d = sqrt(d);
		double l, m;
		r += norm(c.r)*((l = atan2(b.imag(), min(b.real(), -d)) - atan2(a.imag(), min(a.real(), -d)))
			+ (m = atan2(b.imag(), max(b.real(), d)) - atan2(a.imag(), max(a.real(), d))))
			+ a.imag()*(min(d, max(a.real(), -d)) - max(-d, min(b.real(), d)));
		assert(-pi < l && -pi < m && l < pi && m < pi);
	}
	return r / 2;
}

int N;
ld G[110][110];
ld Hs[110];
Polygon polys[110];
ld solve() {
	ld res = 0;
	for (int i = 0; i < N; i++) polys[i].clear();
	//    vector<Polygon> polys(N);
	for (int i = 0; i < N; i++) {
		int n; scanf("%d%lf", &n, &Hs[i]);
		for (int j = 0; j < n; j++) {
			polys[i].push_back(input_point());
		}
	}
	double theta, phi; cin >> theta >> phi;
	theta = theta*pi / 180; phi = phi*pi / 180;
	Point S = input_point(), T = input_point();
	for (int i = 0; i < N; i++) {
		int sz = (int)polys[i].size();
		ld L = Hs[i] / tan(phi);
		for (int j = 0; j < sz; j++) {
			ld x = polys[i][j].real(), y = polys[i][j].imag();
			polys[i].push_back(Point(x - L*cos(theta), y - L*sin(theta)));
		}
		polys[i] = convex_hull(polys[i]);
	}

	fill(*G, *G + 110 * 110, INF);
	for (int i = 0; i < N + 2; i++) G[i][i] = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (i == j) continue;
			ld D = INF;
			for (int k = 0; k < polys[i].size(); k++) {
				if (is_in_polygon(polys[j], polys[i][k]) > 0) {
					D = 0;
					break;
				}
				for (int l = 0; l < polys[j].size(); l++) {
					Line l1(polys[i][k], polys[i][(k + 1) % polys[i].size()]);
					Line l2(polys[j][l], polys[j][(l + 1) % polys[j].size()]);
					D = min(D, dist_ss(l1, l2));
				}
			}
			G[i][j] = G[j][i] = D;
		}
	}
	for (int i = 0; i < N; i++) {
		if (is_in_polygon(polys[i], S) > 0) {
			G[N][i] = G[i][N] = 0;
		}
		else {
			ld D = INF;
			for (int k = 0; k < polys[i].size(); k++) {
				Line l1(polys[i][k], polys[i][(k + 1) % polys[i].size()]);
				D = min(D, dist_sp(l1, S));
			}
			G[N][i] = G[i][N] = D;
		}

		if (is_in_polygon(polys[i], T) > 0) {
			G[N + 1][i] = G[i][N + 1] = 0;
		}
		else {
			ld D = INF;
			for (int k = 0; k < polys[i].size(); k++) {
				Line l1(polys[i][k], polys[i][(k + 1) % polys[i].size()]);
				D = min(D, dist_sp(l1, T));
			}
			G[N + 1][i] = G[i][N + 1] = D;
		}
	}
	G[N][N + 1] = G[N + 1][N] = abs(S - T);

	for (int i = 0; i < N + 2; i++) {
		for (int j = 0; j < N + 2; j++) {
			for (int k = 0; k < N + 2; k++) {
				G[j][k] = min(G[j][k], G[j][i] + G[i][k]);
			}
		}
	}
	res = G[N][N + 1];
	return res;
}
int main(void) {
	//    cin.tie(0); ios_base::sync_with_stdio(false);
	while (cin >> N, N) {
		cout << fixed << setprecision(12) << solve() << endl;
	}
	return 0;
}