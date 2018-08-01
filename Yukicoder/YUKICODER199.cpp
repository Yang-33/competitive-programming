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

/* -----  2018/07/31  Problem: yukicoder 199  / Link: http://yukicoder.me/problems/no/199  ----- */
/* ------問題------

XY座標上の点が5つ与えられる。点を線で繋いで星が描けるかどうか判定せよ。

※星の定義を図で説明します。
(A)はきれいな星になっていますね。
(B)は赤の矢印で示した部分が出ていないので星ではありません。
(C)はかなり歪んでいますが星です。
シルエットにしたとき5つのとんがりが無いとダメという認識でお願いします。

-----問題ここまで----- */
/* -----解説等-----

適当な一直線上にない4点を選んで、内部か周上に点があるときはダメ。
これを実装したけどサンプルすら通らない。
これは凸包5点かを調べていることになるので、貼る

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
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N = 5;
	vector<Point>ps;
	FOR(i, 0, N) {
		int x, y;
		cin >> x >> y;
		ps.push_back(Point(x, y));
	}
	int ok = (convex_hull(ps).size() == 5);
	cout << (ok ? "YES" : "NO") << "\n";

	return 0;
}
