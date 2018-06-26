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

/* -----  2018/06/26  Problem: AOJ 1289 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1289  ----- */
/* ------問題------

球の反射

-----問題ここまで----- */
/* -----解説等-----

ゆるさん

----解説ここまで---- */


#define EPS (1e-10)
#define equals(a,b) (fabs((a)-(b)) < EPS)
struct Point3D {
	double x, y, z;
	Point3D() {}
	Point3D(double x, double y, double z) :x(x), y(y), z(z) {}
	Point3D operator+(Point3D p) const { return Point3D(x + p.x, y + p.y, z + p.z); }
	Point3D operator-(Point3D p) const { return Point3D(x - p.x, y - p.y, z - p.z); }
	Point3D operator*(double k) const { return Point3D(x*k, y*k, z*k); }
	Point3D operator/(double k) const { return Point3D(x / k, y / k, z / k); }
	Point3D operator*(Point3D p) {
		return Point3D(y*p.z - z*p.y, z*p.x - x*p.z, x*p.y - y*p.x);
	}
	double operator^(Point3D p) {
		return x*p.x + y*p.y + z*p.z;
	}
	double norm() { return x*x + y*y + z*z; }
	double abs() { return sqrt(norm()); }
	bool operator < (const Point3D &p) const {
		if (x != p.x) return x < p.x;
		if (y != p.y) return y < p.y;
		return z < p.z;
	}
	bool operator == (const Point3D &p) const {
		return fabs(x - p.x) < EPS && fabs(y - p.y) < EPS && fabs(z - p.z) < EPS;
	}
};
istream &operator >> (istream &is, Point3D &p) {
	is >> p.x >> p.y >> p.z;
	return is;
}
ostream &operator << (ostream &os, Point3D p) {
	os << fixed << setprecision(12) << p.x << " " << p.y << " " << p.z;
	return os;
}

typedef Point3D Vector3D;
typedef vector<Point3D> Polygon3D;

struct Segment3D {
	Point3D p1, p2;
	Segment3D() {}
	Segment3D(Point3D p1, Point3D p2) :p1(p1), p2(p2) {}
};
typedef Segment3D Line3D;

istream &operator >> (istream &is, Segment3D &s) {
	is >> s.p1 >> s.p2;
	return is;
}

struct Sphere {
	Point3D c;
	double r;
	Sphere() {}
	Sphere(Point3D c, double r) :c(c), r(r) {}
};

istream &operator >> (istream &is, Sphere &c) {
	is >> c.c >> c.r;
	return is;
}

double norm(Vector3D a) {
	return a.x*a.x + a.y*a.y + a.z*a.z;
}
double abs(Vector3D a) {
	return sqrt(norm(a));
}
double dot(Vector3D a, Vector3D b) {
	return a.x*b.x + a.y*b.y + a.z*b.z;
}
Vector3D cross(Vector3D a, Vector3D b) {
	return Vector3D(a.y*b.z - a.z*b.y, a.z*b.x - a.x*b.z, a.x*b.y - a.y*b.x);
}

Point3D project(Line3D l, Point3D p) {
	Point3D b = l.p2 - l.p1;
	double t = dot(p - l.p1, b) / norm(b);
	return l.p1 + b*t;
}

Point3D reflect(Line3D l, Point3D p) {
	return p + (project(l, p) - p)*2.0;
}

double getDistanceLP(Line3D l, Point3D p) {
	return abs(cross(l.p2 - l.p1, p - l.p1) / abs(l.p2 - l.p1));
}

double getDistanceSP(Segment3D s, Point3D p) {
	if (dot(s.p2 - s.p1, p - s.p1) < 0.0) return abs(p - s.p1);
	if (dot(s.p1 - s.p2, p - s.p2) < 0.0) return abs(p - s.p2);
	return getDistanceLP(s, p);
}

bool intersectSC(Segment3D s, Sphere c) {
	double d = getDistanceSP(s, c.c);
	if (d > c.r) return 0;
	return !((abs(s.p1 - c.c) <= c.r) && (abs(s.p2 - c.c) <= c.r));
}

pair< Point3D, Point3D > Crosspoint(const Sphere &c, const Line3D &l) { 
	Point3D hp = project(l, c.c), h = hp - c.c;
	const double d2 = h.norm();
	Point3D v = (l.p2 - l.p1) * sqrt(c.r * c.r - d2) / (l.p2 - l.p1).abs();
	return { hp - v, hp + v };
}

pair< Point3D, Point3D > Crosspoint(const Sphere &c, Segment3D &l) {
	Segment3D aa(l.p1, l.p2);
	if (intersectSC(l, c) == 2) return Crosspoint(c, Line3D(aa.p1, aa.p2));
	auto ret = Crosspoint(c, Line3D(aa.p1, aa.p2));
	if (dot(l.p1 - ret.first, l.p2 - ret.first) < 0) ret.second = ret.first;
	else ret.first = ret.second;
	return (ret);
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N;
	while (cin >> N, N) {
		Point3D st;
		cin >> st;
		vector<Sphere>a(N);
		FOR(i, 0, N) {
			cin >> a[i].c >> a[i].r;
		}
		Segment3D bar(Point3D(0, 0, 0), st / st.abs()*1e5);

		int ns = -1; // now sphere
		while (1) {
			// 最も短いものを選択する
			int nxs = -1; // next sphere
			FOR(i, 0, N) {
				if (i == ns)continue;
				if (intersectSC(bar, a[i])) {
					bar.p2 = Crosspoint(a[i], bar).first;
					nxs = i;
				}
			}
			if (nxs == -1)break;

			Line3D sui(a[nxs].c, bar.p2);
			Point3D rf = reflect(sui, bar.p1);// 関係
			bar = Segment3D(bar.p2, rf + (rf-bar.p2 )/(rf-bar.p2).abs()  *1e5);
			ns = nxs;
		}
		cout << fixed << setprecision(10) << bar.p1.x << " " << bar.p1.y << " " << bar.p1.z << endl;
	}


	return 0;
}
