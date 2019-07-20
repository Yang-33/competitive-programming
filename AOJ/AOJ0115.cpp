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
//const int INF = 1e9;                          const LL LINF = 1e16;
//const LL MOD = 1000000007;                    const double PI = acos(-1.0);

/* -----  2019/07/20  Problem: AOJ 0115 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0115  ----- */

/////////////////////////////////
// 3 次元幾何ライブラリ一式
/////////////////////////////////

/* Point */
using DD = double;
const DD INF = 1LL << 60;      // to be set appropriately
const DD EPS = 1e-10;        // to be set appropriately
const DD PI = acos(-1.0);
DD torad(int deg) { return (DD)(deg)* PI / 180; }
DD todeg(DD ang) { return ang * 180 / PI; }

struct Point3D {
	DD x, y, z;
	Point3D(DD x = 0.0, DD y = 0.0, DD z = 0.0) : x(x), y(y), z(z) {}
	friend ostream& operator << (ostream &s, const Point3D &p) { return s << '(' << p.x << ", " << p.y << ", " << p.z << ')'; }
};

Point3D operator + (const Point3D &p, const Point3D &q) { return Point3D(p.x + q.x, p.y + q.y, p.z + q.z); }
Point3D operator - (const Point3D &p, const Point3D &q) { return Point3D(p.x - q.x, p.y - q.y, p.z - q.z); }
Point3D operator * (const Point3D &p, DD a) { return Point3D(p.x * a, p.y * a, p.z * a); }
Point3D operator * (DD a, const Point3D &p) { return Point3D(a * p.x, a * p.y, a * p.z); }
Point3D operator / (const Point3D &p, DD a) { return Point3D(p.x / a, p.y / a), p.z / a; }
Point3D cross(const Point3D &p, const Point3D &q) {
	return Point3D(p.y * q.z - p.z * q.y, p.z * q.x - p.x * q.z, p.x * q.y - p.y * q.x);
}
DD dot(const Point3D &p, const Point3D &q) { return p.x * q.x + p.y * q.y + p.z * q.z; }
DD norm(const Point3D &p) { return dot(p, p); }
DD abs(const Point3D &p) { return sqrt(dot(p, p)); }
bool eq(const Point3D &p, const Point3D &q) { return abs(p - q) < EPS; }
DD area(const Point3D &a, const Point3D &b, const Point3D &c) { return abs(cross(b - a, c - a)) / 2; }

struct Line3D : vector<Point3D> {
	Line3D(const Point3D &a = Point3D(), const Point3D &b = Point3D()) {
		this->push_back(a);
		this->push_back(b);
	}
	friend ostream& operator << (ostream &s, const Line3D &l) { return s << '{' << l[0] << ", " << l[1] << '}'; }
};

struct Sphere : Point3D {
	DD r;
	Sphere(const Point3D &p = Point3D(), DD r = 0.0) : Point3D(p), r(r) {}
	friend ostream& operator << (ostream &s, const Sphere &c) { return s << '(' << c.x << ", " << c.y << ", " << c.r << ')'; }
};

struct Plane : vector<Point3D> {
	Plane(const Point3D &a = Point3D(), const Point3D &b = Point3D(), const Point3D &c = Point3D()) {
		this->push_back(a);
		this->push_back(b);
		this->push_back(c);
	}
	friend ostream& operator << (ostream &s, const Plane &p) {
		return s << '{' << p[0] << ", " << p[1] << ", " << p[2] << '}';
	}
};


Point3D proj(const Point3D &p, const Line3D &l) {
	DD t = dot(p - l[0], l[1] - l[0]) / norm(l[1] - l[0]);
	return l[0] + (l[1] - l[0]) * t;
}

Point3D proj(const Point3D &p, const Plane &pl) {
	Point3D ph = cross(pl[1] - pl[0], pl[2] - pl[0]);
	Point3D pt = proj(p, Line3D(pl[0], pl[0] + ph));
	return p + (pl[0] - pt);
}

Point3D refl(const Point3D &p, const Line3D &l) {
	return p + (proj(p, l) - p) * 2;
}

Point3D refl(const Point3D &p, const Plane &pl) {
	return p + (proj(p, pl) - p) * 2;
}

bool isinterPL(const Point3D &p, const Line3D &l) {
	return (abs(p - proj(p, l)) < EPS);
}
DD distancePL(const Point3D &p, const Line3D &l) {
	return abs(p - proj(p, l));
}
DD distanceLL(const Line3D &l, const Line3D &m) {
	Point3D nv = cross(l[1] - l[0], m[1] - m[0]);
	if (abs(nv) < EPS) return distancePL(l[0], m);
	Point3D p = m[0] - l[0];
	return abs(dot(nv, p)) / abs(nv);
}


vector<Point3D> crosspoint(const Line3D &l, const Plane &pl) {
	vector<Point3D> res;
	Point3D ph = cross(pl[1] - pl[0], pl[2] - pl[0]);
	DD baseLength = dot(l[1] - l[0], ph);
	if (abs(baseLength) < EPS) return vector<Point3D>();
	DD crossLength = dot(pl[0] - l[0], ph);
	DD ratio = crossLength / baseLength;
	res.push_back(l[0] + (l[1] - l[0]) * ratio);
	return res;
}

vector<Point3D> crosspointSPL(const Line3D &s, const Plane &pl) {
	vector<Point3D> res;
	Point3D ph = cross(pl[1] - pl[0], pl[2] - pl[0]);
	DD baseLength = dot(s[1] - s[0], ph);
	if (abs(baseLength) < EPS) return vector<Point3D>();
	DD crossLength = dot(pl[0] - s[0], ph);
	DD ratio = crossLength / baseLength;
	if (ratio < -EPS || ratio > 1.0 + EPS) return vector<Point3D>();
	res.push_back(s[0] + (s[1] - s[0]) * ratio);
	return res;
}

// 三次元三角形上に点があるか？
bool Plane_include_point(const vector<Point3D> & bar, const Point3D & cp) {
	assert((int)bar.size() == 3);
	return !(area(cp, bar[1], bar[2]) + area(cp, bar[2], bar[0]) + area(cp, bar[0], bar[1]) - area(bar[0], bar[1], bar[2]) > EPS);
}
void solve_AOJ0115() {
	Point3D my, en;
	vector<Point3D>bar(3);
	cin >> my.x >> my.y >> my.z >> en.x >> en.y >> en.z;
	for (int i = 0; i < 3; ++i) {
		cin >> bar[i].x >> bar[i].y >> bar[i].z;
	}
	Line3D beam(my, en);
	Plane barier(bar[0], bar[1], bar[2]);
	vector<Point3D> cps = crosspointSPL(beam, barier);
	if (cps.empty()) cout << "HIT" << "\n";
	else {
		Point3D cp = cps.front();
		if (!Plane_include_point(bar, cp))
			cout << "HIT" << "\n";
		else
			cout << "MISS" << "\n";
	}
}

int main() {
	solve_AOJ0115();

	return 0;
}
