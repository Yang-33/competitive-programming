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

/* -----  2018/06/12  Problem: AOJ 2151 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2151  ----- */
/* ------問題------

ある貧乏な国のおてんばで勇敢なお姫様が，政略結婚のため別の国に嫁ぐことになった．ところがお姫様を亡き者としようとしている悪漢が嫁ぎ先への道の途中で刺客を放っている．
お姫様を無事に相手国に送り届けるため，あなたは安全な経路を既に決定していたのだが，お姫様の今までに通ったことのない道を通ってみたいというわがままなたっての願いで別の道を通ることとなった．そこであなたは地図を見ながらお姫様が通る道を決めなおすことにした．
全ての道は，宿場同士をつなぐ街道である．便宜上，出発地点及び目的地点も宿場とする．ところが，新しい道は治安の問題を抱えていた．盗賊やお姫様を亡き者にしようとする刺客が襲いかかってくる可能性が高いのである．
そのような危険な道を通るには護衛を雇うことが望ましい．護衛は宿場で雇うことができ，道単位で姫を守らせることができる．護衛が守っている間は盗賊や刺客に襲われることはないが，距離 1 につき金 1 がかかる．そのため，護衛を雇うためには所持金よりも次の宿場までの距離が長くないことが条件となる．
いま，与えられた予算 L のもとで，姫が無事に目的地に着くまでに襲いかかってくる盗賊や刺客の人数を最小化することを考える．あなたの仕事は，その最小化された人数を求めることである．なお，宿場にいる間に襲われることはないものとする．

-----問題ここまで----- */
/* -----解説等-----

襲われる数がコストになっていて、これを適当な場所で消せる。
襲ってくる人数の最短路上で、残りの資金を区別できれば良い。

----解説ここまで---- */

using tp = tuple<int, int, int>;

VVL dijkstra(const vector<vector<tp>>& G, int L) {
	int N = SZ(G);
	VVL dist(N, VL(L + 1, LINF));

	priority_queue<tp, vector<tp>, greater<tp>>pq;
	pq.push(tp(0, 0, L));
	dist[0][L] = 0;
	while (!pq.empty()) {// d, v, l
		int d, v, l;
		tie(d, v, l) = pq.top(); pq.pop();
		if (dist[v][l] < d)continue;
		FOR(i, 0, SZ(G[v])) {
			int nv, nc, ne;
			tie(nv, nc, ne) = G[v][i];
			if (l - nc >= 0 && dist[nv][l - nc] > dist[v][l]) {
				dist[nv][l - nc] = dist[v][l];
				pq.push(tp(dist[nv][l - nc], nv, l - nc));
			}
			if (dist[nv][l] > dist[v][l] + ne) {
				dist[nv][l] = dist[v][l] + ne;
				pq.push(tp(dist[nv][l], nv, l));
			}
		}
	}
	return dist;
}

int main(void) {
	int N, M, L;
	while (cin >> N >> M >> L, N) {
		vector<vector<tp>>G(N);
		FOR(i, 0, M) {
			int a, b, c, d;
			cin >> a >> b >> c >> d;
			a--, b--;
			G[a].push_back(tp(b, c, d));
			G[b].push_back(tp(a, c, d));
		}
		VVL distvvl = dijkstra(G, L);
		LL ans = LINF;
		FOR(l, 0, L + 1) {
			ans = min(ans, distvvl[N - 1][l]);
		}

		cout << ans << endl;
	}
	return 0;
}