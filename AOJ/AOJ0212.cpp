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

/* -----  2018/06/12  Problem: AOJ 0212 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0212  ----- */
/* ------問題------

A 君は高校の休みを利用して、高速バス(以下、「バス」 )で一人旅をする計画を立てています。まず、A 君は一番行ってみたい町を選んでそこを目的地にしました。次に出発地から目的地までバスを乗り継いでいくルートを決めなければなりません。乗り継ぎをするときは、バスを降りてから別のバスに乗り換えるので、それぞれのバスの乗車券が必要になります。
A 君は親戚のおじさんからバスの割引券を何枚かもらいました。 この券を 1 枚使うと乗車券 1 枚を半額で購入できます。例えば、図 1 の出発地5から目的地1へ行く場合には、5→4→6→2→1と5→3→1の二つの経路が考えられます。割引券が 2 枚あるとすると、交通費を最も安くするには5→4→6→2→1の経路をたどった場合、4→6と6→2の路線に割引を利用し、合計料金は 4600円となります。一方、5→3→1の経路をたどった場合、5→3と3→1の路線に割引を利用し、合計料金は 3750 円となります。
A 君は観光にお金を回したいので、交通費はできるだけ少なくしようと考えています。そこで A 君は、出発地から目的地までの最も安い交通費を求めるプログラムを作成することにしました。

-----問題ここまで----- */
/* -----解説等-----

最短路上で区別するべきなのは、割引券の使用回数。

----解説ここまで---- */

VVL Dijkstra(const vector<vector<PLL>>& G, int s, int C) {
	VVL dist(SZ(G), VL(C + 1, LINF));
	dist[s][C] = 0;
	using tp = tuple<LL, LL, LL>;
	priority_queue<tp, vector<tp>, greater<tp>> que;
	que.push(tp(0LL, s, C));

	while (!que.empty()) {
		LL d, v, c;
		tie(d, v, c) = que.top(); que.pop();
		if (d > dist[v][c]) continue;

		FOR(i, 0, (int)G[v].size()) {
			int nv = G[v][i].first;
			if (c > 0)
				if (dist[nv][c - 1] > dist[v][c] + G[v][i].second / 2) {
					dist[nv][c - 1] = dist[v][c] + G[v][i].second / 2;
					que.push(tp(dist[nv][c - 1], nv, c - 1));
				}
			if (dist[nv][c] > dist[v][c] + G[v][i].second) {
				dist[nv][c] = dist[v][c] + G[v][i].second;
				que.push(tp(dist[nv][c], nv, c));
			}
		}
	}
	return dist;
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int C, N, M, S, D;
	while (cin >> C >> N >> M >> S >> D, C) {
		S--, D--;
		vector<vector<PLL>>G(N);
		FOR(i, 0, M) {
			int a, b, c;
			cin >> a >> b >> c; a--, b--;
			G[a].push_back(PLL(b, c));
			G[b].push_back(PLL(a, c));
		}
		VVL dist = Dijkstra(G, S, C);
		LL ans = LINF;
		FOR(i, 0, C + 1) {
			ans = min(ans, dist[D][i]);
		}
		cout << ans << "\n";
	}

	return 0;
}