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

/* -----  2018/06/09  Problem: AOJ 2768 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2768  ----- */
/* ------問題------

ここにN枚の紙がある。あなたは3台のスキャナーを並列に用いることで、 全ての紙をスキャンしたいと考えている。
それぞれの紙はスキャンにかかる時間が決まっており、i番目の紙をスキャンするのにかかる時間はTiである。
紙をスキャンする順番は任意であるが、1台のスキャナーで複数の紙を同時にスキャンすることはできない。
全ての紙のスキャンが終了し、スキャンを行っているスキャナーがなくなるまでにかかる時間を最小化しなさい。

-----問題ここまで----- */
/* -----解説等-----

最後まで最適がわからないので、(箱詰め問題はNPなので)DPをする。
パラメータは3つだが、累積和を持っておけば探索量は一つ落とせて、
O(NT^2)でできる。
boolDPだけどこれ以上速くならない。
その理由を知っておくと今後役に立ちそう。

----解説ここまで---- */

#define MAXT 1005
LL N;
vector<int> T;
bool memo[55][MAXT][MAXT];

void dfs(int n, int x, int y, LL sum) {
	if (memo[n][x][y]) return;
	memo[n][x][y] = true;
	if (n == N) return;
	if (x + T[n] < MAXT) dfs(n + 1, x + T[n], y, sum + T[n]);
	if (y + T[n] < MAXT) dfs(n + 1, x, y + T[n], sum + T[n]);
	if (sum - x - y + T[n] < MAXT) dfs(n + 1, x, y, sum + T[n]);
}

void solve() {
	cin >> N;
	T.resize(N);
	for (auto& in : T) { cin >> in; }
	sort(T.begin(), T.end());
	reverse(T.begin(), T.end());
	dfs(0, 0, 0, 0);
	int sum = accumulate(T.begin(), T.end(), 0);

	LL ans = LINF;
	for (int i = 0; i < MAXT; i++) {
		for (int j = 0; j < MAXT; j++) {
			if (memo[N][i][j] == false) continue;
			LL t = -1;
			t = max({ i,j,sum - i - j });
			ans = min(ans, t);
		}
	}
	cout << ans << endl;
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	solve();

	return 0;
}
