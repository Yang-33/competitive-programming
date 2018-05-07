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
#define debug(x) cerr << #x << ": " << x << endl
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/05/05  Problem: yukicoder 152  / Link: http://yukicoder.me/problems/no/152  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

原子ピタゴラス数は、
m,nが互いに素
m > n
m-nは奇数
で、(a,b,c) = (m^2 − n^2, 2mn, m^2 + n^2)
を満たす。
これを求めれば良い。
a+b+c≦L/4で、a+b+c = 2m^2+2mn ≦ 2m^2 ≦ L/4
として求めれば良い。

----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int L; cin >> L;
	for (int m = 2; 2 * m*m < L / 4; m++) {
		for (int n = (m % 2) + 1; n < m; n += 2) {
			if (2 * m*(m + n) <= L / 4 && __gcd(m, n) == 1) {
				ans++;
			}
		}
	}

	cout << ans << "\n";

	return 0;
}
