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

/* -----  2018/02/23  Problem: 008_agc_b / Link: https://agc008.contest.atcoder.jp/tasks/agc008_b?lang=en ----- */
/* ------問題------

N 個のマスが横一列に並んでいます。 左から i 番目のマスには整数 ai が書かれています。
最初、すべてのマスは白色です。 すぬけ君は次の操作を好きな回数だけ繰り返します。
連続する K 個のマスを選び、それらすべてを白く塗るか、それらすべてを黒く塗る。 このとき、各マスの色は上書きされる。
すぬけ君が操作を終えた後、黒いマスに書かれた整数の総和がスコアになります。 考えられるスコアの最大値を求めてください。

-----問題ここまで----- */
/* -----解説等-----

flipでは長さKの区間以外の部分は任意の色にできる

----解説ここまで---- */

LL N, K;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> K;
	VL a(N);
	FOR(i, 0, N) {
		cin >> a[i];
	}
	VL asum(N + 1, 0);
	VL psum(N + 1, 0);
	FOR(i, 0, N) {
		asum[i + 1] += asum[i] + a[i];
		psum[i + 1] += psum[i] + max(0LL, a[i]);
	}


	ans = 0;
	FOR(i, 0, N - K + 1) {
		LL ret = (psum[i] - psum[0]) + (psum[N] - psum[K + i]);
		ans = max(ans, ret);
		ans = max(ans, ret + asum[i+K] - asum[i]);
	}


	cout << ans << "\n";

	return 0;
}
