#include <bits/stdc++.h>
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

/* -----  2018/04/09  Problem: yukicoder 027  / Link: http://yukicoder.me/problems/no/027  ----- */
/* ------問題------

異なる3種類の長さA、B、Cの板を無数に用意できる。
A、B、Cは整数の値で自由に決めて良い。
板と板はつなげて伸ばすことができる。
指定されたV0、V1、V2、V3の長さの板を作りたい。
最低何枚の板が必要か？

-----問題ここまで----- */
/* -----解説等-----

dp(i) :=三種類の板を使用してiの長さの板を作るために必要な最小枚数　とする。
一様にやるDPでこれは更新できて、あとは三種類の板を全探索すれば良い。

----解説ここまで---- */

LL N;


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	VI v(4);
	FOR(i, 0, 4) {
		cin >> v[i];
	}
	int ans = INF;
	FOR(a, 1, 31) {
		FOR(b, a, 31) {
			FOR(c, b, 31) {
				VI dp(70, INF);
				dp[0] = 0;
				FOR(i, 0, 30) {
					dp[i + a] = min(dp[i + a], dp[i] + 1);
					dp[i + b] = min(dp[i + b], dp[i] + 1);
					dp[i + c] = min(dp[i + c], dp[i] + 1);
				}
				int f = 1;
				int ret = 0;
				FOR(i, 0, 4) {
					if (dp[v[i]]!=INF && dp[v[i]]) {
						ret += dp[v[i]];
					}
					else f = 0;
				}
				if (f) {
					ans = min(ans, ret);
				}
			}
		}
	}
	cout << ans << "\n";

	return 0;
}
