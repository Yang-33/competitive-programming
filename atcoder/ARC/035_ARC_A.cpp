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

/* -----  2018/10/24  Problem: ARC 035 A / Link: http://arc035.contest.atcoder.jp/tasks/arc035_a  ----- */
/* ------問題------

高橋くんは、ある文字列を持っていました。あるとき、Cat Snuke がやってきて文字列の一部を食べてしまいました。
高橋くんは元の文字列が回文であった可能性があるかを知りたいです。そこで、食べられた文字を適切に埋め合わせて、回文とすることができるか調べてください。
食べられた文字それぞれを、どの文字で埋め合わせるかは自由に決められます。

-----問題ここまで----- */
/* -----解説等-----

回文の判定をする際に、*をskipすればよい。

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string s; cin >> s;
	int ok = 1;
	FOR(i, 0, SZ(s)) {
		int j = SZ(s) - 1 - i;
		if (s[i] == '*' || s[j] == '*') continue;
		if (s[i] == s[j])continue;
		else ok = 0;
	}
	
	
	cout << (ok?"YES":"NO") << "\n";

	return 0;
}
