#include "bits/stdc++.h"
using namespace std;

using VS = vector<string>;    using LL = long long;
using VI = vector<int>;       using VVI = vector<VI>;
using PII = pair<int, int>;   using PLL = pair<LL, LL>;
using VL = vector<LL>;        using VVL = vector<VL>;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(a) int((a).size())
#define SORT(c) sort(ALL((c)))
#define RSORT(c) sort(RALL((c)))
#define UNIQ(c) (c).erase(unique(ALL((c))), end((c)))
#define FOR(i, s, e) for (int(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (int(i) = (s); (i) > (e); (i)--)
#define debug(x) cerr << #x << ": " << x << endl
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2017/11/18  Problem: ABC 079 B / Link: http://abc079.contest.atcoder.jp/tasks/abc079_b  ----- */
/* ------問題------

今、日本は 11 月 18 日ですが、11 と 18 は隣り合うリュカ数です。
整数 N が与えられるので、N 番目のリュカ数を求めてください。
ただし、リュカ数は i 番目のリュカ数を Li とすると、
L0=2
L1=1
Li=Li−1+Li−2(i≧2)
と定義される数とします。

-----問題ここまで----- */
/* -----解説等-----

再帰では大変なのでfor文でやる？

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	VL a(N + 1, 0);
	a[0] = 2;
	a[1] = 1;
	FOR(i, 2, N + 1) {
		a[i] = a[i - 1] + a[i - 2];
	}
	ans = a[N];
	cout << ans << "\n";

	return 0;
}
