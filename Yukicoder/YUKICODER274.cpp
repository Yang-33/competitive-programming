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

/* -----  2018/09/23  Problem: yukicoder 274  / Link: http://yukicoder.me/problems/no/274  ----- */
/* ------問題------

1×1のブロックが横にM個連なった1×Mのブロックがある。
ブロックは基本白色であるが左からL番目から左からR番目(0-index)までの連続したブロックはピンク色である。
ブロックは180度回転することもできる（90度回転はできません）。
すなわち、以下の図のようなものである。



横の長さが同じ1×MのN本のブロックが与えられる。
それぞれのブロックはそれぞれピンク色の連続した領域を1つ持つ。
N本のブロックを上に積んでいき良い壁を作りたい。
良い壁とは縦の列でブロックを見たときピンク色のブロックが1つ以下のものをいう。

例えば、1×6のブロックを4つ積んだときの良い壁と悪い壁の例。


左の壁は縦にブロックを見たときにピンク色のブロックが無いか1つのピンク色のブロックがある良い壁である。
一方、右の壁は縦で見たときピンク色のブロックが2つ以上ある場合があり悪い壁である。

いずれのブロックにも180度回転を好きなだけ行うことができる。
与えられるN本のブロックをすべて積んで良い壁を作れるか判定せよ。

-----問題ここまで----- */
/* -----解説等-----

ある対称な点において、2箇所以上線分が存在する場合は無理。
あとは適当にできる。


2sat解: あるw:Wにおいて、これを選択するならば他のものは選択できない、をつくる?



----解説ここまで---- */

class SCC {
public:
	const int n;
	vector<vector<int>> G;
	vector<vector<int>> rG;
	vector<int > vs;
	vector<bool> used;
	vector<int > cmp;
	int sccsize_k;
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
		vector<set<int>> s(sccsize_k);//group間に多重辺があるときにこれを解消してDAGにするためのset
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
	vector<vector<int>>get_graph_naive() { //多重辺のあるDAG
		int V = (int)G.size();
		vector<vector<int>> res(sccsize_k);
		for (int i = 0; i < V; ++i) {
			for (int j = 0; j < (int)G[i].size(); j++) {
				if (!same(i, G[i][j]))res[cmp[i]].push_back(cmp[G[i][j]]);
			}
		}
		return res;
	}

	vector<int>get_color() {
		return cmp;
	}
};

// Aの状態を0/1として、2つの関係について
// 禁止するものに対して辺を貼ることで、この禁止成約をみたすようなものが存在するかを判定する。
struct TwoSat {
	int v;
	SCC graph;

	// v literals
	// 0~v-1: true
	// v~2v-1: false

	TwoSat(int n):v(n),graph(2*v){}

	inline int num(int id, bool b) { return id + (b ? 0 : v); }

	void addClause(int x, bool X, int y, bool Y) {
		graph.addEdge(num(x, !X), num(y, Y));
		graph.addEdge(num(y, !Y), num(x, X));
	}

	// 割り当てが可能か調べる
	bool satisfiability() {
		graph.scc();
		FOR(i,0,v)if (graph.cmp[i] == graph.cmp[v + i]) return false;
		return true;
	}

	// リテラルの真偽値を返す
	vector<bool> get_literals() {
		assert(satisfiability());
		vector<bool> res(v);
		FOR(i,0,v)res[i] = (graph.cmp[i]>graph.cmp[v + i]);
		return res;
	}

	void usage(VI A) {
		auto prohibit = [](auto a,auto b) {
			return true; // false
		};
		auto rev = [](auto a) {
			return a;
		};
		int n;
		FOR(i, 0, n)FOR(j, 0, i) {
			FOR(ii, 0, 2)FOR(jj, 0, 2) {
				int bi = A[i], bj = A[j];
				if (ii) rev(bi);
				if (jj) rev(bj);
				if (prohibit(bi,bj))addClause(i, ii, j, jj);
			}
		}
	}
};



int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int H, W; cin >> H >> W;
	TwoSat solver(H);
	vector<PII>LR(H);
	FOR(i, 0, H) {
		cin >> LR[i].first >> LR[i].second;
	}

	auto cover = [](const PII&a, const PII&b){
		return max(a.first, b.first) <= min(a.second, b.second);
	};
	auto rev = [&W](const PII&a) {
		return PII(W-a.second-1,W-a.first-1);
	};



	FOR(i, 0, H) {
		FOR(j, 0, i) {
			FOR(ii, 0, 2)FOR(jj, 0, 2) {
				PII x = LR[i], y = LR[j];
				if (ii)x = rev(x);
				if (jj)y = rev(y);
				if (cover(x, y)) {
					solver.addClause(i, ii, j, jj);
				}
			}
		}
	}

	
	cout << (solver.satisfiability() ? "YES" : "NO") << endl;

	return 0;
}
