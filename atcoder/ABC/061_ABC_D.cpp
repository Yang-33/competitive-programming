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

/* -----  2018/02/15  Problem: 061_abc_d / Link: https://abc061.contest.atcoder.jp/tasks/abc061_d?lang=en  ----- */
/* ------問題------

N 頂点 M 辺の重み付き有向グラフがあります。 
i(1≦i≦M) 番目の辺は 頂点 ai から 頂点 bi を重み ci で結びます。 
このグラフと駒を利用して、次の1人ゲームを行います。

最初、駒を頂点 1 に置いて、プレイヤーのスコアを 0 とします。 
プレイヤーは、次の条件で駒を繰り返し移動させることができます。

頂点 ai に駒があるとき、i 番目の辺を利用して頂点 bi に移動する。移動後にプレイヤーのスコアが ci 加算される。
頂点 N に駒があるときのみ、ゲームを終了できます。 
なお、与えられる有向グラフの上で頂点 1 から頂点 N に移動できることは保障されています。

プレイヤーがゲーム終了時のスコアを出来るだけ大きくするような行動を取ったとき、ゲーム終了時のスコアはいくつになるでしょうか? 
ゲーム終了時のスコアをいくらでも大きくできる場合は inf と出力してください。

-----問題ここまで----- */
/* -----解説等-----

頂点の更新をしていく際に、何度も更新されるものは永遠に増やせることになる。
実際に何度も更新されるかを確認すれば良い。

----解説ここまで---- */


struct Edge {
	LL to, cost;
	Edge(int t, LL c = 0) : to(t), cost(c)
	{}
	bool operator>(const Edge& rhs) const {
		return cost > rhs.cost;
	}
	bool operator<(const Edge& rhs) const {
		return cost < rhs.cost;
	}

};
using Graph = vector< vector<Edge> >;


// precondition: d.size == V
// O(V*E)
// 負閉路が存在するときはfalse,そうでないときはtrue
void BellmanFord(const Graph& G, vector<LL>& d) {
	const int V = G.size();
	//for (int i = 0; i < V; ++i)
	//	d[i] = INF;
	//d[s] = 0;

	for (int lp = 0; lp <= V; ++lp) {
		for (int i = 0; i < V; ++i) {
			for (const auto& e : G[i]) {
				if ( d[e.to] < d[i] + e.cost) {
					d[e.to] = d[i] + e.cost;
				}
			}
		}
	}
}



LL N,M;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N>>M;
	Graph G(N);
	FOR(i, 0, M) {
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		G[a].push_back(Edge(b,c));
	}
	VL dist(N, -LINF);
	dist[0] = 0;
	BellmanFord(G, dist);
	VL d2 = dist;
	BellmanFord(G, d2);

	if (d2[N - 1] != dist[N - 1]) {
		cout << "inf" << endl;
	}else
	{
		ans = dist[N - 1];
		cout << ans << "\n";
	}

	return 0;
}
