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

/* -----  2018/08/25  Problem: yukicoder 241  / Link: http://yukicoder.me/problems/no/241  ----- */
/* ------問題------

N人の生徒がいるクラスがあります。生徒はS0君からSN−1君までいます。
それぞれの生徒に0からN−1までの出席番号を割り振りたいです。
しかし、それぞれの生徒には嫌いな数が1つあり出席番号にしたくありません。
どの生徒にも嫌いな数が当たらないように出席番号を割り振りなさい。

※test2.txt はコーナーケースかもしれません。ACしない場合は制約をよく読みましょう。

-----問題ここまで----- */
/* -----解説等-----

このwriterさんマッチングすきね
二部グラフのマッチングを行えば良い。あとは復元をする。ライブラリ的にはmatch[v]に番号が入っているのでinverseをとればよい。

----解説ここまで---- */

struct Bipartite_Matching {
	vector<vector<int>> graph;
	vector<int> match, alive, used;
	int timestamp;

	Bipartite_Matching(int n) {
		timestamp = 0;
		graph.resize(n);
		alive.assign(n, 1);
		used.assign(n, 0);
		match.assign(n, -1);
	}

	void add_edge(int u, int v) {
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	bool dfs(int v) {
		used[v] = timestamp;
		for (int i = 0; i < graph[v].size(); i++) {
			int u = graph[v][i], w = match[u];
			if (alive[u] == 0) continue;
			if (w == -1 || (used[w] != timestamp && dfs(w))) {
				match[v] = u;
				match[u] = v;
				return (true);
			}
		}
		return (false);
	}

	int bipartite_matching() {
		int ret = 0;
		for (int i = 0; i < graph.size(); i++) {
			if (alive[i] == 0) continue;
			if (match[i] == -1) {
				++timestamp;
				ret += dfs(i);
			}
		}
		return (ret);
	}
};

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;
	Bipartite_Matching f(N * 2);
	VI a(N);
	FOR(i, 0, N) {
		int bannum; cin >> bannum;
		FOR(j, 0, N) {
			if (j == bannum)continue;
			f.add_edge(i, N + j);
		}
	}
	int ans = f.bipartite_matching();
	if (ans == N) {
		FOR(i, 0, N) {
			cout << f.match[i]-N << endl;
		}
	}
	else {
		cout << -1 << "\n";
	}

	return 0;
}
