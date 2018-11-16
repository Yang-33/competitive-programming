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

/* -----  2018/11/16  Problem: ARC 022 A / Link: http://arc022.contest.atcoder.jp/tasks/arc022_a  ----- */
/* ------問題------

ある高校にはスーパーICT高校生が通っています。 なぜ彼がそう呼ばれているのかはその高校の生徒の誰も知りません。 手がかりはICTという文字列だけです。けれども、ICTが何の略称なのか分かりません。 生徒たちは一晩考えぬいてICTの本来の意味であると思われる文字列を思いつきました。 しかし眠たい頭で考えたので、その文字列からいくつか文字を省いてICTになるか自信がありません。
生徒たちが考えた文字列 S が与えられるので、それからいくつか文字を省いてICTという文字列が作れるかどうか判定してください。

-----問題ここまで----- */
/* -----解説等-----

単純な状態遷移っぽく書いた。
よく考えなくてもO(|S|^3)で良かった気がする

----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string s; cin >> s;
	string t;
	FOR(i, 0, SZ(s)) {
		t += string(1, tolower(s[i]));
	}
	FOR(i, 0, SZ(t)) {
		if (ans == 0 && t[i] == 'i')ans = 1;
		else if (ans == 1 && t[i] == 'c')ans = 2;
		else if (ans == 2 && t[i] == 't')ans = 3;
	}

	cout << (ans==3?"YES":"NO") << "\n";

	return 0;
}
