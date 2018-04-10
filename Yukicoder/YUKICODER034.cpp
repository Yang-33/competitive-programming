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

/* -----  2018/04/10  Problem: yukicoder 034  / Link: http://yukicoder.me/problems/no/034  ----- */
/* ------問題------

太郎君は砂漠を歩く行商人です。
太郎君はこれから次の街へ行こうとしています。

砂漠には移動しやすい場所とそうでない場所があり、
太郎君は長年の経験から、
その場所に行くとどれくらいの体力を消耗するかを知っています。

砂漠は際限なく続いていますが、太郎君が知っているのは N×N マスの範囲だけで、
その外側に行くと命の危険があるため絶対に行きません。

いま太郎君は体力 V で (SX,SY) の場所に立っており、次の街は (GX,GY) の場所にあります。
太郎君は、辺を共有する前後左右の隣接マスへのみ移動することができ、
今居るマスから隣のマスへ移動するときに1回の移動とみなし、
さらに、移動した先の砂漠レベル(LXY)分の体力が減ります。
移動先の砂漠レベルが0の場合、体力値は減りませんが、
太郎君の体力が 0以下 になった時点で太郎君が死んでしまいます。
街に着いた瞬間に死んでしまってもいけません。

太郎君は、商品をできるだけ早く捌きたいので、
「太郎君が死なずに」「最も早く次の街へ着く」には、
どれくらい時間がかかるか計算してください。

-----問題ここまで----- */
/* -----解説等-----

時間を最短距離とみたグラフについて、体力の状態もさまざまなので、体力ごとに頂点を作成する。
ただし辺のコストが1なのでBFSになる。
dist(y,x,v):=体力がvで点(y,x)にいるときの最小時間として計算する。

別解としてDPの添字と目的値を変更するアレで、
dist(距離,y,x):=必要な最小体力とすると速いらしい。

----解説ここまで---- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, V; cin >> N >> V;
	int sy, sx, ty, tx; cin >> sx >> sy >> tx >> ty;
	sy--, sx--, tx--, ty--;
	VVI cost(N, VI(N));
	FOR(i, 0, N) {
		FOR(j, 0, N) {
			cin >> cost[i][j];
		}
	}
	using tp = tuple<int, int, int, int>;
	queue<tp>pq;
	vector<VVI>dist(N, VVI(N, VI(V, INF)));
	dist[sy][sx][V - 1] = 0;
	pq.push(tp(0, V - 1, sy, sx));

	while (!pq.empty()) {
		int d, v, y, x;
		tie(d, v, y, x) = pq.front(); pq.pop();
		if (dist[y][x][v] < d)continue;
		if (ty == y&&tx == x) {
			cout << d << endl;
			return 0;
		}
		FOR(k, 0, 4) {
			int ny = y + DY[k], nx = x + DX[k];
			if (0 <= ny&&ny < N && 0 <= nx&&nx < N) {
				int nv = v - cost[ny][nx];
				if (nv >= 0) {
					if (dist[ny][nx][nv] > dist[y][x][v] + 1) {
						dist[ny][nx][nv] = dist[y][x][v] + 1;
						pq.push(tp(dist[ny][nx][nv], nv, ny, nx));
					}
				}
			}
		}

	}
	//int ans = INF;
	//FOR(i, 0, V) {
	//	ans = min(ans, dist[ty][tx][i]);
	//}
	cout <<-1<< "\n";

	return 0;
}
