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
#define DEBUG(x) 
#endif
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/10/19  Problem: ARC 038 D / Link: http://arc038.contest.atcoder.jp/tasks/arc038_d  ----- */
/* ------問題------

N 頂点 M 辺の有向グラフがあります。このグラフの頂点 i には、整数 Xi が書かれています。ゲーム好きな兄妹がこのグラフと 1 つのチェスの駒を使ってゲームをしようとしています。

最初、駒を頂点 1 に置く。
プレイヤーは自分のターンに、以下のいずれかちょうど 1 つの操作をしなければならない。
移動 : 駒を別の頂点にちょうど 1 回移動させる。駒が頂点 i にある場合は、頂点 i から頂点 j に向かう辺があるような頂点 j にのみ移動させることができる。
終了宣言 : ゲームを終了させる。
交互にターンを繰り返し、どちらかのプレイヤーが終了宣言をするか、後手が 109 回移動をさせた直後の時点でゲームは終了となり、その時点で駒がある頂点に書かれた整数がこのゲームの スコア となる。
先手のプレイヤーがスコアを出来るだけ大きくするような行動を取り、後手のプレイヤーがスコアを出来るだけ小さくするような行動を取るとき、ゲームのスコアはいくつになるでしょうか？

-----問題ここまで----- */
/* -----解説等-----



----解説ここまで---- */

void g(const VVI &g, const VVI &rg, vector<int> &d) {
	int V = (int)g.size();
	vector<int> count(V);
	for (int i = 0; i < V; i++) {
		count[i] = (int)g[i].size();
	}
	for (int i = 0; i < V; i++) {
		if (d[i] == 1) {
			for (int nx : rg[i]) {
				count[nx]--;
			}
		}
	}
	for (int i = 0; i < V; i++) {
		if (d[i] == -1) {
			for (int nx : rg[i]) {
				if (d[nx]) continue;
				d[nx] = 1;
				for (int nxv : rg[nx]) {
					count[nxv]--;
				}
			}
		}
	}
	queue<int> q;
	for (int i = 0; i < V; i++) {
		if (count[i]) continue;
		q.push(i);
	}
	while (q.size()) {
		int p = q.front(); q.pop();
		if (d[p]) continue;
		d[p] = -1;
		for (int nx : rg[p]) {
			if (d[nx]) continue;
			d[nx] = 1;
			for (int nxv : rg[nx]) {
				count[nxv]--;
				if (!count[nxv]) {
					q.push(nxv);
				}
			}
		}
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, M; cin >> N >> M;
	VL x(N);
	FOR(i, 0, N) {
		cin >> x[i];
	}

	VVI G(2 * N), rG(2 * N);
	FOR(i, 0, M) {
		int a, b; cin >> a >> b;
		a--, b--;
		G[a].push_back(b + N);
		rG[b + N].push_back(a);
		G[a + N].push_back(b);
		rG[b].push_back(a + N);
	}
	LL L = 0, R = INF + 1;
	auto f = [&](LL X) {
		VI d(2 * N, 0);
		FOR(i, 0, N) {
			if (X <= x[i]) {
				d[i] = 1;
				d[i + N] = 0;
			}
			else {
				d[i] = 0;
				d[i + N] = 1;
			}
		}
		g(G, rG, d);
		return d[0] == 1;
	};
	while (R - L > 1) {
		LL mid = (L + R) / 2;
		if (f(mid)) {
			L = mid;
		}
		else {
			R = mid;
		}
	}
	LL ans = L;
	cout << ans << "\n";

	return 0;
}
