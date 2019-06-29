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

/* -----  2019/06/22  Problem: ABC 131 C / Link: http://abc131.contest.atcoder.jp/tasks/abc131_c  ----- */

/*最大公約数を求める関数(再帰版ユーグリッドの互除法)*/
long long  gcd(long long  a, long long  b) { return b ? gcd(b, a%b) : a; }
// minusのときはabsしておけばOK
/*最小公倍数を求める関数。最小公倍数の性質( a×b÷[aとbの最大公約数] )を利用。*/
long long  lcm(long long  a, long long  b) { return a / gcd(a, b) * b; }

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL A, B, C, D; cin >> A >> B >> C >> D;
	auto solve = [&](LL x) {
		LL ret = x;
		ret -= x / C;
		ret -= x / D;
		ret += x / (lcm(C, D));
		return ret;
	};
	cout << solve(B) - solve(A - 1) << endl;

	return 0;
}
