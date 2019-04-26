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

/* -----  2019/04/11  Problem: ABC 013 C / Link: http://abc013.contest.atcoder.jp/tasks/abc013_c  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	// 普通の食事の回数でやる

	LL N, H; cin >> N >> H;
	LL A, B, C, D, E; cin >> A >> B >> C >> D >> E;
	LL ans = LINF;
	FOR(hutu, 0, N + 1) {
		LL cost = A * hutu;
		LL new_H = H + B * hutu;
		auto f = [&](int p, LL leftH) {
			// p日質素をする
			leftH += p * D;
			int sis_day = N - hutu - p;
			leftH -= sis_day * E;
			return leftH > 0;
		};
		LL L = -1, R = N;
		while (R - L > 1) {
			LL mid = (L + R) / 2;
			if (f(mid, new_H)) {
				R = mid;
			}
			else L = mid;
		}
		// R is ok
		cost += R * C;
		ans = min(ans, cost);
	}

	cout << ans << "\n";

	return 0;
}
