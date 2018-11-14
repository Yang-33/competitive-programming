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
//#pragma GCC optimize ("-O3") 
#ifdef YANG33
#include "mydebug.hpp"
#else
#define DD(x) 
#endif
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/11/12  Problem: EDU054 D / Link: __CONTEST_URL__  ----- */
/* ------問題------

K本まで使用して、0から最短路であるような頂点を構成する辺を確保したい。
そのような頂点を最大化するような辺はどれか。

-----問題ここまで----- */
/* -----解説等-----

最短路木を作成する。なるべく0に近いものは保持したいので、頂点iに到達するために使用した辺、というのを保持し、
これをdist順でK本取れば良い。

----解説ここまで---- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, M, K; cin >> N >> M >> K;
	using tp = tuple<int, int, int>;
	vector<vector<tp>>edge(N);
	FOR(i, 0, M) {
		int a, b, c; cin >> a >> b >> c;
		a--, b--;
		edge[a].push_back(tp(i, b, c));
		edge[b].push_back(tp(i, a, c));
	}

	VL dist(N, LINF);
	dist[0] = 0;
	priority_queue<PLL,vector<PLL>,greater<PLL>>pq;
	pq.push(PLL(0, 0));
	VI use(N, 0);
	while (!pq.empty()) {
		LL d, v; tie(d, v) = pq.top(); pq.pop();
		if (dist[v] != d)continue;
		for (auto it : edge[v]) {
			int id, to, cost;
			tie(id, to, cost) = it;
			if (dist[to] > dist[v] + cost) {
				dist[to] = dist[v] + cost;
				use[to] = id;
				pq.push(PLL(dist[to], to));
			}
		}
	}

	vector<PLL>candidate;
	FOR(i, 1, N) {
		candidate.push_back(PLL(dist[i], use[i]));
	}
	SORT(candidate);
	VI ans;
	FOR(i, 0, SZ(candidate)) {
		if (i == K)break;
		ans.push_back(candidate[i].second + 1);
	}
	cout << SZ(ans) << endl;
	for (int it : ans) {
		printf("%d ", it);
	}
	puts("");

	return 0;
}
