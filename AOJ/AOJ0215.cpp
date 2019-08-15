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

/* -----  2019/08/14  Problem: AOJ 0215 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0215  ----- */


int main() {

	int W, H;
	while (cin >> W >> H, H || W) {
		VS masu(H); {
			FOR(i, 0, H) {
				cin >> masu[i];
			}
		}

		vector<vector<PII>>poses; {
			auto getposes = [&](char c) {
				vector<PII>pos;
				FOR(i, 0, H) {
					FOR(j, 0, W) {
						if (masu[i][j] == c) {
							pos.emplace_back(i, j);
						}
					}
				}
				return pos;
			};
			FOR(i, 0, 5) {
				poses.emplace_back(getposes('1' + i));
			}
			poses.emplace_back(getposes('G'));
			poses.emplace_back(getposes('S'));
		}
		deque<int>order; {
			FOR(i, 0, 6) {
				order.push_back(i);
			}
		}
		auto order_rotation = [&]() {
			int f = order.front();
			order.pop_front();
			int five = order.back();
			order.pop_back();
			order.push_back(f);
			order.push_back(five);
		};

		auto chmin = [](auto &a, auto b) {
			a = min(a, b);
		};
		auto f = [&](int a, int b, const vector<int>&dp) {
			vector<int>nx(SZ(poses[b]), INF);
			FOR(ai, 0, SZ(poses[a])) {
				FOR(bi, 0, SZ(poses[b])) {
					chmin(nx[bi], dp[ai] + abs(poses[a][ai].first - poses[b][bi].first) + abs(poses[a][ai].second - poses[b][bi].second));
				}
			}

			return nx;
		};

		PII ans(INF, INF); {
			FOR(t, 0, 5) {

				// 先頭をSとswap
				int x = order.front();
				order.front() = 6;
				vector<int>dp(SZ(poses[order.front()]), 0);
				FOR(i, 0, 5) {
					dp = f(order[i], order[i + 1], dp);
				}
				auto res = PII(*min_element(ALL(dp)),t);
				chmin(ans, res);

				order.front() = x; // restore
				order_rotation();
			}
		}


		if (ans.first == INF)puts("NA");
		else cout << ans.second + 1 << " " << ans.first << "\n";
	}


	return 0;
}
