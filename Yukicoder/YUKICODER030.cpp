#include <bits/stdc++.h>
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

/* -----  2018/04/09  Problem: yukicoder 030  / Link: http://yukicoder.me/problems/no/030  ----- */
/* ------問題------

太郎君はとある工場を建てようとしています。
効率よく生産するためには、材料を計画的に購入しなければなりません。
この工場では、最終的に製造したい製品を 製品番号N とし、
製品番号1 ～ N−1 の中間素材となる製品を取り扱います。

製品番号1 ～ N−1 の製品は、外部から購入するか、
またはこの工場で製造するかのどちらかにより手に入るものとします。
また、最終製品Nも含め製造することが出来る製品は、外部から購入せずに必ず製造するものとします。

入力に、各製品番号(1～N)の製造方法（材料の製品番号・個数と、その材料から1個製造できる製品番号）
が与えられるので、最終製品Nを1個作るために、外部から購入する必要のある最小の個数を
1～N−1番の 製品番号ごとにそれぞれ1行で出力してください。

製品iの製造方法が複数書かれている場合は、それらすべての材料が必要です。
製品Nを製造するための製造方法は必ず与えられます。

-----問題ここまで----- */
/* -----解説等-----

indegがゼロのとこから再帰すると、ボトムアップな計算にできるので、これはメモ化再帰でできる。

頭がついていないとグラフを反転させてdfsをしがち。

----解説ここまで---- */

LL N, M;

LL ans = 0LL;

LL dfs(int v, VL& need, vector<vector<PII>>& G) {
	if (need[v] != 0) {
		return need[v];
	}
	LL res = 0;
	FOR(i, 0, SZ(G[v])) {
		res += dfs(G[v][i].first, need, G)*G[v][i].second;
	}

	return need[v] = res;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	vector<vector<PII>> G(N), rG(N);
	FOR(i, 0, M) {
		int a, b, c; cin >> a >> b >> c;
		a--; c--;
		rG[c].push_back(PII(a, b));
		G[a].push_back(PII(c, b));
	}

	vector<LL> need(N, 0);
	need[N - 1] = 1;
	FOR(i, 0, N - 1) {
		if (SZ(rG[i])) {
			cout << 0 << endl;
		}
		else cout << dfs(i, need, G) << endl;
	}


	return 0;
}
