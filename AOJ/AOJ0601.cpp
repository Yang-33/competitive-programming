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

/* -----  2018/07/23  Problem: AOJ 0601 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0601  ----- */
/* ------問題------

フクロモモンガのJOI 君が住んでいる森にはユーカリの木が N 本生えており，それらの木には1 から N の番号がついている．木 i の高さは Hi メートルである．
JOI 君が相互に直接飛び移ることのできる木の組が M 組あり，各組の木の間を飛び移るためにかかる時間が定まっている．JOI 君が木の間を飛び移っている間は，地面からの高さが1 秒あたり1 メートル下がる．すなわち，JOI 君の現在の地面からの高さが h メートル，木の間を飛び移るためにかかる時間が t 秒であるとき，飛び移った後の地面からの高さは h−t メートルとなる．ただし，h−t が0 よりも小さくなる場合や行き先の木の高さよりも大きくなる場合は飛び移ることができない．
さらに，JOI 君は木の側面を上下に移動することによって，地面からの高さを0 メートルから今いる木の高さの範囲で増減させることができる．JOI 君が地面からの高さを1 メートル増加または減少させるためには1 秒の時間がかかる．
JOI 君は，木1 の高さX メートルの位置から木N の頂上(高さHN メートルの位置) に行こうとしており，そのためにかかる時間の最小値を知りたい．

-----問題ここまで----- */
/* -----解説等-----

これすき
時間と高さを意識したくなるが、遷移の条件を縛れば時間と現在の高さは同一のものとしてみなせる。
最後の時間をもってダイクストラをしたとき、Xからどれだけ降りたかが時間で、最後h[N-1]だけ登らないと行けないのでこれを計算する。
遷移は現在頂点の頂点から次に移れるかだけを見ればよい。

----解説ここまで---- */

LL Dijkstra(const vector<vector<PLL>>& G, int s, int X, const VL& h) {
	priority_queue<PLL> que;
	que.push(PLL(X, s));
	VI  visit(SZ(G), 0);
	while (!que.empty()) {
		PLL p = que.top(); que.pop();
		int v; /* 頂点*/ long long d; /* 頂点vまでの距離 */
		tie(d, v) = p;
		if (visit[v]) continue;
		visit[v] = 1;
		if (v == SZ(G) - 1)	return (X - d) + (h[SZ(G) - 1] - d);
		FOR(i, 0, (int)G[v].size()) {
			int nv = G[v][i].first;
			LL nxc = min(h[nv], d - G[v][i].second);
			if (h[v] < G[v][i].second)continue;
			que.push(PLL(nxc, nv));
		}
	}
	return -1;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, M, X;
	cin >> N >> M >> X;
	vector<vector<PLL>>G(N);
	VL h(N);
	FOR(i, 0, N) {
		cin >> h[i];
	}
	FOR(i, 0, M) {
		int a, b, t; cin >> a >> b >> t;
		a--, b--;
		G[a].push_back(PLL(b, t));
		G[b].push_back(PLL(a, t));
	}

	LL ans = Dijkstra(G, 0, X, h);
	cout << ans << "\n";

	return 0;
}
