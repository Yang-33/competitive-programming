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

/* -----  2017/10/28  Problem: ICPC2012国内予選D / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1182&lang=jp  ----- */
/* ------問題------

鉄道乗り継ぎ
東京の鉄道ネットワークは非常に複雑である． たとえば，図D-1のような路線図が含まれている．
この路線図の上で，A駅からD駅に行きたいとする． 最短距離の経路を選ぶなら，A→B→Dと行けばよいことは明らかである． 
しかし，最短距離の経路が必ず最小コストの経路になるとは限らない． 図で，A-B，B-C，C-Dが同じ鉄道会社の線で，B-Dだけ別の会社の線だったとする．
この場合，A→B→C→Dの経路の方がA→B→Dの経路より安いことがありうる． その要因の一つは，運賃が距離に比例していないことである．
距離が長いほど，単位距離当たりの運賃は安くなるように設定されていることが多い．
複数の会社の線を乗り継ぐと，それぞれの会社の運賃を単純に合計するので， 単一の会社の線だけを使った経路に比べて，距離は短くとも， 運賃は割高になってしまうことがあるのだ．

この問題では，複数の鉄道会社からなる路線図が与えられる． また，それぞれの会社の運賃表（距離から運賃を計算するルール）が与えられる．
出発地と目的地が与えられたとき，最も安い運賃の経路を求めるプログラムを書くことがあなたの仕事である．

-----問題ここまで----- */
/* -----解説等-----

GCJ2017 R1Bに出てきたのと似ている
二回ワーシャルフロイドするやつ

会社ごとに頂点ごとの最短距離を求める。dist[i][j][c]:=会社Cを用いたときの頂点(i.j)間の最小距離(なければINF
また会社ごとの距離に対するコストを求めておく。これは10000ぐらい以下になるはずなので適当にとる。(なければINF)sumcost[dist][c]
これらを用いて、全点間での最小コストの辺を張ることができる。cost[i][j]=min(cost[i][j],sumcost[(dist[i][j][c])][c])
これで下準備ができたのであとはダイクストラなりワーシャルフロイドなりをすれば、
求めたい頂点間の最小コストが求められる。

キモはコストと辺をうまくとることだと思った。
入力の説明がめんどくさい。

----解説ここまで---- */

ll N, M, C, St, Goal;
using tp = tuple<int, ll, int>;
using fp = tuple<ll, ll, int, int>;
//vector<pll>gG[105];

ll dist[105][105][25];
ll p[55];
ll q[55];
ll r[55];
ll sumcost[20050][55];
ll cost[105][105];

ll ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	while (1) {

		FOR(i, 0, 20005)FOR(j, 0, 55)sumcost[i][j] = 0;
		FOR(i, 0, 55)p[i] = r[i] = q[i] = 0;
		FOR(i, 0, 105)FOR(j, 0, 105)FOR(k, 0, 25) {
			if (i == j)dist[i][j][k] = 0;
			else	dist[i][j][k] = LINF;
		}

		cin >> N >> M >> C >> St >> Goal;
		if (N == 0 && M == 0 && C == 0 && St == 0 && Goal == 0)break;

		FOR(i, 0, M) {
			ll x, y, d, c;
			cin >> x >> y >> d >> c;
			dist[y][x][c] = dist[x][y][c] = min(dist[x][y][c], d);
		}

		FOR(i, 1, C + 1)  cin >> p[i];

		FOR(c, 1, C + 1) {
			FOR(j, 0, p[c] - 1)cin >> q[j];
			FOR(j, 0, p[c])  cin >> r[j];

			ll pos = 0;
			//累積和
			FOR(i, 1, 20000) {
				if (pos + 1 != p[c] && i > q[pos])pos++;
				sumcost[i][c] = sumcost[i - 1][c] + r[pos];
			} 
			/*
			FOR(i,0,20000){
				if(pos+1<p[c]&&i>q[pos])pos++;
				sumcost[i][c]=sumcost[i-1][c]+r[pos];
			}

			*/
		}

		FOR(c, 1, C + 1) {
			FOR(k, 1, N + 1) {
				FOR(i, 1, N + 1) {
					FOR(j, 1, N + 1) {
						dist[i][j][c] = min(dist[i][j][c], dist[i][k][c] + dist[k][j][c]);
					}
				}
			}
		}

		FOR(i, 0, 105)FOR(j, 0, 105) {
			if (i == j)cost[i][j] = 0;
			else cost[i][j] = LINF;
		}

		FOR(c, 1, C + 1) {
			FOR(i, 1, N + 1) {
				FOR(j, 1, N + 1) {
					if (dist[i][j][c] == LINF)continue;
					cost[i][j] = min(cost[i][j], sumcost[dist[i][j][c]][c]);
				}
			}
		}


		FOR(k, 1, N + 1) {
			FOR(i, 1, N + 1) {
				FOR(j, 1, N + 1) {
					cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
				}
			}
		}
		if (cost[St][Goal] == LINF)ans = -1;
		else ans = cost[St][Goal];
		cout << ans << endl;

	}

	return 0;
}
