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
#define debug(x) cout << #x << ": " << x << endl
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000009;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2017/11/02  Problem: yukicoder189 / Link: https://yukicoder.me/problems/no/189  ----- */
/* ------問題------

ある日、新しい暦「おたく暦」が採用されることになりました。
おたく暦は1年をMヶ月、1ヶ月をD日とする暦です。
例えばMとDがそれぞれ2と3であったとき、1年は1月1日、1月2日、1月3日、2月1日、2月2日、2月3日の6日間で構成されます。現在は最適なMMとDDが検討されています。

XX月YY日についてXXの数字和とYYの数字和が等しいとき、XX月YY日は"SUPER HAPPY DAY"と呼ばれます。
ここで数字和とは与えられた整数の各桁の数字が表す数の総和です。
例えば4月22日、10月1日、121月2020日は4=2+2、1+0=1、1+2+1=2+0+2+0となりSUPER HAPPY DAYです。
一方、4月5日や10月19日、1234月123450日は4≠54≠5、1+0≠1+9、1+2+3+4≠1+2+3+4+5+0となり、SUPER HAPPY DAYではありません。

kamipeipaa君はおたく暦のMMとDDが定まったとき，1年間にどれだけSUPER HAPPY DAYがあるか気になっています。
kamipeipaa君のために1年間に含まれるSUPER HAPPY DAYの数をmod 1000000009で求めてください。

-----問題ここまで----- */
/* -----解説等-----

桁DP。
先のことから使いまわしのプロになったので、
dp[i番目を今見ている][あとどれだけの値をもっているか][less?]:=桁和sumとなる総数
として、sumは全体で9*201=1809なのでこれは全探索によって総数が取れる。
sum-nxが負になったら人生終了することぐらいわかるよね・・・時間が溶けた

----解説ここまで---- */

LL N;

LL ans = 0LL;

LL dp[202][1900][2];

LL f(string &target, int i, int sum, int less = 0) {
	if (i == -1) {
		assert(sum >= 0);
		return (sum == 0);
	}
	if (dp[i][sum][less] != -1 && less == 1)return  dp[i][sum][less];

	LL res = 0;
	int num = target[i] - '0';
	int Max = less ? 9 : num;
	FOR(nx, 0, Max + 1) {
		if (sum - nx < 0)break;
		res += f(target, i - 1, sum - nx, less | (nx < Max));
		//debug(res);
//		res = (res + MOD) % MOD;
	}
	if (less == 1)return dp[i][sum][less] = res%MOD;
	return res%MOD;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	string M, D;
	cin >> M >> D;
	reverse(ALL(M));
	reverse(ALL(D));
	fill(**dp, **dp + 202 * 1900 * 2, -1);
	FOR(sum, 1, 1809 + 1) {
		(ans += f(M, SZ(M) - 1, sum)*f(D, SZ(D) - 1, sum))%=MOD ;
	}
	cout << ans << "\n";

	return 0;
}
