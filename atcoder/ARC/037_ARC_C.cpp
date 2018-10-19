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
#define DEBUG(x) 
#endif
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/10/19  Problem: ARC 037 C / Link: http://arc037.contest.atcoder.jp/tasks/arc037_c  ----- */
/* ------問題------

高橋君は「N2マス計算」で計算力をつけることにした。「N2マス計算」は N 行 N 列の表を用意して行う。
i 行目の左端のマスのさらに左には数 ai が書かれており、 j 列目の上端のマスのさらに上には数 bj が書かれている。
高橋君はこの表の i 行 j 列目 に ai×bj の値を計算して書き込む。

すぐに解き終わってしまい退屈したので、高橋君は自分が書き込んだ N2 個の値を昇順に並べ替えることにした。
並べ替えた結果小さい方から K 番目 (1 番から数える) に位置する値を求めよ。

-----問題ここまで----- */
/* -----解説等-----



----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, K; cin >> N >> K;
	VL a(N), b(N);
	FOR(i, 0, N) {
		cin >> a[i];
	}
	FOR(i, 0, N) {
		cin >> b[i];
	}

	SORT(b);
	// 積がx以下になる個数 a[i]≠0
	auto f = [&N, &a, &b](LL x) {
		LL ret = 0;
		FOR(i, 0, N) {
			LL val = x / a[i];
			ret += upper_bound(ALL(b), val) - b.begin();
		}
		DEBUG(
			debug(x, ret));
		return ret;
	};

	// O(Nlog^2N)
	LL L = 0, R = 1e18 + 10;
	while (R - L > 1) {
		LL mid = (L + R) / 2;
		if (f(mid) >= K) {
			R = mid;
		}
		else {
			L = mid;
		}
	}
	ans = R;
	cout << ans << "\n";

	return 0;
}