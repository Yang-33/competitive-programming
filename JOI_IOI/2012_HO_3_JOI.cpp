#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define FOR(i, s, e) for (ll(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (ll(i) = (s); (i) > (e); (i)--)
#define debug(x) cout << #x << ": " << x << endl
#define mp make_pair
#define pb push_back
const ll MOD = 1000000007;
const int INF = 1e9;
const ll LINF = 1e16;
const double PI = acos(-1.0);
int dx[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2017/05/01  Problem: JOI本戦 2012 3 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0605  ----- */
/* ------問題------

屋敷の大きさ M, N および，スイッチのある K 個の部屋の位置 (X1, Y1), (X2, Y2),..., (XK, YK) が与えられる．
東西に隣り合う 2 部屋を結ぶすべての扉は閉じていて，南北に隣り合う 2 部屋を結ぶすべての扉は開いている状態から始めて，
部屋 (1, 1) の中央から部屋 (M, N) の中央まで移動するのに最短で何分かかるかを求めるプログラムを作成せよ．
ただし，部屋 (M, N) に辿り着くことができないときはそれを指摘せよ．

一部屋移動するのに1分、スイッチを押すのに1分かかるとする。

-----問題ここまで----- */
/* -----解説等-----

スイッチと移動の制約から縦あるいは横にしか移動できないことがわかるので、これは最短経路問題に帰着することができる。
したがって、拡張ダイクストラっぽく解けばよい。
辺は、頂点座標から持とうとすると、(2*10^5)^2だけのメモリが必要になってしまう。これは頂点に番号をつければ解決できる。
辺の情報は一手で到達可能な頂点との距離だけを調査すればよいので、座標をｘ、ｙで別々にソートし、これに対して辺を構築すればよい。
また、start,targetからの辺も構築しなければならない。

スイッチを押すと進行方向が変化するので、進行方向と辺の情報をもって、進路変更したかどうかを確認していけばよい。
辺の情報には、縦辺であるか横辺であるかの2値をもてばよい。また、ノードにはこの頂点に到達するときに縦か横から入ってきたかの情報を持たせれば、
この頂点からの移動が、スイッチを押す必要がるかないかを判断することに使うことができる。
node[横から来たかどうか][頂点] := ある方向からこの頂点にきたときの最短距離として解くことができ、node[0][target]とnode[1][target]の
最小値が目的の最短経路となる。

tuple便利！

----解説ここまで---- */

ll W, H, K;
typedef tuple<int, int, ll> tp;
tuple<int, int, ll> xdat[200010];
tuple<int, int, ll> ydat[200010];
vector<tp>G[200010];
ll d[2][200010];
ll ans = 0LL;

ll dijkstra(ll s, ll t) {

	FOR(i, 0, 200010)d[0][i] = d[1][i] = LLONG_MAX / 2;

	priority_queue<tp, vector<tp>, greater<tp>>q;
	d[0][s] = 0;
	q.push(tp(0, s, 0));

	while (!q.empty()) {
		ll here, dis, z;
		tie(dis, here, z) = q.top(); q.pop();
		if (dis > d[z][here])continue;

		FOR(i, 0, G[here].size()) {
			ll to, pd, zz, addc = 0;
			tie(to, pd, zz) = G[here][i];
			if (z != zz) {//スイッチで方向切り替え
				addc = 1;
			}
			if (d[zz][to] > d[z][here] + pd + addc) {
				d[zz][to] = d[z][here] + pd + addc;
				q.push(tp(d[zz][to], to, zz));
			}
		}
	}

	return min(d[0][t], d[1][t]);
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> W >> H >> K;

	bool fs = false, ft = false;
	FOR(i, 0, K) {
		int x, y; cin >> x >> y;
		x--; y--;
		if (x == 0 && y == 0)fs = true;
		else if (x == W - 1 && y == H - 1)ft = true;
		xdat[i] = make_tuple(x, y, i);
		ydat[i] = make_tuple(y, x, i);
	}
	ll Kx = K, Ky = K;
	if (fs == false)xdat[Kx] = make_tuple(0, 0, Kx), Kx++;
	if (ft == false) {
		xdat[Kx] = make_tuple(W - 1, H - 1, Kx);
		ydat[Ky] = make_tuple(H - 1, W - 1, Kx); //!
		Kx++; Ky++;
	}

	sort(xdat, xdat + Kx);
	sort(ydat, ydat + Ky);
	//FOR(i, 0, Kx) {
	//	cout << get<0>(xdat[i]) << " " << get<1>(xdat[i]) << " " << get<2>(xdat[i]) << " " << endl;
	//}
	//FOR(i, 0, Ky) {
	//	cout << get<0>(ydat[i]) << " " << get<1>(ydat[i]) << " " << get<2>(ydat[i]) << " " << endl;
	//}

	FOR(i, 0, Kx) {
		if (get<0>(xdat[i]) == get<0>(xdat[i + 1])) {
			G[get<2>(xdat[i])].push_back(make_tuple(get<2>(xdat[i + 1]), abs(get<1>(xdat[i]) - get<1>(xdat[i + 1])), 0));
			G[get<2>(xdat[i + 1])].push_back(make_tuple(get<2>(xdat[i]), abs(get<1>(xdat[i]) - get<1>(xdat[i + 1])), 0));
		}
	}

	FOR(i, 0, Ky) {
		if (get<0>(ydat[i]) == get<0>(ydat[i + 1])) {
			G[get<2>(ydat[i])].push_back(make_tuple(get<2>(ydat[i + 1]), abs(get<1>(ydat[i]) - get<1>(ydat[i + 1])), 1));
			G[get<2>(ydat[i + 1])].push_back(make_tuple(get<2>(ydat[i]), abs(get<1>(ydat[i]) - get<1>(ydat[i + 1])), 1));
		}
	}


	ans = dijkstra(get<2>(xdat[0]), get<2>(xdat[Kx - 1]));
	if (ans == LLONG_MAX / 2)ans = -1;

	cout << ans << endl;

	return 0;
}
