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

/* -----  2019/03/03  Problem: ABC 120 D / Link: http://abc120.contest.atcoder.jp/tasks/abc120_d  ----- */
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
	vector<LL> a(M), b(M);
	for (int i = 0; i < M; ++i) {
		cin >> a[i] >> b[i];
		a[i]--, b[i]--;
	}
	UnionFind uf(N);
	LL cnt = (N * (N - 1)) / 2;
	VL outs; {
		FORR(i, M - 1, 0 - 1) {
			outs.push_back(cnt);
			if (!uf.same(a[i], b[i])) {
				LL asz = uf.size(a[i]);
				LL bsz = uf.size(b[i]);
				cnt -= asz * bsz;
				uf.unionSet(a[i], b[i]);
			}
		}
	}

	
	reverse(ALL(outs));
	for (auto it : outs) {
		cout << it << endl;
	}

	return 0;
}
