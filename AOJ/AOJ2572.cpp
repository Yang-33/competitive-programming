#include <bits/stdc++.h>
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

/* -----  2017/12/11  Problem: AOJ 2572 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2572  ----- */
/* ------問題------

長方形の辺が与えられる。
この中に面積がA、Bの円でかつ、これらの共通面積がSとなるような円の配置がそんざいするならば詳細に出力せよ。

-----問題ここまで----- */
/* -----解説等-----

完結実装マスターが隣りにいて、解法を投げたら通してくれた
角度を与えて面積で二分探索をする円の隣に円を置くようにする。
その後これが入らない可能性があるので180度まわせば十分。

本解法は、四隅に寄せて距離を与えて面積で二分探索をするらしい。賢い(思いついて)

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
Point input_point() { ld x, y; cin >> x >> y; return Point(x, y); } // 点の入力
bool eq(ld a, ld b) { return (abs(a - b) < eps); } // 誤差つき等号判定
ld dot(Point a, Point b) { return real(conj(a) * b); } // 内積
ld cross(Point a, Point b) { return imag(conj(a) * b); } // 外積

LL W, H, A, B, S;
ld ra, rb;

ld check(ld theta) {
	ld y = ra*sin(theta / 2);

	ld theta2 = 2 * asin(y / rb);

	ld SC = ra * ra * sin(theta)/2.0 + rb * rb * sin(theta2)/2.0;

	ld S1 = pi * ra * ra * theta / (2 * pi);
	ld S2 = pi * rb * rb * theta2 / (2 * pi);

	ld res = S1 + S2 - SC;
	return res;
}

int main(void) {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	while (cin >> W >> H >> A >> B >> S, W | H | A | B | S) {
		bool swaped = false;
		if (A > B) {
			swap(A, B);
			swaped = true;
		}
		ra = sqrt(A / pi);
		rb = sqrt(B / pi);
		ld l = 0, r = 2 * pi;
		for (int i = 0; i < 300; i++) {
			ld m = (l + r) / 2.0;
			ld area = check(m);
			if (area > S) {
				r = m;
			}
			else {
				l = m;
			}
		}
		ld theta = r;

		ld XA, YA, XB, YB;

		XB = rb + 0.0001; YB = rb + 0.0001;

		if (XB + rb > (ld)W + 0.0001 || (YB + rb) > (ld)H + 0.0001) {
			cout << "impossible" << endl;
			continue;
		}

		ld x = ra * cos(theta / 2), y = ra*sin(theta / 2);
		ld x2 = sqrt(rb*rb - y*y);
		ld ox = x2 + x;

		bool f2 = false;
		for (ld T = 0.0; T < pi + eps; T += 0.0001) {
			ld X = XB + ox * cos(T);
			ld Y = YB + ox *sin(T);
			if (((X + ra) < (ld)W + 0.0001) && ((X - ra) > -0.0001)) {
				if (((Y + ra) < (ld)H + 0.0001) && ((Y - ra) > -0.0001)) {
					XA = X; YA = Y;
					f2 = true;
					break;
				}
			}
		}
		if (!f2) {
			cout << "impossible" << endl;
			continue;
		}
		if (swaped) {
			swap(XA, XB);
			swap(YA, YB);
			swap(ra, rb);
		}
		cout << fixed << setprecision(10) << XA << " " << YA << " " << ra << " " << XB << " " << YB << " " << rb << endl;
	}
	return 0;
}