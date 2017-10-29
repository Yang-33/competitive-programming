#include "bits/stdc++.h"
#include <complex>
using namespace std;

/* -----  2017/10/03  Problem: AOJ 0012  / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0012&lang=jp ----- */
/* ------問題------

三角形の中に点があるかの判定

-----問題ここまで----- */
/* -----解説等-----

CCWを使えばよい
線分によって内包されている領域が三角形の内部となる。
したがってそれを判定すればいい。
幾何ライブラリを栽培し始めた

----解説ここまで---- */


#define X real()
#define Y imag()

typedef long double D;
typedef complex<D> P;
typedef pair<P, P> L;
typedef vector<P> Pol;

const D INF = 1e40;
const D EPS = 1e-8;
const D PI = acos(-1);

int sig(D r) { return (r < -EPS) ? -1 : (r > EPS) ? 1 : 0; }
bool eq(D a, D b) { return abs(a - b) < EPS; }
bool near(P a, P b) { return abs(b - a) < EPS; }

// 内積
D dot(P a, P b) { return a.X * b.X + a.Y * b.Y; }
// 外積
D cross(P a, P b) { return a.X * b.Y - a.Y * b.X; }

// 線分のベクトル
P vec(L a) { return a.second - a.first; }

// 線分abに対する点xの位置
enum CCW { FRONT = 1, RIGHT = 2, BACK = 4, LEFT = 8, ON = 16 };
int ccw(L s, P p) {
	P a = vec(s);
	p -= s.first;
	D cr = cross(a, p);
	if (eq(cr, 0)) {
		if (sig(dot(a, p)) < 0) return BACK;
		if (sig(norm(a) - norm(p)) < 0) return FRONT;
		return ON;
	}
	return (cr > 0) ? LEFT : RIGHT;
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	P a, b, c, p;
	D x[8];
	while (cin >> x[0] >> x[1] >> x[2] >> x[3] >> x[4] >> x[5] >> x[6] >> x[7]) {
		a = P(x[0], x[1]);
		b = P(x[2], x[3]);
		c = P(x[4], x[5]);
		p = P(x[6], x[7]);
		int bit = ccw(L(a, b), p) | ccw(L(b, c), p) | ccw(L(c, a), p);
		if (bit == RIGHT || bit == LEFT) {
			cout << "YES" << endl;
		}
		else cout << "NO" << endl;
	}

	return 0;
}
