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

/* -----  2018/07/07  Problem: soundhound2018_master_qual C / Link: __CONTEST_URL__  ----- */
/* ------問題------

数列 (a1,...,an) の 美しさ を、隣り合う 2 項の組であって、 差の絶対値が d であるものの個数として定義します。 
例えば、d=1 であるとき、数列 (3,2,3,10,9) の美しさは 3 です。
各要素が 1 以上 n 以下の整数である長さ m の数列は全部で nm 通り存在します。 
この nm 通りの数列すべてに対して美しさを求めて、 それらの平均を出力してください。

-----問題ここまで----- */
/* -----解説等-----

期待値と確率で考えたのですが、どっかにいったので解けなくなった。
自明に(N-D)個ぐらい選択できる。項の間は独立なので、
(N-D)*N^{-2}*(M-1)*N^M*(N^M)^{-1}となる。

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);



	long double N, M, D;
	cin >> N >> M >> D;

	long double ans;
	if (D == 0) {
		ans = (M - 1) / N;
	}
	else {
		ans = 2 * (N - D)*(M - 1) / N / N;
	}
	cout << fixed << setprecision(30) << ans << endl;
	return 0;
}
