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

/* -----  2019/06/16  Problem: ABC 130 E / Link: http://abc130.contest.atcoder.jp/tasks/abc130_e  ----- */

const int mod = 1e9 + 7;
LL dp[2003][2003];
int CommomSubsequencesCount(vector<int> s, vector<int> t)
{
	int n1 = s.size();
	int n2 = t.size();

	for (int i = 0; i <= n1; i++) {
		for (int j = 0; j <= n2; j++) {
			dp[i][j] = 0;
		}
	}

	for (int i = 1; i <= n1; i++) {

		// for each charcater in T 
		for (int j = 1; j <= n2; j++) {
			if (s[i - 1] == t[j - 1])
				dp[i][j] = 1 + dp[i][j - 1] + dp[i - 1][j];
			else
				dp[i][j] = (dp[i][j - 1] + dp[i - 1][j] + mod -
					dp[i - 1][j - 1]) % mod;
			dp[i][j] %= mod;
		}
	}
	dp[n1][n2] += 1;
	dp[n1][n2] %= mod;
	return dp[n1][n2];
}


// Driver Program 
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N, M; cin >> N >> M;
	vector<int> a(N);
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
	}
	vector<int> b(M);
	for (int i = 0; i < M; ++i) {
		cin >> b[i];
	}
	cout << CommomSubsequencesCount(a, b) << endl;
	return 0;
}