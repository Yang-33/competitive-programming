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

/* -----  2018/02/24  Problem: code-festival-2017-qual-c_c / Link: https://code-festival-2017-qualc.contest.atcoder.jp/tasks/code_festival_2017_qualc_c?lang=en  ----- */
/* ------問題------

英小文字のみからなる文字列 s があります。 すぬけ君は、次の操作を繰り返し行うことができます。
s の任意の位置 (先頭および末尾を含む) をひとつ選び、英小文字 x をひとつ挿入する。
すぬけ君の目標は、s を回文にすることです。 すぬけ君の目標が達成可能か判定し、達成可能ならば必要な操作回数の最小値を求めてください。
注釈
回文とは、前後を反転しても変わらない文字列のことです。 例えば、a, aa, abba, abcba は回文ですが、ab, abab, abcda は回文ではありません。

-----問題ここまで----- */
/* -----解説等-----

xについてばあいわけすればよい

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);


	string s; cin >> s;
	int l = 0;
	int r = SZ(s) - 1;
	while (l < r) {
		if (s[l] != s[r]) {
			if (s[l] == 'x') {
				ans++;
				l++;
			}
			else if (s[r] == 'x') {
				ans++;
				r--;
			}
			else {
				ans = -1;
				break;
			}
		}
		else {
			l++;
			r--;
		}
	}


	cout << ans << "\n";

	return 0;
}
