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

/* -----  2018/12/19  Problem: codefestival2014_team_relay E / Link: __CONTEST_URL__  ----- */
/* ------問題------

縦 h、横 w で hw 個の正方形のマスに区切られたボードを考えます。各マスには0から9の 1 桁の数字か、もしくは.（ドット）が書かれています。また、ボードには、左上のマスが (1,1)、右上が (1,w)、左下が (h,1)、右下が (h,w) となるように、それぞれのマスに対して順に座標が振られています。
ボード内に書かれた整数が 1 つになるまで以下の手順を繰り返します。
整数が書かれたマスの組で、マンハッタン距離が最大になるような組の中から 1 つをランダムに選びます。（マンハッタン距離とは、2 つのマスの座標がそれぞれ (a,b)、(c,d) であるとき、|a−c|+|b−d| で計算される距離のことです）
1. で選んだ組において、マスに書かれた整数の和を元の数が大きいほうのマスに上書きし、小さいほうのマスには.を上書きします。もし元の数が等しい場合は、好きなほうに整数の和を上書きし、他方を.で上書きします。
上記手順が終了した後、ボード内に残る可能性のある整数のうち、最大のものを求めてください。

-----問題ここまで----- */
/* -----解説等-----

結局、数字が大きい方へ加算されていくだけということが分かる。全部足す。

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL H, W; cin >> H >> W;
	VS vs(H);

	LL ans = 0;
	FOR(i, 0, H) {
		cin >> vs[i];
		FOR(j, 0, W) {
			if (vs[i][j] != '.') {
				ans += vs[i][j] - '0';
			}
		}
	}


	cout << ans << endl;

	return 0;
}
