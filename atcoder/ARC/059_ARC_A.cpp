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

/* -----  2019/01/20  Problem: ARC 059 A / Link: http://arc059.contest.atcoder.jp/tasks/arc059_a  ----- */
/* ------問題------

<p><var>N</var> 個の整数 <var>a_1,a_2,..,a_N</var> が与えられます。
えび君はこれらを書き換えて全て同じ<strong>整数</strong>にしようとしています。
各<var>a_i (1≦i≦N)</var>は高々一回しか書き換えられません(書き換えなくても良い)。
整数<var>x</var>を整数<var>y</var>に書き換えるとき、コストが<var>(x-y)^2</var>かかります。
仮に<var>a_i=a_j (i≠j)</var>だとしても、ひとつ分のコストで同時に書き換えることは出来ません(入出力例<var>2</var> を参照)。
えび君が目的を達成するのに必要なコストの総和の最小値を求めてください。</p>


-----問題ここまで----- */
/* -----解説等-----

a(i)のmin~maxの範囲を全部試せば最小値が見つかる．

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; cin >> N;
	VL a(N);
	FOR(i, 0, N) {
		cin >> a[i];
	}

	LL ans = LINF;
	for (LL x = -100; x <= 100; x++) {
		LL ret = 0;
		FOR(i, 0, N) {
			ret += (x - a[i])*(x - a[i]);
		}
		ans = min(ans, ret);
	}


	cout << ans << endl;

	return 0;
}