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

/* -----  2019/08/25  Problem: GOOGLE_KICKSTART2019_ROUNDE C / Link: https://codingcompetitions.withgoogle.com/kickstart  ----- */


// Street Checkers (13pts, 29pts)
// 0 ≤ R - L ≤ 10^5.

LL sieve(LL L, LL R) {
	if (R <= L)return 0LL;
	auto factcnt = [](LL x, LL a) {
		LL cnt = 0;
		while (x%a == 0) {
			x /= a;
			cnt++;
		}
		return cnt;
	};
	auto powLL = [](LL x, LL n) {LL res = 1; while (n > 0) { if (n & 1) { res = (res*x); }x = (x*x); n >>= 1; }return res; };

	LL n = sqrt(R) + 1;
	std::vector<bool> is_prime_small(n, true);
	std::vector<bool> is_prime(R - L, true);
	vector<vector<PLL>>factset(R - L);
	vector<LL>fs(R - L);
	for (LL i = L; i < R; i++) {
		fs[i - L] = i;
	}

	for (int p = 2; (LL)p*p < R; p++) {
		if (is_prime_small[p]) {
			for (int j = 2 * p; (LL)j*j < R; j += p)is_prime_small[j] = false;
			if (p >= L) {
				factset[p - L].push_back(PLL(p, 1));
				fs[p - L] /= p;
			}
			for (LL j = max(2LL, (L + p - 1) / p)*p; j < R; j += p) {
				is_prime[j - L] = false;
				factset[j - L].push_back(PLL(p, factcnt(j, p)));
				fs[j - L] /= powLL(p, factset[j - L].back().second);
			}
		}
	}
	for (LL i = L; i < R; ++i) {
		{
			LL s = fs[i - L];
			if (s != 1)factset[i - L].push_back(PLL(s, 1));
		}
	}

	LL ans = 0;
	// [(p,cnt)]を何とかする

	for (LL i = L; i < R; ++i) {
		bool ok = 0; // 高々30種
		// 2と奇数
		LL evensum = 0;
		LL oddsum = 1;
		for (auto it : factset[i - L]) {
			if (it.first % 2 == 1) { // odd
				oddsum *= (it.second + 1);
			}
			else {
				if (evensum == 0)evensum = it.second;
				else evensum *= (it.second + 1);
			}
		}
		if (abs(evensum*oddsum - oddsum) <= 2)ok = 1;
		DD(de(i, oddsum, evensum));
		DD(de(i, oddsum,evensum*oddsum));
		ans += ok;
	}
	return ans;
}
// 篩をします
void solve(int testcasenum) {
	LL L, R;
	cin >> L >> R;
	LL ans = sieve(L, R + 1);
	cout << "Case #" << testcasenum << ": ";
	cout << ans << endl;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int T; cin >> T;
	FOR(t, 0, T) {
		solve(t + 1);
	}

	return 0;
}


/*



*/
