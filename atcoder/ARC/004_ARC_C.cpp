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

/* -----  2018/12/13  Problem: ARC 004 C / Link: http://arc004.contest.atcoder.jp/tasks/arc004_c  ----- */
/* ------問題------

太郎君は 1 から N までの正整数の平均値を求めようと思い、1 から N までの合計値を N で割ることにしました。
しかし、1 から N までの正整数を合計するときに、ある正整数 M(M は N 以下の正整数)だけ足し忘れてしまい、間違った平均値を算出してしまいました。
さらに、太郎君は正整数 N の値も忘れてしまいました。

今、間違った平均値だけがわかっています。元の数 N と M の組み合わせとして考えられるものを全て答えてください。

-----問題ここまで----- */
/* -----解説等-----

実験するとそんなにない。
式変形をして、M=YN(N+1)-2NX /2Y となる。
Nが小さいときはこれを全探索すれば良い。
そうは言っていられないので、Nの上限、下限を考える。
N/2がだいたいX/Yぐらいである。
これの近傍のみ見れば良い。

----解説ここまで---- */

LL ans = 0LL;


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	const int sz = 1000;
	//FOR(n, 1,sz) {
	//	FOR(m, 1, n) {
	//		cout << "frac(" << n * (n + 1) / 2 - m << "," << n<<")" << endl;
	//	}
	//}

	LL X, Y;
	scanf("%lld/%lld", &X, &Y);
	LL mn = (2 * X + Y) / Y - sz;
	LL mx = mn + 2 * sz;
	if (mn < 1) {
		mn = 1;
	}
	int ok = 0;
	for (LL n = mn; n <= mx; n++) {
		LL a = Y * (n + 1)*n - 2 * n*X;
		LL b = 2 * Y;
		if (a % b == 0) {
			LL m = a / b;
			if (1 <= m && m <= n) {
				cout << n << " " << m << endl;
				ok = 1;
			}
		}
	}
	if (!ok) {
		cout << "Impossible" << endl;
	}

	return 0;
}
