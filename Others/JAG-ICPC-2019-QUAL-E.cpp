#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
// (a,b)は一緒に選択できない
// というルールが存在するときに
// 最も大きくなるような選択は?
// -> independent set


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
} solver;

int main() {
	int N, M;
	while (cin >> N >> M, N || M) {
		using LL = long long;
		using VL = vector<LL>;
		using VVL = vector<VL>;
		VVL a(N, VL(M));
		FOR(i, 0, N) {
			FOR(j, 0, M) {
				cin >> a[i][j];
			}
		}
		solver.init(M);
		VVL nolink(M, VL(M, 0));
		FOR(i, 0, M) {
			FOR(j, 0, M) {
				if (i == j)continue;
				using PLL = pair<LL, LL>;
				vector<PLL> b;
				FOR(k, 0, N) {
					b.push_back(PLL(a[k][i], a[k][j]));
				}
				sort(b.begin(), b.end());
				bool no = 0;
				FOR(i, 1, N) {
					if (b[i - 1].second > b[i].second)no = 1;
				}
				if (no) {
					nolink[i][j] = 1;
				}
			}
		}

		FOR(i, 0, M) {
			FOR(j, 0, M) {
				if (i!=j && !nolink[i][j])solver.addEdge(i, j);
			}
		}

		cout << solver.solve() << endl;

	}

}