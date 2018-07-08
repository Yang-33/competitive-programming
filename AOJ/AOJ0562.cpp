#include <bits/stdc++.h>
using namespace std;

using VS = vector<string>;    using LL = long long;
using VI = vector<int>;       using VVI = vector<VI>;
using PII = pair<int, int>;   using PLL = pair<LL, LL>;
using VL = vector<LL>;        using VVL = vector<VL>;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
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

/* -----  2018/07/07  Problem: AOJ 0562 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0562  ----- */
/* ------問題------

JOI 国にはN 個の町があり，それらの間はM 本の双方向に通行可能な道路で結ばれている．K 個の町にはショッピングモールがあり，国民は道路を通ってそれらの町のいずれかに行き買い物をする．
家の場所によっては，買い物に行くために長い距離を移動する必要があり，それは非常に不便である．国王はこの実情を把握するため，ショッピングモールのある町までの最短距離が家の場所によってどれだけ長くなりうるのかを調べることにした．家は道路の途中に建てられることもあるので(入力例1 の説明を参照)，この調査は非常に大変である．そこで国王は，優秀なプログラマーであるあなたに，調査を行うプログラムの作成を依頼した．

-----問題ここまで----- */
/* -----解説等-----

複数始点からのダイクストラをしたい。
毎回初期化しては意味がないので、多点で行う。
辺上の最短距離は、a,b間では、(a+b)/2 + c/2ぐらいになる。
あとはceilをすれば良い。

----解説ここまで---- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, M, K;
	cin >> N >> M >> K;
	vector<vector<PLL>>G(N);
	using tp = tuple<int, int, int>;
	vector<tp>edge;
	FOR(i, 0, M) {
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		G[a].push_back(PLL(b, c));
		G[b].push_back(PLL(a, c));
		edge.push_back(tp(a, b, c));
	}

	VL dist(SZ(G), LINF);
	priority_queue<PLL, vector<PLL>, greater<PLL>> que;

	FOR(i, 0, K) {
		int sv; cin >> sv;
		sv--;
		dist[sv] = 0;
		que.push(PLL(0, sv));
	}

	while (!que.empty()) {
		PLL p = que.top(); que.pop();
		int v; /* 頂点*/ long long d; /* 頂点vまでの距離 */
		tie(d, v) = p;

		if (d > dist[v]) continue;

		FOR(i, 0, (int)G[v].size()) {
			int nv = G[v][i].first;
			if (dist[nv] > dist[v] + G[v][i].second) {
				dist[nv] = dist[v] + G[v][i].second;
				que.push(PLL(dist[nv], nv));
			}
		}
	}

	LL ans = 0;
	FOR(i, 0, M) {
		int a, b, c;
		tie(a, b, c) = edge[i];
		ans = max(ans, (dist[a] + dist[b] + c + 1) / 2);
	}
	cout << ans << endl;

	return 0;
}
