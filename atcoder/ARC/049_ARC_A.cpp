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

/* -----  2018/11/12  Problem: ARC 049 A / Link: http://arc049.contest.atcoder.jp/tasks/arc049_a  ----- */
/* ------問題------

文字列 S と、非負整数 A,B,C,D が与えられます。
S の、A,B,C,D 文字目の後ろにダブルクオーテーション"を挿入した文字列を出力してください。
ただし、0 文字目の後ろというのは、文字列の先頭を指すこととします。

-----問題ここまで----- */
/* -----解説等-----

最後に気をつけて挟んでいく。

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string s; cin >> s;
	set <int>a;
	FOR(i, 0, 4) {
		int b; cin >> b;
		a.insert(b);
	}
	string ans;
	FOR(i, 0, SZ(s)) {
		if (a.find(i) != a.end()) {
			ans += string(1, '"');
		}
		ans += string(1, s[i]);
	}
	if (a.find(SZ(s)) != a.end()) {
		ans += string(1, '"');
	}
	cout << ans << "\n";

	return 0;
}
