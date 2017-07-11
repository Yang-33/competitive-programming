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

/* -----  2017/07/12  Problem: AOJ 2672  / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2672  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

bitDP.
頂点の訪問順番が全体として(手紙->届ける場所)ときまっているのでこれを満たす場合のみ遷移させる。

----解説ここまで---- */

ll N, M, K, P;
ll ans = 0LL;
using TypeDijk = pair<ll, ll>;

#define DijkV 1003
ll d[DijkV];
vector<pll>G[DijkV];
void Dijkstra(int s, int t) {
	const int INF = INT_MAX;

	FOR(i, 0, DijkV)d[i] = LLONG_MAX / 10;//init

	d[s] = 0; // 頂点sを0で初期化
	priority_queue<TypeDijk, vector<TypeDijk>, greater<TypeDijk>> que; //優先度付きqueue 降順(距離、頂点)
	que.push(TypeDijk(0ll, s)); // push(距離,頂点)

	while (!que.empty()) {
		TypeDijk p = que.top(); que.pop(); //queueのデータ構造
		int v = p.second; // 頂点
		ll dist = p.first; // 頂点vまでの距離
		if (dist > d[v]) continue; //最適でないならば考慮しない

		FOR(i, 0, G[v].size()) { //頂点vからはi本の辺が存在
			int nv = G[v][i].first; // v->nv
			if (d[nv] > d[v] + G[v][i].second) {
				d[nv] = d[v] + G[v][i].second;
				que.push(TypeDijk(d[nv], nv)); //push(距離,頂点) 
			}
		}
	}
}
ll dp[1 << 13][13];
int t[6]; int s[6];
ll dist[13][13];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> M >> K >> P; P--;
	FOR(i, 0, M) {
		int a, b, c; cin >> a >> b >> c;
		a--; b--;
		G[a].push_back(pll(b, c));
		G[b].push_back(pll(a, c));
	}

	FOR(i, 0, K) {
		cin >> s[i] >> t[i];
		s[i]--; t[i]--;
	}

	FOR(i, 0, K) {
		Dijkstra(s[i], -1);
		FOR(j, 0, K) {
			dist[2 * i][2 * j] = d[s[j]];
			dist[2 * i][2 * j + 1] = d[t[j]];
		}
		Dijkstra(t[i], -1);
		FOR(j, 0, K) {
			dist[2 * i + 1][2 * j] = d[s[j]];
			dist[2 * i + 1][2 * j + 1] = d[t[j]];
		}
	}

	Dijkstra(P, -1);

	FOR(i, 0, 1 << 13)FOR(j, 0, 13)dp[i][j] = INF;
	FOR(i, 0, K) {
		dp[1 << (2 * i)][2 * i] = d[s[i]];
	}

	FOR(i, 0, (1 << (2 * K))) {
		FOR(j, 0, 2 * K) {
			if (dp[i][j] == INF)continue;
			FOR(k, 0, 2 * K) {
				if (i&(1 << k))continue;
				if ((k % 2 == 1) && ((i&(1 << (k - 1))) == 0))continue;
				dp[i | (1 << k)][k] = min(dp[i | (1 << k)][k], dp[i][j] + dist[j][k]);
			}
		}
	}
	ans = INF;
	FOR(i, 0, K) {
		ans = min(ans, dp[(1 << (2 * K)) - 1][2 * i + 1]);
	}
	if (ans == INF)cout << "Cannot deliver" << endl;
	else cout << ans << endl;

	return 0;
}
