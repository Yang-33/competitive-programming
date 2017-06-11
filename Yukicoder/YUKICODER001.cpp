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

/* -----  2017/06/11  Problem: yukicoder 001 / Link: http://yukicoder.me/problems/no/1  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

拡張ダイクストラの類の問題。
次の頂点に移動する場合に同じ距離に対しても別のコストが存在する可能性がある。
このようなときは頂点をコストの種類だけ持つようにしてあげれば複数の状態の頂点をもつことができる。
これは dist[ 現在使用したコストの総和 ][ いまいる頂点 ]:= 今いる頂点で使用したコストがcであるときの最短距離(時間)
として遷移してあげればよい。
RUPC2017day3でこれに似た問題を解いた。

----解説ここまで---- */

ll N, C, V;
ll s[1500];
ll t[1500];
ll y[1500];
ll m[1500];
ll dist[310][50];
vector<pair<ll, pll>>G[50];
ll ans = LINF;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> C >> V;
	FOR(i, 0, V)cin >> s[i];
	FOR(i, 0, V)cin >> t[i];
	FOR(i, 0, V)cin >> y[i];
	FOR(i, 0, V)cin >> m[i];

	FOR(i, 0, V) {
		s[i]--; t[i]--;
		G[s[i]].push_back(mp(t[i], mp(y[i], m[i])));
	}

	FOR(i, 0, 310) {
		FOR(j, 0, 50)dist[i][j] = LINF;
	}

	priority_queue<pair<ll, pll>>q;//dist,v,c
	dist[0][0] = 0;
	q.push(mp(0, mp(0, 0)));
	while (!q.empty()) {
		pair<ll, pll>a = q.top(); q.pop();
		ll d = a.first;
		ll v = a.second.first;
		ll c = a.second.second;
		if (dist[c][v] < d)continue;
		FOR(i, 0, G[v].size()) {
			ll nv = G[v][i].first;
			ll pc = G[v][i].second.first;
			ll pd = G[v][i].second.second;
			if (c + pc > C)continue;
			if (dist[c + pc][nv] > dist[c][v] + pd) {
				dist[c + pc][nv] = dist[c][v] + pd;
				q.push(mp(dist[c + pc][nv], mp(nv, c + pc)));
			}
		}
	}

	FOR(i, 0, C + 1) {
		ans = min(ans, dist[i][N - 1]);
	}

	if (ans == LINF)ans = -1;
	cout << ans << endl;

	return 0;
}
