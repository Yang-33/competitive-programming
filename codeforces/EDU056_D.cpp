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
const LL MOD = 998244353;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/12/15  Problem: EDU056 D / Link: __CONTEST_URL__  ----- */
/* ------問題------

非連結グラフが与えられる。
各頂点に1,2,3を割り振って、ある辺の両端を見たときに常に奇数になるようにしたい。
このような割り振り方は何通りか?

-----問題ここまで----- */
/* -----解説等-----

1-2,3-2の辺しか存在しないので、[1,3]-2で二部グラフになる。
もとのグラフが二部グラフでないならばダメで、
もし良いなら、R,Bに割り振られた頂点に対してans*=(2^B+2^R)個塗り方がある。

二部グラフライブラリが連結用で頭が回らなかったのでグラフのre_idをするやつを書いてしまった。(コメントアウトしてある方)
コメントアウトしてない方みたいに書くと楽。

連結re_idは同じ速度までチューニングできたので今度はそっちを貼るだけにした。

----解説ここまで---- */
LL read() { LL in; scanf("%lld", &in); return in; }

// 各連結成分ごとに、二部グラフであるか?/yesならその彩色を+,-でふりわけた値のvectorを返す(0は常に+とする)
vector<pair<bool, vector<int>>> BipartiteGraphInfo(const std::vector<std::vector<int>>& g) {
	int n = g.size();
	std::vector<int> color(n, -1);
	vector<pair<bool, vector<int>>>infos;
	FOR(i, 0, n) {
		if (color[i] == -1) {
			std::queue<int> que;
			que.push(i);
			color[i] = 0; // colorを更新するときに色を数えることもできる
			int ok = 1;
			vector<int>res;
			res.push_back(i);
			while (!que.empty()) {
				int now = que.front(); que.pop();
				for (auto to : g[now]) {
					if (color[to] != -1) {
						if (color[now] == color[to]) {
							ok = 0;
						}
					}
					else {
						color[to] = color[now] ^ 1;
						res.push_back(color[to] ? -to : to);
						que.push(to);
					}
				}
			}
			if (ok) {
				infos.push_back(pair<bool, vector<int>>(true, move(res)));
			}
			else {
				infos.push_back(pair<bool, vector<int>>(false, vector<int>()));
			}
		}
	}
	return infos;
}
template <::std::uint_fast32_t MODULO> class modint {
public:
	using uint32 = ::std::uint_fast32_t; using uint64 = ::std::uint_fast64_t; using value_type = uint32; uint32 a; modint() noexcept : a(0) {}modint(const uint32 x) noexcept : a(x) {}modint operator+(const modint &o) const noexcept { return a + o.a < MODULO ? modint(a + o.a) : modint(a + o.a - MODULO); }modint operator-(const modint &o) const noexcept { return modint(a < o.a ? a + MODULO - o.a : a - o.a); }modint operator*(const modint &o) const noexcept { return modint(static_cast<uint64>(a) * o.a % MODULO); }modint operator/(const modint &o) const { return modint(static_cast<uint64>(a) * (~o).a % MODULO); }modint &operator+=(const modint &o) noexcept { return *this = *this + o; }modint &operator-=(const modint &o) noexcept { return *this = *this - o; }modint &operator*=(const modint &o) noexcept { return *this = *this * o; }modint &operator/=(const modint &o) { return *this = *this / o; }modint operator~() const noexcept { return pow(MODULO - 2); }modint operator-() const noexcept { return a ? modint(MODULO - a) : *this; }modint operator++() noexcept { return a == MODULO - 1 ? a = 0 : ++a, *this; }modint operator--() noexcept { return a ? --a : a = MODULO - 1, *this; }bool operator==(const modint &o) const noexcept { return a == o.a; }bool operator!=(const modint &o) const noexcept { return a != o.a; }bool operator<(const modint &o) const noexcept { return a < o.a; }bool operator<=(const modint &o) const noexcept { return a <= o.a; }bool operator>(const modint &o) const noexcept { return a > o.a; }bool operator>=(const modint &o) const noexcept { return a >= o.a; }explicit operator bool() const noexcept { return a; }explicit operator uint32() const noexcept { return a; }modint pow(uint32 x) const noexcept { uint64 t = a, u = 1; while (x) { if (x & 1)u = u * t % MODULO; t = (t * t) % MODULO; x >>= 1; }	return modint(u); }
	uint32 get() const noexcept { return a; }
};
using mint = modint<MOD>;


