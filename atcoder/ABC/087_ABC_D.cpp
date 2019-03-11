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

/* -----  2019/03/11  Problem: ABC 087 D / Link: http://abc087.contest.atcoder.jp/tasks/abc087_d  ----- */

template<typename T>
class DiffUnionFind {
	T calc(int x) {
		int r = root(x);
		return dist[x] + diff[x] - diff[r];
	}
	vector<int> par;
	vector<T>dist, diff;

public:
	DiffUnionFind(int n) {
		par.assign(n, -1);
		dist.assign(n, 0);
		diff.assign(n, 0);
	}
	int size(int x) { return -par[root(x)]; }
	bool same(int x, int y) { return root(x) == root(y); }
	int root(int x) {
		if (par[x] < 0)return x;
		int r = root(par[x]);
		dist[x] += dist[par[x]];
		return par[x] = r;
	}
	void unionSet(int x, int y, T val) {
		int rx = root(x), ry = root(y);
		val = val - (dist[y] + diff[y]) + (dist[x] + diff[x]);
		if (rx == ry)return;
		if (size(ry) < size(rx)) {
			swap(ry, rx);
			val = -val;
		}
		par[rx] += par[ry];
		par[ry] = rx;
		dist[ry] = val;

	}

	pair<bool, T>comp(int x, int y) {
		if (!same(x, y))return make_pair(false, 0);
		return make_pair(true, (calc(y) - calc(x)));
	}
};


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, Q; cin >> N >> Q;
	DiffUnionFind<LL> duf(N);
	LL ans = 1;
	FOR(_, 0, Q) {
		LL L, R, D; cin >> L >> R >> D;
		L--, R--;
		if (duf.same(L, R)) {
			ans &= duf.comp(L,R).second == D;
		}
		else {
			duf.unionSet(L, R,D);
		}
	}



	cout << (ans ? "Yes" : "No") << "\n";

	return 0;
}
