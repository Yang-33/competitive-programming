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

/* -----  2019/05/26  Problem: google_kickstart2019_roundC B / Link: https://codingcompetitions.withgoogle.com/kickstart/round/0000000000050ff2  ----- */

// Circuit Board
void solve(int testcasenum) {
	int H, W, K; cin >> H >> W >> K;
	VVI a(H, VI(W, 0));
	FOR(i, 0, H) {
		FOR(j, 0, W) {
			cin >> a[i][j];
		}
	}
	vector<VVI>isok(H, VVI(W, VI(W, 0)));
	FOR(i, 0, H) {
		FOR(L, 0, W) {
			int mn = INF, mx = 0;
			FOR(R, L, W) {
				mn = min(mn, a[i][R]);
				mx = max(mx, a[i][R]);
				if (mx - mn <= K) {
					isok[i][L][R] = 1;
				}
			}
		}
	}

	// 0 1 1 0 0 0 0 1 1 1 1 0 1 1 1 0:= 4
	auto f = [](const VI& a) {
		int ret = 0;
		int cnt = 0;
		for (auto it : a) {
			if (it == 0) {
				cnt = 0;
			}
			else {
				cnt++;
				ret = max(ret, cnt);
			}
		}

		return ret;
	};
	int ans = 0;
	FOR(wL, 0, W) {
		FOR(wR, wL, W) {


			VI uku;
			uku.push_back(0);
			FOR(h, 0, H) {
				uku.push_back(isok[h][wL][wR]);
			}
			uku.push_back(0);
			int mxh = f(uku);
			ans = max(ans, (wR - wL + 1)*mxh);
		}
	}


	cout << "Case #" << testcasenum << ": "
		<< ans << endl;
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
