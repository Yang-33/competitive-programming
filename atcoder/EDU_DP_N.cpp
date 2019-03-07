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

/* -----  2019/01/06  Problem: EDU_DP N / Link: __CONTEST_URL__  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----



----解説ここまで---- */


LL ans = 0LL;
LL dp[402][402];
LL a[402];
LL sums[402];
// min
// [L,R)
LL f(int L, int R) {
	if (L + 1 == R)return 0;
	if (dp[L][R] != LINF) {
		return dp[L][R];
	}

	LL ret = LINF;
	// [l,r)
	auto query = [](int l , int r) {
		return sums[r] - sums[l];
	};
	FOR(i, L + 1, R) {
		LL sub = f(L, i) + f(i, R)+ query(L,i)+query(i,R);
		ret = min(ret, sub);
	}

	return dp[L][R] = ret;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	fill(*dp, *dp + 402 * 402, LINF);
	LL N;

	cin >> N;
	FOR(i, 0, N) {
		cin >> a[i];
	}
	FOR(i, 0, N) {
		sums[i + 1] = sums[i] + a[i];
	}
	ans = f(0, N);
	cout << ans << "\n";

	return 0;
}
