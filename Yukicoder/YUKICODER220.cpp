#include "bits/stdc++.h"
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

/* -----  2017/11/02  Problem: yukicoder220 / Link: https://yukicoder.me/problems/no/220 ----- */
/* ------問題------

11以上10P以下の整数のうち、3の倍数および3の付く数の個数を出力してください。

なお、ある数が3の倍数かつ3の付く数であるとき、その数は1つと数えます。

また、「3の付く数」とは、10進数表記にした時、少なくとも1つの桁が3であるような数のことです。

-----問題ここまで----- */
/* -----解説等-----

桁DP
dp[i番目の桁を今見ている][3の倍数か][3を数字に持っているか][less?]:=総数
として再帰をすればよい。

----解説ここまで---- */


LL N;

LL ans = 0LL;
LL dp[20][3][2][2];
LL f(string &target, int i, int three = 0, int has = 0, int less = 0) {
	if (i == -1) {
		return (has||(three==0));
	}
	LL &res = dp[i][three][has][less];
	if (res != -1)return res;
	res = 0;
	int num = target[i] - '0';
	int Max = less ? 9 : num;
	FOR(nx, 0, Max + 1) {
		res += f(target, i - 1, (three + nx) % 3, has || (nx == 3), less || (nx < Max));
	}
	return res;
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int P;	cin >> P;
	string S = "1";
	FOR(i, 0, P)S += "0";
	reverse(ALL(S));
	fill(***dp, ***dp + 20 * 3 * 2 * 2, -1);
	ans = f(S, SZ(S) - 1);
	ans--;
	cout << ans << "\n";

	return 0;
}
