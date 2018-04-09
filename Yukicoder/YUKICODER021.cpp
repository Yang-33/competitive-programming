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

/* -----  2018/04/09  Problem: yukicoder 021  / Link: http://yukicoder.me/problems/no/021  ----- */
/* ------問題------

N個の数字が与えられるのでこれらをK(≥3)個のグループに振り分ける。
ただし各グループには最低一つ数字が含まれているとする。

ex) 例えば 与えれる数字が {10,3,23,91,5}, K=3 なら
{{3,91},{23,5},{10}} のような振り分けかたはただしく
{{},{3,5,10},{23,91}} のような振り分けかたは認められません

グループごとに平均を計算し, それらをもとに 最大の平均 - 最小の平均 を計算し、
最後に小数点以下を切り上げその値を「平均の差」と呼ぶ。
平均の差を最も大きくするようなグループ分けをしたとき、平均の差はいくつになるか答えよ。

-----問題ここまで----- */
/* -----解説等-----

K≧3なので、最小と最大の値は1つのグループにして、他のやつは適当に他のグループとすることで平均の差を最大化できる。

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int K; cin >>N >>  K;
	VI a(N);
	int M = -INF, m = INF;
	FOR(i, 0, N) {
		int a; cin >> a;
		M = max(M, a);
		m = min(m, a);
	}
	ans = M - m;
	cout << ans << "\n";

	return 0;
}
