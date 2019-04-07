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

/* -----  2019/04/07  Problem: ABC 027 C / Link: http://abc027.contest.atcoder.jp/tasks/abc027_c  ----- */

map<LL, int>gamedp;
const int LOSE = 1, WIN = 2;
LL N;
int f(LL a) {
	if (a > N) {
		return WIN;
	}
	if (gamedp[a])return gamedp[a];

	bool gotolose = 0;
	gotolose |= f(2 * a) == LOSE;
	gotolose |= f(2 * a + 1) == LOSE;

	return gamedp[a] = (gotolose ? WIN : LOSE);
}
void test() {
	FOR(i, 1, 601) {
		N = i;
		gamedp.clear();
		cout << "  " << i << ":= " << "LW"[f(1) == WIN];
		if (i % 10 == 0)cout << endl;
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	if (N == 1) {
		cout << "Aoki" << endl;
		return 0;
	}
	//test();
	LL a = 1;
	LL fours = 4;
	for (;;) {
		if (N <= a + fours) {
			cout << "Takahashi" << endl;
			return 0;
		}
		else if (N <= a + 2 * fours) {
			cout << "Aoki" << endl;
			return 0;
		}
		a += 2 * fours;
		fours *= 4;
	}

	return 0;
}
