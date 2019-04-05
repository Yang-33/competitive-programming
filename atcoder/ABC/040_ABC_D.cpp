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

/* -----  2019/04/05  Problem: ABC 040 D / Link: http://abc040.contest.atcoder.jp/tasks/abc040_d  ----- */

struct UnionFind {
	vector<int> data;
	UnionFind(int n) { data.assign(n, -1); }
	bool unionSet(int x, int y) {
		x = root(x); y = root(y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	bool same(int x, int y) { return root(x) == root(y); }
	int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
	int size(int x) { return -data[root(x)]; }
};
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, M; cin >> N >> M;
	using tp = tuple<int, int, int, int, int>;
	// y, q, a, b, queryi
	vector<tp>querys;
	FOR(_, 0, M) {
		int a, b, y;
		cin >> a >> b >> y;
		a--, b--;
		querys.push_back(tp(y, 0, a, b, -1));
	}
	int Q; cin >> Q;
	FOR(i, 0, Q) {
		int v, y; cin >> v >> y;
		v--;
		querys.push_back(tp(y, 1, v, 0, i));
	}

	RSORT(querys);
	UnionFind uf(N);
	VL ans(Q);
	for (auto query : querys) {
		int y, q, a, b, id;
		tie(y, q, a, b, id) = query;
		if (q == 1) {
			ans[id] = uf.size(a);
		}
		else {
			uf.unionSet(a, b);
		}
	}
	for (auto it : ans) {
		cout << it << endl;
	}

	return 0;
}
