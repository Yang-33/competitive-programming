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

/* -----  2019/07/20  Problem: AOJ 0120 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0120  ----- */
stringstream deletecommma(string line) {
	istringstream ss(line);
	string s;
	stringstream input;
	while (getline(ss, s, ' ')) {
		input << s; input << " ";
	}
	return input;
}
int main() {
	string in;
	while (getline(cin, in)) {
		auto input = deletecommma(in);
		LL W; input >> W;
		VL r; {
			int n;
			while (input >> n) {
				r.push_back(n);
			}
		}
		int N = SZ(r);
		vector<vector<double>>dp(1 << N, vector<double>(N, LINF));
		FOR(i, 0, N) {
			dp[1 << i][i] = 2 * r[i];
		}
		auto f = [](double d, double r1, double r2) {
			double rd = abs(r1 - r2);
			double rs = r1 + r2;
			double x = sqrt(rs*rs - rd * rd);
			return d - r1 + x + r2;
		};
		FOR(state, 0, 1 << N) {
			FOR(from, 0, N) {
				if ((state & 1 << from) == 0)continue;
				if (dp[state][from] > INF)continue;
				FOR(to, 0, N) {
					if (state & 1 << to)continue;
					int nstate = state | (1 << to);
					double cost = f(dp[state][from], r[from], r[to]);
					dp[nstate][to] = min(dp[nstate][to], cost);
				}
			}
		}
		double ans = LINF;
		FOR(i, 0, N) {
			ans = min(ans, dp[(1 << N) - 1][i]);
		}
		cout << (ans <= W ? "OK" : "NA") << "\n";
	}



	return 0;
}
