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

/* -----  2019/06/08  Problem: GCJ2019_R3 D / Link: __CONTEST_URL__  ----- */
using Double = long double;
const double EPS = 1e-4; // ガバガバでOK

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
Point rotate(const Vector& v, Double s) {
	return Vector(v.x * cos(s) - v.y * sin(s),
		v.x * sin(s) + v.y * cos(s));
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


// 矩形構造体
struct Rect {
	Point lt, rb;
	Rect(Point lt_, Point rb_) : lt(lt_), rb(rb_) {}
};

// 矩形の交差判定
bool rect_intersect(const Rect& a, const Rect& b) {
	return (a.lt.x <= b.rb.x && a.rb.y <= b.lt.y && b.lt.x <= a.rb.x && b.rb.y <= a.lt.y);
}

// 多角形構造体
struct Polygon {
	vector< Point > vert;
	Polygon(int n) : vert(n, Point(0, 0)) {}
	Polygon() {}

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

// 線分による多角形の分割
pair<Polygon, Polygon> PolygonDivideLine(const Polygon&po, const Line& line) {
	// 交差点を2つ求める

	// 1つめ


}

// name: Napkin Folding
void solve(int testcasenum) {
	int N, K; cin >> N >> K;
	DD(de(K));
	vector<PII>xy(N);

	vector<Point>P;
	vector<pair<PII, PII>>xyukuc; {
		FOR(i, 0, N) {
			cin >> xy[i].first >> xy[i].second;
			P.push_back(Point(xy[i].first, xy[i].second));
			auto f = [](int x) {
				return PII(x, 1);
			};
			xyukuc.push_back(make_pair(f(xy[i].first), f(xy[i].second)));
		}
	}
	DD(De(xy));
	vector<Point>CP;
	vector<pair<PII, PII>>ukuc; {
		FOR(i, 0, N) {
			int j = (i + 1) % N;
			Point a = P[i], b = P[j];
			Point c = (a + b) / 2;
			CP.push_back(c);
			{
				int x = xy[i].first + xy[j].first;
				int y = xy[i].second + xy[j].second;
				auto f = [](int x) {
					if (x % 2 == 1)return PII(x, 2);
					else return PII(x / 2, 1);
				};
				{
					ukuc.push_back(
						make_pair(
							f(x),
							f(y)));
				}
			}
		}
	}
	// 中点と頂点->重心みたいにしてやるとK=2はある．
	// 移動させた後の点の管理がアレ．全部整数点なので

	// Pを対称にもっていってやる
	// 方針としてはsetにいれてけすのが良さそう
	//     - 切る線分に注意
	// 発見できなかったらダメ
	// 残っていたらダメ

	// えー出力がカスだけど
	// 既約でないとして*/2系で全部できる(存在するなら)
	// 中点の相手は頂点か中点なので

	Double asum = 0; {
		Polygon p(N);
		FOR(i, 0, N) {
			p.vert[i] = P[i];
		}
		asum = p.area();
	}

	// ABで切断したときの面積もいる
	auto solve = [&](Point A, Point B) {
		bool isok = 1;
		set<Point>se;
		// いれとく
		Line divideline(A, B);
		Polygon po;
		po.vert.push_back(A);
		po.vert.push_back(B);
		FOR(i, 0, N) {
			if (P[i] == A || P[i] == B)continue;
			se.insert(P[i]);
			//DD(de(P[i].x, P[i].y));
			if (ccw(A, B, P[i]) == 1) {
				po.vert.push_back(P[i]);
			}
		}
		//DD(de(SZ(se)));
		// みていく
		FOR(i, 0, N) {
			if (P[i] == A || P[i] == B)continue;
			Point pd = reflect(divideline, P[i]);
			//DD(de(P[i].x, P[i].y, "to", pd.x, pd.y));
			if (se.find(pd) == se.end()) {
				isok = 0;
			}
			else {
				se.erase(pd);
			}
		}
		// 残ってたらダメ
		isok &= SZ(se) == 0;
		//DD(de(asum / 2, po.area()));
		isok &= abs(asum / 2 - po.area()) < EPS;
		//DD(de(isok, A.x, A.y, B.x, B.y));
		if (isok) {
		}
		return isok;
	};

	bool ok = 0;
	// K = 2
	pair<PII, PII>ansA, ansB; // ukucからもってきたこたえ
	FOR(i, 0, N) {
		FOR(j, i + 1, N) { // P P 
			if (solve(P[i], P[j])) {
				ok = 1;
				ansA = xyukuc[i];
				ansB = xyukuc[j];
			}
		}

		FOR(j, 0, N) { // P C 
			if (solve(P[i], CP[j])) {
				ok = 1;
				ansA = xyukuc[i];
				ansB = ukuc[j];
			}
		}

	}
	FOR(i, 0, N) { // C C 
		FOR(j, i + 1, N) {
			if (solve(CP[i], CP[j])) {
				ok = 1;
				ansA = ukuc[i];
				ansB = ukuc[j];
			}
		}
	}

	cout << "Case #" << testcasenum << ": ";
	if (!ok) {
		cout << "IMPOSSIBLE" << endl;
	}
	else {
		cout << "POSSIBLE" << endl;
		auto OUT = [](PII a) { return to_string(a.first) + "/" + to_string(a.second); };
		cout << OUT(ansA.first) << " ";
		cout << OUT(ansA.second) << " ";
		cout << OUT(ansB.first) << " ";
		cout << OUT(ansB.second) << endl;
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);


	int T; cin >> T;
	FOR(c, 0, T) {
		solve(c + 1);
	}

	return 0;
}
