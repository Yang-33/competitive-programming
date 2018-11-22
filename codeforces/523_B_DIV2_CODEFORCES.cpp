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

/* -----  2018/11/23  Problem: CodeForces523 B div2 / Link: http://codeforces.com/contest/1061/problem/B  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

降順に並べて、コストを渡す感じにした。

----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, M; cin >> N >> M;
	VL a(N);
	FOR(i, 0, N) {
		cin >> a[i];
	}
	RSORT(a);
	ans = 0;
	LL h = a[0];
	LL p;
	FOR(i, 1, N) {
		if (h == 1) {
			ans += a[i] - 1;
		}
		else if (h > a[i]) {
			ans += a[i];
			h = a[i];
			p = a[i];
		}
		else if (h == a[i]) { // h == a[i]
			ans += a[i] - 1 + 1;
			h--;
		}
		else { // h < a[i]
			ans += h;
			ans += a[i] - h;
			h--;
		}
		h = max(1LL, h);
		DD(de(a[i], h, ans));
	}

	cout << ans << "\n";

	return 0;
}
