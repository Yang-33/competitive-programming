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

/* -----  2019/07/21  Problem: AOJ 0147 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0147  ----- */


int main() {
	VI ans(100); {
		// preprocess
		struct Group {
			int id, arrive, peoples, eattime;
			Group(int i) :
				id(i),
				arrive(5 * i),
				peoples(i % 5 == 1 ? 5 : 2),
				eattime(19 + 17 * (i % 2) + 3 * (i % 3)) {}
		};
		queue<Group>Q; {
			FOR(i, 0, 100)Q.emplace(Group(i));
		}
		int nowt = 0;
		VI seat(17, 0); // 残り時間を入れておく
		auto seathead = [&](int n) {
			int cnt = 0;
			FOR(i, 0, 17) {
				if (!seat[i]) {
					cnt++;
					if (cnt == n)return i - n + 1;
				}
				else { cnt = 0; }
			}
			return -1;
		};

		while (!Q.empty()) {
			while (!Q.empty() && Q.front().arrive <= nowt) {
				int idx = seathead(Q.front().peoples);
				if (idx == -1)break;
				FOR(i, 0, Q.front().peoples) {
					seat[idx + i] = Q.front().eattime;
				}
				ans[Q.front().id] = nowt - Q.front().arrive;
				Q.pop();
			}
			nowt++;
			FOR(i, 0, 17) {
				if (seat[i] > 0) {
					seat[i]--;
				}
			}
		}
	}


	{ // out put
		int in;
		while (cin >> in) {
			cout << ans[in] << "\n";
		}
	}
}