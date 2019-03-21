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

/* -----  2019/03/21  Problem: ABC 063 D / Link: http://abc063.contest.atcoder.jp/tasks/abc063_d  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, A, B; cin >> N >> A >> B;
	vector<LL> a(N);
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
	}
	auto f = [&A,&B,&N](LL x, VL a) {
		FOR(i, 0, N) {
			a[i] -= x * B;
		}
		LL needx = 0;
		FOR(i, 0, N) {
			if (a[i] > 0)needx += (a[i] - 1 + (A - B)) / (A - B);
		}

		return needx <= x;
	};
	LL L = 0, R = 1e9;
	while (R - L > 1) {
		LL mid = (L + R) / 2;
		if (f(mid,a)) {
			R = mid;
		}
		else {
			L = mid;
		}
	}
	LL ans = R;
	
	cout << (ans) << "\n";

	return 0;
}
