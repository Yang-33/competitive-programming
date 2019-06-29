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

/* -----  2019/06/15  Problem: diverta2019-2 B / Link: https://atcoder.jp/contests/diverta2019-2  ----- */


struct UnionFind {
	vector<int> data;
	int allsize;
	UnionFind(int n) :allsize(n) { data.assign(n, -1); }
	bool unionSet(int x, int y) {
		x = root(x); y = root(y);
		if (x != y) {
			allsize--;
			if (data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	bool same(int x, int y) { return root(x) == root(y); }
	int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
	int size(int x) { return -data[root(x)]; }
	int allgroup() { return allsize; }
};



int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; cin >> N;
	vector<int> x(N), y(N);
	for (int i = 0; i < N; ++i) {
		cin >> x[i] >> y[i];
	}
	vector<PII>a;
	FOR(i, 0, N) {
		FOR(j, 0, N) {
			if (i == j)continue;
			if (x[i] - x[j] || y[i] - y[j]) {
				a.push_back(PII(x[i] - x[j], y[i] - y[j]));
			}
		}
	}
	int ans = N;
	for (auto it : a) {
		UnionFind uf(N);
		FOR(i, 0, N) {
			FOR(j, 0, N) {
				if (i == j)continue;
				if (x[i] - it.first == x[j] &&
					y[i] - it.second == y[j]) {
					uf.unionSet(i, j);
				}
			}
		}
		ans = min(ans, uf.allgroup());
	}
	cout << (ans) << "\n";

	return 0;
}
