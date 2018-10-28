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

/* -----  2018/10/28  Problem: ARC 030 B / Link: http://arc030.contest.atcoder.jp/tasks/arc030_b  ----- */
/* ------問題------

n 頂点から成るツリーグラフがあります．このグラフはちょうど n−1 本の辺からなり，連結であることが保障されています．
このような性質を持つグラフは必ず閉路を持ちません． 各頂点番号は 1 から n の相異なる整数で表され，辺のコストは全て 1 です．
このグラフのいくつかの頂点には宝石が高々 1 つあります．宝石のある頂点にいるときのみ，その宝石を回収することができます． 
あなたは，とある頂点 x から出発し，全ての宝石を回収し再び頂点 x に戻ってくるような経路のうち，最短のものを求めたいと思っています．
そのような経路の長さを求めなさい．経路の長さは，経路に含まれる辺のコストの総和で定義されます．

-----問題ここまで----- */
/* -----解説等-----

宝石を見つけたら、そこから根までのパスを1で塗りつぶせば良い。
あとはこれの総和を2倍にすれば良い。

----解説ここまで---- */

int dfs(int v, int p, const VVI&G, const VI&h) {
	int ret = 0;
	FOR(i, 0, SZ(G[v])) {
		int nx = G[v][i];
		if (nx == p)continue;
		int sub = dfs(nx, v, G, h);
		if (sub || h[nx] == 1) {
			ret += sub + 1;
		}
	}
	return ret;
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, x; cin >> N >> x; x--;
	VI h(N);
	FOR(i, 0, N) {
		cin >> h[i];
	}
	VVI G(N);
	FOR(i, 0, N-1) {
		int a, b; cin >> a >> b;
		a--, b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	int ans = 2*dfs(x, -1, G, h);

	cout << ans << "\n";

	return 0;
}
