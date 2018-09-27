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

/* -----  2018/09/27  Problem: yukicoder 289  / Link: http://yukicoder.me/problems/no/289  ----- */
/* ------問題------

文字列Sが与えられるので, その中のそれぞれの数字を1桁の数値とみなして, 全ての合計値を求めてください.
例えば1test23という文字列の数字の合計値は1+2+3=6となる.

2016/05/31 追記 
注意: 数字がない場合は0を出力してください。

-----問題ここまで----- */
/* -----解説等-----

isdigitって知ってる？私はICPCで身につけました

----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string s; cin >> s;
	FOR(i, 0, SZ(s)) {
		if (isdigit(s[i])) {
			ans += s[i] - '0';
		}
	}
	cout << ans << "\n";

	return 0;
}
