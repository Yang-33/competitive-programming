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

/* -----  2019/08/14  Problem: AOJ 0225 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0225  ----- */


// ハミルトンパスっぽいものをつくりたい
// オイラー路っぽくするとひとつに定まる
// 結局オイラー閉路をみつければよい
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
	int N;
	while (cin >> N, N) {
		const int alpha = 26;
		VI indeg(alpha), outdeg(alpha);
		VI exi(alpha, 0);
		VVI edge(alpha, VI(alpha, 0));
		FOR(i, 0, N) {
			string s; cin >> s;
			int f = s.front() - 'a';
			int b = s.back() - 'a';
			indeg[b]++;
			outdeg[f]++;
			exi[f] = 1;
			exi[b] = 1;
			edge[f][b] = 1;
		}
		bool ok = 1;
		{ // check euler cycle
			FOR(i, 0, alpha) { // 相対次数がそれぞれ0であればオイラー閉路が存在
				ok &= indeg[i] == outdeg[i];
			}
		}

		{ // check connection
			// 全部使わないパターンを除去するために連結性を判定
			UnionFind uf(alpha);
			FOR(i, 0, alpha) {
				FOR(j, 0, alpha) {
					if (edge[i][j]) {
						uf.unionSet(i, j);
					}
				}
			}
			set<int>roots;
			FOR(i, 0, alpha) {
				if (exi[i]) {
					roots.insert(uf.root(i));
				}
			}
			if (roots.size() > 1)ok = false;
		}
		puts(ok ? "OK" : "NG");

	}

	return 0;
}
