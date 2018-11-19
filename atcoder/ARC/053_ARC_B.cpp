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

/* -----  2018/11/19  Problem: ARC 053 B / Link: http://arc053.contest.atcoder.jp/tasks/arc053_b  ----- */
/* ------問題------

高橋君は文字列 S を持っています。S は英小文字のみからなります。
まず、高橋君は S の文字を任意の順番に並べ替え、文字列 S' を作ります。
次に、高橋君は S' を任意の位置で分割し、何個かの文字列 s1，s2，…，sN を作ります（N は任意）。ただし、各 si は回文でなければなりません。
各 si の長さの最小値を X とします。高橋君は X をできるだけ大きくしようとしています。X の最大値を求めてください。

-----問題ここまで----- */
/* -----解説等-----

奇数長の回分の中心の数だけ必ず分割しなければならない。
それの外側は均等に割り振りたいので、これを求める。

----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string s; cin >> s;
	VI a(26, 0);
	FOR(i, 0, SZ(s)) {
		a[s[i] - 'a']++;
	}
	int oddCnt = 0;
	FOR(i, 0, 26) {
		if (a[i] & 1)oddCnt++;
	}

	if (oddCnt == 0) {
		ans = SZ(s);
	}
	else {
		int X = SZ(s) - oddCnt;
		X /= 2;
		ans = (X / oddCnt) * 2+1;
	}
	cout << ans << "\n";

	return 0;
}
