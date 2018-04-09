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

/* -----  2018/04/09  Problem: yukicoder 026  / Link: http://yukicoder.me/problems/no/026  ----- */
/* ------問題------

太郎君と二郎君はゲームをしています。

テーブルの上にカップが3つあり、その中の1つだけに○印、
それ以外の2つには×印が外から見えないように記されています。

太郎君から見て左にあるカップから1番、2番、3番として、
最初に○印がどのカップについてるかが公開された後、
二郎君は、何度かカップの位置をそれぞれ入れ替えるので、
太郎君はどのカップに○印が付いているかを当てなければなりません。

入れ替え中も入れ替えた後も、常に、左にあるカップから1番、2番、3番とし、
最初以外は、カップについている印は見ることは出来ません。

入力に、最初に○印が付いているカップの位置番号と、
二郎君が入れ替えたカップの位置番号が与えられるので、
最終的に○印が付いているカップの位置番号を出力してください。

-----問題ここまで----- */
/* -----解説等-----

swapします。

----解説ここまで---- */

LL N,M;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N>>M;
	VI a(4, 0);
	a[N] = 1;
	FOR(i, 0, M) {
		int p, q; cin >> p >> q;
		swap(a[p], a[q]);
	}
	FOR(i, 0, 4) {
		if (a[i])ans = i;
	}
	cout << ans << "\n";

	return 0;
}
