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

/* -----  2018/04/08  Problem: yukicoder 019  / Link: http://yukicoder.me/problems/no/019  ----- */
/* ------問題------

Naomiは、とあるアクションゲームをしている。

そのゲームでは、N個(1から番号がふられている）のステージがありそれぞれ難易度が設定されている。
さらに、それぞれのステージは、先に指定されたステージをクリアしていると難易度が半分になるという仕組みになっている。

選んだステージは必ずクリアできるとし、すべてのステージをクリアすると考える。
この時、任意の順番でステージを選べるとして、各ステージの難易度の合計が最小になるように、ステージを選ぶとしたとき、その難易度の合計を求めてください。

答えは小数になることもあるが、小数第一位まで求めるとして、丸め誤差などの誤差はないように求めてください。

-----問題ここまで----- */
/* -----解説等-----

依存関係が閉路をつくっているところは、最小の値を使用して、残りは半分にできる。
この依存関係は強連結成分なので、SCC->DAGとした有向グラフについて、入次数が0のものについて最小の値を使用し、
そうでないものは常に半分とすることができる。
SCCがつよい。

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

	vector<int >get_color() {
		return cmp;
	}
};


LL N;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	VVI G(N);
	VI L(N), S(N);
	SCC scc(N);
	double ans = 0;
	FOR(i, 0, N) {
		cin >> L[i] >> S[i];
		S[i] --;
		ans += 1.0*L[i] / 2;
		scc.addEdge(S[i], i);
	}
	scc.scc();
	VVI cG = scc.get_graph_DAG();
	VI color = scc.get_color();
	VI indeg(SZ(cG));
	FOR(i, 0, SZ(cG)) {
		FOR(j, 0, SZ(cG[i])) {
			indeg[cG[i][j]]++;
		}
	}
	VI noindeg;
	FOR(i, 0, SZ(cG)) {
		if (indeg[i] == 0)noindeg.push_back(i);
	}
	FOR(i, 0, SZ(noindeg)) {
		int c = noindeg[i];
		VI a;
		FOR(j, 0, N) {
			if (color[j] == c)a.push_back(L[j]);
		}
		int x = *min_element(ALL(a));
		ans += 1.0*x / 2;
	}


	cout << fixed << setprecision(1) << ans << "\n";

	return 0;
}

