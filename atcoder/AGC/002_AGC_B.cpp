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

/* -----  2018/02/23  Problem: 002_agc_b / Link: https://agc002.contest.atcoder.jp/tasks/agc002_b?lang=en  ----- */
/* ------問題------

N 個の箱があります。 箱は 1 から N まで番号が振られています。 最初、1 番目の箱には赤いボールが 1 個入っています。 また、2～N 番目の箱には白いボールが 1 個ずつ入っています。
高橋君は M 回の操作を順に行います。 i 回目の操作では、xi 番目の箱から適当なボールを 1 個選び、それを yi 番目の箱へ移します。
高橋君がすべての操作を終えた後、赤いボールが入っている可能性のある箱は何個か求めてください。

-----問題ここまで----- */
/* -----解説等-----

赤を最後に残すような感じで赤を伝搬する。
これを実際にシュミレーションすれば良い。

----解説ここまで---- */

LL N, M;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	VI red(N, 0);
	red[0] = 1;
	VI ball(N, 1);
	FOR(i, 0, M) {
		int a, b; cin >> a >> b; a--, b--;
		if (red[a]) {
			if (ball[a] == 1) {
				ans--;
				red[a] = 0;
			}
			if (red[b] == 0)ans++;
			red[b] = 1;
		}
		ball[a]--;
		ball[b]++;
	}
	cout << ans + 1 << "\n";

	return 0;
}
