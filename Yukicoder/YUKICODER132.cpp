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

/* -----  2018/05/02  Problem: yukicoder 132  / Link: http://yukicoder.me/problems/no/132  ----- */
/* ------問題------

3 次元上のある点 P と、N 個の点 Q1,Q2,…,QN が与えられます。
dist(i,j,k) で、点 P と、点 Qi,Qj,Qk が通る平面との距離とします。
点 P と、Qi,Qj,Qk が通る平面との距離の和を求めるプログラムを書いて下さい。
つまり ∑1≤i<j<k≤Ndist(i,j,k) の値を求めるプログラムを書いて下さい。
点 x と平面 y の距離は、点 x と、点 x から平面 y に下ろした垂線の足との距離です。

-----問題ここまで----- */
/* -----解説等-----

f(3p) = cross(p1p2,p1p3)
あとは距離を求めておしまい。

----解説ここまで---- */
using Double = long double;

typedef struct Point {
	Double x, y, z;
	Point(Double x_ = 0, Double y_ = 0, Double z_ = 0) : x(x_), y(y_), z(z_) {}
	Point operator - (const Point& p)const {
		return Point(x - p.x, y - p.y, z - p.z);;
	}

} Vector;

Point cross(const Vector& a, const Vector& b) {
	Point ret(a.y*b.z - a.z*b.y, a.z*b.x - a.x*b.z, a.x*b.y - a.y*b.x);
	return ret;
}

Double dist(int i, int j, int k, vector<Point>& ps, Point& P) {
	Vector ab = ps[i] - ps[j];
	Vector ac = ps[i] - ps[k];
	Vector cr = cross(ab, ac);
	Double a = -(cr.x*ps[i].x + cr.y*ps[i].y + cr.z*ps[i].z);
	Double ret = abs(cr.x*P.x + cr.y*P.y + cr.z*P.z + a) / sqrt(cr.x*cr.x + cr.y*cr.y + cr.z*cr.z);
	return ret;
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;
	Point P;
	cin >> P.x >> P.y >> P.z;
	vector<Point>ps(N);
	FOR(i, 0, N) {
		cin >> ps[i].x >> ps[i].y >> ps[i].z;
	}
	Double ans = 0;
	FOR(i, 0, N) {
		FOR(j, i+1, N) {
			FOR(k, j+1, N) {
				ans += dist(i, j, k, ps, P);
			}
		}
	}

	cout << fixed<< setprecision(10)<<ans << "\n";

	return 0;
}
