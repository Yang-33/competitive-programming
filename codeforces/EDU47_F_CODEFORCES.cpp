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

/* -----  2018/07/14  Problem: edu47_f_codeforces / Link: http://codeforces.com/contest/1009/problem/F  ----- */
/* ------問題------

木Tの各頂点の情報をもってくる

-----問題ここまで----- */
/* -----解説等-----

dsu on treeとおもったけどよく分からない感じになった
下から支配していけば良い
ただし全部に反映するとO(N^2)になる。
HLっぽく考えると(これがdsu要素)heavypath上の頂点の情報から差し引きすれば求めたいkがわかる。
登るときに更新することで、上の情報はないときの部分木情報を得ることができる。

難しい…

----解説ここまで---- */


int dep[1000006];
int sz[1000006];
int heavy[1000006];

int ans[1000006];
int cmax[1000006];

map<int, int> Map[1000006];
VVI G;

void make_info(int v, int p) { // heavy edge
	sz[v] = 1;
	dep[v] = dep[p] + 1;
	for (int nx : G[v]) {
		if (nx == p)continue;
		make_info(nx, v);
		sz[v] += sz[nx];
		if (heavy[v] == 0 || sz[nx] > sz[heavy[v]]) {
			heavy[v] = nx;
		}
	}
}

void inc(int A, int val, int x) {
	int ck = Map[A][val] += x;
	if (ck > cmax[A] || (ck == cmax[A] && val < ans[A])) {
		cmax[A] = ck; ans[A] = val;
	}
}

void dfs(int v, int p, int A) {// A :logN
	if (heavy[v] != 0)dfs(heavy[v], v, A);
	inc(A, dep[v], 1);
	for (int nx : G[v]) {
		if (nx == p || nx == heavy[v])continue;
		dfs(nx, v, nx);
		for (const auto& it : Map[nx]) {
			inc(A, it.first, it.second);
		}
	}
	ans[v] = ans[A] - dep[v];
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;
	G = VVI(N + 1);
	FOR(i, 0, N - 1) {
		int a, b; cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	make_info(1, 0);
	dfs(1, 0, 1);
	FOR(i, 1, N + 1) {
		cout << ans[i] << endl;
	}

	return 0;
}
