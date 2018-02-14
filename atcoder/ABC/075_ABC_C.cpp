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

/* -----  2018/02/14  Problem: 075_abc_c / Link: https://abc075.contest.atcoder.jp/tasks/abc075_c?lang=en  ----- */
/* ------問題------

無向グラフが与えられる。橋の数は。

-----問題ここまで----- */
/* -----解説等-----

ライブラリに投げればいいね

----解説ここまで---- */

void Lowlink(int v, int p, int &k, vector<int>& low, vector<int>& ord, vector<int>& used, vector<int>& parent, vector<vector<int>>& G) {
	used[v] = true;
	low[v] = ord[v] = k; k++;
	for (int i = 0; i < (int)G[v].size(); i++) {
		int u = G[v][i];
		if (used[u] == 0) {
			parent[u] = v;
			Lowlink(u, v, k, low, ord, used, parent, G);
			low[v] = min(low[v], low[u]);
		}
		else if (u != p) {
			low[v] = min(low[v], ord[u]);
		}
	}
}

void Art_Points(int root, vector<int>& points, vector<pair<int, int>>& bridges, vector<vector<int>>& G) {
	int n = (int)G.size();
	vector<int>low(n);
	vector<int>ord(n);
	vector<int>used(n, 0);
	vector<int>parent(n, 0);
	int k = 0;

	Lowlink(root, -1, k, low, ord, used, parent, G);
	const int BRIDGE = 1; 
	if (BRIDGE) {
		for (int v = 0; v < n; v++) {
			for (int i = 0; i < (int)G[v].size(); i++) {
				int u = G[v][i];
				if (ord[v] < low[u]) {
					if (u > v)
						bridges.push_back(pair<int, int>(v, u));
					else bridges.push_back(pair<int, int>(u, v));//
				}
			}
		}
		sort(bridges.begin(), bridges.end());
		bridges.erase(unique(bridges.begin(), bridges.end()), bridges.end());
	}
}
LL N, M;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	VVI G(N);
	FOR(i, 0, M) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	VI point;
	vector<PII> bei;
	Art_Points(0, point, bei, G);

	ans = SZ(bei);
	cout << ans << "\n";

	return 0;
}
