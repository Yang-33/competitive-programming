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

/* -----  2017/12/20  Problem: AOJ 0366 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0366  ----- */
/* ------問題------

観光で有名な会津国には、それぞれ 0 から N-1 までの番号が割り当てられた N 個の都市があり、２つの都市を結ぶ一方通行のM 本の道路で道路網が形成されている。
会津国では、都市を結ぶすべての道路沿いに桜並木がある。観光客に桜を楽しんでもらえるように、すべての道路を巡ることができるような道路網に改修したい。そのため、以下の条件を満たすように２つの都市を直接結ぶ道路を何本か増設することにした。
増設する道路は、一方通行のものに限る。
任意の都市から出発したとき、増設したものも含めて国内のすべての道路を１度以上通って出発した都市に戻ることができる。
会津国の観光推進担当者であるあなたは、プログラムを作成して道路建設計画を立てることになった。
会津国の都市と道路の情報が与えられたとき、増設しなければならない道路の数の最小値を出力するプログラムを作成せよ。

-----問題ここまで----- */
/* -----解説等-----

SCCしたあとのDAGについて、この問題はさらにこのDAGを強連結にしたいという問題に言い換えられる。
入次数0,出次数0の強連結成分を発見し、これをかたがわに繋げば最小の構成で目的とする強連結なグラフを作ることができる。
したがってこれらのMAXをとればよい。
はっつけるだけだった
ちなみに問題文はクソで、M=0のときはこれは本来は落ちる。
というのは元ある辺について、追加した辺も通れるようにするということは、辺がないときは何もしなくても良い。
テストケースにはこれがはいっており、ジャッジが間違っている。（答えがNとされている、これは間違い）

----解説ここまで---- */

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
		FOR(v, 0, n) {
			if (!used[v]) dfs(v);
		}
		used.assign(n, false);
		sccsize_k = 0;
		for (int i = vs.size() - 1; i >= 0; i--) {
			int v = vs[i];
			if (!used[v]) rdfs(v, sccsize_k++);
		}
		return sccsize_k;//size
	}
	bool same(int a, int b) {
		return cmp[a] == cmp[b];
	}
	vector<vector<int>>get_graph() {
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
	int color(int v) {
		return cmp[v];
	}
};
LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int M;
	cin >> N >> M;

	SCC scc(N);
	vector<PII>edge(M);
	FOR(i, 0, M) {
		int s, t;
		cin >> s >> t;
		edge[i] = PII(s, t);
		scc.addEdge(s, t);
	}
	int col = scc.scc();
	VVI sccgraph = scc.get_graph(); //頂点が入っている

	VI indeg(col, 0);
	VI outdeg(col, 0);

	FOR(i, 0, M) {
		int s, t;
		tie(s, t) = edge[i];
		if (scc.same(s, t))continue;
		else {// ぐらふにささる
			outdeg[scc.color(s)]++;
			indeg[scc.color(t)]++;
		}
	}
//	debug(col);
	if (col == 1) {
		cout << 0 << endl;
		return 0;
	}

	int inzero = 0;
	int outzero = 0;
	FOR(i, 0, col) {
		if (indeg[i] == 0)inzero++;
		if (outdeg[i] == 0)outzero++;
	}
	ans = (LL)max(inzero, outzero);
	cout << ans << "\n";

	return 0;
}
