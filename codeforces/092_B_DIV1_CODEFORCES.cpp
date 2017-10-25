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

/* -----  2017/10/25  Problem: 092_b_div1_codeforces  / Link: http://codeforces.com/contest/123/problem/B  ----- */
/* ------問題------

二次元座標s,tが与えられる。
|x + y| ≡ 0 (mod 2a),
|x - y| ≡ 0 (mod 2b).
となる点は悪い点と呼ばれている。
s->tの移動に悪い点を最小で何回通らないといけないか。

-----問題ここまで----- */
/* -----解説等-----

マンハッタンチャンス！45度回転させることで長方形領域のななめいどうをすることになる。
0の点を意識して、最低でも線を何回またがないといけないかを確認すればよい。

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int a, b, x[2], y[2];
	cin >> a >> b;

	FOR(i, 0, 2)cin >> x[i] >> y[i];

	int X[2], Y[2];

	FOR(i, 0, 2) {
		X[i] = x[i] - y[i];
		Y[i] = x[i] + y[i];
	}
	a *= 2;
	b *= 2;

	int nx[2], ny[2];
	FOR(i, 0, 2) {
		nx[i] = X[i] / b + (X[i] > 0);
		ny[i] = Y[i] / a + (Y[i] > 0);
	}

	ans = max(abs(ny[0]-ny[1]), abs(nx[0]-nx[1]));

	cout << ans << "\n";

	return 0;
}
