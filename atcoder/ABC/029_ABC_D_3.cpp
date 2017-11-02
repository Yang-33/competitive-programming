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

/* -----  2017/11/01  Problem: ketadp4 / Link: http://abc029.contest.atcoder.jp/tasks/abc029_d  ----- */
/* ------問題------

高橋君は 1 以上 N 以下のすべての整数を十進表記で一回ずつ紙に書きました。
この作業で、高橋君は 1 という数字を何個書いたでしょうか。

-----問題ここまで----- */
/* -----解説等-----

たのちい！
ボトムアップで書き直した

----解説ここまで---- */

LL N;

LL ans = 0LL;
LL dp[11][11][2];
LL f(string &target, int i, int cnt = 0, int less = 0) {
	if (-1 == i) {
		return cnt;
	}

	if (dp[i][cnt][less] != -1 && less == 1)return  dp[i][cnt][less];
	LL res = 0;

	int num = target[i] - '0';
	int Max = less ? 9 : num;
	FOR(nx, 0, Max + 1) {
		res += f(target, i - 1, cnt + (nx == 1), less | (nx<Max));
	}
	if (less == 1)return  dp[i][cnt][less] = res;
	return res;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	string S = to_string(N);
	fill(**dp, **dp + 11 * 11 * 2, -1);
	reverse(ALL(S));
	ans = f(S, SZ(S) - 1);
	cout << ans << "\n";

	return 0;
}
