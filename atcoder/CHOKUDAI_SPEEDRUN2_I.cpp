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

/* -----  2019/05/25  Problem: chokudai_speedrun2 I / Link: __CONTEST_URL__  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);


	LL N;
	cin >> N;
	VL a(N), b(N);
	FOR(i, 0, N) {
		cin >> a[i] >> b[i];
	}
	if (N == 1) {
		cout << 1 << endl;
		return 0;
	}
	VI idx(N);
	auto f = [](LL a, LL b) {
		return (a + b - 1) / b;
	};
	iota(ALL(idx), 0);
	sort(ALL(idx), [&](const int i, const int j) {
		return f(a[j], b[i]) < f(a[i], b[j]);
	});

	// 1,2をみればよい
	bool ok = 1;
	int z = idx.front();
	FOR(i, 1, N) {
		int zi = idx[i];
		if (f(a[zi],b[z]) >= f(a[z],b[zi]))ok = 0;
	}

	if (!ok) {
		cout << -1 << endl;
		return 0;
	}
	LL 	ans = idx.front() + 1;

	cout << (ans) << "\n";

	return 0;
}
