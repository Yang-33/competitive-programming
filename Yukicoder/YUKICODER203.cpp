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

/* -----  2018/08/02  Problem: yukicoder 203  / Link: http://yukicoder.me/problems/no/203  ----- */
/* ------問題------

巷ではゴールデンウィークらしいです。
なのでゴールデンウィークっぽい問題です。

2週間分の平日(x)と休日(o)が分かるカレンダーが与えられます。
この2週間の期間以外は、平日とします。

最大の連休（連続の休日）数を求めてください。

-----問題ここまで----- */
/* -----解説等-----

調べる。

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string s1, s2;
	cin >> s1 >> s2;
	string s = s1 + s2;
	int ans = 0;
	int cnt = 0;
	FOR(i, 0, SZ(s)) {
		if (s[i] == 'o')cnt++, ans = max(ans, cnt);
		else cnt = 0;
	}
	cout << ans << "\n";

	return 0;
}
