#include "bits/stdc++.h"
using namespace std;

using VS = vector<string>;    using LL = long long;
using VI = vector<int>;       using VVI = vector<VI>;
using PII = pair<int, int>;   using PLL = pair<LL, LL>;
using VL = vector<LL>;        using VVL = vector<VL>;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define EB emplace_back
#define MP make_pair
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

/* -----  2017/11/20  Problem: AOJ 1298 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1298  ----- */
/* ------問題------

色Bの二次元上の整数点がN個与えられる。
色Wの二次元上の整数点がM個与えられる。
これらを一本の線分で2つの境界に分離したとき、片側には一色しかない、すなわちB,Wを分離できるか。

-----問題ここまで----- */
/* -----解説等-----

凸包＋線分交錯＋点、線分交錯
片方の色のみで凸法をつくったとき、多角形の中に他の色の点があった場合、これはだめ
また、凸多角形と別の色の線分が一つでも交錯するときは、分離できないので、だめ
以上は点が３ついじょうのときに議論できる。
点が2追加の場合は、交錯する、線分上に点が乗っている場合のみだめ
と場合分けをすることでこの問題は解ける。

----解説ここまで---- */

#include <complex>

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
// 内積
ld dot(Point a, Point b) {
	return real(conj(a) * b);
}

// 外積
ld cross(Point a, Point b) {
	return imag(conj(a) * b);
}

int ccw(Point a, Point b, Point c) {
	b -= a; c -= a;
	if (cross(b, c) > eps) return 1;   // a,b,cが反時計周りの順に並ぶ
	if (cross(b, c) < -eps) return -1; // a,b,cが時計周りの順に並ぶ
	if (dot(b, c) < 0) return 2;       // c,a,bの順に直線に並ぶ
	if (norm(b) < norm(c)) return -2;  // a,b,cの順に直線に並ぶ
	return 0;                          // a,c,bの順に直線に並ぶ
}

typedef vector<Point> Polygon;
// 凸包
Polygon convex_hull(vector<Point> ps) {
	int n = ps.size();
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

struct Line
{
	Point a, b;
	Line(Point p, Point q) :a(p), b(q) {};
	Line(ld x1, ld y1, ld x2, ld y2) :a(Point(x1, y1)), b(Point(x2, y2)) {};
};


// 誤差つき等号判定
bool eq(ld a, ld b) {
	return (abs(a - b) < eps);
}
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

// 点が多角形に内包されているか? yes:2
#define curr(P, i) P[i]
#define next(P, i) P[(i+1)%P.size()]
enum { OUT, ON, IN };
int contains(const Polygon& P, const Point& p) {
	bool in = false;
	for (int i = 0; i < P.size(); ++i) {
		Point a = curr(P, i) - p, b = next(P, i) - p;
		if (imag(a) > imag(b)) swap(a, b);
		if (imag(a) <= 0 && 0 < imag(b))
			if (cross(a, b) < 0) in = !in;
		if (cross(a, b) == 0 && dot(a, b) <= 0) return ON;
	}
	return in ? IN : OUT;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, M;
	while (cin >> N >> M, N || M) {
		int yesf = 1;
		vector<Point>B(N);
		vector<Point>W(M);
		FOR(i, 0, N) {
			B[i] = input_point();
		}
		FOR(i, 0, M) {
			W[i] = input_point();
		}
		if (N <= 2 && M <= 2) {// line and dat
			Line L1(B[0], B[1]);
			Line L2(W[0], W[1]);

			if (N == 2 && M == 2) {
				yesf = !isis_ss(L1, L2);//交差してたらダメ
			}
			else if (N == 1 && M == 1) {
				yesf = 1;// 絶対分離できる
			}
			else if(N==1){// 2 and 1;
				yesf = !isis_sp(L2, B[0]);
			}
			else if (M == 1) {
				yesf = !isis_sp(L1, W[0]);
			}
		}
		else {// convex hull 
			// B 

			Polygon Bgraph = convex_hull(B);
				//線分交錯
			FOR(i, 0, SZ(Bgraph)) {
				Line BB(Bgraph[i], Bgraph[(i + 1) % (SZ(Bgraph))]);
				FOR(j, 0, SZ(W)) {
					FOR(k, j + 1, SZ(W)) {
						Line WW(W[j],W[k]);
						if (isis_ss(BB,WW)) {
							yesf = 0;// 交錯したらダメ
						}
					}
				}
			}
				// 点内包
			FOR(i, 0, SZ(W)) {
				if (contains(Bgraph, W[i]) == 2) {
					yesf = 0;
				}
			}




			// N (copy)
			Polygon Wgraph = convex_hull(W);
				//線分交錯
			FOR(i, 0, SZ(Wgraph)) {
				Line WW(Wgraph[i], Wgraph[(i + 1) % (SZ(Wgraph))]);
				FOR(j, 0, SZ(B)) {
					FOR(k, j + 1, SZ(B)) {
						Line BB(B[j], B[k]);
						if (isis_ss(BB, WW)) {
							yesf = 0;// 交錯したらダメ
						}
					}
				}
			}
			// 点内包
			FOR(i, 0, SZ(B)) {
				if (contains(Wgraph, B[i]) == 2) {
					yesf = 0;
				}
			}
		}

		cout << ((yesf) ? "YES" : "NO") << "\n";
	}

	return 0;
}
