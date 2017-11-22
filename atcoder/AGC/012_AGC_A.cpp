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

/* -----  2017/11/22  Problem: 012_agc_a / Link: https://agc012.contest.atcoder.jp/tasks/agc012_a?lang=en  ----- */
/* ------問題------

AtCoder Group Contestの参加者に 3N 人が参加します。 i 番目の参加者の 強さ は整数 ai で表されます。 参加者が 3 人 1 組となるようにチームを N 組作ることにしました。1 人の参加者が複数のチームに所属することはできません。
チームの強さはチームメンバーの強さのうち 2 番目に大きい値で表されます。 例えば、強さが 1,5,2 のメンバーからなるチームの強さは 2 になり、強さが 3,2,3 のメンバーからなるチームの強さは 3 になります。
N 組のチームの強さの和としてありうる値のうち、最大の値を求めてください。

-----問題ここまで----- */
/* -----解説等-----

最大から上から二番目のものをとっていけばよい。

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	N *= 3;
	VL a(N);
	FOR(i, 0, N) { cin >> a[i]; }
	SORT(a);
	int cnt = 0;
	for (int i = N - 2; cnt<N/3; i -= 2) {
		ans += a[i];
		cnt++;
	}
	cout << ans << "\n";

	return 0;
}
