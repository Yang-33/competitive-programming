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

/* -----  2017/07/09  Problem: AGC 017 D / Link: http://agc017.contest.atcoder.jp/tasks/agc017_d  ----- */
/* ------問題------

結局、green hackenbush.

-----問題ここまで----- */
/* -----解説等-----

green hackenbush.
根についた辺についてみればこれはNim.
根の統合を完了した際に根自体も削除可能なことから、これは辺のgrundy数+1と見れる。
それを実装する。

----解説ここまで---- */

vector<int> t_parent;
VI t_ord;
// 木における 親 巡回順 のノード番号を記録    巡回終了順
void tree_getorder(const vector<VI> &g, int root) {
	int n = g.size();
	t_parent.assign(n, -1);
	t_ord.clear();

	vector<int> stk; stk.push_back(root);
	while (!stk.empty()) {
		int i = stk.back(); stk.pop_back();
		t_ord.push_back(i);
		for (int j = (int)g[i].size() - 1; j >= 0; j--) {
			int c = g[i][j];
			if (t_parent[c] == -1 && c != root)
				stk.push_back(c);
			else
				t_parent[i] = c;
		}
	}
}

int main() {
	int N;
	scanf("%d", &N);
	vector<vector<int> > g(N);
	for (int i = 0; i < N - 1; ++i) {
		int u, v;
		scanf("%d%d", &u, &v), --u, --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	tree_getorder(g, 0);
	vector<int> grundy(N);
	for (int ix = (int)t_ord.size() - 1; ix > 0; --ix) {
		int i = t_ord[ix], p = t_parent[i];
		//debug(i+1);

		grundy[p] ^= grundy[i] + 1;
	}
	bool ans = grundy[0] != 0;
	puts(ans ? "Alice" : "Bob");
	return 0;
}
