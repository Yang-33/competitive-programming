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

/* -----  2017/12/04  Problem: codefestival2017_team_relay D / Link: https://cf17-relay-open.contest.atcoder.jp/tasks/relay2_d  ----- */
/* ------問題------

無向グラフ G が与えられます。G は N 個の頂点と M 本の辺を持ちます。G の頂点には 1 から N までの番号が付けられており、G の i 番目の辺 (1≤i≤M) は頂点 ai と bi を結びます。G は自己辺や多重辺を持ちません。
あなたは、G の二頂点間に辺を付け足す操作を繰り返し行うことができます。ただし、その結果 G が自己辺や多重辺を持ってはなりません。また、頂点 1 と 2 が直接的または間接的に辺で結ばれてしまうと、あなたの身体を 1000000007 ボルトの電圧が襲います。これも避けなければなりません。
これらの条件のもとで、最大で何本の辺を付け足すことができるでしょうか？なお、頂点 1 と頂点 2 がはじめから直接的または間接的に辺で結ばれていることはありません。

-----問題ここまで----- */
/* -----解説等-----

10^9 + 7 ボルトを喰らいたくないので真剣に考えると、完全グラフを大きいものにマージしていけばたくさん辺を追加できる。
UFいらなかった。

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



LL N, M;

LL ans = 0LL;


void dfs(int v, int p, VI& used, VVI &G) {
	used[v] = 1;
	FOR(i, 0, SZ(G[v])) {
		if (p != G[v][i] && used[G[v][i]] == 0)
			dfs(G[v][i], v, used, G);
	}
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	UnionFind uf(N);
	LL ret = 0;
	vector<vector<int > >G(N, VI());
	FOR(i, 0, M) {
		int a, b; cin >> a >> b;
		a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
		uf.unionSet(a, b);
	}

	VI used(N, 0);
	priority_queue<PLL>q;
	VI aa(2, 0);
	FOR(i, 0, N) {
		if (used[i] == 1)continue;
		LL S = uf.size(i);
		dfs(i, -1, used, G);
		ret += S*(S - 1) / 2LL;
		if (i >= 2)q.push(PII(S, i));
		else aa[i] = S;
		used[i] = 1;
	}
	int id = aa[1] > aa[0];
	q.push(PII(aa[id], id));
	while (q.size() > 1) {
		PII a = q.top(); q.pop();
		PII b = q.top();//q.pop();

		int as = a.first;
		int av = a.second;
		int bs = b.first;
		int bv = b.second;
		if ((av == 0 && bv == 1) || (av == 1 && bv == 0)) {
			q.push(a);
		}
		else {
			q.pop(); // b
			ret += as* bs;
			q.push(PII(as + bs, min(av, bv)));
		}

	}

	// つかったものは使わない

	ans = ret - M;
	cout << ans << "\n";

	return 0;
}
