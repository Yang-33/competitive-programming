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

/* -----  2018/04/17  Problem: yukicoder 084  / Link: http://yukicoder.me/problems/no/084  ----- */
/* ------問題------

太郎君はそろばんが苦手で、特に、珠の位置によってその珠が表す数が違うことに納得ができなかった。
そこで、太郎君は二次元の各場所に珠があるかどうかのみで表す整数を決めるような新しい方法を考えだした。
以下ではわかりやすさを優先して、抽象化して説明する。
R 行 C 列のマス目があり、各マスには珠があるかどうかである。
珠は合計で RC−1 個ある。つまり、1 マスだけ珠がないマスが存在する。
各盤面に対して 0 以上の整数を対応させる。
また、対応させる整数の最大値を K とすると、0 以上 K 以下の全ての整数に対して対応する盤面が存在しなければいけない。
ただし、そろばんはひっくり返すことはできないが、回転することができるため、回転して一致する盤面に対しては同じ整数を対応させなくてはいけない。
R と C が与えられるので、対応させる整数の最大値 K の最大値を求めるプログラムを書いてください。

-----問題ここまで----- */
/* -----解説等-----

[1][3][2]
[4][0][4]
[2][3][1]
のような区画に分類される、ただし1,2は大きい区間で、列がそれぞれ奇数のときに0,3,4が存在しうる。  
正方形のとき、1/2,3/4はおなじになることに注意すると数を求めることができる。

----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL H, W; cin >> H >> W;
	if (H == W) {
		ans = (H / 2)*(W / 2) + (H % 2 ? W / 2 : 0) + (W%2&&H%2?1:0);
	}
	else {
		ans = 2 * (H / 2)*(W / 2) + (H % 2 ? W / 2 : 0) + (W % 2 ? H / 2 : 0) + (W % 2 && H % 2 ? 1 : 0);
	}
	ans -= 1;
	cout << ans << "\n";

	return 0;
}
