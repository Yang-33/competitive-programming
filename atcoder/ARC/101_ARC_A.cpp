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

/* -----  2018/08/25  Problem: ARC 101 A / Link: http://arc101.contest.atcoder.jp/tasks/arc101_a  ----- */
/* ------問題------

数直線上に N 本のろうそくが置かれています。 左から i 番目のろうそくは座標 xi に置かれています。 ただし、x1<x2<…<xN が成り立ちます。
最初、どのろうそくにも火が付いていません。 すぬけ君は、N 本のうち K 本のろうそくに火を付けることにしました。
今、すぬけ君は座標 0 にいます。 すぬけ君は、数直線上を左右に速度 1 で移動することができます。 また、自分と同じ座標のろうそくに火を付けることができます。 このとき、火を付けるのに掛かる時間は無視できます。
K 本のろうそくに火を付けるのに必要な最小の時間を求めてください。

-----問題ここまで----- */
/* -----解説等-----

0から何個右、左に行くかをみればよい。

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, K; cin >> N >> K;
	VL a(N);
	FOR(i, 0, N) {
		cin >> a[i];
		if (a[i] == 0)K--;
	}
	a.push_back(0);
	SORT(a);
	UNIQ(a);
	int cent = lower_bound(ALL(a), 0) - a.begin();
	LL ans = LINF;
	VL L(N + 2, LINF);
	L[0] = 0;
	FOR(i, 0, cent) {
		L[i + 1] = abs(a[cent - i - 1]);
	}

	VL R(N + 2, LINF);
	R[0] = 0;
	FOR(i, cent + 1, SZ(a)) {
		R[i - cent] = abs(a[i]);
	}
	FOR(i, 0, K + 1) {// 左にi個
		LL Ls = L[i];
		LL Rs = R[K - i];
		ans = min({ ans, Ls * 2 + Rs, 2 * Rs + Ls });
	}
	cout << ans << endl;

	return 0;
}
