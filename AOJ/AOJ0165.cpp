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

/* -----  2019/07/23  Problem: AOJ 0165 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0165  ----- */


vector<long long > make_prime(long long  N) {
	vector<long long >a;
	vector<long long> prime(N + 1);
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

struct Cumusum {
	vector<LL>csum;
	Cumusum(vector<LL>&a) {
		csum.assign((int)a.size() + 1, 0);
		for (int i = 0; i < (int)a.size(); i++) {
			csum[i + 1] = csum[i] + a[i];
		}
	}
	LL query(int l, int r) {
		return csum[r] - csum[l];
	}
};


int main() {
	auto prime_arrays = make_prime(999983);
	Cumusum psum(prime_arrays);
	int N;
	while (cin >> N, N) {
		LL ans = 0;
		FOR(i, 0, N) {
			LL P, M; cin >> P >> M;
			ans += psum.query(max(0LL, P - M), min(999983LL, P + M) + 1) - 1;
		}
		cout << ans << "\n";
	}
}