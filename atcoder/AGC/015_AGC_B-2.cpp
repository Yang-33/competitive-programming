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

/* -----  2017/11/22  Problem: 015_agc_b / Link: https://agc015.contest.atcoder.jp/tasks/agc015_b?lang=en  ----- */
/* ------問題------

すけぬ君は、N 階建てのビルを建てました。ビルにはエレベーターが 1 基あり、すべての階に止まります。
すけぬ君は、各階に上下の方向ボタンを設置しましたが、うっかりしていたため、どの階にも上向きか下向きの片方のボタンしかありません。 そのため、どの階からも上か下のどちらかにしか進むことができません。 Si が U のとき i 階には上向きのボタンしかなく、上にしか進めないことを、D のとき下向きのボタンしかなく、 下にしか進めないことを表します。
ある階から目的の階へと移動したい住民は、仕方がないので必要があれば他の階を経由して目的の階へと向かうことにしました。 全ての階の順序対 (i,j) についての、i 階から j 階へ行くときのエレベーターに乗る回数の最小値の合計を求めてください。

-----問題ここまで----- */
/* -----解説等-----

そのまま行けるときは行ける階の数、
行けないときは2手あればいけるので、これをそのまま書く。

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);


	string S; cin >> S;
	N = SZ(S);
	FOR(i, 0, N) {
		if (S[i] == 'U')ans += N - (i + 1), ans += 2 * i;
		else ans += i, ans += 2 * (N - (i + 1));
	}
	cout << ans << "\n";

	return 0;
}
