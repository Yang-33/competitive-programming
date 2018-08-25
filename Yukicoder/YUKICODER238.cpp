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

/* -----  2018/08/25  Problem: yukicoder 238  / Link: http://yukicoder.me/problems/no/238  ----- */
/* ------問題------

（この問題は Codeforces Round #286 (Div. 2) の問題A の入力の制約を変更したものです。）

K氏が英小文字からなる文字列 s をくれた。これに英小文字をちょうど一つ挿入して回文にしてほしいそうだ。
（回文とは、前から読んでも後ろから読んでも文字が同じ順番で出現するような文字列である。
例えば "noon", "testset", "a" はどれも回文であるが、 "test", "kitayuta" は回文ではない。）

挿入する文字としてどの英小文字を使ってもよく、それを s のどの位置に挿入してもよい。
s の先頭や末尾への挿入も可能である。
与えられた文字列 s がすでに回文であっても、一文字を挿入しなくてはならない。

s に英小文字を一つ挿入し、その結果文字列を回文にすることが可能ならば、そのようにして得られる回文を一つ出力せよ。
そうでなければ、 "NA" （引用符除く）と大文字で出力せよ。
得られる回文が複数存在する場合は、そのうちどれを出力してもよい。

-----問題ここまで----- */
/* -----解説等-----

回文か、一個なにかが異なる回文もどきは回分にできる

----解説ここまで---- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string s; cin >> s;
	int ok = 1;
	FOR(i, 0, SZ(s) / 2) {
		int j = SZ(s) - i - 1;
		ok &= s[i] == s[j];
	}
	if (ok) {
		cout << s.substr(0, SZ(s) / 2) + string(1, s[SZ(s) / 2]) + s.substr(SZ(s) / 2) << endl;
		return 0;
	}
	int diffcnt = 0;
	auto check = [&s](int l, int r) {
		int len = r - l+1;
		int ok = 1;
		FOR(i, 0, len/2) {
			int L = l + i; int R = r - i;
			ok &= s[L] == s[R];
		}
		return ok;
	};
	FOR(i, 0, SZ(s) / 2) {
		int j = SZ(s) - i - 1;
		if (s[i] != s[j]) {
			diffcnt++;
			if (check(i, j - 1)) {
				cout << s.substr(0, i) + string(1, s[j]) + s.substr(i) << endl;
				return 0;
			}
			if (check(i + 1, j)) {
				cout << s.substr(0, j + 1) + string(1, s[i]) + s.substr(j + 1) << endl;
				return 0;
			}
			diffcnt++;
			break;
		}
	}
		cout << "NA" << endl;

	return 0;
}
