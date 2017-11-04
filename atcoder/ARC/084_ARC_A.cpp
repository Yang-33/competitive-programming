#include "bits/stdc++.h"
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

/* -----  2017/11/04  Problem: ABC 084 A / Link: http://arc084.contest.atcoder.jp/tasks/arc084_a  ----- */
/* ------問題------

今年もすぬけ祭の季節がやってきました。りんごさんは、まず手始めにすぬけ君召喚の儀式を執り行おうと思っています。 儀式には祭壇が必要で、祭壇は上部、中部、下部の
3 つのカテゴリーのパーツ1 つずつからなります。

祭壇の3 カテゴリーのパーツがそれぞれN 個ずつあります。
i 個目の上部のパーツのサイズはAi 、i 個目の中部のパーツのサイズはBi 、i 個目の下部のパーツのサイズはCi です。
祭壇を作るにあたっては、中部のパーツのサイズは上部のパーツのサイズより真に大きく、下部のパーツのサイズは中部のパーツのサイズより 真に大きくなければなりません。逆に、この条件を満たす任意の
3 つのピースを組み合わせて祭壇を作ることができます。

りんごさんが作ることのできる祭壇は何種類あるでしょうか。ただし、
2 つの祭壇が異なるとは、上部、中部、下部に使われるピースのうち 少なくとも1 つが異なることを言います。

-----問題ここまで----- */
/* -----解説等-----

真ん中からみればよい。
そうすることでb[i]よりも真に小さいa[i]の個数と、b[i]よりも真に大きいc[i]の個数がわかる。
そうでなくて、K段あるときはDPをすればよい。
O(KNlogN)ぐらい。

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	VI a(N), b(N), c(N);
	FOR(i, 0, N)cin >> a[i];
	FOR(i, 0, N)cin >> b[i];
	FOR(i, 0, N)cin >> c[i];
	SORT(a);
	SORT(b);
	SORT(c);

	FOR(i, 0, N) {
		int anum = lower_bound(ALL(a), b[i]) - begin(a);
		int cnum = upper_bound(ALL(c), b[i]) - begin(c);
		if (anum >= 1 && cnum != N) {
			ans += anum*(N-cnum);
		}
	}

	cout << ans << "\n";

	return 0;
}
