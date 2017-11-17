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

/* -----  2017/11/03  Problem: yukicoder319 / Link: https://yukicoder.me/problems/no/319  ----- */
/* ------問題------

りあんくんは, 正整数 A,B(A≤B)A,B(A≤B) に対し AA から BB までの数字を十進表記でつなげた文字列を考え, 「(A,B)(A,B)文字列」と名付けることとしました.
例えば「(3,5)(3,5)文字列」は "345345", 「(8,13)(8,13)文字列」は "89101112138910111213", 「(102,102)(102,102)文字列」は "102102" となります.
ここでりあんくんは, ある正整数 A,BA,B からなる「(A,B)(A,B)文字列」に含まれる "1212" という連続部分文字列の個数が気になってしまいました.
初めてのぽしゃけで酔っぱらってしまいダメダメなりあんくんの代わりに, 「(A,B)(A,B)文字列」に含まれる "1212" の個数を求めてあげてください.

-----問題ここまで----- */
/* -----解説等-----

ある数字に含まれる12の個数は桁DPが得意なのでこれは簡単に求めることができる。
次に数A, Bの境界に生じる12の列は、純粋に数え上げることができる。(ソースコードのコメント参照)
桁DPのときに横着をしてA--とかをしているのでちゃんと戻せば数え上げられる。

----解説ここまで---- */

LL N;

LL ans = 0LL;
LL dp[14][7][2][2];
LL f(string & target, int i, int has = 0, int one = 0, int less = 0) {
	if (i == -1) {
		return has;
	}
	if (dp[i][has][one][less] != -1 && less == 1)return dp[i][has][one][less];
	LL res = 0;
	int num = target[i] - '0';
	int Max = less ? 9 : num;
	FOR(nx, 0, Max + 1) {
		if (nx == 1) {
			res += f(target, i - 1, has,1, less || (nx < Max));
		}
		else if (nx == 2) {
			res += f(target, i - 1, one==1 ? has + 1 : has, 0, less || (nx < Max));
		}
		else res += f(target, i - 1, has, 0, less || (nx < Max));
	}

	if (less == 1)return dp[i][has][one][less] = res;
	return res;
}

LL calc[14];
LL oneandtwo(string &s) {
	reverse(ALL(s));
	LL ret = 0;
	FOR(i, 0, SZ(s)) {
		if (SZ(s) - 1 != i) {
			ret += calc[i];
		}
		else {//ここめんどい
			if (s[0] > '2') {
				ret += calc[i];
			}
			else if (s[0] == '2') {
				LL t = 0;
				FOR(j, 1, SZ(s) - 1) {
					t *= 10;
					t += s[j] - '0';
				}
				if (s.back() >= '2')t++;
				ret += t;
			}
			else {
				;
			}
		}
	}
	return ret;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	LL a, b; cin >> a >> b;
	a--;
	string A, B;
	A = to_string(a);
	B = to_string(b);
	fill(***dp, ***dp + 14 * 7 * 2 * 2, -1);

	reverse(ALL(A));
	reverse(ALL(B));
	ans = f(B, SZ(B) - 1);
	ans -= f(A, SZ(A) - 1);

	/*  1212の桁DP + 連結 *1 + 2* の数え上げ */
	/*
	1,2
	21,22
	---(1+1)
	201,202
	211,212
	...
	291,292
	---(10)
	2001,2002
	2011,2012
	..
	2991,2992
	---(100)
	*/
	FOR(i, 0, 14) {
		calc[i] = pow(10, (i ? i - 1 : 0));
	}
	ans += oneandtwo(B);
	a++;
	A = to_string(a); // 2 2では存在しないので、数は戻して考える
	reverse(ALL(A));
	ans -= oneandtwo(A);
	cout << ans << "\n";

	return 0;
}
