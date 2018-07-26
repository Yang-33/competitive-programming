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

/* -----  2018/07/26  Problem: yukicoder 164  / Link: http://yukicoder.me/problems/no/164  ----- */
/* ------問題------

入力に N 個の1以上の整数が与えられる。
そのうち、最小の値を出力せよ。

ただし、入力は10進法表記とは限らず、
与えられる整数1つにつき、それぞれ2進法表記から36進法表記までの間のいずれかで与えられ、
正当に解釈できる限り何進法表記として解釈しても構わないが、
入力が意図する値は、解釈できるうちの最小の数値である。

通常16進法表記は、各桁に [ 0～9, A～F ] の16文字を使用するが、
本問題ではこれを拡張して17進法表記以降は G～Z を順に追加で使用し、
36進法表記では [ 0～9, A～Z ] の36文字を使用することとする。

例として、「YUKICODER」を36進法表記で表した数値としたとき、
10進法表記では、98313307106787 となる。
また、与えられる整数は0で始まる場合もあることに注意せよ。

-----問題ここまで----- */
/* -----解説等-----

sample2が優しい
"独立しているので"全部調べれば良い。

----解説ここまで---- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;
	auto norm = [](char c) {
		if (isdigit(c))return c - '0';
		else return c - 'A' + 10;
	};
	LL ans = LLONG_MAX;
	FOR(i, 0, N) {
		string s; cin >> s;
		int high = 0;
		for (const auto&it : s) {
			high = max(high, norm(it));
		}
		FOR(decimal, high + 1, 36 + 1) {
			LL ret = 0;
			for (const auto & it : s) {
				ret *= decimal;
				ret += norm(it);
			}
			ans = min(ans, ret);
		}
	}


	cout << ans << "\n";

	return 0;
}
