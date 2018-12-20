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

/* -----  2018/12/21  Problem: codefestival2015_team_relay F / Link: __CONTEST_URL__  ----- */
/* ------問題------

頂点の個数と辺の本数がどちらも N であるような、無向連結グラフが何種類あるかを N=3～6 についてそれぞれ求めてください。ただし、自己ループや多重辺があってはいけません。頂点どうしや辺どうしは区別しません。
例えば N=4 のときは、下図のような 2 種類のグラフがあります。

figure
N が大きくなっても、出来るグラフは サイクルがちょうど 1 つ含まれる グラフになります。

-----問題ここまで----- */
/* -----解説等-----

手で書きます　おわり

----解説ここまで---- */

int a[] = { 0,0,0,1,2,5,13 };
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	FOR(i, 0, 4) {
		cout << a[i + 3] << endl;
	}

	return 0;
}