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

/* -----  2018/09/25  Problem: yukicoder 279  / Link: http://yukicoder.me/problems/no/279  ----- */
/* ------問題------

kamipeipaa君は木が大好きですが，今日は文字列で遊んでいます。
kamipeipaa君は文字列Sを並び替えたときに"tree"という部分文字列をいくつ作ることが可能か興味があります。教えてあげてください。

-----問題ここまで----- */
/* -----解説等-----

カウントする

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string s; cin >> s;
	auto f = [&](char in) {
		int ret = 0;
		for (auto c : s)
			if (c == in)ret++;
		return ret;
	};
	int ans = min({ f('t'),f('r'),f('e')/2 });
	cout << ans << "\n";

	return 0;
}
