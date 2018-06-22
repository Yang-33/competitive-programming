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

/* -----  2018/06/24  Problem: AOJ 2224 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2224  ----- */
/* ------問題------

ねこちゃんが囲まれている。
壁を撤去して解放せよ。ただし壁の長さだけコストがかかるのでこれを最小化せよ。

-----問題ここまで----- */
/* -----解説等-----

自明に最大全域森を残したいので、MSTの逆をすればよい。(550…?)

----解説ここまで---- */


/* Union Find */
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



struct edge {
	int f, t;
	double c;
	edge(int a, int b, double cc) :f(a), t(b), c(cc) {}
	bool operator < (const edge &e) const { return c < e.c; };
};

struct KRUSKAL {


	double kruskal(int V, int E, vector<edge>& es) {
		sort(es.begin(), es.end());
		UnionFind uf(V);
		double min_cost = 0;
		FOR(i, 0, E) {
			if (!uf.same(es[i].f, es[i].t)) {
				min_cost += es[i].c;
				uf.unionSet(es[i].f, es[i].t);
			}
		}
		return min_cost;
	}
};

// L 550
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, M; cin >> N >> M;

	vector<double >x(N), y(N);
	FOR(i, 0, N) {
		cin >> x[i] >> y[i];
	}
	auto dist = [&](int i, int j) {
		return sqrt((x[i] - x[j]) *(x[i] - x[j]) + ((y[i] - y[j])*(y[i] - y[j])));
	};
	double sum = 0;
	vector<edge>edges;
	FOR(i, 0, M) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		sum += dist(a, b);
		edges.push_back(edge(a, b, -dist(a, b)));
	}
	KRUSKAL mst;
	double ans = sum + mst.kruskal(N, (int)edges.size(), edges);


	cout << fixed << setprecision(10) << ans << endl;

}