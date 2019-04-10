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

/* -----  2019/04/10  Problem: ABC 017 C / Link: http://abc017.contest.atcoder.jp/tasks/abc017_c  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, M; cin >> N >> M;
	VL seg(M + 1, 0);
	LL Ssum = 0;
	FOR(i, 0, N) {
		LL L, R, S; cin >> L >> R >> S;
		L--;
		Ssum += S;
		seg[L] += S;
		seg[R] -= S;
	}
	FOR(i, 0, M) {
		seg[i + 1] += seg[i];
	}
	LL minp = *min_element(seg.begin(),seg.begin()+M);

	LL ans = Ssum - minp;


	cout << (ans) << "\n";

	return 0;
}
