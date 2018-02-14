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

/* -----  2018/02/14  Problem: 062_arc_b / Link: https://arc062.contest.atcoder.jp/tasks/arc062_b?lang=en  ----- */
/* ------問題------

シカのAtCoDeerくんは友達のTopCoDeerくんとあるゲームをして対戦しています。 
このゲームは N ターンからなります。各ターンではそれぞれのプレイヤーはじゃんけんのグーかパーを出します。
ただし、各プレイヤーは次の条件を満たす必要があります。
(※) 各ターンの後で、(今までにパーを出した回数)≦(今までにグーを出した回数)　を満たす

このゲームでの各プレイヤーの得点は、(勝ったターンの数) − (負けたターンの数) です。
AtCoDeerくんは特殊能力を持っているので、ゲームが始まる前にTopCoDeerくんの出す N ターンの手を全て知ることが出来ました。
AtCoDeerくんの各ターンでの手を決めて、AtCoDeerくんの得点を最大化してください。 TopCoDeerくんの出す手の情報は文字列 s で与えられます。
s の i(1≦i≦N) 文字目が gのときは i ターン目でTopCoDeerくんがグーを出すことを、 pのときはパーを出すことを表します。

-----問題ここまで----- */
/* -----解説等-----

全部グーを出すとして、この時-p.size()点である。
ここからいくつか改善をするとする。
パーに変更することで必ず点数の改善が見込める。
したがってN-p.size(),p.size()の比率で勝敗が決まる。
得点はこの差であるから、N/2-p.size()が得点になる。

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string S;
	cin >>S;
	ans = SZ(S) / 2;
	FOR(i, 0, SZ(S)) {
		if (S[i] == 'p')
			ans--;
	}


	cout << ans << "\n";

	return 0;
}
