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

/* -----  2019/08/14  Problem: AOJ 0222 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0222  ----- */

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
	VI ps; {
		auto primes = make_prime(10'000'000);
		int n = SZ(primes);
		VI b({ 2,6,8 });
		FOR(i, 0, n - 4 + 1) {
			int p = primes[i];
			bool f = 1;
			FOR(j, 0, 3) {
				f &= primes[i + j + 1] == p + b[j];
			}
			if (f)ps.push_back(primes[i + 3]);
		}
	}

	LL N;
	while (cin >> N, N) {
		auto it = upper_bound(ALL(ps), N) - ps.begin();
		--it;
		cout << ps[it] << "\n";
	}

	return 0;
}
