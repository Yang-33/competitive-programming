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
const int INF = 1e8;
const ll LINF = 1e16;
const double PI = acos(-1.0);
int dx[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2017/06/11  Problem: yukicoder034  / Link: http://yukicoder.me/problems/no/34  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

移動する分だけ体力が減少してしまう。
従って更新回数は盤面の大きさを大きく超えることはなく、上からN^2*Vで大きく抑えることができる。
また体力の減少の制約から、200*9ほどの体力があれば必ずゴールに到達できるため、状態数は10^4*10^4の10%ほどでしかなくなる。
したがってTLEは回避できる。

また最小の移動回数が知りたいので、ノードの更新は必要ない。
これは移動回数について一方通行のダイクストラ法で地点を更新していけばよく、各地点の情報は
dist[Y][X][残りの体力]:=最小移動回数として遷移していけばよい。

...c++使いこなせてない。

----解説ここまで---- */

ll N, V;
int sx, sy, tx, ty;
int masu[100][100];
int dist[100][100][10010];
ll ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> V;
	cin >> sx >> sy >> tx >> ty;
	sx--; sy--; tx--; ty--;
	FOR(i, 0, N) {
		FOR(j, 0, N)cin >> masu[i][j];
	}
	//input
	FOR(i, 0, 100)FOR(j, 0, 100)FOR(k,0,10010)dist[i][j][k] = INF;
	
	using tp = tuple<int, int, int>;
	queue<tp>q;
	q.push(tp(sy, sx, V));
	dist[sy][sx][V] = 0;
	ans = -1;
	while (!q.empty()) {
		//debug(q.size());
		int y, x, v;
		tie(y, x, v) = q.front(); q.pop();
		if (y == ty&&x == tx) {
			cout << dist[ty][tx][v] << endl;
			return 0;
		}
		FOR(i, 0, 4) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (0 <= ny&&ny < N && 0 <= nx&&nx < N) {
				int nv = v - masu[ny][nx];
				if (nv > 0 && dist[ny][nx][nv] == INF) {
					dist[ny][nx][nv] = dist[y][x][v] + 1;
					q.push(tp(ny, nx, nv));
				}
			}
		}
	}


	cout << ans << endl;

	return 0;
}
