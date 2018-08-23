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

/* -----  2018/08/23  Problem: yukicoder 220  / Link: http://yukicoder.me/problems/no/220  ----- */
/* ------問題------

1以上10P以下の整数のうち、3の倍数および3の付く数の個数を出力してください。
なお、ある数が3の倍数かつ3の付く数であるとき、その数は1つと数えます。
また、「3の付く数」とは、10進数表記にした時、少なくとも1つの桁が3であるような数のことです。

-----問題ここまで----- */
/* -----解説等-----

桁DP
dp[i番目の桁を今見ている][3の倍数か][3を数字に持っているか][less?]:=総数
として再帰をすればよい。
0も含まれてしまうのでこれだけとりのぞけばよい
一応テンプレ式で書いた。

----解説ここまで---- */


LL dp[20][3][2][2];
LL f(string &s, int i, int three, bool has, bool less) {
	if (i < 0)return has || three == 0;
	if (dp[i][three][has][less] != -1)return dp[i][three][has][less];

	LL ret = 0;
	int Mx = (less ? 9 : s[i] - '0');
	FOR(nx, 0, Mx + 1) {
		ret += f(s, i - 1, (three + nx) % 3, has || nx == 3, less || nx < Mx);
	}

	return dp[i][three][has][less] = ret;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	fill(***dp, ***dp + 20 * 12, -1);
	int n; cin >> n;
	string s = string(1, '1') + string(n, '0');
	reverse(ALL(s));
	cout << f(s, SZ(s) - 1, 0, 0, 0) - 1 << endl;

	return 0;
}
