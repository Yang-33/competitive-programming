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

/* -----  2017/11/11  Problem: ABC 085 A / Link: http://arc085.contest.atcoder.jp/tasks/arc085_a  ----- */
/* ------問題------

高橋くんはプログラミングコンテストに出ていますが， YES か NO で答える問題でTLEしてしまいました。
提出の詳細を見ると，テストケースは全てでN ケースあり，そのうちM ケースでTLEしていました。
そこで高橋くんは,M ケースではそれぞれ実行に1900 ms かかって1/2 の確率で正解し， 残りのN−M ケースではそれぞれ実行に100 ms かかって必ず正解するプログラムへ書き換えました。
そして，以下の操作を行います。このプログラムを提出する。全てのケースの実行が終わるまで待機する。
もしM ケースのうちどれかで不正解だった場合，もう一度プログラムを提出する。これを，一度で全てのケースに正解するまで繰り返す。
この操作が終了するまでの，プログラムの実行時間の総和の期待値をX msとした時，X を出力してください。
なお，X は整数で出力してください。

-----問題ここまで----- */
/* -----解説等-----

期待値の確率は収束したとき逆数の絶対値になるため、できる

----解説ここまで---- */

LL N,M;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> N>>M;
	cout << (M * 1900 + (N - M) * 100)*pow(2, M) << endl;


	return 0;
}
