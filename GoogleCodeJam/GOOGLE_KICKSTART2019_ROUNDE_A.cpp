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

/* -----  2019/08/25  Problem: GOOGLE_KICKSTART2019_ROUNDE A / Link: https://codingcompetitions.withgoogle.com/kickstart  ----- */

// Cherries Mesh (9pts, 13pts)
struct UnionFind {
	vector<int> data;
	int nn;
	UnionFind(int n) { data.assign(n, -1); nn = n; }
	bool unionSet(int x, int y) {
		x = root(x); y = root(y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
			nn--;
		}
		return x != y;
	}
	bool same(int x, int y) { return root(x) == root(y); }
	int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
	int size(int x) { return -data[root(x)]; }
};
// クラスカルして終わり
void solve(int testcasenum) {
	int N, M; cin >> N >> M;
	int ans = 0;
	UnionFind uf(N);
	FOR(i, 0, M) {
		int a, b; cin >> a >> b;
		a--, b--;
		if (uf.same(a, b))continue;
		uf.unionSet(a, b);
		ans++;
	}
	ans += 2 * (uf.nn - 1);

	cout << "Case #" << testcasenum << ": ";
	cout << ans << "\n";
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int T; cin >> T;
	FOR(t, 0, T) {
		solve(t + 1);
	}

	return 0;
}



/*
[1 input]:
2
2 1
1 2
3 1
2 3
[1 output]:
Case #1: 1
Case #2: 3

*/
