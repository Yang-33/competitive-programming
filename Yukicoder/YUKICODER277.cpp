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

/* -----  2018/09/25  Problem: yukicoder 277  / Link: http://yukicoder.me/problems/no/277  ----- */
/* ------問題------

N頂点の木が一つ与えられる。
各頂点には1～Nの番号が重複なく割り当てられていて、頂点1がこの木の根である。
ある頂点iについて、根からの距離をRi、一番近い葉からの距離をLiとする。
頂点番号順にmin(Ri,Li)を出力せよ。

注) 頂点uから頂点vに移動するときに通る最小の辺の数を、頂点uから頂点vへの距離（頂点vから頂点uへの距離）とする。

-----問題ここまで----- */
/* -----解説等-----

葉からと根からの幅優先探索をして、最良の結果のみを残せば良い。

----解説ここまで---- */



int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;
	VVI G(N);
	FOR(i, 0, N-1) {
		int a, b; cin >> a >> b;
		a--, b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	auto f = [&G](queue<PII>&q, VI&dist) {
		while (!q.empty()) {
			PII a = q.front(); q.pop();
			for (int nx : G[a.first]) {
				if (dist[nx] > dist[a.first] + 1) {
					dist[nx] = dist[a.first] + 1;
					q.push(PII(nx, dist[nx]));
				}
			}
		}
	};

	VI rtDist(N, INF);
	queue<PII>rtq;
	rtDist[0] = 0;
	rtq.push(PII(0, 0));
	f(rtq, rtDist);

	VI lfDist(N, INF);
	queue<PII>lfq;
	FOR(i, 0, N) {
		if (SZ(G[i]) == 1) {
			lfDist[i] = 0;
			lfq.push(PII(i, 0));
		}
	}
	f(lfq,lfDist);

	FOR(i, 0, N) {
		cout << min(rtDist[i], lfDist[i]) << endl;
	}

	return 0;
}
