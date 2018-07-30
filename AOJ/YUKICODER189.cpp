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
const LL MOD = 1000000009;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/07/30  Problem: yukicoder 189  / Link: http://yukicoder.me/problems/no/189  ----- */
/* ------問題------

ある日、新しい暦「おたく暦」が採用されることになりました。おたく暦は1年をMヶ月、1ヶ月をD日とする暦です。例えばMとDがそれぞれ2と3であったとき、1年は1月1日、1月2日、1月3日、2月1日、2月2日、2月3日の6日間で構成されます。現在は最適なMとDが検討されています。

X月Y日についてXの数字和とYの数字和が等しいとき、X月Y日は"SUPER HAPPY DAY"と呼ばれます。ここで数字和とは与えられた整数の各桁の数字が表す数の総和です。例えば4月22日、10月1日、121月2020日は4=2+2、1+0=1、1+2+1=2+0+2+0となりSUPER HAPPY DAYです。一方、4月5日や10月19日、1234月123450日は4≠5、1+0≠1+9、1+2+3+4≠1+2+3+4+5+0となり、SUPER HAPPY DAYではありません。

kamipeipaa君はおたく暦のMとDが定まったとき，1年間にどれだけSUPER HAPPY DAYがあるか気になっています。kamipeipaa君のために1年間に含まれるSUPER HAPPY DAYの数をmod 1000000009で求めてください。

-----問題ここまで----- */
/* -----解説等-----

桁DPをする。dp[i][sum]:= ith桁について、その総和がsumになる組み合わせ数
これを求めて、dp[i][sum](D)*dp[i][sum](M)についてもとめればよい。

唐突なおたく暦すこすこのすこ

----解説ここまで---- */

LL dp[202][1810];

LL f(const string& s, int i, int sum, bool less) {
	if (i == -1) {
		return sum == 0;
	}
	if (less&&dp[i][sum] != -1) {
		return dp[i][sum];
	}
	LL ret = 0;
	int num = s[i] - '0';
	int Max = less ? 9 : num;
	FOR(nx, 0, Max + 1) {
		if (sum - nx < 0)continue;
		ret += f(s, i - 1, sum - nx, less || (nx < Max)) % MOD;
		ret %= MOD;
	}

	if (less)return dp[i][sum] = ret;
	return ret;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);


	string M, D; cin >> M >> D;
	reverse(ALL(M)), reverse(ALL(D));
	fill(*dp, *dp + 202 * 1810, -1);
	LL ans = 0;
	FOR(i, 1, 1810) {
		ans += f(M, SZ(M) - 1, i, 0)*f(D, SZ(D) - 1, i, 0);
		ans %= MOD;
	}

	cout << ans << "\n";

	return 0;
}
