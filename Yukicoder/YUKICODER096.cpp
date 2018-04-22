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
int DX[9] = { 0, 0, 1, -1, 1, 1, -1, -1,0 };    int DY[9] = { 1, -1, 0, 0, 1, -1, 1, -1,0 };

/* -----  2018/04/19  Problem: yukicoder 096  / Link: http://yukicoder.me/problems/no/096  ----- */
/* ------問題------

no64

-----問題ここまで----- */
/* -----解説等-----

愚直O(N^2)が間に合わないので、まず適当に分割をする。ここでは10mの制約を活かして10*10領域に点を入れる。
まず10m以内でつながっているグループに分けないことには、最長距離が求められないため、
隣接8マスをマージの対称にして、UnionFindで集合をまとめる。
まとめ終わったものについてもグループが大きい場合があるので、凸包で頂点数を減らす。
その後はO(V^2)をしてもいいけれど、練習のためキャリパー法を使ってみる。  
凸多角形の最遠点対をO(V)ぐらいで求められるので、勉強して書く。

分割サイズをB,幅をWとして、
O(W^2/B^2+NlogN)?　よくわからない

----解説ここまで---- */

struct UnionFind {
	vector<int> data;
	UnionFind(int n) { data.assign(n, -1); }
	bool unionSet(int x, int y) {
		x = root(x); y = root(y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	bool same(int x, int y) { return root(x) == root(y); }
	int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
	int size(int x) { return -data[root(x)]; }
};

const long double EPS = 1e-9;
using Double = long double;
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
Double cross(const Vector& a, const Vector& b) {
	return a.x * b.y - a.y * b.x;
}
Double norm(const Point& a) {
	return a.x * a.x + a.y * a.y;
}
Double abs(const Point& a) {
	return sqrt(norm(a));
}
Double dot(const Vector& a, const Vector& b) {
	return a.x * b.x + a.y * b.y;
}
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

int ccw(const Point& a, const Point& b, const Point&  c) {
	Vector ba = b - a, ca = c - a;
	if (cross(ba, ca) > EPS) return +1; // ccw
	if (cross(ba, ca) < -EPS) return -1; // cw
	if (dot(ba, ca) < -EPS) return +2; // c-a-b
	if (abs(ba) + EPS < abs(ca)) return -2; // a-b-c
	return 0; // a-c-b
}
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
pair< PII, Double > caliper(const Polygon& p) {
	int n = SZ(p);
	if (n == 2) {
		return make_pair(PII(0, 1), abs(p.at(0) - p.at(1)));
	}
	int i = 0, j = 0;
	FOR(k, 0, n) {
		if (!(p.at(i) < p.at(k))) i = k;
		if (p.at(j) < p.at(k)) j = k;
	}
	PII pp(-1, -1);
	Double res = 0;
	int si = i, sj = j;
	while (i != sj || j != si) {
		Double cur = abs(p.at(i) - p.at(j));

		if (res + EPS < cur) {
			res = cur;
			pp = PII(i, j);
		}
		int di = (i + 1) % n;
		int dj = (j + 1) % n;
		if (cross(p.at(di) - p.at(i), p.at(dj) - p.at(j)) < 0) i = di;
		else j = dj;
	}

	return make_pair(pp, res);
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;
	VI x(N), y(N);
	vector<VVI>backet(2001, VVI(2001));

	FOR(i, 0, N) {
		cin >> x[i] >> y[i];
		x[i] += 10000, y[i] += 10000;
		backet[x[i] / 10][y[i] / 10].push_back(i);
	}
	UnionFind uf(N);

	FOR(i, 0, 2001) {
		FOR(j, 0, 2001) {
			for (auto id : backet[i][j]) {
				FOR(k, 0, 9) {
					int ny = i + DY[k], nx = j + DX[k];
					if (0 <= ny && ny < 2001 && 0 <= nx && nx < 2001) {
						for (auto nid : backet[ny][nx]) {
							int dist = pow(x[id] - x[nid], 2) + pow(y[id] - y[nid], 2);
							if (dist <= 100) {
								uf.unionSet(id, nid);
							}
						}
					}
				}
			}
		}
	}
	VVI groups(N);
	FOR(i, 0, N) {
		groups[uf.root(i)].push_back(i);
	}


	Double ans = 1;
	FOR(i, 0, SZ(groups)) {
		vector<Point>vp;
		FOR(j, 0, SZ(groups[i])) {
			vp.emplace_back(x[groups[i][j]], y[groups[i][j]]);
		}
		Polygon ch = convex_hull(vp);
		if (SZ(ch.vert) > 1) {
			auto ret = caliper(ch);
			ans = max(ans, ret.second + 2);
		}
		else if (SZ(ch.vert) == 1) {
			ans = max(ans, (Double)2);
		}
	}




	cout << fixed << setprecision(10) << ans << "\n";

	return 0;
}
