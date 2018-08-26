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

/* -----  2018/08/26  Problem: yukicoder 245  / Link: http://yukicoder.me/problems/no/245  ----- */
/* ------問題------

平面上に N 個の線分があります。
あなたはそこに 1 つ好きに直線を引くことができます。
最大で何本の線分と交わるようにできるか求めてください。
この問題において、直線と線分が交わるとは、
両方に共通して含まれる点(端点を含む)が 1 個以上存在することとします。

-----問題ここまで----- */
/* -----解説等-----

ギリギリを考えると、端点を2個選んでいることになる。2個選んでそれを通る物があるかをcheckすればよい。
ライブラリ重くない？

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
bool eq(ld a, ld b) { return (abs(a - b) < eps); } 
ld dot(Point a, Point b) { return real(conj(a) * b); } 
ld cross(Point a, Point b) { return imag(conj(a) * b); } 

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

Point proj(Line l, Point p) {
	ld t = dot(p - l.a, l.a - l.b) / norm(l.a - l.b);
	return l.a + t * (l.a - l.b);
}
int ccw(Point a, Point b, Point c) {
	b -= a; c -= a;
	if (cross(b, c) > eps) return 1;   // a,b,cが反時計周りの順に並ぶ
	if (cross(b, c) < -eps) return -1; // a,b,cが時計周りの順に並ぶ
	if (dot(b, c) < 0) return 2;       // c,a,bの順に直線に並ぶ
	if (norm(b) < norm(c)) return -2;  // a,b,cの順に直線に並ぶ
	return 0;                          // a,c,bの順に直線に並ぶ
}

bool isis_ll(Line l, Line m) { return !eq(cross(l.b - l.a, m.b - m.a), 0); }
bool isis_ls(Line l, Line s) {
	return isis_ll(l, s) &&
		(cross(l.b - l.a, s.a - l.a) * cross(l.b - l.a, s.b - l.a) < eps);
}
bool isis_lp(Line l, Point p) { return (abs(cross(l.b - p, l.a - p)) < eps); }
ld dist_lp(Line l, Point p) {
	return abs(p - proj(l, p));
}
ld dist_ls(Line l, Line s) {
	return isis_ls(l, s) ? 0 : min(dist_lp(l, s.a), dist_lp(l, s.b));
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;
	vector<Line>segs;
	vector<Point>points;
	FOR(i, 0, N) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		segs.push_back(Line(Point(a, b), Point(c, d)));
		points.push_back(Point(a, b));
		points.push_back(Point(c, d));
	}
	int ans = 1;

	FOR(i, 0, 2*N) {
		FOR(j, 0, i) {
			// 端点が決定された
			Line decideLine(points[i], points[j]);
			int ret = 0;
			FOR(k, 0, N) {
				if (dist_ls(decideLine,segs[k])< eps)ret++;
			}
			ans = max(ans, ret);
		}
	}


	cout << ans << "\n";

	return 0;
}
