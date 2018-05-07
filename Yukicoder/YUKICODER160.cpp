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

/* -----  2018/05/05  Problem: yukicoder 160  / Link: http://yukicoder.me/problems/no/160  ----- */
/* ------問題------

太郎君の住んでいる地域には地下鉄の駅がN個あり、0からN−1までの番号が振られています。
駅と駅は路線で結ばれており、それぞれの路線について移動時間が決まっています。

急ぎの用事がある太郎君は駅Sから駅Gまでの最短経路を気にしています。
駅Sから駅Gまでの最短経路を出力するプログラムを書いてください。
ただし、そのような経路は複数考えられる場合があるので、最短経路のうち辞書順最小のものを出力してください。

ここで最短経路とは用いる路線の移動時間の和が最小となる経路のことです。乗り換えの時間などは考慮する必要はありません。経路は、出発する駅と目的の駅を含みます。
ある経路Pが経路Qよりも辞書順で小さいというのは、経路上の駅をそれぞれ(p1,p2,…,pk)と(q1,q2,…,ql)と表した時、あるjが存在して、i=1,2,…,j−1についてpi=qiかつpj<qjとなることです。

-----問題ここまで----- */
/* -----解説等-----

S-T,T-S最短路は一緒。後ろから復元はできるので、後ろから小さいものを貪欲にとっていけば良い。

----解説ここまで---- */

VI Dijkstra(vector<vector<PLL>>& G, int s, int t) {
	swap(s, t);
	VL dist(SZ(G), LINF);
	dist[s] = 0;
	priority_queue<PLL, vector<PLL>, greater<PLL>> que;
	que.push(PLL(0LL, s));

	while (!que.empty()) {
		PLL p = que.top(); que.pop();
		int v; long long d;
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
	int cur = t;
	VI path{ t };
	while (cur != s) {
		int nx_v = INF;
		FOR(i, 0, (int)G[cur].size()) {
			if (dist[cur] == dist[G[cur][i].first] + G[cur][i].second) {
				nx_v = min(nx_v, (int)G[cur][i].first);
			}
		}
		cur = nx_v; path.push_back(cur);
	}
	return path;
}


LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, M, S, T;
	cin >> N >> M >> S >> T;
	vector<vector<PLL>> G(N);
	FOR(i, 0, M) {
		int a, b, c; cin >> a >> b >> c;
		G[a].push_back(PII(b, c));
		G[b].push_back(PII(a, c));
	}
	VI path = Dijkstra(G, S, T);
	FOR(i, 0, SZ(path)) {
		cout << path[i] << " \n"[i == SZ(path) - 1];
	}
	return 0;
}
