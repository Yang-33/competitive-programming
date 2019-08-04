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

/* -----  2019/07/27  Problem: AOJ 0202 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0202  ----- */

auto make_prime(long long  N) {
	vector<long long >a;
	vector<bool> prime(N + 1);
	FOR(i, 0, N + 1) {
		prime[i] = 1;
	}prime[0] = prime[1] = 0;

	for (LL i = 2; i <= N; i++) {
		if (prime[i]) {
			a.push_back((long long)i);
			for (LL j = i * 2; j <= N; j += i)
				prime[j] = 0;
		}
	}
	return prime;
}

int main() {
	auto is_prime = make_prime(1000000);
	LL N, X;
	while (cin >> N >> X, N || X) {
		vector<LL> a(N);
		for (int i = 0; i < N; ++i) {
			cin >> a[i];
		}

		VL dp(X + 1, 0);
		dp[0] = 1;
		FOR(i, 0, N) {
			FOR(w, 0, X + 1 - a[i]) {
				dp[w + a[i]] |= dp[w];
			}
		}
		// 参加人数で割り切れない:x円のとき，xが素数
		int ok = 0;
		FOR(i, 3, X + 1) {
			if (dp[i] && is_prime[i])ok = i;
		}
		if (!ok)cout << "NA\n";
		else cout << ok << endl;

	}
	return 0;
}
