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

/* -----  2018/04/09  Problem: yukicoder 023  / Link: http://yukicoder.me/problems/no/023  ----- */
/* ------問題------

体力の初期値がHの敵を倒したい。
敵は体力が0以下になると倒せる。
攻撃方法は通常攻撃と必殺技の2通りがある。
通常攻撃は1回の攻撃でAのダメージを与える。
通常攻撃はかならず当たる。
必殺技は1回の攻撃でDのダメージを与える。
ただし、必殺技が当たる確率は2/3である。
必殺技は1/3の確率でダメージは0である。
最終的に敵を倒すまでの回数の期待値を
最小にするように攻撃を選んでいく。
敵を倒すまでの攻撃数の期待値はいくつか？

-----問題ここまで----- */
/* -----解説等-----

基本的なDP。dp(体力i):=iのダメージを与えるために必要な最小の期待値　とする。
期待値は確率の逆数でできるので、簡単な漸化式になる。

----解説ここまで---- */

LL N;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int H, A, D;
	cin >> H >> A >> D;
	vector<double> dp(H + 1, INF);
	dp[0] = 0;
	FOR(i, 0, H) {
		dp[min(i + A, H)] = min(dp[min(i + A, H)], dp[i] + 1);
		dp[min(i + D, H)] = min(dp[min(i + D, H)], dp[i] + 1.5);
	}
	double ans = dp[H];
	cout <<fixed<< setprecision(3)<<  ans << "\n";

	return 0;
}
