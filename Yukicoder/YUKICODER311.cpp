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

/* -----  2018/10/01  Problem: yukicoder 311  / Link: http://yukicoder.me/problems/no/311  ----- */
/* ------問題------

1〜Nまでの数字について、

3の倍数かつ5の倍数：FizzBuzz
3の倍数：Fizz
5の倍数：Buzz
それ以外：その数字自体
と変換して、書き並べます。これをFizzBuzzString(N)とします。 では、FizzBuzzString(N)に含まれる'z'の個数を求めて下さい。

注意:64ビット整数値を利用するため、JavaScriptでの回答は困難かもしれません。
PHPでは/ではなくdivint関数を使用する可能性が高いです。

-----問題ここまで----- */
/* -----解説等-----

ちょうど重複する部分が2倍なので、それぞれの集合を求めるだけで良い。

----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	
	LL N; cin >> N;
	LL ans = N / 5 + N / 3;
	ans *= 2;
	cout << ans << "\n";

	return 0;
}
