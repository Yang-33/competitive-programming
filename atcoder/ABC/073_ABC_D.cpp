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

/* -----  2017/10/04  Problem: Nagoya_univ_contest_17_e  / Link: https://agc019.contest.atcoder.jp/tasks/agc019_a  ----- */
/* ------問題------

あなたは行きつけの店、インフバリューにアイスティーを買いに来ています。
この店では、様々なサイズのボトル入りアイスティーが様々な価格で売られています。
具体的な価格は、0.25 リットルサイズが一つ Q 円、0.5 リットルサイズが一つ H 円、1 リットルサイズが一つ S 円、2 リットルサイズが一つ D 円です。各サイズの在庫は無限にあります。
あなたはちょうど N リットルのアイスティーを買いたいです。これに必要な金額は何円でしょうか？

-----問題ここまで----- */
/* -----解説等-----

1L,2Lで最適なものを先に作っておけばよい
Nが奇数のときは1Lを買わなくてはならないが、それ以外は2Lの最適値でOK

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	VL a(4);
	FOR(i, 0, 4) {
		cin >> a[i];
	}
	cin >> N;
	LL one = LINF;
	LL two = LINF;
	one = min({ one,a[0] * 4LL,a[1] * 2LL,a[2] });
	two = min(one * 2, a[3]);
	if (N % 2 == 1)ans = N / 2 * two + one;
	else ans = N / 2 * two;
	cout << ans << "\n";

	return 0;
}