int main() {
	int T = read();
	FOR(_, 0, T) {
		LL N = read(), M = read();
		VVI G(N);
		FOR(i, 0, M) {
			int a = read() - 1, b = read() - 1;
			G[a].push_back(b);
			G[b].push_back(a);
		}

		mint ans = 1;
		int f = 1;
		auto infos = BipartiteGraphInfo(G);
		for (auto it : infos) {
			if (it.first) {
				int R = 0;
				int bb = 0;
				for (int i : it.second) {
					if (i >= 0)R++;
					else bb++;
				}
				int B = SZ(it.second) - R;
				//assert(bb == B);
				mint two = 2;
				mint res = 0;
				res += two.pow(B);
				res += two.pow(R);
				ans *= res;
			}
			else {
				f = 0;
			}
		}

		if (f) {
			cout << ans.get() << endl;
		}
		else {
			cout << 0 << endl;
		}
	}

	return 0;
}

//LL read() { LL in; scanf("%lld", &in); return in; }
//// /*  g is     bipartite-graph : return 0/1 vector
//// /*  g is NOT bipartite-graph : return empty vector
//std::vector<int> isBipartiteGraph(const std::vector<std::vector<int>>& g) {
//	int n = g.size();
//	std::vector<int> color(n, -1);
//	std::queue<int> que;
//	que.push(0);
//	color[0] = 0; // colorを更新するときに色を数えることができる
//	while (!que.empty()) {
//		int now = que.front(); que.pop();
//		for (auto to : g[now]) {
//			if (color[to] != -1) {
//				if (color[now] == color[to]) {
//					return std::vector<int>();
//				}
//			}
//			else {
//				color[to] = color[now] ^ 1;
//				que.push(to);
//			}
//		}
//	}
//	return color;
//}
//template <::std::uint_fast32_t MODULO> class modint {
//public:
//	using uint32 = ::std::uint_fast32_t; using uint64 = ::std::uint_fast64_t; using value_type = uint32; uint32 a; modint() noexcept : a(0) {}modint(const uint32 x) noexcept : a(x) {}modint operator+(const modint &o) const noexcept { return a + o.a < MODULO ? modint(a + o.a) : modint(a + o.a - MODULO); }modint operator-(const modint &o) const noexcept { return modint(a < o.a ? a + MODULO - o.a : a - o.a); }modint operator*(const modint &o) const noexcept { return modint(static_cast<uint64>(a) * o.a % MODULO); }modint operator/(const modint &o) const { return modint(static_cast<uint64>(a) * (~o).a % MODULO); }modint &operator+=(const modint &o) noexcept { return *this = *this + o; }modint &operator-=(const modint &o) noexcept { return *this = *this - o; }modint &operator*=(const modint &o) noexcept { return *this = *this * o; }modint &operator/=(const modint &o) { return *this = *this / o; }modint operator~() const noexcept { return pow(MODULO - 2); }modint operator-() const noexcept { return a ? modint(MODULO - a) : *this; }modint operator++() noexcept { return a == MODULO - 1 ? a = 0 : ++a, *this; }modint operator--() noexcept { return a ? --a : a = MODULO - 1, *this; }bool operator==(const modint &o) const noexcept { return a == o.a; }bool operator!=(const modint &o) const noexcept { return a != o.a; }bool operator<(const modint &o) const noexcept { return a < o.a; }bool operator<=(const modint &o) const noexcept { return a <= o.a; }bool operator>(const modint &o) const noexcept { return a > o.a; }bool operator>=(const modint &o) const noexcept { return a >= o.a; }explicit operator bool() const noexcept { return a; }explicit operator uint32() const noexcept { return a; }modint pow(uint32 x) const noexcept { uint64 t = a, u = 1; while (x) { if (x & 1)u = u * t % MODULO; t = (t * t) % MODULO; x >>= 1; }	return modint(u); }
//	uint32 get() const noexcept { return a; }
//};
//using mint = modint<MOD>;
//class SCC {
//private:
//	const int n;
//	vector<vector<int>> G;
//	vector<vector<int>> rG;
//	vector<int > vs;
//	vector<bool> used;
//	vector<int > cmp;
//	int sccsize_k;
//public:
//	SCC(int _n) : n(_n), G(_n), rG(_n), used(_n), cmp(_n) {}
//	void addEdge(int from, int to) {
//		G[from].emplace_back(to);
//		rG[to].emplace_back(from);
//	}
//	void dfs(int v) {
//		used[v] = true;
//		for (auto&& nxt : G[v]) {
//			if (!used[nxt]) dfs(nxt);
//		}
//		vs.emplace_back(v);
//	}
//	void rdfs(int v, int k) {
//		used[v] = true;
//		cmp[v] = k;
//		for (auto&& nxt : rG[v]) {
//			if (!used[nxt]) rdfs(nxt, k);
//		}
//		vs.emplace_back(v);
//	}
//	int scc() {
//		for (int v = 0; v < n; v++) {
//			if (!used[v]) dfs(v);
//		}
//		used.assign(n, false);
//		sccsize_k = 0;
//		for (int i = vs.size() - 1; i >= 0; i--) {
//			int v = vs[i];
//			if (!used[v]) rdfs(v, sccsize_k++);
//		}
//		return sccsize_k;
//	}
//	bool same(int a, int b) {
//		return cmp[a] == cmp[b];
//	}
//	vector<int >get_color() {
//		return cmp;
//	}
//};
//
//vector<VVI> ForestToGraphs(const vector<PII>&edge, int V) {
//
//	int  scc_sz;
//	vector<int>color; {
//		SCC SccG(V);
//		for (const auto&it : edge) {
//			SccG.addEdge(it.first, it.second);
//			SccG.addEdge(it.second, it.first);
//		}
//		scc_sz = SccG.scc();
//		color = SccG.get_color();
//	}
//
//
//	vector<int>CC(scc_sz, 0);
//	vector<vector<PII>>reid_edges(scc_sz); {
//		map<PII, int>Map;
//		auto reid = [&Map, &CC](const int c, const int x) {
//			auto it = Map.find(PII(c, x));
//			if (it != Map.end()) {
//				return it->second;
//			}
//			else {
//				int nc = CC[c];
//				Map[PII(c, x)] = nc;
//				CC[c]++;
//				return nc;
//			}
//		};
//		FOR(i, 0, SZ(edge)) {
//			int a = edge[i].first, b = edge[i].second;
//			const int c = color[a];
//			a = reid(c, a), b = reid(c, b);
//			reid_edges[c].push_back(PII(a, b));
//		}
//	}
//	vector<VVI> Graphs(scc_sz); {
//		FOR(i, 0, scc_sz) {
//			Graphs[i].resize(CC[i]);
//			FOR(j, 0, SZ(reid_edges[i])) {
//				const int a = reid_edges[i][j].first;
//				const int b = reid_edges[i][j].second;
//				Graphs[i][a].push_back(b);
//				Graphs[i][b].push_back(a);
//			}
//
//		}
//	}
//
//	return Graphs;
//}
//int main() {
//	int T = read();
//	FOR(_, 0, T) {
//		LL N = read(), M = read();
//		vector<VVI>forest; {
//			vector<PII>edge(M);
//			FOR(i, 0, M) {
//				int a = read() - 1, b = read() - 1;
//				edge[i] = PII(a, b);
//			}
//			forest = ForestToGraphs(edge, N);
//		}
//
//		int f = 1;
//		mint ans = 1;
//		FOR(j, 0, SZ(forest)) {
//			DD(de(SZ(forest[j])));
//			if (SZ(forest[j]) == 0) {
//				ans *= 3;
//				DD(de(ans.get()));
//				continue;
//			}
//			VI res = isBipartiteGraph(forest[j]);
//			if (SZ(res)) {
//				int B = 0;
//				FOR(i, 0, SZ(forest[j])) {
//					if (res[i] == 1) {
//						B++;
//					}
//				}
//				int R = SZ(forest[j]) - B;
//				mint two = 2;
//				mint ret = 0;
//				ret += two.pow(R);
//				ret += two.pow(B);
//				ans *= ret;
//			}
//			else {
//				f = 0;
//			}
//			DD(de(ans.get()));
//		}
//		if (f) {
//			cout << ans.get() << endl;
//		}
//		else {
//			cout << 0 << endl;
//		}
//	}
//
//	return 0;
//}
