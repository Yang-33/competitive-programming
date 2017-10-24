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

/* -----  2017/10/23  Problem: nu_1  / Link:  http://joi2007ho.contest.atcoder.jp/tasks/joi2007ho_a ----- */
/* ------問題------

n 個の整数からなる数列 a1, a2, ..., an と正整数 k (1 5 k 5 n) が与えられる．この
とき，連続して並ぶ k 個の整数の和　 Si = ai +ai+1 +...+ai+k−1 (1 5 i 5 n−k + 1)
の最大値を出力するプログラムを作りなさい．

-----問題ここまで----- */
/* -----解説等-----

累積和的なノリをやります。

----解説ここまで---- */

LL N,K;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N>>K;
	VL a(N);
	LL ret = 0;
	FOR(i, 0, N) {
		cin >> a[i];
		if (i < K) {
			ret += a[i];
		}
		else {
			ans = max(ret, ans);
			ret -= a[i - K];
			ret += a[i];
			ans = max(ans, ret);
		}
	}
	cout << ans << "\n";

	return 0;
}
