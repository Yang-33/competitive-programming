#include <bits/stdc++.h>
using namespace std;

using VS = vector<string>;    using LL = long long;
using VI = vector<int>;       using VVI = vector<VI>;
using PII = pair<int, int>;   using PLL = pair<LL, LL>;

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

/* -----  2018/11/10  Problem: ARC 025 C / Link: http://arc025.contest.atcoder.jp/tasks/arc025_c  ----- */
/* ------問題------

ウサギとカメが ARC 山でレースをすることになった。
ARC 山には N 個の中継点があり、中継点には 1 から N まで番号が付けられている。また異なる 2 つの中継点間を結ぶ道が M 本ある。どの 2 つの異なる道に関しても、結んでいる 2 つの中継点同士が一致することはない。道ごとに長さが定まっている。また、ARC 山にあるどの 2 つの異なる中継点についても、いくつかの道を経由することで行き来することができる。
レースでは、中継点の中から、目的地 A、ウサギのスタート地点 B、カメのスタート地点 C を選択する。A,B,C は中継点のうち 1 つでなければならず、A,B,C は互いに異なる必要がある。レースが始まると、ウサギは毎秒 R メートル、カメは毎秒 T メートルで目的地に進む。
カメは、カメが最適な移動を行うことでウサギがどの経路を使用してもカメより後に目的地に辿り着くような A,B,C の組 (A,B,C) が全部でいくつあるのかが知りたい。

-----問題ここまで----- */
/* -----解説等-----

1点決めてダイクストラをすると、dist(rabit)/R > dist(turtle)/Tの対を数えることになる。(ただしそれぞれの点は重複しない)
これは、dist(rabit)*T/R > dist(turtle)を数えるということで、ダイクストラのリストをソートして二分探索すれば良い。
T/Rが1より大きいとdist(rabit)も数えてしまう点のみに注意すれば、あとは簡単。

----解説ここまで---- */

using VL = vector<double>;
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


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, M, R, T; cin >> N >> M >> R >> T;
	vector<vector<PLL>> G(N);
	FOR(i, 0, M) {
		int a, b, c; cin >> a >> b >> c;
		a--, b--;
		G[a].push_back(PLL(b, c));
		G[b].push_back(PLL(a, c));
	}
	// A!=B && B!=C && C!=A
	LL ans = 0;
	FOR(A, 0, N) {
		VL distlist = Dijkstra(G, A);
		LL subans = 0;
		SORT(distlist);
		// binary search
		// 1いる…??
		// 異なるという制約をどうするか。
		// 1はいらない
		// 大小の包含があるため、T/Rが1以上であれば key自身を含む。
		// 
		DD(de(A); De(distlist));
		FOR(i, 1, N) {
			double key = (distlist[i] * 1.0* T) / R;// きりあげなくてもいい?? -> double
			LL idx = lower_bound(ALL(distlist), key) - distlist.begin();
			DD(de(i, key, idx));
			// key??
			idx--;
			if (T > R)idx--;
			subans += idx;
		}


		ans += subans;
	}

	cout << ans << "\n";

	return 0;
}