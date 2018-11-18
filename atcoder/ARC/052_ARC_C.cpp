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

/* -----  2018/11/18  Problem: ARC 052 C / Link: http://arc052.contest.atcoder.jp/tasks/arc052_c  ----- */
/* ------問題------

町 0 から町 N−1 までの N 個の町があります。
これらは M 個の双方向に行き来可能な道で結ばれています。
道にはタイプ A とタイプ B の二種類の道があります。
タイプ A の道を通ると、コストが 1 かかります。
タイプ B の道を通るとき、コストが (今まで通ったタイプ B の道の本数) +1 かかります。
ただし、i (1≤i≤M) 本目の道は、町 Ai と町 Bi を結び、Ci が 0 のときはタイプ A、Ci が 1 のときはタイプ B とします。
全ての町において、町 0 からその町までの移動にかかる最小コストをそれぞれ求めてください。
ただし、町 0 から到達できない町は存在しないものとします。

-----問題ここまで----- */
/* -----解説等-----

適当に遷移を緩和して上げると良いと思った。
Bの辺をあとで評価したかったのでこれをキーにしたら2000msで通ってしまった(だめそう)

他の人の提出をみたら頂点番号をいじっていたので、マネしてqueueに入れる頂点の整列順序を変えたら、
200msになった(ええ…)
これatcoderでの知見っぽそうなので以降試してみたい
というか、judgedataを意識して作らないとこれ落とせなさそうなのでどこでも試すべきな気がする

----解説ここまで---- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, M; cin >> N >> M;
	vector<vector<PLL>>G(N);
	FOR(i, 0, M) {
		int a, b, c; cin >> c >> a >> b;
		G[a].push_back(PLL(b, c));
		G[b].push_back(PLL(a, c));
	}
	VL dist(N, LINF);
	dist[0] = 0;
	using PLLL = tuple<LL, LL, LL>;
	priority_queue<PLLL, vector<PLLL>, greater<PLLL>> que;
	que.push(PLLL(0, 0, 0));

	while (!que.empty()) {
		LL t, d, v;
		tie(t, d, v) = que.top(); que.pop();
		v = -v;
		dist[v] = min(dist[v], d);

		FOR(i, 0, (int)G[v].size()) {
			int nv = G[v][i].first;
			int cc = G[v][i].second;
			if (cc == 0) {
				LL nx = d + 1;
				if (dist[nv] > nx) {
					que.push(PLLL(t, nx, -nv));
				}
			}
			else {
				LL nx = d + t + 1;
				if (dist[nv] > nx) {
					que.push(PLLL(t + 1, nx, -nv));
				}
			}
		}
	}
	FOR(i, 0, N) {
		cout << dist[i] << endl;
	}

	return 0;
}
