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

/* -----  2019/07/24  Problem: AOJ 0182 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0182  ----- */

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
	LL N;
	while (cin >> N, N) {
		vector<LL> a(N);
		for (int i = 0; i < N; ++i) {
			cin >> a[i];
		}
		struct A {
			int N;
			VL a;
			vector<set<LL>>st;
			A(const VL&in, const int N) :a(in), N(N), st(N) {
				RSORT(a);
			}
			// 配るやつをえらぶ
			bool selectUse(int headid, LL used, LL filled) {
				if (used == (1LL << N) - 1)return true;
				FOR(i, headid, N) {
					// iよりも後のものを選んでもiを埋めることができない
					if (!(used & 1LL << i))return false;
					if ((filled & 1LL << i)
						&& (selectFill(i + 1, used, filled ^ (1LL << i),
							i, a[i])))return true;
				}
				return false;
			}
			bool selectFill(int kubaruid, LL used, LL filled, int headmemo, LL sum) {
				if (sum == 0) {
					if (used == (1LL << N) - 1)return true;
					// 0となる組み合わせに到達したら次の配るビーカーを選択
					else return selectUse(headmemo + 1, used, filled);
				}
				{
					LL ub = 0; {
						FOR(i, kubaruid, N) {
							if (!(used & 1LL << i))ub += a[i];
						}
					}
					if (sum - ub > 0)return false;
				}
				if (st[headmemo].count(filled))return false;
				st[headmemo].insert(filled);
				FOR(i, kubaruid, N) {
					if ((!(used & 1LL << i)) && sum - a[i] >= 0) {
						if (selectFill(i + 1, used | (1LL << i), filled | (1LL << i), headmemo, sum - a[i]))return true;
					}
				}
				return false;
			}
		};
		A solve(a, N);
		bool ok = solve.selectUse(0, 1 << 0, 1 << 0);
		cout << (ok ? "YES" : "NO") << "\n";
	}


	return 0;
}
