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

/* -----  2019/03/19  Problem: ABC 065 D / Link: http://abc065.contest.atcoder.jp/tasks/abc065_d  ----- */

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

	LL N; cin >> N;
	using tp = tuple<LL, LL, LL>;
	vector<tp>xy(N);
	FOR(i, 0, N) {
		LL x, y; cin >> x >> y;
		xy[i] = tp(x, y, i);
	}
	vector<tp>edge;
	SORT(xy); {
		FOR(i, 0, N - 1) {
			LL a, ai, b, bi;
			tie(a, ignore, ai) = xy[i];
			tie(b, ignore, bi) = xy[i + 1];
			edge.push_back(tp(b - a, ai, bi));
		}
	}


	sort(ALL(xy), [](const tp& a, const tp &b) {return get<1>(a) < get<1>(b); });
	{
		FOR(i, 0, N - 1) {
			LL a, ai, b, bi;
			tie(ignore, a, ai) = xy[i];
			tie(ignore, b, bi) = xy[i + 1];
			edge.push_back(tp(b - a, ai, bi));
		}
	}
	UnionFind uf(N);
	SORT(edge);
	LL ans = 0;
	for (auto it : edge) {
		LL c, a, b;
		tie(c, a, b) = it;
		if (!uf.same(a, b)) {
			ans += c;
			uf.unionSet(a, b);
		}
	}

	cout << ans << endl;

	return 0;
}
