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

/* -----  2018/09/27  Problem: yukicoder 287  / Link: http://yukicoder.me/problems/no/287  ----- */
/* ------問題------

nを1以上の整数とします。
a+b+c+d+e+f+g+h=6n を満たし、なおかつ、
0≤a≤n,
0≤b≤n,
0≤c≤n,
0≤d≤n,
0≤e≤n,
0≤f≤n,
0≤g≤n,
0≤h≤n
も満たすような整数の組(a,b,c,d,e,f,g,h)の個数G(n)を求めよ。

-----問題ここまで----- */
/* -----解説等-----

dp[i]:=総和がiとなるような組み合わせ数
として解ける。

----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N;  cin >> N;
	// 8つで6N,1つではnまで
	VL dp(6 * N + 1, 0);
	dp[0] = 1;
	FOR(i, 0, 8) {
		VL nx(6 * N + 1, 0);
		FOR(j, 0, 6 * N + 1) {
			FOR(add, 0, N + 1) {
				if (j + add > 6 * N)break;
				nx[j+add] += dp[j];
			}
		}
		nx.swap(dp);
	}
	ans = dp[6 * N];
	cout << ans << "\n";

	return 0;
}
