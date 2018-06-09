#include <bits/stdc++.h>
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

/* -----  2018/04/21  Problem: ARC 096 A / Link: http://arc096.contest.atcoder.jp/tasks/arc096_a  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

貪欲で良いことが示せるので、やる

----解説ここまで---- */

LL A, B, C, X, Y;

LL ans = 0LL;

int main() {

	cin >> A >> B >> C >> X >> Y;
	ans = 1e18;

	LL N = min(X, Y);
	ans = N*min(A + B, 2 * C);
	X -= N, Y -= N;
	ans += Y*min(2 * C, B) + X*min(2 * C, A);
	cout << ans << "\n";

	return 0;
}
