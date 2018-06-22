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

/* -----  2018/06/24  Problem: AOJ 1242 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1242  ----- */
/* ------問題------

N点与えられるので、隣接点との線分でできる多角形を作る。
この多角形の内部と線上のグリッド和は。

-----問題ここまで----- */
/* -----解説等-----

xの値を一つづつ進めていけばよい。
するとyでの区間併合になる。
あとは気合をすれば良い。

----解説ここまで---- */



// M 550
typedef long double ld;
using Point = complex<ld>;
using Polygon = vector<Point>;

namespace std {
	bool operator < (const Point& a, const Point& b) {
		return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
	}
}

struct Line {
	Point a, b;
	Line(Point p, Point q) :a(p), b(q) {};
	Line(ld x1, ld y1, ld x2, ld y2) :a(Point(x1, y1)), b(Point(x2, y2)) {};
};


ld gety(const Line &line, int X) {
	ld y1 = line.a.imag();
	ld y2 = line.b.imag();
	ld x1 = line.a.real();
	ld x2 = line.b.real();
	return y1 + (y2 - y1)*(X - x1) / (x2 - x1);
}

using PII = pair<int, int>;
PII calc(Line &a, Line &b, int X) {// [X,X+1]
	int res = 0;
	ld ya1 = gety(a, X);
	ld ya2 = gety(a, X + 1);
	ld yb1 = gety(b, X);
	ld yb2 = gety(b, X + 1);
	int yh = ceil(max({ ya1,ya2,yb1,yb2 }));
	int yl = floor(min({ ya1,ya2,yb1,yb2 }));
	res += abs(yh - yl);
	return PII(yl, yh);// L and H
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N;
	while (cin >> N, N) {
		vector<Point> ps(N + 1);
		FOR(i, 0, N) {
			ld x, y;
			cin >> x >> y;
			ps[i] = Point(x, y);
		}

		ps[N] = ps[0];
		vector<Line> lines;
		FOR(i, 0, N) {
			lines.push_back(Line(ps[i], ps[i + 1]));
		}

		int ans = 0;
		FOR(x, -2000, 2000) { // [x:x+1]でみる
			vector<Line>includeline;
			FOR(i, 0, N) {
				if ((lines[i].a.real() <= (x + 0.5) && (x + 0.5) <= lines[i].b.real()) || (lines[i].b.real() <= (x + 0.5) && (x + 0.5) <= lines[i].a.real()))
					includeline.push_back(lines[i]);
			}

			sort(includeline.begin(), includeline.end(),
				[&](const Line &a, const Line &b) {
				ld ya = max(gety(a, x), gety(a, x + 1));
				ld yb = max(gety(b, x), gety(b, x + 1));
				return (ya > yb);
			});


			vector<PII>v;
			for (int i = 0; i < (int)includeline.size(); i += 2) {
				v.push_back(calc(includeline[i], includeline[i + 1], x));
			}
			sort(v.begin(), v.end());
			int  L, R;
			FOR(i, 0, (int)v.size()) { // grid mergeをする最後の併合忘れに注意
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
							;
						}
					}
					else {
						L = v[i].first, R = v[i].second;
						ans += abs(R - L);
					}
				}
			}
			//cout << "aaaa:" << ret << endl;
		}

		cout << ans << endl;
	}

	return 0;
}
