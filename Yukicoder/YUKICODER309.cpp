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

/* -----  2018/09/30  Problem: yukicoder 309  / Link: http://yukicoder.me/problems/no/309  ----- */
/* ------問題------

匿名希望さんが講演している時，倉敷市が何県の都市か分かる人挙手と言ったところ，3～4 割の人しか手を挙げないという事件がありました．
倉敷市といえば，白壁が綺麗な美観地区に大原美術館もある，倉敷うどんのふるいちもある，チボリ公園は潰れてショッピングモールになりました．
とにかく，観光的にも人気スポットで，気候もとても住みやすいことで有名であります．
知名度がこんなに低い訳はないのですが，残念ながら聴衆は競技プログラミング勢であり，シャイな人が多かったため，知っていても手を挙げなかったと思われます．
それを確かめるために簡単なモデルで実験してみましょう．
シャイな人は，周りの人が手を挙げてなければ手を挙げづらいという心理が働くと考えられるので，それをモデル化したものです．
R 行 C 列の席があり，全ての席が聴衆で埋まっているとします．
講演は上で行われているとして，上から i 行目，左から j 列目の人を (i,j) と書きます．
人 (i,j) が倉敷市が何県の都市か知っている確率を Pi,j/100，つまり，Pi,j% とし，各人が倉敷市が何県か知ってるかどうかは独立の事象とします．
また，各人 (i,j) に対して，その人のシャイ度に対するパラメータ Si,j∈{0,1,2,3,4} が与えられます．
聴衆が手を挙げるかどうかは以下のメカニズムによって決定されることにしましょう．
最初，全ての人が持つポイントは 0 で，自分が持つポイントが 4 以上になった瞬間に手を挙げ，挙げ続けます．
もし，人 (i,j) が倉敷市が何県の都市か知っている場合は，その人は 4−Si,j ポイントを得ます．
人 (i,j) は自分の前 (i−1,j)，左 (i,j−1)，右 (i,j+1) の人のそれぞれが手を挙げた瞬間に，その人 (i,j) は 1 ポイントを得ます．
つまり，前，左右の人の全てが手を挙げた場合，合計で 3 ポイントが得られます．
前，左右に人がいない場合は，その分のポイントは得られないことに注意してください．
さて，このとき，最終的に何人の人が手を挙げるのか，期待値を求めるプログラムを書いてください．

-----問題ここまで----- */
/* -----解説等-----

まず、ある列の状態を求める際に上と現在列にしか左右されない。
更に、事象が独立かつ左右からの伝播があるので全部調べないとだめ。
したがって上と現在の列を全列挙したbitdpが必要。
これをやっていけばよい。https://kimiyuki.net/writeup/algo/yukicoder/309/
をします。

----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int H, W; cin >> H >> W;
	vector<vector<double>>P(H, vector<double>(W));
	FOR(i, 0, H) {
		FOR(j, 0, W) {
			cin >> P[i][j];
			P[i][j] /= 100.0;
		}
	}
	VVI S(H, VI(W));
	FOR(i, 0, H) {
		FOR(j, 0, W) {
			cin >> S[i][j];
		}
	}

	vector<vector<double>>dp(H + 1, vector<double>(1 << W, 0));

	dp[0][0] = 1;
	FOR(i, 0, H) {
		FOR(state, 0, 1 << W) {
			double p = 1;
			FOR(j, 0, W) {
				if (state & 1 << j) {
					p *= P[i][j];
				}
				else {
					p *= 1 - P[i][j];
				}
			}
			// 現在の列がstateであるような確率pは分かっている

			auto ok = [](int s, int k) {
				return s & 1 << k;
			};
			FOR(pre, 0, 1 << W) {
				if (dp[i][pre] < 1e-12)continue;
				int upstate = 0;
				FOR(j, 0, W) {
					if (S[i][j] == 0 && ok(state, j))upstate |= 1 << j;
					if (S[i][j] == 1 && ok(state, j) && ok(pre, j))upstate |= 1 << j;
				}
				FOR(j, 1, W) {
					if (S[i][j] == 1 && ok(state, j) && ok(upstate, j - 1))upstate |= 1 << j;
					if (S[i][j] == 2 && ok(state, j) && ok(pre, j) && ok(upstate, j - 1))upstate |= 1 << j;
				}

				FORR(j, W - 2, 0 - 1) {
					if (S[i][j] == 1 && ok(state, j) && ok(upstate, j + 1))upstate |= 1 << j;
					if (S[i][j] == 2 && ok(state, j) && ok(pre, j) && ok(upstate, j + 1))upstate |= 1 << j;
				}
				FORR(j, W - 2, 0) {
					if (S[i][j] == 2 && ok(state, j) && ok(upstate,j-1) && ok(upstate, j + 1))upstate |= 1 << j;
					if (S[i][j] == 3 && ok(state, j) && ok(pre, j) && ok(upstate, j - 1) && ok(upstate, j + 1))upstate |= 1 << j;
				}


				dp[i + 1][upstate] += p * dp[i][pre];
			}
		}
	}
	double ans = 0;

	FOR(i, 0, H) {
		FOR(state, 0, 1 << W) {
			ans += __builtin_popcount(state)*dp[i + 1][state];
		}
	}

	cout << fixed << setprecision(10) << ans << "\n";

	return 0;
}
