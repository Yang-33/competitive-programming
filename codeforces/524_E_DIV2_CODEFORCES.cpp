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

/* -----  2018/11/24  Problem: CodeForces524 E div2 / Link: http://codeforces.com/contest/1080/problem/E  ----- */
/* ------問題------

H*Wの領域にアルファベットがある。
任意長方形を選択して、それぞれの行について適当に並び替えても良い時、
行方向にも列方向にも回文であるような選択の組合せは何通りか?

-----問題ここまで----- */
/* -----解説等-----

ある幅Wを選択したときに、それぞれの行が回文になるかどうかは簡単に判定することができる。
さて、複数行をまたいで回文になるかどうかはなったりならなかったりと連続性が成り立たない。
ある長方形を選択したときにどのように並び替えても1通りであるから、一つでもそのようなものが存在するかどうかを見れば良い。
全ての組合せを含みうる=hashと見ることができるので、行ごとにhashをとりこの値でmanacherを適用すれば良い、(天才)
位置について偶数半径と奇数半径が存在するので、これに注意。
また、回文でないものはuniqueなhashにすること、奇数半径のときにカウントしないことに注意する。
これ結構面白い。

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int H, W; cin >> H >> W;
	VS vs(H);
	FOR(i, 0, H) {
		cin >> vs[i];
		FOR(j, 0, W) {
			vs[i][j] -= 'a';
		}
	}
	LL ans = 0;

	FOR(L, 0, W) {
		int sz = 2 * H + 1;
		VVI asum(sz, VI(27, 0));// [26]:この行は回文であるか
		VI state(sz, 0);
		FOR(R, L, W) {
			FOR(i, 0, H) {
				asum[2 * i + 1][vs[i][R]]++;
				state[2 * i + 1] ^= 1 << vs[i][R];
			}
			int no = 1;
			FOR(i, 0, H) {
				if (__builtin_popcount(state[2 * i + 1]) > 1)asum[2 * i + 1][26] = no++;
				else asum[2 * i + 1][26] = 0; // ダメであっても良くなる場合が存在する
			}
			// [L,R]でmanacharのノリをする
			VI radius(sz, 0);
			int i = 0, j = 0;
			while (i < (int)asum.size()) {
				while (i - j >= 0 && i + j < (int)asum.size() && asum[i - j] == asum[i + j]) { ++j; }
				radius[i] = j; int k = 1;
				while (i - k >= 0 && i + k < (int)asum.size() && k + radius[i - k] < j) { radius[i + k] = radius[i - k]; ++k; }
				i += k;	j -= k;
			}
			auto getOddR = [&radius](int k) {
				DD(assert(2 * k + 1 < (int)radius.size()));
				return radius[2 * k + 1] / 2;
			};

			auto getEvenR = [&radius](int k) {
				DD(assert(2 * k + 2 < (int)radius.size()));
				return (radius[2 * k + 2] - 1) / 2;
			};
			FOR(i, 0, H) {
				ans += getEvenR(i);
			}
			FOR(i, 0, H) {
				if (asum[2 * i + 1][26] == 0) {
					ans += getOddR(i);
				}
			}

		}
	}



	cout << ans << endl;

	return 0;
}
