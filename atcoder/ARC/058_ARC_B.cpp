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

/* -----  2018/02/15  Problem: 058_arc_b / Link: https://arc058.contest.atcoder.jp/tasks/arc058_b?lang=en ----- */
/* ------問題------

縦 H マス、横 W マスのマス目があります。 いろはちゃんは、今一番左上のマス目にいます。 そして、右か下に1マス移動することを繰り返し、一番右下のマス目へと移動します。 ただし、下から A 個以内、かつ左から B 個以内のマス目へは移動することは出来ません。
移動する方法は何通りあるか求めてください。
なお、答えは非常に大きくなることがあるので、答えは 109+7 で割ったあまりを出力してください。

-----問題ここまで----- */
/* -----解説等-----

point(A,w)上までの移動とpoint(A,w+1)からの移動を考えたとき、これらはすべて独立した経路を通過する

----解説ここまで---- */


LL F[200005], R[200005];
long long  powmod(long long  x, long long  n, long long  MOD) {
	long long  res = 1;
	while (n > 0) {
		if (n & 1) {
			res = (res*x) % MOD;
		}
		x = (x*x) % MOD;
		n >>= 1;
	}
	return res;
}
void make() {
	F[0] = 1;
	for (int i = 1; i<200005; i++) F[i] = F[i - 1] * i%MOD;
	for (int i = 0; i<200005; i++) R[i] = powmod(F[i], MOD - 2, MOD);
}

LL nCr(int a, int b) {
	return F[a] * R[b] % MOD*R[a - b] % MOD;
}

LL H, W, A, B;
LL ans = 0LL;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> H >> W >> A >> B;
	make();
	FOR(h, 0, H - A) {
		ans += (nCr(B - 1 + h, B - 1) * nCr(W - 1 - B + H - 1 - h, W - 1 - B)) % MOD;
		ans %= MOD;
	}


	cout << ans << "\n";

	return 0;
}
