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
//#pragma GCC optimize ("-O3") 
#ifdef YANG33
#include "mydebug.hpp"
#else
#define DD(x) 
#endif
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/12/21  Problem: codefestival2015_team_relay I / Link: __CONTEST_URL__  ----- */
/* ------問題------

最近ある街の若者の間では Platoon Match （小隊バトル） というハイカラな遊びが流行っている。 水鉄砲を携えレインコートに身を包み、フィールド内を駆け回って敵に水を当てた回数を競うチーム戦である。
以下に詳細なルールを記す。まず N 人の参加者が（人数が均等とは限らない） 2 つのチームに分かれる。全員それぞれのチームの本陣から一斉に出発し、用意されたフィールド内を移動して敵チームのメンバーに水鉄砲を当てることを目指す。ゲーム中に敵チームのメンバーに水鉄砲で撃たれた人は一時的にゲームから抜け、即座に自分のチームの本陣に戻って再びゲームに参加する。ゲーム終了時にそれぞれの参加者は自分が敵に撃たれた回数と敵を撃った回数を自己申告し、ゲームの勝敗を決定する。
さて、あなたはこれまでの Platoon Match の記録を取っていたのだが、それぞれのゲームのチーム分けを記録し忘れており、各参加者が何回撃ったか・撃たれたかしか分からないようになっていた。そもそもこの記録はつじつまが合っているのだろうか？ひとまずあなたは記録されている各参加者の成績を実現するようなチーム分けが存在するかどうか確かめることにした。

-----問題ここまで----- */
/* -----解説等-----

無限時間かかった。これ系に気づくのにムラがありすぎる。
\sum_X a = \sum_{S\setminus X} b \wedge \sum_X b = \sum_{S\setminus X} a となりうるかを判定する。
左側の式について、\sum_X a = \sum_{S} b - \sum_{X} bであり、移項して
\sum_X (a+b) = \sum_{S} b となる。したがってこれを判定すればよく、
これは部分和DPをすればよいだけである。

----解説ここまで---- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; cin >> N;
	VL a(N), b(N);
	FOR(i, 0, N) {
		cin >> a[i] >> b[i];
	}
	LL Asum = accumulate(ALL(a), 0LL);
	LL Bsum = accumulate(ALL(b), 0LL);

	if (Asum != Bsum) {
		cout << "invalid" << endl;
	}
	else {
		VL c(N);
		FOR(i, 0, N) {
			c[i] = a[i] + b[i];
		}
		VL dp(80004, 0);
		dp[0] = 1;
		FOR(i, 0, N) {
			FORR(k, 80000 - c[i], 0 - 1) {
				dp[k + c[i]] |= dp[k];
			}
		}
		bool f = dp[Bsum];
		cout << (f ? "valid" : "invalid") << endl;

	}
	return 0;
}