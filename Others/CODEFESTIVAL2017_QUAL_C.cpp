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

/* -----  2017/10/08  Problem: codefestival2017_qual C  / Link: http://code-festival-2017-qualb.contest.atcoder.jp/tasks/code_festival_2017_qualb_c  ----- */
/* ------問題------

グラフGがある。辺を3本たどって到達できる場所に辺を追加する。
何本追加できるか。

-----問題ここまで----- */
/* -----解説等-----

辺を追加してもグラフの二部グラフの関係は変わらない。
二部グラフだね(さすがにア)
二部グラフではないときは完全グラフになるまで辺を追加できる。

----解説ここまで---- */

const int N = 100100;
int n;
vector<int> g[N];
int col[N];

bool dfs(int v) {
	for (int u : g[v]) {
		if (col[u] != -1) {
			if (col[v] == col[u]) return false;
		}
		else {
			col[u] = col[v] ^ 1;
			if (!dfs(u)) return false;
		}
	}
	return true;
}

int main()
{

	int m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int v, u;
		cin >> v >> u;
		v--; u--;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	for (int i = 0; i < n; i++)
		col[i] = -1;
	col[0] = 0;
	ll ans = 0;
	if (!dfs(0))
		ans = (ll)n * (n - 1) / 2;
	else {
		ans = 0;
		for (int i = 0; i < n; i++)
			ans += col[i];
		ans *= n - ans;
	}
	ans -= m;
	cout << ans << "\n";
	
	return 0;
}
