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

/* -----  2018/08/25  Problem: yukicoder 242  / Link: http://yukicoder.me/problems/no/242  ----- */
/* ------問題------

5×5マスの描かれたカードを使ってビンゴゲームをやります。
カードの25つのマスには1から99の数字のうち25つが重複せずに書かれています。
縦、横、斜めのいずれかで5つの数字が1列揃うと1つのビンゴです。

A君はランダムに数字の書かれたビンゴカードを渡されました。
これから1から99の数字のうちN個がランダムで重複せず読み上げられます。
N個の数字が読み上げられた後に、できたビンゴの数の期待値はいくつか。

-----問題ここまで----- */
/* -----解説等-----

大変難しい
ビンゴであることにとらわれずに列にある数字が選択される確率を求める。
(nC5)/(99C5)である。
ビンゴの列は12個あるので、期待値の線形性から12倍すればよい。

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;

	double ret = 1.;
	FOR(i, 0, 5) {
		ret *= (N - i) / (99.0 - i);
	}
	double ans = 12 * ret;
	cout << fixed << setprecision(10) << ans << "\n";

	return 0;
}
