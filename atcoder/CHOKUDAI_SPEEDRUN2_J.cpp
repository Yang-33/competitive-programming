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

/* -----  2019/05/25  Problem: chokudai_speedrun2 J / Link: __CONTEST_URL__  ----- */
vector<LL> getdivisor(LL n) {
	vector<LL> res;
	for (LL i = 1; i*i <= n; i++) {
		if (n%i == 0) {
			res.push_back(i);
			if (n / i != i)res.push_back(n / i);
		}
	}
	sort(res.begin(), res.end());
	return res;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);


	LL N;
	cin >> N;
	VL a(N), b(N);
	// minを更新を2パターンやる

	FOR(i, 0, N) {
		cin >> a[i] >> b[i];
	}
	auto d1 = getdivisor(a[0]);
	auto d2 = getdivisor(b[0]);
	// 約数全探索?
	// a[0],b[0]の約数をどっちかがもつかみたいなのをする
	// 約数は1000個ぐらいなので信じると間に合う?


	auto f = [&](LL x) {
		FOR(i, 1, N) {
			if (a[i] % x == 0 || b[i] % x == 0) {
				;
			}
			else return false;
		}
		return true;
	};

	LL ans = 1;
	for (auto it : d1) {
		if (f(it))ans = max(ans, it);
	}
	for (auto it : d2) {
		if (f(it))ans = max(ans, it);

	}

	cout << (ans) << "\n";

	return 0;
}
