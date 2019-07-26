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

/* -----  2019/07/26  Problem: AOJ 0188 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0188  ----- */


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
		vector<int> a(N);
		for (int i = 0; i < N; ++i) {
			cin >> a[i];
		}
		int target; cin >> target;
		auto f = FUNC([&](auto f, int L, int R) {
			if (L > R)return 0;
			int mid = (L + R) / 2;
			if (a[mid] == target)return 1;
			if (a[mid] > target) {
				return 1 + f(L, mid - 1);
			}
			else {
				return 1 + f(mid + 1, R);
			}
		});
		cout << f(0, N - 1) << "\n";
	}

	return 0;
}