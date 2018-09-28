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

/* -----  2018/09/28  Problem: yukicoder 294  / Link: http://yukicoder.me/problems/no/294  ----- */
/* ------問題------

3で割り切れる正の整数を「Fizz」、5で割り切れる正の整数を「Buzz」とします。
3でも5でも割り切れる正の整数を「FizzBuzz」とするようです。
そして、3でも5でも割り切れて3と5の数字からなる正の整数を「SuperFizzBuzz」とします。

例えば、小さなほうから数えて1番目のSuperFizzBuzzは555です。
555は3でも5でも割り切れて3と5の数字のうち5だけを使った正の整数です。

小さなほうから数えてN番目のSuperFizzBuzzはいくつでしょうか？

-----問題ここまで----- */
/* -----解説等-----

2進数として見る。すると、ある桁数のとき、33..5..5.3.5という数を表現できる。
あとは上限が小さいので計算できる。

dpでもできるらしいのでdpも解きたい
:数え上げDP
:桁DP

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N;  cin >> N;
	string ans;
	int cnt = 0;
	FOR(dig, 3, 26) {
		FOR(state, 0, (1 << dig)) {
			if (state & 1) {// ..5
				int five = __builtin_popcount(state);
				int three = dig - five;
				int sum = 3 * three + 5 * five;
				if (sum % 3 == 0) {
					cnt++;
					if (N == cnt) {
						FOR(i, 0, dig) {
							ans += string(1,
								"35"[!!(state & 1<<(dig-i-1))]);
						}
						break;
					}

				}

			}
		}
	}

	cout << ans << "\n";

	return 0;
}
