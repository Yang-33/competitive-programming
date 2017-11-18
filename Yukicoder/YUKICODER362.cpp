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

/* -----  2017/11/18  Problem: yukicoder362 / Link: __CONTEST_URL__  ----- */
/* ------問題------

門松列 とは 3 個の要素からなる数列A1,A2,A3 で以下の 2 つの条件を満たすものです。

A1,A2,A3 は全て異なる
3 つの要素の中で A2 が最も大きい、または、A2 が最も小さい

NN桁 (3≤N) の 正整数X の上から i桁目 の数を Xi とします。
数列 Xi, Xi+1, Xi+2 (1≤i≤N−2 ) が全て門松列になるとき、Xは門松ナンバーです。
例えば、 4514 や 893 は門松ナンバーですが、 114514 や 89 は門松ナンバーではありません。

X が門松ナンバーであり、X より小さい門松ナンバーが K個 存在するとき、X は K+1番目 の門松ナンバーであるといいます。
1番目の門松ナンバーは102、404番目の門松ナンバーは893、1000番目の門松ナンバーは3296です。

正整数K(1≤K≤10^10) が与えられるので、 K番目の門松ナンバーを求めてください。

-----問題ここまで----- */
/* -----解説等-----

桁DPで、dp(上から何番目を見ているか、前の前の数字は何か、前の数字は何か、?/up/down, less?):=総数
としてやる。
再帰でやると典型になってうれしい気持ちになる。
そうすると総数が分かり、これは単調増加であるから二分探索ができる。

----解説ここまで---- */


LL dp[20][10][10][3][2];
// 0:? 1:up 2:down
LL f(string &s, int i, int befbef = 0, int bef = 0, int up = 0, int less = 0) {
	if (i == -1) {
		return 1;
	}
	if (less == 1 && dp[i][befbef][bef][up][less] != -1)return dp[i][befbef][bef][up][less];
	LL res = 0;
	int num = s[i] - '0';
	int Max = less ? 9 : num;
	FOR(nx, 0, Max + 1) {
		if (up == 0) {// 0,5,?
			if (bef == 0)res += f(s, i - 1, bef, nx, (0), less || (nx < Max));
			else if (nx > bef)res += f(s, i - 1, bef, nx, (1), less || (nx < Max));
			else if (nx < bef)res += f(s, i - 1, bef, nx, (2), less || (nx < Max));
		}
		else if (up == 1) {// 1,4,?
			if (nx < bef&&befbef != nx)res += f(s, i - 1, bef, nx, (2), less || (nx < Max));
		}
		else if (up == 2) {
			if (nx > bef&&befbef != nx)res += f(s, i - 1, bef, nx, (1), less || (nx < Max));
		}
	}
	if (less == 1)return dp[i][befbef][bef][up][less] = res;
	else return res;
}

LL two(LL x) {
	string s = to_string(x);
	reverse(ALL(s));
	
	return f(s, SZ(s) - 1);
}

void solve(LL kado) {
	LL L = 0; LL R = 37294859064823 + 1;
	LL mid;
	FOR(i, 0, 60) {
		mid = (L + R) / 2;
		if (two(mid)-91 >= kado) {
			R = mid;
		}
		else L = mid;

	}
	printf("%lld\n", R);
}



int main() {

	fill(****dp, ****dp + 20 * 10 * 10 * 3 * 2, -1);
	int N;  scanf("%d", &N);
	FOR(i, 0, N) {
		LL a; scanf("%lld", &a);
		solve(a);
	}

	return 0;
}
