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
//#pragma GCC optimize ("-O3") 
#ifdef YANG33
#include "mydebug.hpp"
#else
#define DD(x) 
#endif
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/10/24  Problem: ARC 036 A / Link: http://arc036.contest.atcoder.jp/tasks/arc036_a  ----- */
/* ------問題------

高橋くんはこれから N 日間の睡眠の予定を建てることにしました。 i 日目には ti 分だけ寝る予定です。
また、高橋くんは連続した 3 日間の睡眠時間の合計が K 分を下回ると、その連続した3日目に睡眠不足になります。 厳密に言うと、 x≧3 のとき x−2 日目、 x−1 日目、 x 日目の睡眠時間の合計が K を下回ると、 x 日目に睡眠不足になります。 合計がちょうど Kになった場合は睡眠不足になりません。
あらかじめ高橋くんの睡眠の予定を与えるので、高橋くんが睡眠不足になるかどうかを求めてください。 もし睡眠不足になるならば、何日目に睡眠不足になるか求めてください。 答えが複数通り考えられるならば、最初に睡眠不足になる日を求めてください。
高橋くんは 1 日目と 2 日目には睡眠不足にならないものとします。 また、高橋くんは昼寝しかしないので、睡眠により日をまたぐことは考えなくて良いです。

-----問題ここまで----- */
/* -----解説等-----

シュミレーションをすればよい。

----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, K; cin >> N >> K;
	VI t(N);

	FOR(i, 0, N) {
		cin >> t[i];
	}
	int ans = -1;
	int sum = t[0] + t[1] + t[2];
	FOR(i, 3, N) {
		if (sum < K) {
			ans = i ;
			break;
		}
		sum -= t[i - 3];
		sum += t[i];
	}
	cout << ans << "\n";

	return 0;
}
