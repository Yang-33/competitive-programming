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

/* -----  2019/07/15  Problem: HUPC2019day2 D / Link: __CONTEST_URL__  ----- */
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
inline int readint() { int in; scanf("%d", &in); return in; }
inline void outint(int out, bool endl = 1) { printf("%d%c", out, " \n"[endl]); }
bool limitedSubSumK(const VL&a, const VL&m, LL K) {
	VL dp(K + 1, -1);
	int N = (int)a.size();
	dp[0] = 0;
	FOR(i, 0, N) {
		FOR(j, 0, K + 1) {
			if (dp[j] >= 0) {
				dp[j] = m[i];
			}
			else if (j < a[i] || dp[j - a[i]] <= 0) {
				dp[j] = -1;
			}
			else {
				dp[j] = dp[j - a[i]] - 1;
			}
		}
	}
	return dp[K] >= 0;
}
int main() {
	int N = readint(), R = readint();
	UnionFind uf(N);
	FOR(i, 0, N) {
		int p = readint() - 1;
		uf.unionSet(i, p);
	}
	VL a, m; {
		map<int, int>M;
		FOR(i, 0, N) {
			M[uf.root(i)]++;
		}
		map<int, int>I;
		for (auto it : M) {
			I[it.second]++;
		}
		for (auto it : I) {
			a.push_back(it.first);
			m.push_back(it.second);
		}
	}
	cout << (limitedSubSumK(a, m, min(R, N - R)) ? "Yes" : "No") << "\n";

	return 0;
}
