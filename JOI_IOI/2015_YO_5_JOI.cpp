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

/* -----  2017/06/08  Problem: JOI予選2015 5 / Link:  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0623 ----- */
/* ------問題------

Zombie Island

-----問題ここまで----- */
/* -----解説等-----

ゾンビのいる場所には到達できない。
ゾンビのいる街を始点にし、この頂点からの距離がS以下の町での宿泊コストをQにすればよい。
また、ゾンビのいる街には訪れることのないように町の到達可能フラグや、町の宿泊コストを最大にしてしまえばよい。（ほんとか？）
ので、距離更新に関するダイクストラ法をゾンビについてと宿泊にかかるコストについて行えばよい。

----解説ここまで---- */

#define MAX 100010
ll N, M, K, S, P, Q;
vector<int >G[MAX];
ll cost[MAX];
ll dist[MAX];
bool f[MAX];
ll ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> M >> K >> S;
	cin >> P >> Q;
	FOR(i, 2, N) {
		cost[i] = P;
	}
	FOR(i, 0, N + 1) {
		dist[i] = LINF;
	}
	priority_queue<pll, vector<pll>, greater<pll>>q;

	FOR(i, 0, K) {
		int c; cin >> c;
		dist[c] = 0;
		q.push(mp(0, c));
		G[0].push_back(c);
		cost[c] = LINF;
	}
	FOR(i, 0, M) {
		int a, b;
		cin >> a >> b;
		G[a].pb(b);
		G[b].pb(a);
	}

	while (!q.empty()) {
		ll d = q.top().first;
		ll v = q.top().second;
		q.pop();
		if (dist[v] < d)continue;
		//cout << "check: on v: " << v << endl;
		FOR(i, 0, G[v].size()) {
			ll nv = G[v][i];
			if (dist[v] + 1 <= S)
				if (dist[nv] > dist[v] + 1) {
					dist[nv] = dist[v] + 1;
					q.push(mp(dist[nv], nv));
				}
		}
	}

	FOR(i, 0, N + 1) {
		if (1 <= dist[i] && dist[i] <= S) {
			cost[i] = Q;
		}
		dist[i] = LINF;
	}

	dist[1] = 0;
	cost[N] = 0;
	q.push(mp(0, 1));
	while (!q.empty()) {
		ll d = q.top().first;
		ll v = q.top().second;
		q.pop();
		if (dist[v] < d)continue;
		FOR(i, 0, G[v].size()) {
			ll nv = G[v][i];
			if (dist[nv] > dist[v] + cost[nv]) {
				dist[nv] = dist[v] + cost[nv];
				q.push(mp(dist[nv], nv));
			}
		}
	}
	ans = dist[N];
	cout << ans << endl;

	return 0;
}