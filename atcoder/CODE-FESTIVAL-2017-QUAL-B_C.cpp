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

/* -----  2018/03/03  Problem: code-festival-2017-qual-b_c / Link: https://code-festival-2017-qualb.contest.atcoder.jp/tasks/code_festival_2017_qualb_c?lang=en  ----- */
/* ------問題------

りんごさんは N 頂点 の連結な無向グラフを持っています。 このグラフにはすでに M 本の辺があり、i 本目の辺は頂点 Ai と頂点 Bi を繋いでいます。
りんごさんは以下の操作を行うことで、辺を追加しようと思っています。
操作：頂点 u から辺をちょうど 3 本辿ることによって頂点 v に辿り着けるような u,v(u≠v) をとり、頂点 u と頂点 v の間に辺を追加する。ただし、すでに頂点 u と頂点 v の間に辺が存在する場合は辺を追加することはできない。
りんごさんが追加できる辺の本数の最大値を求めて下さい。

-----問題ここまで----- */
/* -----解説等-----

二部グラフとそうでないときを考える。
二部グラフでないときは最終的には完全グラフになるまで辺を追加することができる。
一方二部グラフのときは辺を追加しても二部グラフのままであるから、二部グラフの頂点の色の数に対応して
追加する辺の数を決めることができる。
これは先にカウントを行い、まわりの頂点の数を差し引けば良い。

----解説ここまで---- */

LL N, M;

LL ans = 0LL;
LL black = 0;
void dfs(int v, int p, VI &color, int c, VVI &G) {
	color[v] = c;
	if (c == 0)black++;
	FOR(i, 0, SZ(G[v])) {
		int nx = G[v][i];
		if (color[nx] != -1) {
			if (color[nx] == c)ans = 0;
		}
		else {
			dfs(nx, v, color, !c, G);
		}
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	VVI G(N);
	FOR(i, 0, M) {
		int a, b; cin >> a >> b;
		a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	VI color(N, -1);
	ans = 1;
	dfs(0, -1, color, 0, G);
	if (ans) { // 二部グラフ
		ans = 0;
		// O(V+E)

		int white = N -  black;
		FOR(i, 0, N) {

			int ret = 0;
			if (color[i] == 1) {// white
				ans += black - SZ(G[i]);
			}
			else {
				ans += white - (SZ(G[i]));
			}
		}
		ans /= 2;

	}
	else {// ではない
		ans = 0;
		FOR(i, 0, N) {
			ans += (N - 1) - SZ(G[i]);
		}
		ans /= 2;
	}
	cout << ans << "\n";

	return 0;
}
