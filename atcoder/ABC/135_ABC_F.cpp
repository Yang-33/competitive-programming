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

/* -----  2019/07/27  Problem: ABC 135 F / Link: http://abc135.contest.atcoder.jp/tasks/abc135_f  ----- */

struct RHMOD {
	RHMOD() {}RHMOD(const string &S) : S_(S) { int n = (int)S.size(); for (int iter = 0; iter < SZ(mod); ++iter) { hash[iter].assign(n + 1, 0); power[iter].assign(n + 1, 1); for (int i = 0; i < n; ++i) { hash[iter][i + 1] = (hash[iter][i] * base + S[i]) % mod[iter]; power[iter][i + 1] = power[iter][i] * base % mod[iter]; } } }
	inline long long get(int l, int r, int id = 0) const { long long res = hash[id][r] - hash[id][l] * power[id][r - l] % mod[id]; if (res < 0) res += mod[id]; return res; }
	inline int getLongestPrefixSum(int a, int b) const { int len = min((int)S_.size() - a, (int)S_.size() - b); int low = -1, high = len + 1; while (high - low > 1) { int mid = (low + high) / 2; if (get(a, a + mid, 0) != get(b, b + mid, 0)) high = mid; else if (get(a, a + mid, 1) != get(b, b + mid, 1)) high = mid; else low = mid; }return low; }const int base = 9973; const vector<int> mod = { 999999937LL, 1000000007LL }; string S_; vector<long long> hash[2], power[2];
};

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string s, t;
	cin >> s >> t;
	int c_s = SZ(s);
	int cur_sz = c_s + 2 + SZ(t);
	string TEXT = s;
	{
		TEXT += "!!"; // 2!
		TEXT += t;
	}
	{
		while (cur_sz < 2 * c_s) {
			cur_sz += SZ(t);
			TEXT += t;
		}
	}
	int tsumlength = -2 - c_s + cur_sz;
	RHMOD superhash(TEXT);

	int ans = 0;
	FOR(spos, 0, c_s) {
		int cur_t = 0;
		int cur_s = spos;
		DD(de(cur_t, "test---"));
		int sumS = 0; {
			while (INF) {
				int tidx = c_s + 2 + cur_t;
				int tlcp = superhash.getLongestPrefixSum(cur_s, tidx);
				if (tlcp == 0)break;
				sumS += tlcp;
				DD(de(cur_t, cur_s, "deg", tlcp));
				cur_t += tlcp;	cur_t %= tsumlength;
				cur_s += tlcp;	cur_s %= c_s;
				DD(de("aft,", cur_t, cur_s))
					if (sumS >= 2 * max(c_s, tsumlength)) {
						DD(de("inf."));
						ans = INF;
						break;
					}
			}
		}
		DD(de("sub end"));
		if (ans == INF)break;
		else {
			int ret = sumS / SZ(t);
			DD(de(ret));
			ans = max(ans, ret);
		}
	}

	if (ans == INF)cout << "-1\n";
	else cout << ans << "\n";

	return 0;
}


