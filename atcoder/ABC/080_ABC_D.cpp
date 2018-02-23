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

/* -----  2018/02/23  Problem: 080_abc_d / Link: https://abc080.contest.atcoder.jp/tasks/abc080_d?lang=en  ----- */
/* ------問題------

joisinoお姉ちゃんは、録画機を用いて N 個のテレビ番組を録画しようとしています。
テレビが受信できるチャンネルは C 個あり、1 から C までの番号がついています。
joisinoお姉ちゃんの録画したいテレビ番組のうち、i 個目のテレビ番組は、時刻 si から時刻 ti まで、チャンネル ci で放送されます。(ただし時刻 si を含み、時刻 ti を除く)
ただし、同じチャンネルで複数のテレビ番組が同時に放送されることはありません。
また、録画機は、あるチャンネルの時刻 S から時刻 T までを録画するとき、時刻 S−0.5 から時刻 T までの間、他のチャンネルの録画に使うことができません。(ただし時刻 S−0.5を含み、時刻 T を除く)
N 個のテレビ番組の全ての放送内容が含まれるように録画するとき、必要な録画機の最小個数を求めてください。

-----問題ここまで----- */
/* -----解説等-----

同じチャンネルは一回ということに注意して適当にimos法で区間を管理する。
また埋める区間は[2s-1,2t)

----解説ここまで---- */

LL N,C;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N>>C;
	VVI m(C, VI(2e5 + 10, 0));
	FOR(i, 0, N) {
		int s, t, c;
		cin >> s >> t >> c;
		m[c - 1][2*s-1]++;
		m[c - 1][2*t]--;
	}
	FOR(i, 0, C) {
		FOR(j, 0, 2e5) {
			m[i][j + 1] += m[i][j];
		}
	}
	FOR(i, 0, C) {
		FOR(j, 0, 2e5) {
			if (m[i][j])m[i][j] = 1; // 同じチャンネルは一回
		}
	}
	FOR(i, 0, 2e5) {
		LL cnt = 0;
		FOR(c, 0, C) {
			cnt += m[c][i];
		}
		ans = max(ans, cnt);
	}
	cout << ans << "\n";

	return 0;
}
