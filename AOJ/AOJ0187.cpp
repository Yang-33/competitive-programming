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

/* -----  2019/07/26  Problem: AOJ 0187 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0187  ----- */

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

// 直線の平衡判定
bool is_parrallel(const Line& a, const Line& b) {
	return is_parrallel(a.s - a.e, b.s - b.e);
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

int main() {
	int x1, y1, x2, y2;
	while (cin >> x1 >> y1 >> x2 >> y2) {
		if (x1 == 0 && x2 == 0 && y1 == 0 && y2 == 0)break;
		vector<Segment>ps; {
			ps.emplace_back(Point(x1, y1), Point(x2, y2));
			FOR(i, 0, 2) {
				cin >> x1 >> y1 >> x2 >> y2;
				ps.emplace_back(Point(x1, y1), Point(x2, y2));
			}
		}
		bool alltouch = 1; {
			FOR(i, 0, 3) {
				int j = (i + 1) % 3;
				alltouch &= is_crossss(ps[i], ps[j]);
			}
		}
		if (!alltouch) {
			puts("kyo");
		}
		else {
			Polygon P(0); {
				FOR(i, 0, 3) {
					int j = (i + 1) % 3;
					P.vert.emplace_back(cross_point(ps[i], ps[j]));
				}
			}
			Double D = P.area();
			if (D >= 1'900'000)puts("dai-kichi");
			else if (D >= 1'000'000)puts("chu-kichi");
			else if (D >= 100'000)puts("kichi");
			else if (D > 0)puts("syo-kichi");
			else puts("kyo");
		}
	}

	return 0;
}