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

/* -----  2018/03/11  Problem: ARC 091 A / Link: http://arc091.contest.atcoder.jp/tasks/arc091_a  ----- */
/* ------問題------

縦横に無限に広がるマス目があり、そのうちの連続する N 行 M 列の領域のすべてのマスに表裏の区別できるカードが置かれています。 最初はすべてのカードが表を向いています。

以下の操作を、カードが置かれている全てのマスについて 1 度ずつ行います。

そのマスと辺または点で接する 8 つのマスと、そのマスの合計 9 マスについて、カードが存在するなら裏返す。
すべての操作を行った後の各カードの状態は操作を行う順番に依らないことが証明できます。 すべての操作を行った後、裏を向いているカードの枚数を求めてください。

-----問題ここまで----- */
/* -----解説等-----

はしっこでない部分は裏になる。
ただし2,1の場合は別

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);


	LL M;
	cin >> N>>M;
	if (N == 1 && M == 1)ans = 1;
	else if (N == 1) {
		ans = 0;
		if (M > 2)ans = M - 2;
	}
	else if (N == 2) {
		ans = 0;
	}
	else if (M == 1) {
		ans = 0;
		if (N > 2)ans = N - 2;
	}
	else if (M == 2) {
		ans = 0;
	}
	else {
		N -= 2;
		M -= 2;
		ans = N*M;
	}

	cout << ans << "\n";

	return 0;
}
