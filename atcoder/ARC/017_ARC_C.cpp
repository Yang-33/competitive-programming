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

/* -----  2018/11/22  Problem: ARC 017 C / Link: http://arc017.contest.atcoder.jp/tasks/arc017_c  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----



----解説ここまで---- */



int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, X; cin >> N >> X;
	VL a(N);
	FOR(i, 0, N) {
		cin >> a[i];
	}

	// 半分全列挙
	VL sums;
	int N1 = N / 2;
	FOR(state, 0, 1 << N1) {
		LL sub = 0;
		FOR(i, 0, N1) {
			if (state & 1 << i) {
				sub += a[i];
			}
		}
		sums.push_back(sub);
	}
	SORT(sums);
	int N2 = N - N1;
	LL ans = 0;
	FOR(state, 0, 1 << N2) {
		LL sub = 0;
		FOR(i, 0, N2) {
			if (state & 1 << i) {
				int j = i + N1;
				sub += a[j];
			}
		}
		ans += upper_bound(ALL(sums), X - sub) - lower_bound(ALL(sums), X - sub);
	}
	cout << ans << endl;

	return 0;
}
