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

/* -----  2018/04/15  Problem: yukicoder 070  / Link: http://yukicoder.me/problems/no/070  ----- */
/* ------問題------

太郎君は健康のために、毎日、寝た時刻と起きた時刻の記録をとっています。
入力に、寝た時刻と起きた時刻のリストが与えられるので、
睡眠時間の合計を出力してください。
太郎君は、1回につき24時間以上眠り続けることは無いものとします。
太郎君の世界は1日あたり24時間、1時間は60分で表されます。

-----問題ここまで----- */
/* -----解説等-----

24時間以上寝ることは無いので起床時間を大きくして計算をすると楽です。

----解説ここまで---- */
LL N;

LL ans = 0LL;

int main() {
	cin >> N;
	FOR(i, 0, N) {
		int H, M, h, m;
		scanf("%d:%d %d:%d", &H, &M, &h, &m);
		int rising = (60 * (h + 24) + m );
		int bed = 60 * H + M;
		ans += (rising - bed) % 1440;
	}
	cout << ans << "\n";

	return 0;
}
