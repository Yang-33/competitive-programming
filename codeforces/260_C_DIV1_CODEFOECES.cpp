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

/* -----  2018/06/08  Problem: 260_C_div1_codefoeces / Link: http://codeforces.com/contest/455/problem/C?locale=en  ----- */
/* ------問題------

森が与えられる。
その後、次のクエリに答えろ。
1:merge
2:xの属す木の直径

-----問題ここまで----- */
/* -----解説等-----

まずクエリを考える。
直径は真ん中らへんでやるのがgoodなので、
UnionFindで、mergeするときにmax値も更新すれば良い。

次に最初の構築を考える。
これは普通に直径を求めれば良い。

----解説ここまで---- */

struct UnionFind {
	vector<int> data;
	vector<LL> Dia;
	UnionFind(int n) { data.assign(n, -1); Dia.assign(n, 0); }
	bool unionSet(int x, int y, int f = 0) {
		x = root(x); y = root(y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
			if (f)Dia[x] = max({ Dia[x], Dia[y], ((Dia[x] + 1) / 2) + ((Dia[y] + 1) / 2) + 1 });
		}
		return x != y;
	}
	bool same(int x, int y) { return root(x) == root(y); }
	int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
	int size(int x) { return -data[root(x)]; }
	LL getDia(int x) { return Dia[root(x)]; }
};
LL longest = 0;
LL dfs(int v, int p, VVI &G, VI &visit) {
	visit[v] = 1;
	LL Max1 = 0, Max2 = 0;
	FOR(i, 0, SZ(G[v])) {
		int nx = G[v][i];
		if (nx == p)continue;
		if (!visit[nx]) {
			LL dep = dfs(nx, v, G, visit) + 1;
			if (dep > Max1) {
				Max2 = Max1;
				Max1 = dep;
			}
			else if (dep > Max2) {
				Max2 = dep;
			}
		}
	}
	longest = max(longest, Max1 + Max2);

	return Max1;
}

void solve_CF_260_d1_C() {
	int N, M, Q; cin >> N >> M >> Q;
	// 1:x group longest path
	// 2:union

	UnionFind uf(N);
	VVI G(N);
	FOR(i, 0, M) {
		int a, b; cin >> a >> b; a--, b--;
		G[a].push_back(b);
		G[b].push_back(a);
		uf.unionSet(a, b);
	}
	VI visit(N, 0);
	FOR(i, 0, N) {
		if (!visit[i]) {
			longest = 0;
			dfs(i, -1, G, visit);
			int root = uf.root(i);
			uf.Dia[root] = longest;
		}
	}


	FOR(i, 0, Q) {
		int q; cin >> q;
		if (q == 1) {
			int x; cin >> x;
			x--;
			cout << uf.getDia(x) << endl;
		}
		else {
			int x, y; cin >> x >> y;
			x--, y--;
			uf.unionSet(x, y, 1);
		}
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	solve_CF_260_d1_C();

	return 0;
}
