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

/* -----  2018/07/26  Problem: yukicoder 162  / Link: http://yukicoder.me/problems/no/162  ----- */
/* ------問題------

yuki君は毎年誕生日に歯科検診を受け、虫歯が見つかった場合その場で虫歯を抜くことにしている。
今日はyuki君のA歳の誕生日であり、歯科検診を受けたが、還暦を迎えても未だに虫歯が１本もない。
そのためyuki君の歯は（両端にある抜歯済みの親不知を除いて)上下それぞれ14本ずつ綺麗に並んでいる。

yuki君はふと病院のポスターにある「8020運動」という言葉が目に留まった。
80歳までに20本以上歯を残そうという運動だ。
ポスターを見たyuki君は、80歳の誕生日の歯科健診を終えたとき、何本歯が残るか気になった。

１年の間に虫歯が発生する確率は、磨きやすさや汚れやすさが変わるため直前の検診後(23:40追記)の左右の歯の有無により定まる。
現在の年齢と、虫歯が発生する確率が与えられるので、80歳の誕生日の歯科健診後に残っているyuki君の歯の本数の期待値を答えよ。

-----問題ここまで----- */
/* -----解説等-----

これ好き(3時間かかりました)
まず上下の歯は独立である。期待値の線形性から14本の場合を求めて2倍にすればよい
次に一本歯が死んだとする。左右の歯は独立になるので、細かい場合を計算しておけば良いことになる。
これはDPの気持ちになるがDPはわからないのでメモ化する

なんか3^nを感じ取ったけど3^nも通るらしい。(そう)

----解説ここまで---- */

// 期待値を返却
double dfs(int year, int tooth, const vector<double>& p, vector<vector<double>>& dp) {
	if (year == 0)return tooth;

	if (dp[year][tooth] > -0.5)return dp[year][tooth];
	dp[year][tooth] = 0;
	double ret = 0;
	if (tooth == 1) {
		ret = p[0] * 0 + (1 - p[0])*dfs(year - 1, tooth, p, dp);
	}
	else {
		FOR(state, 0, 1 << tooth) { // 歯が生き残る/生き残らない
			double sum = 0;
			double prob = 1;
			int cum = 0;
			FOR(i, 0, tooth + 1) {
				if (state & 1 << i) {// 俺は生えるぞ
					if (i == 0 || i == tooth - 1) {
						prob *= 1 - p[1];
					}
					else {
						prob *= 1 - p[2];
					}
					cum++;
				}
				else { // 悪い、俺死んだ
					if (i == 0 || i == tooth - 1) {
						prob *= p[1];
					}
					else if (i != tooth) {
						prob *= p[2];
					}
					if (cum) {
						sum += dfs(year - 1, cum, p, dp);
					}
					cum = 0;

				}
			}

			ret += prob*sum;
		}
	}


	return dp[year][tooth] = ret;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int A; cin >> A;
	vector<double> p(3);
	FOR(i, 0, 3)cin >> p[i], p[i] /= 100.0;

	int N = 80 - A;
	vector<vector<double>>dp(N + 1, vector<double>(14 + 1, -1));


	double ans = dfs(N, 14, p, dp) * 2;
	cout << fixed << setprecision(10) << ans << "\n";

	return 0;
}

