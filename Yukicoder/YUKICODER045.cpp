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

/* -----  2018/04/11  Problem: yukicoder 045  / Link: http://yukicoder.me/problems/no/045  ----- */
/* ------問題------

あなたは、回転寿司にきている。
お寿司はN皿が順番に流れてくる。N皿のお寿司のそれぞれの美味しさがViで表される。
流れてくるお寿司が自分の前に来た時に取ることができるが、このお店のルールで、
連続で皿を取ることが出来ない。
もちろん、自分の前を過ぎたお寿司も取ることが出来ない。

この時、あなたが得られる美味しさの最大の合計値を求めてください。
お寿司は一周回ってくることはないとする。

-----問題ここまで----- */
/* -----解説等-----

DP.
dp[i][0]:=i番目を食べないときの美味しさの合計の最大値
dp[i][1]:=i番目を食べる  ときの美味しさの合計の最大値
とすると簡単に遷移できる。

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	VI v(N);

	FOR(i, 0, N) {
		cin >> v[i];
	}
	VVL dp(N + 1, VL(2, 0));
	FOR(i, 0, N) {
		dp[i + 1][1] = max(dp[i + 1][1], dp[i][0] + v[i]);
		dp[i + 1][0] = max(dp[i + 1][0], dp[i][1]);
		dp[i + 1][0] = max(dp[i + 1][0], dp[i][0]);
	}
	ans = max(dp[N][0], dp[N][1]);

	cout << ans << "\n";

	return 0;
}
