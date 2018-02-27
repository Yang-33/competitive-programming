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

/* -----  2018/02/27  Problem: 064_arc_b / Link: https://abc048.contest.atcoder.jp/tasks/arc064_b?lang=en  ----- */
/* ------問題------

長さ 3 以上の文字列 s があります。 s の中に同一の文字が隣り合う箇所はありません。
高橋君と青木君がゲームで勝負します。 二人は交互に次の操作を行います。 高橋君が先手です。
s から両端以外の文字をひとつ取り除く。 ただし、その文字を取り除くことで、s の中に同一の文字が隣り合う箇所ができる場合、その文字を取り除くことはできない。
先に操作を行えなくなった人が負けです。 二人が最適に行動したとき、どちらが勝つかを判定してください。

-----問題ここまで----- */
/* -----解説等-----

終了条件は端が一緒で文字列が奇数のとき
端が異なって文字列が偶数のとき
手によれず勝てた

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	cout << ((s.front() == s.back())^(SZ(s)%2)?"First":"Second") << "\n";

	return 0;
}
