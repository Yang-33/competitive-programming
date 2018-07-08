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

/* -----  2018/07/07  Problem: soundhound2018_master_qual D / Link: https://soundhound2018-summer-qual.contest.atcoder.jp/tasks/soundhound2018_summer_qual_d  ----- */
/* ------問題------

kenkoooo さんはすぬけ国での旅行の計画を立てています。 すぬけ国には n 個の都市があり、m 本の電車が走っています。 都市には 1 から n の番号がつけられていて、 i 番目の電車は都市 ui と vi の間を両方向に走っています。 どの都市からどの都市へも電車を乗り継ぐことで到達できます。
すぬけ国で使える通貨には、円とスヌークの 2 種類があります。 どの電車の運賃も円とスヌークのどちらの通貨でも支払え、 i 番目の電車の運賃は、 円で支払う場合 ai 円、 スヌークで払う場合 bi スヌークです。
両替所のある都市に行くと、1 円を 1 スヌークに両替することができます。 ただし、 両替をするときには持っている円すべてをスヌークに両替しなければなりません。 つまり、kenkoooo さんの所持金が X 円であるときに両替をすると、 kenkoooo さんの所持金は X スヌークになります。 現在、両替所は n 個の都市すべてに存在しますが、 i 番目の都市の両替所は今年から i 年後に閉鎖されてしまい、 i 年後とそれ以降は使うことができません。
kenkoooo さんは 1015 円を持って都市 s から旅に出て、 都市 t へ向かおうと思っています。 移動中、kenkoooo さんは両替所のある都市のいずれかで円をスヌークに両替しようと考えています。 ただし、都市 s または都市 t の両替所で両替をしてもよいものとします。
kenkoooo さんは移動の経路と両替をする都市を適切に選ぶことで、できるだけ多くのスヌークを持っている状態で 都市 t に辿り着きたいと考えています。 i=0,…,n−1 のそれぞれについて、i 年後に都市 s から都市 t へ移動した際に kenkoooo さんが所持しているスヌークの最大額を求めてください。 ただし、旅行中に年をまたぐことは無いとします。

-----問題ここまで----- */
/* -----解説等-----

S-i,i-Tの最短経路がわかるとき、後ろから緩和していけば良い。

----解説ここまで---- */

VL Dijkstra(const vector<vector<PLL>>& G, int s) {
	VL dist(SZ(G), LINF);
	dist[s] = 0;
	priority_queue<PLL, vector<PLL>, greater<PLL>> que;
	que.push(PLL(0LL, s));

	while (!que.empty()) {
		PLL p = que.top(); que.pop();
		int v; /* 頂点*/ long long d; /* 頂点vまでの距離 */
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

	int N, M, S, T;
	cin >> N >> M >> S >> T;
	S--, T--;
	vector<vector<PLL>> GE(N), GS(N);
	FOR(i, 0, M) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		a--, b--;
		GE[a].push_back(PLL(b, c));
		GE[b].push_back(PLL(a, c));
		GS[a].push_back(PLL(b, d));
		GS[b].push_back(PLL(a, d));
	}

	VL StoV = Dijkstra(GE, S);
	VL TtoV = Dijkstra(GS, T);
	VL ans(N, 0);
	LL mon = 1e15;
	LL ret = LINF;
	FORR(i, N - 1, 0 - 1) {// 緩和
		ret = min(ret, StoV[i] + TtoV[i]);
		ans[i] = mon - ret;
	}
	FOR(i, 0, N) {
		cout << ans[i] << endl;
	}

	return 0;
}
