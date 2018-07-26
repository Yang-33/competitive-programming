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

/* -----  2018/07/26  Problem: edu002_E / Link: http://codeforces.com/contest/600/problem/E  ----- */
/* ------問題------

部分木に含まれる最大の色の個数について、その色の和を全ての頂点に対して求めよ。

-----問題ここまで----- */
/* -----解説等-----

dsu on treeがしたい！
まずはマージテク
これでよくない?笑

セオリーどうりにやっていけばよい

dsu on treeより速いけど、なぜ

----解説ここまで---- */

VVI G;
int col[100005];
int sz[100005];
int heavy[100005];
LL ans[100005];
LL submax[100005];
map<int, int>Map[100005];

void make_info(int v = 1, int p = -1) {
	sz[v] = 1;
	for (int nx : G[v]) {
		if (nx == p)continue;
		make_info(nx, v);
		sz[v] += sz[nx];
		if (heavy[v] == 0 || sz[nx] > sz[heavy[v]]) {
			heavy[v] = nx;
		}
	}
}

// make ans
void add(int TOP, int c, int x) {
	int val = Map[TOP][c] += x;
	if (val > submax[TOP]) {
		submax[TOP] = val;
		ans[TOP] = 0;
	}
	if (submax[TOP] == val) {
		ans[TOP] += c;
	}
}

// 部分木にふくまれる色の種類について、その和
void dfs(int v, int p ,int TOP) {
	if (heavy[v] != 0) {
		dfs(heavy[v], v, TOP);
	}
	add(TOP, col[v], 1);
	for (int nx : G[v]) {
		if (nx == p || nx == heavy[v])continue;
		dfs(nx, v, nx);// light top
		for (const auto&it : Map[nx]) {
			add(TOP, it.first, it.second);
		}
	}
	ans[v] = ans[TOP];
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;
	FOR(i, 0, N)cin >> col[i+1];
	G = VVI(N+1);
	FOR(i, 0, N - 1) {
		int a, b; cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	make_info();

	dfs(1, -1,1);

	FOR(i, 1, N + 1)cout << ans[i] << " \n"[i == N];

	return 0;
}
