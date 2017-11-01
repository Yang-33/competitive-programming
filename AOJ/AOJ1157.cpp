#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i,s,e) for(int(i)=(s);(i) < (e);(i)++)
#define debug(x) cout << #x << ": " << x << endl
const int INF = 1e9;
const ll LINF = 1e16;
/* -----  2017/11/01  Problem: AOJ1157  / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1157&lang=jp ----- */
/* ------問題------

ACM 大学では毎年 7 月に運動会が開かれるが， そのハイライトとなる競技は大玉転がしである． この大玉転がしではグラウンド上にひかれた直線状のコースに沿って大玉を転がす． グラウンドには複数の直方体ブロックが障害物として置かれていて動かすことができない． ブロックに大玉がぶつからないように， かつ大玉の底の点がコースの線から離れないように転がさなければならない．
競技をおもしろくするために，大玉をなるべく大きなものにすることになった． 上の条件を満たすような転がし方が可能な大玉の半径の最大値を求めるプログラムを作成しなさい．
大玉は完全な球，グラウンドは平面とする． ブロックの形は直方体である．ブロックの底面の四辺はグラウンド上にあり， X, Y 軸のいずれかと平行になっている． コースは，始点から終点までの線分として与えられる． 大玉の底の点が始点に接している状態からスタートし， 終点に接している状態でゴールするものとする．
なお，大玉とブロックの位置関係は，図 E-1 (a), (b) のようになる可能性がある．

-----問題ここまで----- */
/* -----解説等-----

しりません

----解説ここまで---- */
typedef long double ld;
typedef complex<ld> Point;

const ld eps = 1e-9, pi = acos(-1.0);

namespace std {
	bool operator<(const Point &lhs, const Point &rhs) {
		if (lhs.real() < rhs.real() - eps) return true;
		if (lhs.real() > rhs.real() + eps) return false;
		return lhs.imag() < rhs.imag();
	}
}

// 点の入力
Point input_point() {
	ld x, y;
	cin >> x >> y;
	return Point(x, y);
}

// 誤差つき等号判定
bool eq(ld a, ld b) {
	return (abs(a - b) < eps);
}

// 内積
ld dot(Point a, Point b) {
	return real(conj(a) * b);
}

// 外積
ld cross(Point a, Point b) {
	return imag(conj(a) * b);
}

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
bool isis_ll(Line l, Line m) {
	return !eq(cross(l.b - l.a, m.b - m.a), 0);
}

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
bool isis_lp(Line l, Point p) {
	return (abs(cross(l.b - p, l.a - p)) < eps);
}

// 点の線分上判定
bool isis_sp(Line s, Point p) {
	return (abs(s.a - p) + abs(s.b - p) - abs(s.b - s.a) < eps);
}

// 垂線の足
Point proj(Line l, Point p) {
	ld t = dot(p - l.a, l.a - l.b) / norm(l.a - l.b);
	return l.a + t * (l.a - l.b);
}

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
vector<Line> tangent_cp(Circle c, Point p) {
	vector<Line> ret;
	Point v = c.p - p;
	ld d = abs(v);
	ld l = sqrt(norm(v) - c.r * c.r);
	if (isnan(l)) { return ret; }
	Point v1 = v * Point(l / d, c.r / d);
	Point v2 = v * Point(l / d, -c.r / d);
	ret.push_back(Line(p, p + v1));
	if (l < eps) return ret;
	ret.push_back(Line(p, p + v2));
	return ret;
}

// 円と円の接線
vector<Line> tangent_cc(Circle c1, Circle c2) {
	vector<Line> ret;
	if (abs(c1.p - c2.p) - (c1.r + c2.r) > -eps) {
		Point center = (c1.p * c2.r + c2.p * c1.r) / (c1.r + c2.r);
		ret = tangent_cp(c1, center);
	}
	if (abs(c1.r - c2.r) > eps) {
		Point out = (-c1.p * c2.r + c2.p * c1.r) / (c1.r - c2.r);
		vector<Line> nret = tangent_cp(c1, out);
		ret.insert(ret.end(), nret.begin(),nret.end());
	}
	else {
		Point v = c2.p - c1.p;
		v /= abs(v);
		Point q1 = c1.p + v * Point(0, 1) * c1.r;
		Point q2 = c1.p + v * Point(0, -1) * c1.r;
		ret.push_back(Line(q1, q1 + v));
		ret.push_back(Line(q2, q2 + v));
	}
	return ret;
}

int main() {
	cin.tie(0); ios::sync_with_stdio(false);
	int N;
	Line st;
	vector<Line> lines;
	vector<int> Hs;
	while (cin >> N,N) {
		int sx, sy, ex, ey;
		cin >> sx >> sy >> ex >> ey;
		st = Line(Point(sx, sy), Point(ex, ey));
		lines.clear();
		Hs.clear();

		bool kousa = false;
		for (int i = 0; i < N; i++) {
			int minx, miny, maxx, maxy, h;
			cin >> minx >> miny >> maxx >> maxy >> h;

			if (minx <= min(sx, ex) && miny <= min(sy, ey) && max(sx, ex) <= maxx && max(sy, ey) <= maxy) {
				kousa = true;
			}

			lines.push_back(Line(Point(minx, miny), Point(minx, maxy)));
			lines.push_back(Line(Point(minx, miny), Point(maxx, miny)));
			lines.push_back(Line(Point(minx, maxy), Point(maxx, maxy)));
			lines.push_back(Line(Point(maxx, miny), Point(maxx, maxy)));
			for (int j = 0; j < 4; j++) Hs.push_back(h);
		}
		if (kousa) { cout << 0 << endl; continue; }

		bool f = false;

		ld ans = 1000;
		for (int i = 0; i < lines.size(); i++) {
			ld dic = dist_ss(st, lines[i]);
			if (dic < eps) { cout << 0 << endl; f = true; break; }

			ld l = 0, r = 1000;
			for (int j = 0; j < 100; j++) {
				ld  mid = (l + r) / 2;
				Point tyusin(0, mid);
				Line tyo_takasa(Point(dic, 0), Point(dic, Hs[i]));

				ld r_dic = dist_sp(tyo_takasa, tyusin);
				if (mid - r_dic >eps) {
					r = mid;
				}
				else {
					l = mid;
				}
			}
			ans = min((ld)ans, l);
		}
		if (f) continue;
		cout << setprecision(10) <<  ans << endl;
	}
	return 0;
}