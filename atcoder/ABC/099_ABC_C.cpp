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
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2019/03/04  Problem: ABC 099 C / Link: http://abc099.contest.atcoder.jp/tasks/abc099_c  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; 
	cin >> N;
	

	VL a;
	a.push_back(1);
	FOR(i, 1, 7){
		a.push_back(pow(9, i));
		a.push_back(pow(6, i));
	}
	VL dp(N + 1, LINF);
	dp[0] = 0;
	for (auto it : a) {
		FOR(i, 0, N - it + 1) {
			dp[i + it] = min(dp[i + it], dp[i] + 1);
		}
	}
	LL ans = dp[N];
	cout << (ans) << "\n";

	return 0;
}
