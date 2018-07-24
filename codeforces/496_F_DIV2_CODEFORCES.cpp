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

/* -----  2018/07/10  Problem: CodeForces496 E div2 / Link: http://codeforces.com/contest/1005/problem/E  ----- */
/* ------問題------

根0としたときに、無向グラフGで、距離の和が最小になるような辺の選択の仕方をK個出力する

-----問題ここまで----- */
/* -----解説等-----

まずBFSをする。するとその情報から最短路DAGができる。
次にHLDを思い出して、根を0としたときに根方向に辺を張る。
M*Kなので、この根方向の辺を1個きめればよい。

----解説ここまで---- */

VS ans;
int K;
void dfs(int th, string& s, const VVI& cand) {
	if (ans.size() == K)return;
	if (th == SZ(cand)) {
		ans.push_back(s);
		return;
	}
	FOR(i, 0, SZ(cand[th])) {
		int nx = cand[th][i];
		s[nx] = '1';
		dfs(th+1, s, cand);
		s[nx] = '0';
		if (ans.size() == K)return;
	}
}

int main() {

	LL N, M;
	cin >> N >> M >> K;

	VVI G(N);
	VI u(M), v(M);
	FOR(i, 0, M) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--, b--;
		u[i] = a, v[i] = b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	VI dist(N, -1);
	dist[0] = 0;
	queue<int>q;
	q.push(0);
	while (!q.empty()) {
		int nv = q.front(); q.pop();
		FOR(i, 0, SZ(G[nv])) {
			int nx = G[nv][i];
			if (dist[nx] >= 0)continue;
			dist[nx] = dist[nv] + 1;
			q.push(nx);
		}
	}

	VVI cand(N);
	FOR(i, 0, M) {
		if (dist[u[i]] == dist[v[i]])continue;
		if (dist[u[i]] < dist[v[i]])cand[v[i]].push_back(i);
		else cand[u[i]].push_back(i);
	}

	string temp(M, '0');
	dfs(1, temp, cand);

	cout << SZ(ans) << endl;
	for (auto&it : ans) {
		cout << it << endl;
	}


	return 0;
}
