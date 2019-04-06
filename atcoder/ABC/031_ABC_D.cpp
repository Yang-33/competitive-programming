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

/* -----  2019/04/06  Problem: ABC 031 D / Link: http://abc031.contest.atcoder.jp/tasks/abc031_d  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL K, N; cin >> K >> N;
	vector<string> nums(N), text(N);
	for (int i = 0; i < N; ++i) {
		cin >> nums[i] >> text[i];
	}
	int maxS = 1; {
		FOR(i, 0, K) {
			maxS *= 3;
		}
	}
	FOR(state, 0, maxS) {
		int S = state;
		vector<int>lens(K + 1,0);
		FOR(i, 0, K) {
			int kthlen = S % 3 + 1;
			lens[i + 1] = kthlen;
			S /= 3;
		}

		// check
		// 定まるか見る
		bool ok = 1;
		vector<string>ans(K + 1);
		FOR(i, 0, N) {
			int lensum = 0;
			FOR(j, 0, SZ(nums[i])) {
				int num = nums[i][j] - '0';
				int len = lens[num];
				ok &= SZ(text[i]) > lensum;
				if (!ok)continue;
				string t = text[i].substr(lensum, len);
				if (SZ(ans[num])) {
					ok &= ans[num] == t;
				}
				ans[num] = t;
				lensum += len;
			}
			ok &= lensum == SZ(text[i]);
		}
		if (ok) {
			FOR(i, 1, K + 1) {
				cout << ans[i] << endl;
			}
			return 0;
		}
	}

	return 0;
}
