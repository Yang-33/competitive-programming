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

/* -----  2019/07/09  Problem: SQUARE869120CONTEST_03 B / Link: https://atcoder.jp/contests/s8pc-3/  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL H, W, K; cin >> H >> W >> K;
	assert(K > 1);
	vector<string> s(H);
	for (int i = 0; i < H; ++i) {
		cin >> s[i];
		FOR(j, 0, W) {
			s[i][j] -= '0';
		}
	}
	auto fall = [](VS& s) {
		int H = SZ(s), W = SZ(s[0]);
		FOR(j, 0, W) {
			vector<int>a;
			FOR(i, 0, H) {
				if (s[i][j])a.push_back(s[i][j]);
				s[i][j] = 0;
			}
			FOR(i, 0, SZ(a)) {
				s[H - i - 1][j] = a[SZ(a) - 1 - i];
			}
		}
	};
	auto f = [&K, &fall](int aa, int bb, auto s) {
		s[aa][bb] = 0;
		LL ret = 0;
		bool upd = 1;
		LL t = 0;
		int H = SZ(s), W = SZ(s[0]);
		while (upd) {
			fall(s);
			upd = 0;
			LL sub = 0;
			{ // check
				FOR(i, 0, H) {
					int cnt = 0;
					int pre = -1;
					FOR(j, 0, W) {
						if (s[i][j] == pre)cnt++;
						else if (s[i][j] != pre && cnt >= K) {
							upd |= pre;
							while (cnt) {
								int k = j - cnt;
								sub += s[i][k];
								s[i][k] = 0;
								cnt--;
							}
							pre = s[i][j];
							cnt = 1;
						}
						else if (s[i][j] != pre) {
							pre = s[i][j];
							cnt = 1;
						}
					}
					if (pre != -1 && cnt >= K) {
						upd |= pre;
						while (cnt) {
							int k = W - cnt;
							sub += s[i][k];
							s[i][k] = 0;
							cnt--;
						}
					}
				}
			}
			ret += (LL)pow(2LL, t)*sub;
			t++;
		}
		return ret;
	};
	LL ans = 0LL;
	FOR(i, 0, H) {
		FOR(j, 0, W) {
			ans = max(ans, f(i, j, s));
		}
	}


	cout << (ans) << "\n";

	return 0;
}
