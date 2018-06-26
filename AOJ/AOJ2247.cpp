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

/* -----  2018/06/26  Problem: AOJ 2247 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2247  ----- */
/* ------問題------

バーベルの回転
- 速度と方向が与えられるのでシュミレーションせよ

-----問題ここまで----- */
/* -----解説等-----

絵に書く。
すると以下の情報が得られる。
- 回転方向が一致するときは外分点を中心に回転する
- 回転方向が一致しないときは内分点を中心に回転する

あとは面倒だけどホイすれば良い。

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
Point rotate(Point p, double thi) {
	return Point(p.real()*cos(thi) - p.imag()*sin(thi),
		p.real()*sin(thi) + p.imag()*cos(thi));
}
Point mulconst(Point& p, double K) { // K倍
	return Point(p.real()*K, p.imag()*K);
}

void NextState(Point& L, Point& R, double Lgo, double Rgo) {
	if (abs(Lgo - Rgo) < eps) { //すすめる
		Point Vec = R - L;
		Point E = Vec / abs(Vec);
		Point VecP90 = rotate(E, PI / 2.0);
		L += mulconst(VecP90, Lgo);
		R += mulconst(VecP90, Rgo);
	}
	else { // 内分/外分
		// Center
		Point Bunshi = mulconst(L, -Rgo) + mulconst(R, Lgo);
		Point Cent = mulconst(Bunshi, 1 / (Lgo - Rgo));
		// 原点っぽくみる
		Point NL = L - Cent;
		Point NR = R - Cent;

		double Lr = abs(NL);
		double Rr = abs(NR);
		if (Lgo*Rgo > 0) { // 外分
			if (Rgo > Lgo) { // 時計
				L = Cent + rotate(NL, abs(Lgo) / Lr);
				R = Cent + rotate(NR, abs(Rgo) / Rr);
			}
			else { // 逆時計
				L = Cent + rotate(NL, -abs(Lgo) / Lr);
				R = Cent + rotate(NR, -abs(Rgo) / Rr);
			}

		}
		else { // 内分
			L = Cent + rotate(NL, -Lgo / Lr); // ok
			R = Cent + rotate(NR, Rgo / Rr);
		}
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);


	int N, D;
	while (cin >> N >> D, N) {
		Point L(-D, 0);
		Point R(D, 0);
		cout << fixed << setprecision(10);

		FOR(i, 0, N) {
			int Lsp, Rsp, time;
			cin >> Lsp >> Rsp >> time;
			double Lgo = Lsp*1.0 / 360 * 2 * PI*time;
			double Rgo = Rsp*1.0 / 360 * 2 * PI*time;
			NextState(L, R, Lgo, Rgo);
		}
		Point mid = (L + R);
		cout << mid.real() / 2 << endl;
		cout << mid.imag() / 2 << endl;

	}

	return 0;
}
