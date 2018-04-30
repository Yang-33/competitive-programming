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

/* -----  2018/04/27  Problem: AOJ 2182 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2182  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

dp[i][eleven]:=i番目までの数を使ったときに、あまりがeleven%11となるような数字の組数
なんかmapで累積和dpもできる気がする(区間LR選択みたいに)

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string s;
	while (cin >> s, s != "0") {
		ans = 0;
		N = SZ(s);
		VVL dp(N + 1, VL(11, 0));
		FOR(i, 0, N) {
			int num = s[i] - '0';

			if (num)dp[i + 1][num]++;

			FOR(j, 0, 11)
				dp[i + 1][(10 * j + num) % 11] += dp[i][j];
		}
		FOR(i, 1, N + 1) {
			ans += dp[i][0];
		}


		cout << ans << "\n";
	}


	return 0;
}
