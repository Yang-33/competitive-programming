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

/* -----  2018/02/23  Problem: 081_arc_b / Link: https://abc071.contest.atcoder.jp/tasks/arc081_b?lang=en  ----- */
/* ------問題------

2×N のマス目があります． すぬけ君は，このマス目に N 個のドミノを，重ならないように敷き詰めました． ここで，ドミノは，1×2 または 2×1 のマス目を覆うことができます．
すぬけ君は，赤色，水色，緑色の 3 色を使って，これらのドミノを塗ることにしました． このとき，辺で接しているドミノは異なる色で塗るようにします． ここで，必ずしも 3 色すべてを使う必要はありません．
このような塗り方が何通りあるかを mod 1000000007 で求めてください．
ただし，ドミノの敷き詰め方は，文字列 S1,S2 を用いて，次のようにして与えられます．
各ドミノは，それぞれ異なる英小文字または英大文字で表される．
Si の j 文字目は，マス目の上から i 番目，左から j 番目のマスにどのドミノがあるかを表す．

-----問題ここまで----- */
/* -----解説等-----

状態が4通りしか無いので全部書く。
最初だけ塗れる色の数が違うので気をつける。

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	string s1, s2;
	cin >> s1 >> s2;
	ans = 1;
	int mode = -1;
	FOR(i, 0, N) {
		if (mode == -1) {//init
			if (s1[i] == s2[i]) {
				mode = 0; ans = 3;
			}
			else {
				mode = 1; ans = 6;
			}
		}
		else if (mode == 0) {// :
			if (s1[i] == s2[i]) {
				mode = 0; ans *= 2;
			}
			else {
				mode = 1; ans *= 2;
			}
		}
		else if (mode == 1) {// =L

			mode = 2;
		}
		else if (mode == 2) {// =R
			if (s1[i] == s2[i]) {
				mode = 0; ans *= 1;
			}
			else {
				mode = 1; ans *= 3;
			}
		}

		ans %= MOD;
	}
	cout << ans << "\n";

	return 0;
}
