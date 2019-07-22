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

/* -----  2019/07/23  Problem: AOJ 0150 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0150  ----- */


vector<long long > make_prime(long long  N) {
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
	return a;
}

int main() {
	auto primes = make_prime(10000);
	vector<PLL>twin_primes; {
		FOR(i, 0, SZ(primes)) {
			FOR(j, 0, i) {
				if (primes[i] - primes[j] == 2) {
					twin_primes.emplace_back(primes[i], primes[j]);
				}
			}
		}
	}
	LL N;
	while (cin >> N, N) {
		auto it = lower_bound(ALL(twin_primes), PLL(N + 1, -1)) - twin_primes.begin();
		it--;
		PLL ans = twin_primes[it];
		cout << ans.second << " " << ans.first << "\n";
	}
}
