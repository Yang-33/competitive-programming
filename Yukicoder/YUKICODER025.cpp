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

/* -----  2018/04/09  Problem: yukicoder 025  / Link: http://yukicoder.me/problems/no/025  ----- */
/* ------問題------

peachは、分数で表された数が、有限小数で表されるかを知りたくなった。
「有限小数」とは 1/8=0.125 のような有限の小数で表される数値のことである。
4/3=1.33333… のような数は、有限の小数では表されないため該当しない。

ここで、64ビット符号付き整数で表される自然数が2つ(N,M)与えられる。
この時 N/Mが有限小数で表されるか判定してください。

有限小数で表される時、0でない一番小さい桁の数字を出力してください。
有限小数で表すことが出来ない時、−1を出力してください。

小数にならない時も、0でない一番小さい桁の数字を求めてください。

-----問題ここまで----- */
/* -----解説等-----

N/M * 10^kが整数になるならもとの分数は有限小数であることから考える。

----解説ここまで---- */

LL N,M;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N>>M;

	LL g = __gcd(N, M);
	N = N / g; M = M / g;
	LL MM = M;
	int cnt2 = 0, cnt5 = 0;
	while (MM % 2 == 0) {
		MM /= 2;
		cnt2++;
	}
	while (MM % 5 == 0) {
		MM /= 5;
		cnt5++;
	}
	if (MM != 1) {
		cout << -1 << endl;
	}
	else { // 有限小数
		while (N % 10 == 0) {
			N /= 10;
		}
		N = N % 10;
		for (; cnt2 > 0 || cnt5 > 0; cnt2--, cnt5--) {
			if (cnt2 <= 0)N = (N*2) % 10;
			if (cnt5 <= 0)N = (N*5)% 10;
		}
		cout << N << endl;
	}

	return 0;
}
