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
#define debug(x) cerr << #x << ": " << x << endl
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/09/19  Problem: yukicoder 264  / Link: http://yukicoder.me/problems/no/264  ----- */
/* ------問題------

自分と相手がじゃんけんをする。
じゃんけんの結果を標準出力に出力してください。
結果は、自分が勝ったら「Won」、自分が負けたら「Lost」、引き分けなら「Drew」を出力してください。

-----問題ここまで----- */
/* -----解説等-----

じゃんけんの表は斜めに結果があるので、45度回転させれば簡単。

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N, K; cin >> N >> K;
	int ans = (N - K + 3) % 3;
	string Shadowverse[3] = { "Drew","Lost","Won" };
	cout << Shadowverse[ans] << "\n";

	return 0;
}