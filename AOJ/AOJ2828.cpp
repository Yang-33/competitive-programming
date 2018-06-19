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

/* -----  2018/06/23  Problem: AOJ 2828 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2828  ----- */
/* ------問題------

マトリョーシカはロシアの民芸品として有名な人形である． マトリョーシカは上下に分割でき，開くと中により小さい別の人形が入っている． 現れた小さい人形を開くとさらに小さい人形が入っている，というような入れ子構造になっている．
あなたは旅行先で珍しい形のマトリョーシカを見つけ，N 体の人形を購入した． i 番目の人形の形状は，xi × yi × zi の直方体である．
ひとしきりマトリョーシカを鑑賞したあなたは，マトリョーシカを仕舞おうとしている． その前に，いくつかの人形を別の人形に格納することによって必要なスペースを減らしたい． 人形を格納する際には，まだ中にひとつも人形を格納していない人形にだけ，他の人形をひとつ格納できる． ただし，直接的に格納される人形についてだけ数えるものとし，中に人形が入っている人形を別の人形に格納することはできる．
収納された人形は，外部から見えない状態になる． ただし，以下の条件を満たさなければならない．
人形は回転してよいが，直方体のそれぞれの辺は，他方の直方体のいずれかの辺に平行
回転後，対応する辺同士の長さそれぞれについて，収納される側の人形の長さの方が短い
1 個の人形の中に直接収納できる人形の数は高々 1 個
押入れの容積は限られているので，外部から見えている人形の体積の和を最小化したい． あなたの仕事は，人形を収納する操作を任意の回数繰り返して達成できる，外部から見えている人形の体積の和の最小値を求めるプログラムを作成することである．

-----問題ここまで----- */
/* -----解説等-----

意味論を考えると、箱の中に"入るものは"コストゼロにできる。
DAGの最小パス被覆ぽいなと思えれば、in/outの関係にすることができる。
あとはコストがかかる、かからないを表現すれば良い。

----解説ここまで---- */

typedef long long PD_Type;
const PD_Type PD_INF = 1 << 30;

struct Primal_Dual
{
	typedef pair< PD_Type, int > pii;

	struct edge
	{
		int to, rev;
		PD_Type	cap, cost;
		edge() {}
		edge(int to, PD_Type cap, PD_Type cost, int rev) :to(to), cap(cap), cost(cost), rev(rev) {}

	};
	vector< vector< edge > > graph;
	vector< int > prevv, preve;
	vector< PD_Type > potential, min_cost;
	Primal_Dual(int V) : graph(V) {}

	void add_edge(int from, int to, PD_Type cap, PD_Type cost)
	{
		graph[from].push_back(edge(to, cap, cost, (int)graph[to].size()));
		graph[to].push_back(edge(from, 0, -cost, (int)graph[from].size() - 1));
	}

	PD_Type min_cost_flow(int s, int t, int f)
	{
		int V = graph.size();
		PD_Type ret = 0;
		priority_queue< pii, vector< pii >, greater< pii > > que;
		potential.assign(V, 0);
		preve.assign(V, -1);
		prevv.assign(V, -1);

		while (f > 0) {
			min_cost.assign(V, PD_INF);
			que.push(pii(0, s));
			min_cost[s] = 0;

			while (!que.empty()) {
				pii p = que.top();
				que.pop();
				if (min_cost[p.second] < p.first) continue;
				for (int i = 0; i < (int)graph[p.second].size(); i++) {
					edge &e = graph[p.second][i];
					PD_Type nextCost = min_cost[p.second] + e.cost + potential[p.second] - potential[e.to];
					if (e.cap > 0 && min_cost[e.to] > nextCost) {
						min_cost[e.to] = nextCost;
						prevv[e.to] = p.second, preve[e.to] = i;
						que.push(pii(min_cost[e.to], e.to));
					}
				}
			}
			if (min_cost[t] == PD_INF) return -1;
			for (int v = 0; v < V; v++) potential[v] += min_cost[v];
			PD_Type addflow = f;
			for (int v = t; v != s; v = prevv[v]) {
				addflow = min(addflow, graph[prevv[v]][preve[v]].cap);
			}
			f -= addflow;
			ret += addflow * potential[t];
			for (int v = t; v != s; v = prevv[v]) {
				edge &e = graph[prevv[v]][preve[v]];
				e.cap -= addflow;
				graph[v][e.rev].cap += addflow;
			}
		}
		return ret;
	}
};
int N;
struct hako {
	int h, w, d;
	int V;
	hako(int h = 0, int w = 0, int d = 0) :h(h), w(w), d(d) {
		V = h * w * d;
	}
	bool operator < (const hako& hako2) const {
		if (h < hako2.h && w < hako2.w && d < hako2.d) return true;
		if (h < hako2.h && w < hako2.d && d < hako2.w) return true;
		if (h < hako2.w && w < hako2.h && d < hako2.d) return true;
		if (h < hako2.w && w < hako2.d && d < hako2.h) return true;
		if (h < hako2.d && w < hako2.h && d < hako2.w) return true;
		if (h < hako2.d && w < hako2.w && d < hako2.h) return true;
		return false;
	}
};
LL solve() {
	LL res = 0;
	Primal_Dual PD(2 * N + 2);
	int S = 2 * N, T = S + 1;
	vector<hako> hakos(N);
	for (int i = 0; i < N; i++) {
		int x, y, z; cin >> x >> y >> z;
		hakos[i] = hako(x, y, z);
		PD.add_edge(S, i, 1, 0);
		PD.add_edge(i, T, 1, hakos[i].V);
		PD.add_edge(i + N, T, 1, 0);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) continue;
			if (hakos[i] < hakos[j]) {
				PD.add_edge(i, j + N, 1, 0);
			}
		}
	}
	res = PD.min_cost_flow(S, T, N);
	return res;
}
int main(void) {
	cin.tie(0); ios_base::sync_with_stdio(false);
	while (cin >> N, N) {
		cout << solve() << endl;
	}
	return 0;
}