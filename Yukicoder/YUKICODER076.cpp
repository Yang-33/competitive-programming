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

/* -----  2018/04/16  Problem: yukicoder 076  / Link: http://yukicoder.me/problems/no/076  ----- */
/* ------問題------

サイコロXは 6 つの面を持っていてそれぞれの面には 1 から 6 までの整数が書かれています。
出目の和が N 以上となるまでサイコロXを振り続けます。
何回振ることになるか、期待値を求めるプログラムを書いてください。
何回か振った時のサイコロの出目は独立であると仮定してください。
（サイコロの各面が出る確率は等しいとは限りません）

-----問題ここまで----- */
/* -----解説等-----

http://garnacha.techblog.jp/archives/39168955.html で根源を理解した。とても分かりやすかった。
同様の考え方で、DP[x] = E[x] := 出目の和がX以上になるときの期待値 = 残りXを出すまでの期待値とする。
このとき、E[0] = 0, E[1] = 1 + p_1*E[0] = 1 , E[2] = 1 + p_1*E[1] + p_2*E[0],...と求めることができる。  
これでpが判明するので、あとは普通の期待値DPをすれば良い。
勉強になりました！

----解説ここまで---- */


vector<double> judge() {
	vector<double>E({
		0,
		1.0000000000000000,
		1.0833333333333333,
		1.2569444444444444,
		1.5353009259259260,
		1.6915991512345676,
		2.0513639724794235
	});
	vector<double>p(7, 0);
	vector<double>dp(1e6 + 1);
	FOR(i, 1, 5 + 1) {// p[1..5]
		p[i] = E[i + 1] - 1.0;
		FOR(j, 1, i) {
			p[i] -= p[j] * E[i + 1 - j];
		}
	}
	p[6] = 1 - accumulate(p.begin(), p.begin() + 6, 0.0);
	FOR(i, 0, 7) {
		dp[i] = E[i];
	}
	FOR(i, 7, 1e6+1) {
		double x = 1.0;
		FOR(j, 1, 6 + 1) {
			x += p[j] * dp[i - j];
		}
		dp[i] = x;
	}


	return dp;
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	vector<double>dp = judge();
	int T; cin >> T;
	FOR(kim, 0, T) {
		int N; cin >> N;
		double ans = dp[N];
		cout << fixed << setprecision(10) << ans << "\n";
	}

	return 0;
}
