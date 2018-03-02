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

/* -----  2018/03/02  Problem: 088_arc_b / Link: https://abc083.contest.atcoder.jp/tasks/arc088_b?lang=en  ----- */
/* ------問題------

0 と 1 からなる文字列 S が与えられます。 以下の操作を好きな回数繰り返すことで S の要素をすべて 0 にできるような、|S| 以下の最大の整数 K を求めてください。
S の長さ K 以上の連続する区間 [l,r] を選ぶ(すなわち、r−l+1≥K が満たされる必要がある)。l≤i≤r なるすべての整数 i に対し、Si が 0 なら Si を 1 に、Si が 1 なら Si を 0 に置き換える。

-----問題ここまで----- */
/* -----解説等-----

ひっくり返していく中で境界を削除していきたい。
境界を削除する際には境界から端まで遠い方をKとすれば良い。
この複数あるKのうち、最小のものが解を生成する条件なのでこれを探せば良い。

ans = LINFとして 1WA
初期解に気をつけて#

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string s; cin >> s;

	ans = SZ(s);
	
	FOR(i, 0, SZ(s)-1) {
		if (s[i] != s[i + 1]) {
			ans = min(ans, (LL)max(i + 1, SZ(s) - (i + 1)));
		}
	}


	cout << ans << "\n";

	return 0;
}
