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

/* -----  2019/04/28  Problem: square869120Contest_01 F / Link: __CONTEST_URL__  ----- */




// dp(i,c mod,dsum,less)
LL C, D;
LL dp[81][51][722][2];
LL tens[81];
LL f(string &target, int i, int mul = 0, int dsum = 0, int less = 0) {
	if (dsum > D)return 0;
	if (2 * (i + 1) == SZ(target)) {
		return mul % C == 0 && dsum == D;
	}

	if (dp[i][mul][dsum][less] != -1)return dp[i][mul][dsum][less];
	LL res = 0;
	int num = target[i] - '0';
	int Max = (less ? 9 : num);
	FOR(nx, 0, Max + 1) {
		int lowid = SZ(target) - 1 - i;
		LL cmul = nx * (tens[i] + tens[lowid]);
		res += f(target, i - 1, (cmul + mul) % C, dsum + 2 * nx, less || nx < Max);
	}
	return dp[i][mul][dsum][less] = res % MOD;
}

string minusone(string s) {
	for (int i = (int)s.size() - 1; i >= 0; --i) {
		if (s[i] == '0') { s[i] = '9'; }
		else { s[i]--; break; }
	}
	if (s[0] == '0')s = s.substr(1);
	return s;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string a, b; cin >> a >> b;
	//a = minusone(a);
	cin >> C >> D; // g

	tens[0] = 1;
	FOR(i, 0, 81) {
		tens[i + 1] = tens[i] * 10 % C;
	}
	fill(***dp, ***dp + 81 * 51 * 722 * 2, -1);
	LL ans = f(b, SZ(b) - 1);
	DD(de(ans));
	fill(***dp, ***dp + 81 * 51 * 722 * 2, -1);
	ans -= f(a, SZ(a) - 1);
	ans += MOD;
	ans %= MOD;
	cout << ans << "\n";

	return 0;
}