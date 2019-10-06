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

/* -----  2019/09/30  Problem: GOOGLE_KICKSTART2019_ROUNDF A / Link: https://codingcompetitions.withgoogle.com/kickstart/about  ----- */


// Teach Me(11pts, 25pts)
void solve(int testcasenum) {
	LL N; cin >> N;
	LL S; cin >> S;
	LL ans = N * N - N;
	VVL a(N);
	map<LL, LL>skill_subset;
	FOR(i, 0, N) {
		int c; cin >> c;
		FOR(k, 0, c) {
			LL x; cin >> x;
			a[i].push_back(x);
		}
		SORT(a[i]);
		FOR(state, 1, 1 << c) {
			LL sum = 0;
			LL ten3 = 1;
			FOR(k, 0, c) {
				if (state & 1 << k) {
					sum += ten3 * a[i][k];
					ten3 *= 1001;
				}
			}
			skill_subset[sum]++;
		}
	}
	FOR(i, 0, N) {
		int c = SZ(a[i]);
		LL sum = 0;
		LL ten3 = 1;
		FOR(k, 0, c) {
			sum += a[i][k] * ten3;
			ten3 *= 1001;
		}
		ans -= skill_subset[sum]-1;
	}

	cout << "Case #" << testcasenum << ": ";
	cout << ans << "\n";
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

/*
[1 input]:
2
4 100
4 80 90 100 5
1 90
1 80
3 80 90 100
3 30
4 10 11 12 13
4 10 11 12 13
5 25 26 27 28 29
[1 output]:
Case #1: 7
Case #2: 4

*/
