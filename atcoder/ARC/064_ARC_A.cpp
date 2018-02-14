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

/* -----  2018/02/14  Problem: 064_arc_a / Link: https://abc048.contest.atcoder.jp/tasks/arc064_a?lang=en  ----- */
/* ------問題------

N 個の箱が横一列に並んでいます。 最初、左から i 番目の箱には ai 個のキャンディが入っています。
すぬけ君は次の操作を好きな回数だけ行うことができます。
キャンディが 1 個以上入っている箱をひとつ選び、その箱のキャンディを 1 個食べる。
すぬけ君の目標は次の通りです。
どの隣り合う 2 つの箱を見ても、それらの箱に入っているキャンディの個数の総和が x 以下である。
目標を達成するために必要な操作回数の最小値を求めてください。

-----問題ここまで----- */
/* -----解説等-----

右側を調整することによって次回取らなくてもいい可能性が出るので、右側を貪欲に取れば良い。

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int X;

	cin >> N>>X;
	VL a(N);
	FOR(i, 0, N) {
		cin >> a[i];
	}
	FOR(i, 0, N - 1) {
		LL sum = a[i] + a[i + 1];
		if (sum >= X) {
			LL ne = sum - X;
			ans += ne;
			if (ne > a[i + 1]) {
				a[i+1] = 0;
			}
			else a[i + 1] -= ne;
		}
	}
	cout << ans << "\n";

	return 0;
}
