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

/* -----  2018/04/30  Problem: AOJ 2306 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2306  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

関係のない辺に関してはコスト0の頂点が追加されて、現在の集合の頂点の一つが0になるので、追加しないほうが良い。
条件を満たすものに対して、M=100から、N≦15とかなので、枝刈り全探索で全然間に合う。
問題文をちゃんと読んでいないから解き損ねた。

----解説ここまで---- */

LL N;

LL ans = 0LL;



void dfs(int v, VI &vs, VVI &G) {
	if (v == N) {
		LL ret = 0;
		if (SZ(vs) < 2)return;
		FOR(i, 0, SZ(vs)) {
			int u = vs[i];
			int t = INF;
			FOR(j, 0, SZ(vs)) {
				int n = vs[j];
				if (n != u) {
					t = min(t, G[u][n]);
				}
			}
			ret += t;
		}
		ans = max(ans, ret);
		return;
	}

	dfs(v + 1, vs,G);

	FOR(i, 0, SZ(vs)) {
		int u = vs[i];
		if (G[v][u] == 0)return;
	}
	vs.push_back(v);
	dfs(v + 1, vs, G);
	vs.pop_back();

}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int M; cin >> N >> M;
	VVI G(N, VI(N, 0));
	FOR(i, 0, M) {
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		G[a][b] = G[b][a] = c;
	}
	VI v;
	dfs(0, v, G);
	cout << ans << "\n";

	return 0;
}
