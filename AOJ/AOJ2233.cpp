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

/* -----  2019/06/01  Problem: AOJ 2233 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/2233  ----- */

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
// 距離
Double distance(const Point& a, const Point& b) {
	return abs(a - b);
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


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;
	double R; cin >> R;

	Double Theta; {
		double THETA; cin >> THETA;
		Theta = degToRadian(THETA);
	}

	vector<Point>Ps;
	FOR(i, 0, N) {
		double x, y; cin >> x >> y;
		Ps.push_back(Point(x, y));
	}
	vector<vector<Double>>tocost(N, vector<Double>(N));
	vector<VVI> canthrough = vector<VVI>(N, VVI(N, VI(N, 0)));
	FOR(i, 0, N) {
		FOR(j, 0, N) {
			tocost[i][j] = distance(Ps[i], Ps[j]);
			FOR(k, 0, N) {
				// i,j,k
				Point s = Ps[j] - Ps[i];
				Point t = Ps[k] - Ps[j];
				canthrough[i][j][k] = acos(cosign(s, t)) <= Theta;
			}
		}
	}

	vector<vector<vector<Double>>>dist(N, vector<vector<Double>>(N, vector<Double>((int)R + 1, LINF)));
	using tp = tuple<Double, int, int, int>;
	priority_queue<tp, vector<tp>, greater<tp>>q;
	auto IFPUSH = [&](int nx, int v, int r, Double cost) {
		if (dist[nx][v][r] > cost) {
			dist[nx][v][r] = cost;
			q.push(tp(cost, nx, v, r));
		}
	};

	FOR(i, 1, N) {
		if (tocost[0][i] <= R) {
			IFPUSH(i, 0, 1, tocost[0][i]);
		}
	}
	while (!q.empty()) {
		Double co; int v, p, r;
		tie(co, v, p, r) = q.top(); q.pop();
		FOR(nx, 0, N) {
			if (nx == p || nx == v)continue;
			if (!canthrough[p][v][nx])continue;
			if (co + tocost[v][nx] > R)continue;
			IFPUSH(nx, v, r + 1, co + tocost[v][nx]);
		}

	}
	int ans = 0;
	FOR(i, 0, N) {
		FOR(j, 0, N) {
			if (i == j)continue;
			FOR(k, 1, (int)R + 1) { // k個得た
				if (dist[i][j][k] > R)continue;
				DD(de(dist[i][j][k], i, j, k));
				ans = max(ans, k);
			}
		}
	}
	cout << ans << endl;


	return 0;
}
