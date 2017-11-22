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
const LL MOD = 1000000007;                    
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2017/11/22  Problem: AOJ 1242 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1242  ----- */
/* ------問題------

多角形で内包されるマスと、直線上のマスを合計した際のマスの面積は？

-----問題ここまで----- */
/* -----解説等-----

天才解法がうかばないので、制約をいかして、X-X+1の面積を考える。
上下にソートできたとき、これらの最近2ペアが塗りつぶされる面積であるから、
塗りつぶされる面積をマージしていけば重複せずに数え上げることができる。

----解説ここまで---- */

typedef long double ld;
const ld EPS = 1e-8;
const ld PI = acos(-1.0);
bool eq(ld a, ld b) { return abs(a - b) < EPS; }
typedef complex<ld> Point;
typedef vector<Point> Polygon;

namespace std
{
	bool operator < (const Point& a, const Point& b)
	{
		return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
	}
}
// 点の入力
Point input_point() {
	ld x, y;
	cin >> x >> y;
	return Point(x, y);
}
const ld eps = 1e-9, pi = acos(-1.0);


struct Line
{
	Point a, b;
	Line(Point p, Point q) :a(p), b(q) {};
	Line(ld x1, ld y1, ld x2, ld y2) :a(Point(x1, y1)), b(Point(x2, y2)) {};
};

LL N;

LL ans = 0LL;
ld gety(const Line &line, int X) {
	ld y1 = line.a.imag();
	ld y2 = line.b.imag();
	ld x1 = line.a.real();
	ld x2 = line.b.real();
	if (eq(x1, X))return y1;
	if (eq(x2, X))return y2;
	//debug(X); debug(y1); debug(y2); debug(x1); debug(x2) << endl;
	/*debug((y2 - y1)*(x2 - X) / (X - x1)) << endl;*/
	return y1+(y2 - y1)*(X-x1) / (x2 - x1);
}


PII calc(Line &a, Line &b, int X) {// [X,X+1]
	int res = 0;
	ld ya1 = gety(a, X);
	ld ya2 = gety(a, X + 1);
	ld yb1 = gety(b, X);
	ld yb2 = gety(b, X + 1);
	int yh = ceil(max({ ya1,ya2,yb1,yb2 }));
	int yl = floor(min({ ya1,ya2,yb1,yb2 }));
	//debug(yh); debug(yl) << endl;
	res += abs(yh - yl);
	//debug(res) << endl;
	//return res;
	return PII(yl,yh);// L and H
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	while (cin >> N, N) {
		vector<Point> ps(N + 1);
		FOR(i, 0, N) {
			ps[i] = input_point();
		}
		ps[N] = ps[0];
		vector<Line> lines;
		FOR(i, 0, N) {
			lines.push_back(Line(ps[i], ps[i + 1]));
		}

		ans = 0;
		FOR(x, -2000,2000) {
			//[x,x+1]で数え上げる
			//　この区間でsort
			vector<Line>includeline;
			FOR(i, 0, N) {
				if ((lines[i].a.real() <= (x+0.5)&& (x + 0.5) <= lines[i].b.real()) || (lines[i].b.real() <= (x + 0.5) && (x + 0.5) <= lines[i].a.real()))
					includeline.push_back(lines[i]);
			}
			auto mysort = [&](const Line &a, const Line &b) {
				ld ya = max(gety(a, x), gety(a, x + 1));
				ld yb = max(gety(b, x), gety(b, x + 1));
				return (ya > yb);
			};
			//debug(x); debug(SZ(includeline)) << endl;
			sort(ALL(includeline), mysort);
			
			
			vector<PII>v;
			for (int i = 0; i < SZ(includeline); i += 2) {
				v.push_back(calc(includeline[i], includeline[i + 1], x));
			}
			SORT(v);//低い順になった
			int  L,R;
			FOR(i, 0, SZ(v)) {
				if (i == 0) {
					L = v[i].first, R = v[i].second;
					ans += abs(R - L);
				}
				else {
					if (v[i].first <= R) {
						if (R <= v[i].second) {
							ans += abs(v[i].second - R);
							R = v[i].second;
						}
						else {
							;// nop
						}
					}
					else {
						L = v[i].first, R = v[i].second;
						ans += abs(R - L);
					}
				}
			}
			//debug(ans);

		}



		cout << ans << "\n";
	}

	return 0;
}