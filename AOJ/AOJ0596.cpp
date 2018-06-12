#include <bits/stdc++.h>
using namespace std;

using VS = vector<string>;    using LL = int;
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
const int INF = 1e9;                          const LL LINF = 1e9;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/06/12  Problem: AOJ 0596 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0596  ----- */
/* ------問題------

IOI 国は町 1 から町 N までの N 個の町からなり，町と町とは道路で結ばれている．IOI 国には K 本の道路があり，すべての道路は異なる 2 つの町を結んでいる．車は道路を双方向に自由に移動できるが，道路以外を通ってある町から別の町に行くことはできない．
IOI 国の町 1 に住む JOI 君は，町 N に住む祖母の家までタクシーで行くことにした．IOI 国にはタクシー会社 1 からタクシー会社 N までの N 個のタクシー会社がある．IOI 国のタクシー会社には次のような少々特殊な規則がある．
タクシー会社 i のタクシーには，町 i でのみ乗車できる．
タクシー会社 i のタクシーの運賃は，利用した距離によらず Ci である．
タクシー会社 i のタクシーは，乗車してから連続して最大 Ri 本の道路しか通ることができない．
たとえば R1 = 2 の場合，町 1 からタクシー会社 1 のタクシーに乗車すると，最大 2 本の道路しか通ることができないため，道路を 3 本以上通るためには途中の町でタクシーを乗り換える必要がある．
JOI 君は町以外の地点でタクシーに乗ったりタクシーから降りたりすることはできない．また，タクシー以外の移動手段を用いることもできない．JOI 君が町 N に到達するために必要な運賃の合計の最小値を求めるプログラムを作成せよ．

-----問題ここまで----- */
/* -----解説等-----

効率解法がない、うく
多重辺をはってしまった。うく

----解説ここまで---- */

int Dijkstra(const vector<vector<PLL>>& G, int s) {
	VL dist(SZ(G), INF);
	dist[s] = 0;
	priority_queue<PLL, vector<PLL>, greater<PLL>> que;
	que.push(PLL(0LL, s));

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
	return dist[SZ(G)-1];
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);


	int N, E;
	cin >> N >> E;
	vector<vector<PII>>G(N);
	VVI infoG(N);
	vector<PII>Vinfo(N);
	FOR(i, 0, N) {
		int c, r; cin >> c >> r;
		Vinfo[i] = PII(c, r);
	}
	
	FOR(i, 0, E) {
		int a, b; cin >> a >> b;
		a--, b--;
		infoG[a].push_back(b);
		infoG[b].push_back(a);
	}
	FOR(base, 0, N) {
		VI visit(N, 0);
		queue<PII>q;
		int cost = Vinfo[base].first;
		int R = Vinfo[base].second;
		q.push(PII(base, 0));// r本たどった
		while (!q.empty()) {
			int v, r;
			tie(v, r) = q.front(); q.pop();
			if (visit[v])continue;
			visit[v] = 1;
			if (base != v) {
				G[base].push_back(PII(v, cost));
			}
			if (R>r) {
				FOR(i, 0, SZ(infoG[v])) {
					int nx = infoG[v][i];
					if (visit[nx])continue;
					q.push(PII(nx, r + 1));
				}
			}
		}
	}
	LL ans =Dijkstra(G,0);

	cout << ans << "\n";

	return 0;
}
