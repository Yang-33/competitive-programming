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

/* -----  2018/10/28  Problem: ARC 043 D / Link: http://arc043.contest.atcoder.jp/tasks/arc043_d  ----- */
/* ------問題------

高橋国には N 個の空き家がある。空き家は 1 から N の整数で番号付けされており、順に東西に一直線に 1 キロメートル間隔で並んでいる。 つまり i 番目の空き家は ある基準点から真東に i キロメートル進んだところにある。
この国に M 世帯の家族が引っ越してきた。 i 番目の家族は Pi 人家族である。 この M 世帯の家族に 1 軒ずつ空き家を振り分けていく。このとき複数の家族に同じ家を振り分けてはならない。
あなたの目標は「住民の距離」を最大化するように空き家を振り分けることである。 「住民の距離」とは引っ越してきた人々の中の全ての 2 人組について、その住んでいる家の距離の総和を取った値である。
最適な振り分け方をしたときの「住民の距離」の最大値を求めよ。

-----問題ここまで----- */
/* -----解説等-----

うーん、これはすごいなあ
dp(i,x):=i個を左右においたとして、左にx個あるような場合の最大値
とする。左右からの更新をM*(\sum a[i])回やればよい。
解説には厳密な理由が書かれているが、当然大きいものを左右に分けるべきで、
一個加えたときのコストはL*RみたいにできることからこのDPはなりたつ。
辺を加えていく動作に対応するので、最後に0についての加算を忘れないこと。

----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, M; cin >> N >> M;
	VL a(M);
	FOR(i, 0, M) {
		cin >> a[i];
	}
	RSORT(a);
	const int sz = 1e5 + 5;
	VL dp(sz, -INF);
	dp[0] = 0;
	VL asum(M + 1, 0);
	FOR(i, 0, M) {
		asum[i + 1] = asum[i] + a[i];
	}
	FOR(i, 0, M) {
		VL nx(sz, -INF);
		FOR(j, 0, sz) {
			if (dp[j] == -INF)continue;
			nx[j + a[i]] = max(nx[j + a[i]], dp[j] + (j)*(asum[M] - j));
			LL R = asum[i] - j;
			nx[j] = max(nx[j], dp[j] + (asum[M] - R)*(R));
		}
		nx.swap(dp);
	}
	ans = 0;
	FOR(j, 0, sz) {
		ans = max(ans, dp[j] + (N - M + 1)*(j)*(asum[M] - j));
	}

	cout << ans << "\n";

	return 0;
}
