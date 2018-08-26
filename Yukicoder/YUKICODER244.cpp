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

/* -----  2018/08/26  Problem: yukicoder 244  / Link: http://yukicoder.me/problems/no/244  ----- */
/* ------問題------

グラフとは頂点と辺からなるデータ構造のことである。
頂点と頂点の間を辺で繋ぐことで頂点と頂点を結ぶことができる。
頂点と頂点を辺で繋いだ頂点間を自由に移動できる。

いま頂点がN個与えられる。
最初の状態ですべての頂点は辺で繋がっていない。
頂点と頂点を辺で繋ぐときのグラフのルールは次のようなものである。

・辺は必ず異なる頂点間を繋ぐ。
・同じ頂点と頂点の間に２本以上の辺は無い。

最初からある頂点の数Nが与えられるので、
すべての頂点を移動できるように繋ぐ必要のある最少の辺の本数を答えよ。

-----問題ここまで----- */
/* -----解説等-----

木

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N;  cin >> N;
	int ans = N - 1;
	cout << ans << "\n";

	return 0;
}
