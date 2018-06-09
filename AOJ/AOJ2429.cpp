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

/* -----  2018/05/19  Problem: AOJ 2429 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2429  ----- */
/* ------問題------

太郎君は小学生で、チラシの裏に落書きをしています。 ある時、太郎君は次のゲームを思いつきました。

n×nの格子状のマス目を書いておきます。
それぞれのマス目の初期状態は、丸印が書かれているか、書かれていないかのどちらか一方です。
これらの丸印を消したり書いたりして最終的にどの一列を見ても必ずちょうど1つのみの丸印が、どの一行を見ても必ず1つのみの丸印が存在するようにすることが目標であり、この状態にすればゲームをクリアしたことになります。
太郎君はこのゲームを思いつきましたが、太郎君はこのゲームをクリアするのに大変時間がかかってしまいます。そこで、大学生であるあなたに助けを求めました。 太郎君の兄であり大学生であるあなたの仕事は以下の通りです。
厳密な状況を考えるために、あるマス目に丸印を書き込むコスト、あるマス目にある丸印を消すコストをあなたは導き出しました。このコストを用いてこのゲームをクリアするためにかかる操作のコストを最小化するような手順を考える。 このとき、最小のコストおよびそのコストを達成するような手順を出力するプログラムを書いてください。 出力については、最小コストを達成する手順なら、どのような操作、順番でも出力してもよいものとする。

-----問題ここまで----- */
/* -----解説等-----

割当問題。
ある頂点を選択するとき、関係する頂点は全部削除しなければならない。
これをすべての点について行ったとき、最小になるようにしたい。
これは縦横の二部グラフについて、最小費用流でできる。
復元は、選択した頂点間にはフローを流したことになるので、よくあるチェックを行えば良い。

----解説ここまで---- */


/* 最小費用流 非負 */
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

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);


	int N;	cin >> N;
	VVI wri(N, VI(N, 0));
	VVI era(N, VI(N, 0));
	VS vs(N);
	FOR(i, 0, N) {
		FOR(j, 0, N) {
			cin >> wri[i][j];
		}
	}
	FOR(i, 0, N) {
		FOR(j, 0, N) {
			cin >> era[i][j];
		}
	}
	FOR(i, 0, N) {
		cin >> vs[i];
	}

	Primal_Dual F(2*N+2);
	int S = 2 * N, T = S + 1;
	FOR(i, 0, N) {
		F.add_edge(S, i, 1, 0);
		FOR(j, 0, N) {
			int costsum = 0;
			if (vs[i][j] == '.')costsum += wri[i][j];
			FOR(k, 0, N) {
				if (k == j)continue;
				if (vs[i][k] == 'o')costsum += era[i][k];
			}
			F.add_edge(i, N + j, 1, costsum);
		}
		F.add_edge(N + i, T, 1, 0);
	}


	int ans = F.min_cost_flow(S,T,N);
	cout << ans << "\n";

	VS anspri;
	FOR(i, 0, N) {// i -> j+Nをcheckでよい
		FOR(j, 0, SZ(F.graph[i])) {
			if (F.graph[i][j].cap == 0) { // 1つのjのみ割り当てた
				int to = F.graph[i][j].to - N;
				if (to >= N)continue;
				if (vs[i][to] == '.') {
					stringstream ss;
					ss << i + 1 << " " << to + 1 << " write";
					anspri.push_back(ss.str());
				}
				FOR(k, 0, N) {
					if (k == to)continue;
					if (vs[i][k] == 'o') {
						stringstream ss;
						ss << i + 1 << " " << k + 1 << " erase";
						anspri.push_back(ss.str());
					}
				}
			}
		}


	}

	cout << SZ(anspri) << endl;
	FOR(i, 0, SZ(anspri)) {
		cout << anspri[i] << endl;
	}


	return 0;
}
