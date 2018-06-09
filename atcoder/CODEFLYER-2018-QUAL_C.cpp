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

/* -----  2018/06/02  Problem: codeflyer-2018-qual C / Link: __CONTEST_URL__  ----- */
/* ------問題------
N 個の都市があり、1,2,…,N の番号がついています。 これらの都市はこの順に一直線上に並んでいます。 各 i (1≤i≤N) について、都市 i の座標は Xi です。

高橋くんは都市 i と都市 j の間の移動手段を以下のように選びます。

都市 i と都市 j の距離 |Xi−Xj| が D 以下であれば、徒歩で移動する。
そうでない場合、電車で移動する。
3 つの都市 (の番号) の組 (i,j,k) であって、以下の条件を満たすものの個数を求めてください。

i<j<k
高橋くんは都市 i と都市 j の間、および都市 j と都市 k の間を徒歩で移動する。
高橋くんは都市 i と都市 k の間を電車で移動する。


-----問題ここまで----- */
/* -----解説等-----

たくさん解法はあるけど、僕は包除でといた。
全体から、徒歩∧電車、電車∧徒歩、電車∧電車、をとりのぞけばよい。

----解説ここまで---- */



LL N, D;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> D;
	VL a(N);
	FOR(i, 0, N) {
		cin >> a[i];
	}
	FOR(i, 1, N + 1) {
		ans += (i - 1)*(N - i);
	}
	VL overD(N + 10, 0);
	VL underD(N + 10, 0);
	FOR(i, 0, N) {
		overD[i] = lower_bound(ALL(a), a[i] + D + 1) - a.begin();
		underD[i] = lower_bound(ALL(a), a[i] - D) - a.begin();
		underD[i]--;
	}

	LL ret = 0;
	// 包除
	FOR(i, 0, N) {
		LL Lout = underD[i] + 1;
		LL Rin = overD[i] - i - 1;
		ret += Lout*Rin;
	}
	FOR(i, 0, N) {
		LL Lin = i - underD[i] - 1;
		LL Rout = N - overD[i];
		ret += Lin*Rout;
	}
	FOR(i, 0, N) {
		LL Lout = underD[i] + 1;
		LL Rout = N - overD[i];
		ret += Lout*Rout;
	}
	int L = 0;
	LL xx = 0;
	FOR(i, 0, N) {
		LL x = 0;
		while (a[i] - a[L]>D) {
			L++;
		}
		LL w = i - L - 1;
		x = w*(w + 1) / 2;
		xx += x;
	}
	ret += xx;
	ans -= ret;
	cout << ans << "\n";

	return 0;
}
