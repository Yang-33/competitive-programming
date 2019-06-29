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

/* -----  2019/06/22  Problem: ABC 131 F / Link: http://abc131.contest.atcoder.jp/tasks/abc131_f  ----- */

struct UnionFind {
	vector<int> data;
	int sz;
	UnionFind(int n) { data.assign(n, -1); sz = n; }
	bool unionSet(int x, int y) {
		x = root(x); y = root(y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
			sz--;
		}
		return x != y;
	}
	bool same(int x, int y) { return root(x) == root(y); }
	int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
	int size(int x) { return -data[root(x)]; }
	int allsz() { return sz; }
};


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;
	VI x(N), y(N);
	map<int, int>xp;
	map<int, int>yp;
	UnionFind uf(N);
	FOR(i, 0, N) {
		cin >> x[i] >> y[i];
		if (xp.find(x[i]) == xp.end()) {
			xp[x[i]] = i;
		}
		else {
			uf.unionSet(i, xp[x[i]]);
		}
		if (yp.find(y[i]) == yp.end()) {
			yp[y[i]] = i;
		}
		else {
			uf.unionSet(i, yp[y[i]]);
		}
	}

	VVI comp(uf.allsz());
	map<LL, int>smap;
	map<LL, int>umap;
	int idpoint = 0;
	FOR(i, 0, N) {
		int r = uf.root(i);
		if (umap.find(r) == umap.end()) {
			umap[r] = idpoint++;
		}
	}
	FOR(i, 0, N) {
		smap[i] = umap[uf.root(i)];
	}
	FOR(i, 0, N) {
		comp[smap[i]].push_back(i);
	}
	auto solve = [&](vector<int> &a) {
		if ((int)a.size() < 3)return 0LL;
		LL ret = 0;
		set<int>xs, ys;
		FOR(i, 0, (int)a.size()) {
			xs.insert(x[a[i]]);
			ys.insert(y[a[i]]);
		}
		ret = (LL)xs.size() *(LL)ys.size() - (int)a.size();
		return ret;
	};
	long long ans = 0;
	for (auto it : comp) {
		ans += solve(it);
	}
	cout << ans << endl;

	return 0;
}
