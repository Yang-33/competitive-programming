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

/* -----  2019/04/29  Problem: AOJ 2858 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/2858  ----- */

#define primeN 1000006
bool prime[primeN + 1];
VL  make_prime() {
	vector<long long>a;
	FOR(i, 0, primeN + 1) {
		prime[i] = 1;
	}prime[0] = prime[1] = 0;

	for (int i = 2; i <= primeN; i++) {
		if (prime[i]) {
			a.push_back((long long)i);
			for (int j = i * 2; j <= primeN; j += i)
				prime[j] = 0;
		}
	}
	return a;
}
#undef primeN

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	VL ps = make_prime();

	// 区間篩的なやつ
	LL L, R; cin >> L >> R;
	VVI factp(R-L+1);
	FOR(i, 0, SZ(ps)) {
		LL d = (L + ps[i] - 1) / ps[i];
		d *= ps[i];
		for (LL j = d; j <= R; j += ps[i]) {
			factp[j - L].push_back(ps[i]);
		}
	}
	int ans = 0;
	FOR(i, L, R + 1) {
		int num = i; int cnt = 0;
		FOR(j, 0, SZ(factp[i - L])) {
			LL p = factp[i-L][j];
			while (num%p == 0) {
				num /= p;
				cnt++;
			}
		}
		if (num > 1) {
			factp[i - L].push_back(i); cnt++;
		}
		if (prime[cnt])ans++;
	}
	cout << ans << endl;

	return 0;
}
