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

/* -----  2018/11/24  Problem: CodeForces524 B div2 / Link: http://codeforces.com/contest/1080/problem/B  ----- */
/* ------問題------

ai = (-1)^i * iとする。
Q回クエリが与えられる。
sum a[l..r]を求めよ。

-----問題ここまで----- */
/* -----解説等-----

sum a[0..i) = (-1)^i * i/2みたいな感じなので、
R-Lを計算すれば良い。

----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int Q; cin >> Q;
	auto f = [](LL x) {
		if (x % 2 == 1) {
			x++;
			return -x / 2;
		}
		else {
			return x / 2;
		}
	};
	FOR(_, 0, Q) {
		LL L, R; cin >> L >> R;
		ans = f(R) - f(L - 1);
		cout << ans << "\n";
	}
	
	

	return 0;
}
