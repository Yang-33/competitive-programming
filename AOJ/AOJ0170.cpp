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

/* -----  2019/07/23  Problem: AOJ 0170 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0170  ----- */


int main() {
	int N;
	while (cin >> N, N) {
		VS name(N); VI w(N), s(N);
		FOR(i, 0, N) {
			cin >> name[i] >> w[i] >> s[i];
		}
		VI wsum(1 << N); {
			FOR(state, 0, 1 << N) {
				LL sum = 0;
				FOR(i, 0, N) {
					if (state & 1 << i)sum += w[i];
				}
				wsum[state] = sum;
			}
		}
		// minimize & cond
		VI dp(1 << N, INF);
		VI rev(1 << N, -1);
		dp[0] = 0;
		FOR(state, 0, 1 << N) {
			int n = N - __builtin_popcount(state);
			FOR(i, 0, N) {
				if (state & 1 << i)continue;
				if (s[i] >= wsum[state]) {
					LL cost = dp[state] + n * w[i];
					if (dp[state | (1 << i)] > cost) {
						dp[state | (1 << i)] = cost;
						rev[state | (1 << i)] = i;
					}
				}
			}
		}
		DD(de(dp[(1 << N) - 1]));
		VI ans; {
			int p = rev[(1 << N) - 1];
			int state = (1 << N) - 1;
			while (state) {
				ans.push_back(p);
				state ^= 1 << p;
				p = rev[state];
			}
		}
		for (int i : ans) {
			cout << name[i] << endl;
		}
	}

	return 0;
}