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

/* -----  2017/10/16  Problem: nagoya_19_02  / Link: https://agc004.contest.atcoder.jp/tasks/agc004_a  ----- */
/* ------問題------

1×1×1 のブロックが A×B×C の直方体状に並んでいます。 高橋君は各ブロックを赤色または青色で塗ろうとしています。 このとき、次の条件が成り立つようにします。
赤いブロックも青いブロックもそれぞれ 1 個以上ある。
赤いブロック全体が 1 つの直方体状になっている。
青いブロック全体が 1 つの直方体状になっている。
高橋君は、赤いブロックの個数と青いブロックの個数の差をできるだけ小さくしたいと思っています。 赤いブロックの個数と青いブロックの個数の差の最小値を求めてください。

-----問題ここまで----- */
/* -----解説等-----

LINFは適切に設定しましょう。

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL a, b, c;

	cin >> a >> b >> c;
	ans = LLONG_MAX;
	ans = min({ ans, abs(a / 2 * b*c - (a - a / 2)*c*b) });
	ans = min({ ans, abs(b / 2 * c*a - (b - b / 2)*a*c) });
	ans = min({ ans, abs(c / 2 * a*b - (c - c / 2)*b*a) });


	cout << ans << "\n";

	return 0;
}