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

/* -----  2019/03/24  Problem: google_kickstart2019_rounda A / Link: __CONTEST_URL__  ----- */
// Contention


void solve(int testcase) {
	int N, Q; cin >> N >> Q;
	vector<LL> L(Q), R(Q);
	for (int i = 0; i < Q; ++i) {
		cin >> L[i] >> R[i];
	}


	LL ans = 0;


	cout << "Case #" << testcase + 1 << ": " << ans << endl;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL T; cin >> T;
	FOR(_, 0, T) {
		solve(_);
	}

	return 0;
}
