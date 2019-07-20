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

/* -----  2019/07/20  Problem: AOJ 0118 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0118  ----- */
struct UnionFind {
	vector<int> data;
	int nn;
	UnionFind(int n) :nn(n) { data.assign(n, -1); }
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
const int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };
const int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };
auto is_in = [](int a, int b, int c) { return a <= b && b < c; };
int main() {
	LL H, W;
	while (cin >> H >> W, H || W) {
		vector<string> s(H);
		for (int i = 0; i < H; ++i) {
			cin >> s[i];
		}
		UnionFind uf(H*W);
		FOR(i, 0, H) {
			FOR(j, 0, W) {
				FOR(k, 0, 4) {
					int ny = i + DY[k], nx = j + DX[k];
					if (is_in(0, ny, H) && is_in(0, nx, W)) {
						if (s[i][j] == s[ny][nx]) {
							uf.unionSet(i*W + j, ny*W + nx);
						}
					}
				}
			}
		}

		LL ans = uf.nn;
		cout << (ans) << "\n";
	}

	return 0;
}
