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

/* -----  2018/03/05  Problem: 064_arc_c / Link: https://arc064.contest.atcoder.jp/tasks/arc064_c?lang=en  ----- */
/* ------問題------

xy 平面があります。 すぬけ君は座標 (xs,ys) から座標 (xt,yt) まで移動しようとしています。 すぬけ君は好きな向きへ速さ 1 で動くことができます。 なお、すぬけ君は大きさのない点と見なすことにします。
平面上には N 個の円形のバリアが張ってあります。 i 番目のバリアは中心が (xi,yi) で半径が ri です。 バリアは互いに重なっていたり、互いを含んでいたりすることがあります。
平面上の各座標について、その座標がどのバリアの内部にも含まれない場合、その座標には宇宙線が降り注いでいます。
すぬけ君は移動中にできるだけ宇宙線を浴びたくないので、宇宙線を浴びる時間が最小になるように移動します。 すぬけ君が移動中に宇宙線を浴びる時間の最小値を求めてください。

-----問題ここまで----- */
/* -----解説等-----

移動する人の気持ちになると円から円の移動は中心から中心へ移動するのが最適なのでこれに工夫なく辺を張れば良い
なぜ600点?

----解説ここまで---- */



using Type = pair<double, int>;

vector<double> Dijkstra(vector<vector<pair<int,double>>>& G, int s) {
	vector<double> dist(SZ(G), LINF);
	dist[s] = 0;
	priority_queue<Type, vector<Type>, greater<Type>> que;
	que.push(Type(0LL, s));

	while (!que.empty()) {
		Type p = que.top(); que.pop();
		int v; /* 頂点*/ double d; /* 頂点vまでの距離 */
		tie(d, v) = p;

		if (d > dist[v]) continue;

		FOR(i, 0, (int)G[v].size()) {
			int nv = G[v][i].first;
			if (dist[nv] > dist[v] + G[v][i].second) {
				dist[nv] = dist[v] + G[v][i].second;
				que.push(Type(dist[nv], nv));
			}
		}
	}
	return dist;
}

LL N;

double ans = 0LL;
struct Circle {
	double x, y, r;
	Circle() { x = y = r = 0; }
};

double distance(Circle &a, Circle &b) {
	double d =hypot(a.x - b.x, a.y - b.y)- (a.r + b.r );
	return (d > 0 ? d : 0);
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	double sx, sy, tx, ty;
	cin >> sx >> sy >> tx >> ty >> N;
	vector < Circle > Cir(N + 2);
	FOR(i, 0, N) {
		cin >> Cir[i].x >> Cir[i].y >> Cir[i].r;
	}
	const int S = N;
	const int T = N + 1;
	Cir[S].x = sx; Cir[S].y = sy;
	Cir[T].x = tx; Cir[T].y = ty;
	N += 2;
	
	vector<vector<pair<int,double>>> G(N);
	FOR(i, 0, N) {
		FOR(j, i + 1, N) {
			double d = distance(Cir[i], Cir[j]);
			G[i].push_back(pair<int, double>(j,d));
			G[j].push_back(pair<int, double>(i,d));
		}
	}
	vector<double> dist = Dijkstra(G, S);
	ans = dist[T];
	cout << fixed<<setprecision(10)<<ans << "\n";

	return 0;
}
