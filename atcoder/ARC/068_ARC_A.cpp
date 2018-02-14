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

/* -----  2018/02/14  Problem: 068_arc_a / Link: https://arc068.contest.atcoder.jp/tasks/arc068_a?lang=en  ----- */
/* ------問題------

すぬけくんは 6 面サイコロで遊ぶことにしました。 サイコロは 1 から 6 までの整数がそれぞれの面に書かれており、向かい合う面に書かれた数の和はどれも 7 です。
すぬけくんはサイコロの好きな面が上向きになるように置いたのち何回か以下の操作を行います。
•操作：サイコロを手前、奥、左、右のどれかの方向に 90° だけ回転させる。その後、上を向いている面に書かれた数を y として y 点得る。
例えば、図のように 1 と書かれた面が上を向いており、手前側の面に 5 が、右側の面に 4 が書かれている状況を考えます。
図に示されるように右方向に回転させることで 3 と書かれた面が上を向くようにすることが可能です。 その他、左方向に回転させた場合は 4 と書かれた面が、手前方向に回転させた場合は 2 と書かれた面が、奥方向に回転させた場合は 5 と書かれた面が上を向くようにすることが可能です。
すぬけくんが合計で x 点以上得るために必要な最小の操作回数を求めなさい。


-----問題ここまで----- */
/* -----解説等-----

これすき
正当性を示せてないけど、11で繰り返せることから最後だけ考えれば良い。

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	ans = (N) / 11LL*2;
	int left = N % 11;
	if (left > 6)ans += 2;
	else if (left > 0)ans += 1;
	cout << ans << "\n";

	return 0;
}
