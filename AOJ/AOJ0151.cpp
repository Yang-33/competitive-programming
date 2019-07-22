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

/* -----  2019/07/23  Problem: AOJ 0151 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0151  ----- */


// 指定した値の最大の連続区間長を返す
int max_same_consecutive_element(const vector<int>&a, int num) {
	int mx = 0;
	int cnt = 0;
	for (auto it : a) {
		if (it == num) {
			cnt++;
		}
		else {
			cnt = 0;
		}
		mx = max(mx, cnt);
	}
	return mx;
}
int main() {
	int N;
	while (cin >> N, N) {
		vector<string> a(N);
		for (int i = 0; i < N; ++i) {
			cin >> a[i];
			FOR(j, 0, N) {
				a[i][j] -= '0';
			}
		}
		int ans = 0;
		// 横
		FOR(i, 0, N) {
			VI b;
			FOR(j, 0, N) {
				b.push_back(a[i][j]);
			}
			ans = max(ans, max_same_consecutive_element(b, 1));
		}
		// 縦
		FOR(j, 0, N) {
			VI b;
			FOR(i, 0, N) {
				b.push_back(a[i][j]);
			}
			ans = max(ans, max_same_consecutive_element(b, 1));
		}
		// 斜め // 
		FOR(k, 0, 2 * N - 1) {
			VI b;
			FOR(m, 0, N) {
				if (k - m >= 0 && k - m < N) {
					b.push_back(a[m][k - m]);
				}
			}
			ans = max(ans, max_same_consecutive_element(b, 1));
		}

		// 斜め
		FOR(k, 0, 2 * N - 1) {
			VI b;
			FOR(m, 0, N) {
				if ((N - 1 - k) + m >= 0 && (N - 1 - k) + m < N) {
					b.push_back(a[(N - 1 - k) + m][m]);
				}
			}
			ans = max(ans, max_same_consecutive_element(b, 1));
		}

		cout << ans << "\n";
	}
}