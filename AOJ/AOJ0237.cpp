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

/* -----  2019/08/18  Problem: AOJ 0237 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0237  ----- */


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

// 単位ベクトル
Vector unit_vector(const Vector& a) {
	return a / abs(a);
}
// 単位法線ベクトル Vector aについて右，左を返却
pair<Vector, Vector> normal_unit_vectors(const Vector& a) {
	return make_pair(unit_vector(Vector(a.y, -a.x)), unit_vector(Vector(-a.y, a.x)));
}

int ccw(const Point& a, const Point& b, const Point&  c) {
	Vector ba = b - a, ca = c - a;
	if (cross(ba, ca) > EPS) return +1; // ccw
	if (cross(ba, ca) < -EPS) return -1; // cw
	if (dot(ba, ca) < -EPS) return +2; // c-a-b
	if (abs(ba) + EPS < abs(ca)) return -2; // a-b-c
	return 0; // a-c-b
}

// 直線、線分構造体
typedef struct Line {
	Point s, e;
	Line(Point s_, Point e_) : s(s_), e(e_) {}
} Segment;

// 線分の交差判定
bool is_crossss(const Segment& a, const Segment& b) {
	return (ccw(a.s, a.e, b.s) * ccw(a.s, a.e, b.e) <= 0
		&& ccw(b.s, b.e, a.s) * ccw(b.s, b.e, a.e) <= 0);
}

// 多角形構造体
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

// 点の内包判定
enum { IN, ON, OUT };
int point_in_poly(const Polygon& g, const Point& p) {
	bool in = false;
	int n = SZ(g);

	FOR(i, 0, n) {
		Point a = g.at(i) - p, b = g.at(i + 1) - p;
		if (a.y > b.y) swap(a, b);
		if (a.y <= 0 && 0 < b.y && cross(a, b) + EPS < 0) in = !in;
		if (fabs(cross(a, b)) < EPS && dot(a, b) <= 0) return ON;
	}

	return in ? IN : OUT;
}

// 多角形同士の交差判定 
int poly_touch_poly(const Polygon& a, const Polygon& b) {
	int status = OUT;
	auto update = [&](int &as, int bs) {
		if (bs == IN)as = IN;
		if (bs == ON)as = (as != IN ? ON : IN);
	};
	for (auto p : a.vert) {
		update(status, point_in_poly(b, p));
	}
	for (auto p : b.vert) {
		update(status, point_in_poly(a, p));
	}
	FOR(i, 0, SZ(a.vert)) {
		Line aa(a.at(i), a.at(i + 1));
		FOR(j, 0, SZ(b.vert)) {
			Line bb(b.at(j), b.at(j + 1));
			if (is_crossss(aa, bb))update(status, IN);
		}
	}

	return status;
}


