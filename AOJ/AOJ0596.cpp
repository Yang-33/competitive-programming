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

/* -----  2017/06/28  Problem:  / Link:   ----- */
/* ------問題------

koji is cool

-----問題ここまで----- */
/* -----解説等-----



----解説ここまで---- */

ll N,K;
int c[5050];
int r[5050];
ll ans = 0LL;
vector<pii>G[5050];
vector<int>G2[5000];
#define DijkV 5050
int dijkd[DijkV];
bool visited[DijkV];

void Dijkstra( int s, int t) {
	FOR(i, 0, DijkV)dijkd[i] = INF;//init
	using TypeDijk = pii;
	dijkd[s] = 0; // 頂点sを0で初期化
	priority_queue<TypeDijk, vector<TypeDijk>, greater<TypeDijk>> que; //優先度付きqueue 降順(距離、頂点)
	que.push(TypeDijk(0ll, s)); // push(距離,頂点)
	
	while (!que.empty()) {
		TypeDijk p = que.top(); que.pop(); //queueのデータ構造
		int v = p.second; // 頂点
		int dist = p.first; // 頂点vまでの距離
	
		if (dist > dijkd[v]) continue; //最適でないならば考慮しない

		FOR(i, 0, G[v].size()) { //頂点vからはi本の辺が存在
			int nv = G[v][i].first;// v->nv
			if (dijkd[nv] > dijkd[v] + G[v][i].second) {
				dijkd[nv] = dijkd[v] + G[v][i].second;
				que.push(TypeDijk(dijkd[nv], nv)); //push(距離,頂点) 
			}
		}
	}
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N>>K;
	FOR(i, 0, N) {
		cin >> c[i]>>r[i];
	}
	FOR(i, 0, K) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		G2[x].pb(y);
		G2[y].pb(x);
	}

	//辺を張る
	/*FOR(i, 0, N) {
		FOR(j, 0, DijkV)visited[j] = 0;
		queue<pii>q;
		q.push(pii(i, r[i] + 1));
		while (!q.empty()) {
			pii p = q.front(); q.pop();
			int v = p.first;
			int left = p.second;
			if (left == 0)continue;
			if (visited[v] == 1)continue;
			visited[v] = 1;
			if (i != v) {
				G[i].push_back(pii(v, c[i]));
			}
			FOR(j, 0, G2[v].size()) {
				q.push(pii(G2[v][j], left - 1));
			}
		}
	}*/

	for (int i = 0; i < N; i++) {
		FOR(j, 0, DijkV)visited[j] = 0;

		queue<pii> que;
		que.push(pii(i, r[i] + 1));
		while (!que.empty()) {
			pii p = que.front(); que.pop();
			int v = p.first;
			if (p.second == 0) continue;
			if (visited[v]==1) continue;
			visited[v] = true;

			if (i != v) G[i].push_back(pii(v,c[i]));
			for (int j = 0; j < G2[v].size(); j++) {
				que.push(pii(G2[v][j], p.second - 1));
			}
		}
	}

	Dijkstra(0, 0);

	ans = dijkd[N - 1];
	cout << ans << endl;

	return 0;
}
