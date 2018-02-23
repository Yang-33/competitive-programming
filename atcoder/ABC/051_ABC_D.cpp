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

/* -----  2018/02/15  Problem: 051_abc_d / Link: https://abc051.contest.atcoder.jp/tasks/abc051_d  ----- */
/* ------問題------

自己ループと二重辺を含まない N 頂点 M 辺の重み付き無向連結グラフが与えられます。
i(1≦i≦M) 番目の辺は頂点 ai と頂点 bi を距離 ci で結びます。
ここで、自己ループは ai=bi(1≦i≦M) となる辺のことを表します。
また、二重辺は (ai,bi)=(aj,bj) または (ai,bi)=(bj,aj)(1≦i<j≦M) となる辺のことを表します。
連結グラフは、どの異なる 2 頂点間にも経路が存在するグラフのことを表します。
どの異なる 2 頂点間の、どの最短経路にも含まれない辺の数を求めてください。

-----問題ここまで----- */
/* -----解説等-----

全点対が求まっていれば d[i][x] + edge(x->j) == d[i][j]
でも求められることは覚えておくべき

----解説ここまで---- */

LL N,M;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N>>M;
	VVI d(N, VI(N, INF));
	vector<pair<PII, int>>edge;
	FOR(i, 0, M) {
		int a, b, c; cin >> a >> b >> c;
		a--, b--;
		d[a][b] = d[b][a] = c;
		edge.push_back(pair<PII, int>(PII(a, b), c));
	}
	FOR(i, 0, N)d[i][i] = 0;
	FOR(k, 0, N)FOR(i, 0, N)FOR(j, 0, N) {
		d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
	}

	FOR(i, 0, M) {
		int s, t, c;
		auto a = edge[i];
		s = a.first.first;
		t = a.first.second;
		c = a.second;
		int nouse = 1;
		FOR(j, 0, N) {
			FOR(k, 0, N) {
				if (d[j][k] == d[j][s] + c + d[t][k])nouse = 0;
			}
		}
		ans += nouse;

	}

	cout << ans << "\n";

	return 0;
}
