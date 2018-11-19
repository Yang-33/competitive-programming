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

/* -----  2018/11/19  Problem: ARC 052 D / Link: http://arc052.contest.atcoder.jp/tasks/arc052_d  ----- */
/* ------問題------

整数の 9 には面白い性質があります。 どのような非負整数 N を選んでも N を 9 で割った余りと、 N を 10 進法で表記した時の各桁の数字の和を 9 で割った余りが一致するのです。
高橋君はこのような性質を持つ整数が他にないか気になりました。しかし、残念なことにこのような性質をもつ整数は 9 と 3 と 1 くらいしか見つかりませんでした。 そこで、「どのような非負整数 N を選んでも・・・」ではなくて「できるだけ多くの非負整数 N に対して・・・」というふうに性質の条件を落として探してみることにしてみました。
高橋君は非負整数 K がどれくらい多くの非負整数 N に対して上のような条件をみたすのかが知りたいです。
高橋君を手伝うために以下の問いに答えてください。
1≦N≦M となる整数 N のうち K で割った余りと、N を 10 進法表記した時の各桁の数字の和を K で割った余りが一致するような N の個数を求めてください。

-----問題ここまで----- */
/* -----解説等-----

解法分割をする。
まず桁の和を考えると、90が上限となる。
Kが大きい時を考えると、i%kを見る際に、i%kは[0,90)の間しか答えになりえない。したがって飛ばし飛ばし愚直なcheckをすればよい。
Kが小さい時を考える。小さいときはi%kとdigitSum(i)%kがたくさん一致する。
これは単純な桁DPでできるのでできる。


----解説ここまで---- */

LL dp[11][10004][90][2];
// (idx,modulo,digitSumModulo,less?)
LL f(const string&s, int idx, int k, int digk, bool less, LL K) {
	if (idx < 0) { return k % K == digk % K; }
	if (dp[idx][k][digk][less] != -1)return dp[idx][k][digk][less];
	int Max = less ? 9 : s[idx] - '0';
	LL ret = 0;
	FOR(nx, 0, Max + 1) {
		ret += f(s, idx - 1, (k * 10 + nx) % K, (digk + nx) % K, less || (nx < Max), K);
	}
	return dp[idx][k][digk][less] = ret;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL K, N; cin >> K >> N;
	LL ans = 0;
	if (K <= 10000) {
		// 桁dpする
		fill(***dp, ***dp + 11 * 10004 * 90 * 2, -1);
		string s = to_string(N);
		reverse(ALL(s));
		ans = f(s, SZ(s) - 1, 0, 0, 0, K);
	}
	else {
		// i%K=[0,K)のみやる(素なので)
		auto digitSum = [](LL x) {
			string s = to_string(x);
			int res = 0;
			for (auto c : s) {
				res += c - '0';
			}
			return res;
		};
		for (LL x = 0; x <= N; x += K) {
			LL up = x + 100;
			for (LL y = x; y <= N && y <= up; y++) {
				if (y%K == digitSum(y) % K)ans++;
			}
		}
	}
	ans--;
	cout << ans << endl;

	return 0;
}
