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

/* -----  2019/03/08  Problem: ABC 093 D / Link: http://abc093.contest.atcoder.jp/tasks/abc093_d  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL Q; cin >> Q;
	auto f = [](LL A, LL B) {
		if (A == B)return 2 * (A - 1);
		LL upMax = A * B - 1;

		LL L = 1, R = 10LL*INF;
		while (R - L > 1) {
			LL mid = (L + R) / 2;
			LL mulmax = (
				mid & 1 ?
				(mid / 2 + 1)*(mid / 2 + 1)
				:
				(mid / 2)*(mid / 2 + 1)
				);
			if (mulmax > upMax)R = mid;
			else L = mid;

		}

		return L - 1;
	};
	FOR(_, 0, Q) {
		LL A, B; cin >> A >> B;
		LL ans = f(A, B);
		cout << (ans) << "\n";
	}



	return 0;
}
