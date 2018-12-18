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

/* -----  2018/11/24  Problem: CodeForces524 D div2 / Link: http://codeforces.com/contest/1080/problem/D  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

？

----解説ここまで---- */
using LLL = double;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL tca; cin >> tca;
	auto check = [](LL n, LL k) {
		LLL fours = 1;
		LLL nk = 3 * k + 1;
		LL val = 0;
		for (; fours < nk;) {
			fours *= 4;
			val++;
		}
		return val <= n;
	};
	FOR(_, 0, tca) {
		LL N, K; cin >> N >> K;
		if (check(N,K)) {
			cout << "YES " << N-1 << endl;
		}
		else {
			cout << "NO" << endl;
		}

	}


	return 0;
}
