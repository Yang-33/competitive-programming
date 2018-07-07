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

/* -----  2018/07/07  Problem: AOJ 2882 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/2882  ----- */
/* ------問題------

通常，西暦 x 年がうるう年か否かは以下のように定義されている．
x が 400 の倍数であれば，うるう年である．
そうでないとき，x が 100 の倍数であれば，うるう年ではない．
そうでないとき，x が 4 の倍数であれば，うるう年である．
そうでないとき，うるう年ではない．
これは次のように一般化できる．ある数列 A1, ..., An について，西暦 x 年が "一般化うるう年" であるか否かを以下のように定義する．
x が Ai の倍数であるような最小の i (1 ≤ i ≤ n) について，i が奇数であれば一般化うるう年であり，偶数であれば一般化うるう年ではない．
そのような i が存在しないとき，n が奇数であれば一般化うるう年ではなく，偶数であれば一般化うるう年である．
例えば A = [400, 100, 4] のとき，この A に対する一般化うるう年は通常のうるう年と等価になる．
数列 A1, ..., An と正の整数 l, r が与えられるので．l ≤ x ≤ r なる正の整数 x のうち，西暦 x 年が A に対する一般化うるう年であるような x の個数を答えよ．

-----問題ここまで----- */
/* -----解説等-----

やっていけばよい

----解説ここまで---- */

using ll = LL;
int n, l, r;
int solve() {
	int res = 0;
	vector<ll> A(n);
	for (auto& in : A) cin >> in;
	for (int x = l; x <= r; x++) {
		res += [&] {
			for (int i = 0; i < n; i++) {
				if (x%A[i] == 0) {
					return (i + 1) & 1;
				}
			}
			return (n + 1) & 1;
		}();
	}
	return res;
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	solve();
	while (cin >> n >> l >> r, n) {
		cout << solve() << endl;
	}
	return 0;
}