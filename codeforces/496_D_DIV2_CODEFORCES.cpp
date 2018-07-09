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

/* -----  2018/07/10  Problem: CodeForces496 D div2 / Link: http://codeforces.com/contest/1005/problem/D  ----- */
/* ------問題------

列に対して適当な区切りを入れる。2321->|2|3|21|
||の間に3の倍数がある時嬉しい。3の倍数の個数は最大何個取れるか。

-----問題ここまで----- */
/* -----解説等-----

(さいごまで良い結果がわからないことが自明なので)DP.
少なくとも3の倍数になったときに分けるのが最適。
dp[i][k]:= ithまでみて、あまりがkであるようなときの3の倍数の最大数
としてdpする。
数をあわせながらやったので編集距離みたいなdpになってしまった。


----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL ans = 0;

	string s;
	cin >> s;
	VVL dp(SZ(s) + 1, VL(3, 0));
	dp[0][0] = 1;
	FOR(i, 0, SZ(s)) {
		int ss = s[i] - '0';
		ss %= 3;
		dp[i + 1][ss] = max({ dp[i][0], dp[i][1], dp[i][2] })+(ss==0);
		FOR(x, 0, 3) {
			if (dp[i][x] == 0)continue;
			int nx = x + (s[i] - '0');
			nx %= 3;
			dp[i + 1][nx] =max(dp[i + 1][nx], dp[i][x]+(nx==0));
		}
	}
	int N = SZ(s);
	//FOR(i, 0, N) {
	//	FOR(j, 0, 3) {
	//		cout << dp[i + 1][j] << " ";
	//	}cout << endl;
	//}
	FOR(i, 0, 3) {
		ans = max(dp[N][i], ans);
	}
	ans -= 1;
	cout << ans << "\n";

	return 0;
}
