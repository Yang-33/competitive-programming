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

/* -----  2019/04/09  Problem: ABC 025 B / Link: http://abc025.contest.atcoder.jp/tasks/abc025_b  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, A, B; cin >> N >> A >> B;
	LL ans = 0LL;
	FOR(i, 0, N) {
		string s; LL d; cin >> s >> d;
		LL dx = (s == "East" ? 1 : -1);
		if (d < A)ans += dx * A;
		else if (d <= B)ans += dx * d;
		else ans += dx * B;
	}

	if (ans > 0) {
		cout << "East ";
	}
	else if (ans < 0) {
		cout << "West ";
	}
	cout << abs(ans) << "\n";

	return 0;
}