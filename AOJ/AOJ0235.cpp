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

/* -----  2019/08/17  Problem: AOJ 0235 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0235  ----- */

// 頂点+辺ver.
template<typename E>
struct TreeDiameter {
	int N;
	vector<vector<E>>G;
	vector<LL> vw;
	TreeDiameter(const vector<vector<E>>& g, const vector<LL> &a = {}) : N(int(g.size())), G(g) {
		if ((int)a.size())vw = a;
		else vw = VL(N, 0);
	}
	PLL dfs(int v, int p) {
		PLL ret = PLL(0, v);
		for (auto u : G[v]) {
			int nx = u.to;
			if (nx == p)continue;
			PLL temp = dfs(nx, v);
			LL ecost = u.cost;
			temp.first += ecost;
			ret = max(ret, temp);
		}
		ret.first += vw[v];
		return ret;
	}

	pair<LL, PLL> build(int root) {
		PLL p = dfs(root, -1);
		return pair<LL, PLL>(p.first, PLL(p.second, p.second)); // !! 
		PLL q = dfs(p.second, -1);
		// return pair<LL, PLL>(q.first, PLL(p.second, q.second));
	}
};

template<typename E>
pair<LL, PLL> getTreeDiameter(const int root, const vector<vector<E>>& G, const vector<LL>& v = {}) {
	return TreeDiameter<E>(G, v).build(root);
}// 微妙らしい


int main() {
	// 次数1を消す
	// 2*sum-残った木の直径ではなく0からの最長パス
	int N;
	while (cin >> N, N) {
		using tp = tuple<int, int, int>;
		vector<tp>edge;
		VI deg(N);
		FOR(i, 0, N - 1) {
			int a, b, c; cin >> a >> b >> c;
			a--, b--;
			deg[a]++;
			deg[b]++;
			edge.emplace_back(a, b, c);
		}
		LL sum = 0;
		struct E {
			int to, cost;
			E(int a, int b) :to(a), cost(b) {}
		};
		vector<vector<E>>G(N); {
			for (auto it : edge) {
				int a, b, c;
				tie(a, b, c) = it;
				DD(de(a, deg[a], b, deg[b]));
				if (deg[a] == 1 && a != 0) continue;
				if (deg[b] == 1 && b != 0) continue;
				G[a].emplace_back(b, c);
				G[b].emplace_back(a, c);
				sum += c;
			}
		}
		auto res = getTreeDiameter(0, G);
		DD(de(2 * sum, res.first));
		LL ans = 2 * sum - res.first;
		cout << ans << "\n";

	}

	return 0;
}
