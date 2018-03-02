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

/* -----  2018/03/02  Problem: 001_agc_b / Link: https://agc001.contest.atcoder.jp/tasks/agc001_b?lang=en  ----- */
/* ------問題------

高橋君は 1 辺の長さが N の 3 枚の鏡を正三角形状に組み合わせました。 三角形の頂点をそれぞれ a,b,c とします。
高橋君は、辺 ab 上の頂点 a から X の点から、辺 bc と平行に不思議な光を発射しました。 不思議な光は、普通の光と同じように真っすぐ進み、鏡に当たると反射するのですが、不思議な光がすでに通った点に当たったときにも反射をします。 例えば、N=5,X=2 のとき、不思議な光の軌跡は図の黄色い矢印のようになります。
このように不思議な光を発射した時、不思議な光は必ず発射した点に戻ってくることが証明できます。 このとき、光の軌跡の長さが全体でいくらになるかを求めて下さい。

-----問題ここまで----- */
/* -----解説等-----

あまりに対して愚直にシュミレーションをしていく
GCDっぽい…

解説↓
また，光の軌跡が三角形の集合となり，三角形の辺の長さの和が下図より N −
gcd(N, X) となることに気付くと，答えが 3(N −gcd(N, X)) であることがわかる．(らしい)
----解説ここまで---- */

LL N, X;

LL ans = 0LL;

LL f(LL x, LL n) {
	if (x == 0 || n == 0)return -(x + n);
	if (x > n)return f(n, x);
	LL c = n / x;
	return 2 * c*x + f(x, n - c*x);
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> X;
	ans = N + f(X, N - X);

	cout << ans << "\n";

	return 0;
}
