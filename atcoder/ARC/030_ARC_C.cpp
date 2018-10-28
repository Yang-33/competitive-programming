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
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/10/28  Problem: ARC 030 C / Link: http://arc030.contest.atcoder.jp/tasks/arc030_c  ----- */
/* ------問題------

n 個の頂点と m 本の辺から成る有向グラフがあります．n 個の頂点は， 1 から n の相異なる整数で番号付けされています． 各頂点には，a から z のアルファベットが 1 つ書かれています．
あなたはこのグラフを好きな頂点から開始し，各頂点を任意の順番で訪問することで，ちょうど k 個のアルファベットを回収したいです． 頂点は何度も訪問することができ，その頂点にアルファベットが存在する場合は任意の訪問タイミングで回収することが出来ますが，アルファベットは一度回収すると無くなります．必要がなければ，回収しなくても良いです．
あなたは，ただ回収するだけでは退屈であると思ったので，それらの k 個のアルファベットを回収した順番に並べたときに辞書順最小になるように回収することにしました．
そのような回収方法を行ったときの，k 個のアルファベットを，回収した順番に出力しなさい． k 個のアルファベットを回収する方法が存在しない場合は，-1 を出力しなさい．

-----問題ここまで----- */
/* -----解説等-----

明らかにSCC+DPをする。
実装がメインっぽそう計算量は3乗だろうか…

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
	VI gc() { return cmp; }
};

const string SINF = "~";

string dfs(int v, int leftK, const VVI&G, const vector<string>&vs, vector<vector<string>>&dp) {
	if (dp[v][leftK].size() != 0) {
		return dp[v][leftK];
	}
	if (leftK == 0)return "";
	string ret = SINF;
	string subv="";

	int vsz = (int)vs[v].size();
	if (leftK <= vsz)ret = vs[v].substr(0, leftK);
	vsz = min(vsz, leftK);
	FOR(i, 0, vsz + 1) {
		string subret = SINF;
		for (int nx : G[v]) {
			subret = min(subret, dfs(nx, leftK - i, G, vs, dp));
		}
		if (subret == SINF)continue;
		subv = vs[v].substr(0, i);
		ret = min(ret, subv + subret);
	}

	return dp[v][leftK] = ret;
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, M, K; cin >> N >> M >> K;
	vector<char>c(N);
	FOR(i, 0, N) {
		cin >> c[i];
	}
	SCC Scc(N);
	FOR(i, 0, M) {
		int a, b; cin >> a >> b;
		a--, b--;
		Scc.addEdge(a, b);
	}
	const int nN = Scc.scc();
	const VI cmp = Scc.gc();
	const VVI nG = Scc.get_graph_DAG();
	VS nvs(nN);
	FOR(i, 0, N) {
		nvs[cmp[i]] += string(1, c[i]);
	}
	FOR(i, 0, nN) {
		SORT(nvs[i]);
	}

	vector<vector<string>>dp(nN, vector<string>(K + 1));
	string ans = SINF;
	FOR(i, 0, nN) {
		ans = min(ans, dfs(i, K, nG, nvs, dp));
	}

	if (ans == SINF) {
		ans = "-1";
	}
	cout << ans << endl;


	return 0;
}
