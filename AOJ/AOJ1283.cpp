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

/* -----  2018/06/26  Problem: AOJ 1283 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1283  ----- */
/* ------問題------

凸多角形が反時計回りで与えられます。
凸多角形の内部にある点のうち
辺からの距離が最も遠い点との距離を出力してください。

-----問題ここまで----- */
/* -----解説等-----

上に凸な三次元グラフがみえるので三分探索を三分探索しても問題無い。
なお、complex<long double>で実装すると誤差不可避になって別の解法が要求される。(**ゆるさん**)
別の解放は凸カット+二分探索らしい
これは多角形を狭めることができるか？という質問になる。
三分探索のほうが楽そう…

----解説ここまで---- */

using Double = long double;
const Double EPS = 1e-9;
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

// 直線、線分構造体
typedef struct Line {
	Point s, e;
	Line(Point s_, Point e_) : s(s_), e(e_) {}
} Segment;

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

/* 多角形 */
typedef vector<Point> Polygon;

// 点の内包判定
enum { IN, ON, OUT };
int point_in_poly(const Polygon& g, const Point& p) {
	bool in = false;
	int n = SZ(g);

	FOR(i, 0, n) {
		Point a = g.at(i) - p, b = g.at((i + 1)%n) - p;
		if (a.y > b.y) swap(a, b);
		if (a.y <= 0 && 0 < b.y && cross(a, b) + EPS < 0) in = !in;
		if (fabs(cross(a, b)) < EPS && dot(a, b) <= 0) return ON;
	}

	return in ? IN : OUT;
}


// pから多角形の最短距離を求める
// 採用されるのは最遠のもの
// ただし多角形から外れていてもその値を返す

long double f(Point& p, Polygon & ps) {
	if (point_in_poly(ps, p)!=OUT) {
		long double ret = LINF;
		// min
		FOR(i, 0, SZ(ps)) {
			Line line(ps[i], ps[(i + 1) % SZ(ps)]);
			ret = min(ret, dist_point_seg(p,line));
		}

		return ret;
	}
	else {
		long double ret = -LINF;
		// max(- to 0)
		FOR(i, 0, SZ(ps)) {
			Line line(ps[i], ps[(i + 1) % SZ(ps)]);
			ret = max(ret, -dist_point_seg(p,line));
		}

		return ret;
	}
}

// Xを決めたときのYを三分探索する
long double solve(long double X, Polygon & ps) {
	long double ret = -LINF;
	long double yL = 0, yR = 10000;
	//while (eps6 < yR - yL) {
	FOR(syiri, 0, 45) {
		long double y1 = (2.0 * yL + yR) / 3;
		long double y2 = (yL + 2.0 * yR) / 3;
		Point p1 = Point(X, y1);
		Point p2 = Point(X, y2);

		long double WL = f(p1, ps);
		long double WR = f(p2, ps);

		if (WL < WR) {
			yL = y1;
		}
		else if(WL> WR){
			yR = y2;
		}
		ret = max(ret, max(WL, WR));
	}

	return ret;
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);


	int N;
	while (cin >> N, N) {
		vector<Point>ps;
		FOR(i, 0, N) {
			Double x, y;
			cin >> x >> y;
			ps.push_back(Point(x, y));
		}
		long double L = 0; long double R = 10000;
		long double ans = 0.0;
		FOR(i, 0, 45) {
			long double LS = (2.0 * L + R) / 3.0;
			long double RS = (L + 2.0 * R) / 3.0;
			long double DL = solve(LS, ps);
			long double DR = solve(RS, ps);
			if (DL < DR) {
				L = LS;
			}
			else if (DL > DR) {
				R = RS;
			}

			ans = max(ans, max(DL, DR));
		}
		cout << fixed << setprecision(10) << ans << endl;
	}

	return 0;
}
