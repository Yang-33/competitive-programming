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

/* -----  2019/07/27  Problem: AOJ 0201 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0201  ----- */

template<typename F>
struct FixPoint : F {
	FixPoint(F&& f) noexcept :F(forward<F>(f)) {}
	template<typename... Args>
	constexpr decltype(auto) operator()(Args&&... args) const noexcept {
		return F::operator()(*this, forward<Args>(args)...);
	}
};

template<typename F>
static inline constexpr decltype(auto) FUNC(F&& f) noexcept {
	return FixPoint<F>{forward<F>(f)};
}


int main() {

	int N;
	while (cin >> N, N) {
		map<int, LL>value;
		map<string, int>sid; {
			FOR(i, 0, N) {
				string s; int v;
				cin >> s >> v;
				sid[s] = i;
				value[i] = v;
			}
		}
		int M; cin >> M;

		VVI G(N);
		FOR(i, 0, M) {
			string top; cin >> top;
			int topid = sid[top];
			int k; cin >> k;
			FOR(_, 0, k) {
				string s; cin >> s;
				int toid = sid[s];
				G[topid].emplace_back(toid);
			}
		}

		auto func = FUNC([&](auto f, int v, int p)->LL {
			LL ret = 0;
			bool upd = false;
			for (auto nx : G[v]) {
				if (nx == p)continue;
				upd = true;
				LL sub = f(nx, v);
				ret += sub;
			}

			if (upd)return ret = min(ret, value[v]);
			else return value[v];
		});
		string target; cin >> target;
		LL ans = func(sid[target], -1);
		cout << ans << "\n";
	}

	return 0;
}
