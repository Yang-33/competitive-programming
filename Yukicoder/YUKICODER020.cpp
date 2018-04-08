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

/* -----  2018/04/08  Problem: yukicoder 020  / Link: http://yukicoder.me/problems/no/020  ----- */
/* ------問題------

太郎君は砂漠を歩く行商人です。
太郎君はこれから次の街へ行こうとしています。

砂漠には移動しやすい場所とそうでない場所があり、
太郎君は長年の経験から、
その場所に行くためにどれくらいの体力を消耗するか知っています。

砂漠は際限なく続いていますが、太郎君が知っているのは N×N マスの範囲だけで、
その外側に行くと命の危険があるため絶対に行きません。
砂漠の中には、(Ox,Oy)の場所にオアシスがありこの場所へ行くと、
「1度だけ」体力を現在の値の「2倍」にすることができます。(オアシスが無い場合もあります)

いま太郎君は (1,1) の場所に立っており、次の街は (N,N) の場所にあります。
太郎君は、辺を共有する前後左右の隣接マスへのみ移動することができ、
次のマスへ移動すると、移動した先の砂漠レベル(Lxy)分の体力が減ります。
移動先の砂漠レベルが0の場合、体力値は減りませんが、
太郎君の体力が0以下になった時点で太郎君が死んでしまいます。

オアシスがある場所にも砂漠レベルが1以上ある場合もあり、
その場合は砂漠レベル分の体力が減った後に、オアシスの効果が適用されます。

太郎君が次の街へ無事たどり着けるか教えてあげてください。

オアシスが(1,1)にあることはない。

-----問題ここまで----- */
/* -----解説等-----

一回もオアシスに行かないときはただのダイクストラでよい。
一回寄るときは、そこまでのこった体力を求めることができるので、オアシスから終点までの最短距離がわかれば判定ができる。

----解説ここまで---- */

LL N;

LL ans = 0LL;

VVI dijkstra(int sy, int sx, VVI& cost) {
	int n = SZ(cost);
	using tp = tuple<int, int, int>;
	priority_queue<tp, vector<tp>, greater<tp>>pq;
	VVI dist(n, VI(n, INF));
	pq.push(tp(0, sy, sx));
	dist[sy][sx] = 0;
	while (!pq.empty()) {
		int d, y, x; tie(d, y, x) = pq.top(); pq.pop();
		if (dist[y][x] < d)continue;
		FOR(k, 0, 4) {
			int ny = y + DY[k], nx = x + DX[k];
			if (0 <= ny&& ny < n && 0 <= nx && nx < n) {
				if (dist[ny][nx] > dist[y][x] + cost[ny][nx]) {
					dist[ny][nx] = dist[y][x] + cost[ny][nx];
					pq.push(tp(dist[ny][nx], ny, nx));
				}
			}
		}
	}
	return dist;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int V, oy, ox;
	cin >> N>>V>>ox>>oy;
	oy--, ox--;
	VVI cost(N, VI(N));
	FOR(i, 0, N) {
		FOR(j, 0, N) {
			cin >> cost[i][j];
		}
	}
	VVI dist = dijkstra(0,0,cost);
	if (dist[N-1][N-1] < V) {
		cout << "YES" << endl;
	}
	else if (oy == -1 && dist[N-1][N-1]>=V) {
		cout << "NO" << endl;
	}
	else {
		int recover = 2 * (V - dist[oy][ox]);
		VVI ndist = dijkstra(oy, ox, cost);
		if (ndist[N-1][N-1] < recover) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}

	return 0;
}
