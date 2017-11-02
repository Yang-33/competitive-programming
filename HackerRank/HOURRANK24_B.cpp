#include "bits/stdc++.h"
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

/* -----  2017/11/02  Problem: hourrank24 B / Link: https://www.hackerrank.com/contests/hourrank-24/challenges/wire-removal  ----- */
/* ------問題------

根が0の木がある。
この木は未確認なただ一辺で崩壊しそうである。
その崩壊しやすさはedge(u,v)に対して根から遠い方である。
崩壊した後に残っているノードの数の期待値は？

-----問題ここまで----- */
/* -----解説等-----

木DP + 期待値をすればよい
なぜかというと、分断される辺は根からの深さによって異なるので、
深さの総和を分母とした確率で計算できる。
あとは分断後の残りのノードの数が知りたいのでこれを計算すればよい。

----解説ここまで---- */

LL N;

double ans = 0LL;
VVI G;
int wei[100005];
int cnt[100005];
int dep[100005];
int dfs(int v, int p, int d) {
	//cout << v << " " << p << endl;
	FOR(i, 0, SZ(G[v])) {
		int nx = G[v][i];
		if (nx == p)continue;
		cnt[v] += dfs(nx, v, d + 1);
	}
	dep[v] = d;
	cnt[v]++;
	return cnt[v];
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	G = VVI(N, VI());
	FOR(i, 0, N - 1) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	dfs(0, -1, 0);
	LL sum = 0;

	FOR(i, 0, N)sum += dep[i];
	FOR(i, 1, N) {
		ans += (double)dep[i] * (N - cnt[i]) / (double)sum;
	}
	cout << fixed<<setprecision(10)<<ans << "\n";

	return 0;
}
