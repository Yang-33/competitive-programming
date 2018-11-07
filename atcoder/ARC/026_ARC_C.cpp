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

/* -----  2018/11/07  Problem: ARC 026 C / Link: http://arc026.contest.atcoder.jp/tasks/arc026_c  ----- */
/* ------問題------

ある小学校には、すごく長い廊下があります。東西に伸びていて、西端から東端まで L メートルあります。 学校の方針で窓は一切ついていないので、蛍光灯で廊下を照らさなければいけません。
この廊下には N 個の蛍光灯がついています。 i 番目の蛍光灯は西端から li メートルの地点と ri メートルの地点の間を照らすことができます。 また、蛍光灯によって点けるのに必要な費用が違います。 i 番目の蛍光灯を点けるには ci 円の費用がかかります。
全ての蛍光灯を点ければ、廊下全体を照らすことは可能ですが、お金がないので可能な限り少ない費用で廊下全体を照らしたいです。 廊下のどの地点、つまり西端から 0 メートルの地点と L メートルの地点の間のどの地点も少なくとも1つ以上の蛍光灯に照らされているように蛍光灯を点けるとき、必要な費用の最小値を求めてください。

-----問題ここまで----- */
/* -----解説等-----

流量1の最小費用流問題として見れる。
区間被覆をして、戻れることにコストを掛けないようにすればよい。
dpでもできる。これは範囲セグ木で適当に左から最小値+addの演算でやれば良い。

----解説ここまで---- */

VL Dijkstra(vector<vector<PLL>>& G, int s) {
	VL dist(SZ(G), LINF);
	dist[s] = 0;
	priority_queue<PLL, vector<PLL>, greater<PLL>> que;
	que.push(PLL(0LL, s));

	while (!que.empty()) {
		PLL p = que.top(); que.pop();
		int v; long long d;
		tie(d, v) = p;

		if (d > dist[v]) continue;

		FOR(i, 0, (int)G[v].size()) {
			int nv = G[v][i].first;
			if (dist[nv] > dist[v] + G[v][i].second) {
				dist[nv] = dist[v] + G[v][i].second;
				que.push(PLL(dist[nv], nv));
			}
		}
	}
	return dist;
}

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; cin >> N;
	LL L; cin >> L;
	vector<vector<PLL>>G(L + 1);
	FOR(i, 0, N) {
		int l, r, c; cin >> l >> r >> c;
		G[l].push_back(PLL(r, c));
	}
	FOR(i, 0, L) { // rev
		G[i + 1].push_back(PLL(i, 0));
	}
	VL dist = Dijkstra(G, 0);
	ans = dist.back();

	cout << ans << "\n";

	return 0;
}