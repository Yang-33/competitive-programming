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

/* -----  2018/08/27  Problem: yukicoder 258  / Link: http://yukicoder.me/problems/no/258  ----- */
/* ------問題------

あなたは、回転寿司にきている。
お寿司はN皿が順番に流れてくる。N皿のお寿司のそれぞれの美味しさがViで表される。

流れてくるお寿司が自分の前に来た時に取ることができるが、このお店のルールで、
連続で皿を取ることが出来ない。
もちろん、自分の前を過ぎたお寿司も取ることが出来ない。

この時、あなたが得られる美味しさの最大の合計値と取ったお皿の番号（1から始まる番号）を昇順に求めてください。
お寿司は一周回ってくることはないとする。

-----問題ここまで----- */
/* -----解説等-----

dpの復元。最小に持ってくる方法はわからない。

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;
	VI a(N);
	FOR(i, 0, N) {
		cin >> a[i];
	}
	VVI dp(N + 1, VI(2, 0));
	FOR(i, 0, N) {
		dp[i + 1][1] = max(dp[i + 1][1], dp[i][0] + a[i]);
		dp[i + 1][0] = max({ dp[i + 1][0],dp[i][0],dp[i][1] });
	}
	int ans = max(dp[N][0], dp[N][1]);
	cout << ans << "\n";
	// 復元
	VI ids;
	for (int i = N; ;) {
		if (ans == dp[i-1][0] + a[i-1]) {
			ids.push_back(i-1);
			ans -= a[i-1];
			i--;
		}
		if (ans == 0)break;
		else i--;
	}
	SORT(ids);
	FOR(i, 0, SZ(ids)) {
		cout << ids[i]+1 << " \n"[i == SZ(ids) - 1];
	}





	return 0;
}
