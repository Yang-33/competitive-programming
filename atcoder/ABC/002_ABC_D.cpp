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

/* -----  2019/04/22  Problem: ABC 002 D / Link: http://abc002.contest.atcoder.jp/tasks/abc002_d  ----- */


#define N 111
struct MaxClique { // 0-base
	typedef bitset< N > Int;
	Int linkto[N], v[N];
	int n;
	void init(int _n) {
		n = _n;
		for (int i = 0; i < n; i++) {
			linkto[i].reset();
			v[i].reset();
		}
	}
	void addEdge(int a, int b) {
		v[a][b] = v[b][a] = 1;
	}
	int popcount(const Int& val)
	{
		return val.count();
	}
	int lowbit(const Int& val)
	{
		return val._Find_first();
	}
	int ans, stk[N];
	int id[N], di[N], deg[N];
#undef N
	Int cans;
	void maxclique(int elem_num, Int candi) {
		if (elem_num > ans) {
			ans = elem_num;
			cans.reset();
			for (int i = 0; i < elem_num; i++)
				cans[id[stk[i]]] = 1;
		}
		int potential = elem_num + popcount(candi);
		if (potential <= ans) return;
		int pivot = lowbit(candi);
		Int smaller_candi = candi & (~linkto[pivot]);
		while (smaller_candi.count() && potential > ans) {
			int next = lowbit(smaller_candi);
			candi[next] = !candi[next];
			smaller_candi[next] = !smaller_candi[next];
			potential--;
			if (next == pivot || (smaller_candi & linkto[next]).count()) {
				stk[elem_num] = next;
				maxclique(elem_num + 1, candi & linkto[next]);
			}
		}
	}
	int solve() {
		for (int i = 0; i < n; i++) {
			id[i] = i;
			deg[i] = v[i].count();
		}
		sort(id, id + n, [&](int id1, int id2) {
			return deg[id1] > deg[id2]; });
		for (int i = 0; i < n; i++)
			di[id[i]] = i;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (v[i][j])
					linkto[di[i]][di[j]] = 1;
		Int cand; cand.reset();
		for (int i = 0; i < n; i++)
			cand[i] = 1;
		ans = 1;
		cans.reset(); cans[0] = 1;
		maxclique(0, cand);
		return ans;
	}
};


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, M; cin >> N >> M;
	MaxClique solver;
	solver.init(N);
	FOR(i, 0, M) {
		int a, b; cin >> a >> b;
		a--, b--;
		solver.addEdge(a, b);
	}
	int ans = solver.solve();
	cout << ans << "\n";

	return 0;
}