class SCC {
private:
	const int n;
	vector<vector<int>> G;
	vector<vector<int>> rG;
	vector<int > vs;
	vector<bool> used;
	vector<int > cmp;
	int sccsize_k;
public:
	SCC(int _n) : n(_n), G(_n), rG(_n), used(_n), cmp(_n) {}
	void addEdge(int from, int to) {
		G[from].emplace_back(to);
		rG[to].emplace_back(from);
	}
	void dfs(int v) {
		used[v] = true;
		for (auto&& nxt : G[v]) {
			if (!used[nxt]) dfs(nxt);
		}
		vs.emplace_back(v);
	}
	void rdfs(int v, int k) {
		used[v] = true;
		cmp[v] = k;
		for (auto&& nxt : rG[v]) {
			if (!used[nxt]) rdfs(nxt, k);
		}
		vs.emplace_back(v);
	}
	int scc() {
		for (int v = 0; v < n; v++) {
			if (!used[v]) dfs(v);
		}
		used.assign(n, false);
		sccsize_k = 0;
		for (int i = vs.size() - 1; i >= 0; i--) {
			int v = vs[i];
			if (!used[v]) rdfs(v, sccsize_k++);
		}
		return sccsize_k;
	}
	bool same(int a, int b) {
		return cmp[a] == cmp[b];
	}
	vector<vector<int>>get_graph_DAG() {
		int V = (int)G.size();
		vector<set<int>> s(sccsize_k);
		vector<vector<int>> res(sccsize_k);
		for (int i = 0; i < V; ++i) {
			for (auto e : G[i]) {
				s[cmp[i]].insert(cmp[e]);
			}
		}
		for (int i = 0; i < sccsize_k; ++i) {
			for (auto j : s[i]) {
				if (i != j) {
					res[i].push_back(j);
				}
			}
		}
		return res;
	}
	vector<vector<int>>get_graph_naive() {
		int V = (int)G.size();
		vector<vector<int>> res(sccsize_k);
		for (int i = 0; i < V; ++i) {
			for (int j = 0; j < (int)G[i].size(); j++) {
				if (!same(i, G[i][j]))res[cmp[i]].push_back(cmp[G[i][j]]);
			}
		}
		return res;
	}
	pair<vector<int>, vector<int>> make_degree() {
		vector<vector<int>>newG = get_graph_DAG();
		int N = (int)newG.size();
		vector<int>indeg(N, 0), outdeg(N, 0);
		for (int v = 0; v < N; v++) {
			for (int nx : newG[v]) {
				outdeg[v]++;
				indeg[nx]++;
			}
		}
		return { indeg,outdeg };
	}

	vector<int>get_color() {
		return cmp;
	}
};




int main() {
	int N, D;
	while (cin >> N >> D, N) {
		// 多角形の交錯を使用
		vector<Polygon>ps;
		FOR(i, 0, N) {
			Polygon p(0); {
				FOR(j, 0, 3) {
					double x, y; cin >> x >> y;
					p.vert.emplace_back(x, y);
				}
			}
			ps.emplace_back(p);
		}

		// [(up:s,down:e) -> [---]
		auto make_rectangle2 = [](const Segment& s, Double d) {
			Polygon p(0);
			{ // ->
				p.vert.emplace_back(s.s);
			}
			Vector unit_norm = normal_unit_vectors(s.e - s.s).first;
			{ // ]
				p.vert.emplace_back(s.s + unit_norm * d);
			}
			{ // <-
				p.vert.emplace_back(s.e + unit_norm * d);
			}
			{ // [
				p.vert.emplace_back(s.e);
			}

			return p;
		};

		auto make_rectangle = [&](const Polygon &p) {
			// - 一緒じゃないやつを見つける
			// - すごく長い長方形で両方向試して，残りの点を含んだ方を採用
			Segment s(Point(0, 0), Point(0, 0));
			int notid = 0;
			{
				FOR(i, 0, 3) {
					int ii = (i + 1) % 3;
					bool notsame = 1;
					FOR(j, 0, 3) {
						if (i == j)continue;
						int jj = (j + 1) % 3;
						if (abs(distance(p.at(i), p.at(i + 1)) - distance(p.at(j), p.at(j + 1))) < EPS)notsame = 0;
					}
					if (notsame) {
						s = Segment(p.vert[i], p.vert[ii]);
						notid = (i + 2) % 3;
					}
				}
			}
			Polygon res;
			FOR(i, 0, 2) { // check
				Polygon rec = make_rectangle2(s, INF);
				if (point_in_poly(rec, p.at(notid)) != OUT) {
					res = make_rectangle2(s, D);
				}
				swap(s.s, s.e);
			}

			return res;
		};

		SCC Graph(N);
		FOR(i, 0, N) {
			auto pi = make_rectangle(ps[i]);
			FOR(j, 0, N) {
				if (i == j)continue;
				if (poly_touch_poly(pi, ps[j]) != OUT) {
					Graph.addEdge(i, j);
				}
			}
		}
		Graph.scc();
		auto resdegs = Graph.make_degree();
		VI indeg = resdegs.first;
		int ans = 0;
		for (auto it : indeg) {
			if (it == 0)ans++;
		}
		cout << ans << "\n";

	}


	return 0;
}
