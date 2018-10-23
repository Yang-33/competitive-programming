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
#define DD(x) 
#endif
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/10/23  Problem: ARC 092 B / Link: http://arc092.contest.atcoder.jp/tasks/arc092_b  ----- */
/* ------問題------

2 つの長さ N の非負整数列 a1,…,aN,b1,…,bN が与えられます。
1≤i,j≤N となるように整数 i,j を選ぶ方法は N2 通りありますが，この N2 通りの i,j それぞれについて，ai+bj を計算し，紙に書き出します。 つまり，紙に N2 個の整数を書きます。
この N2 個の整数のxorを計算してください。

-----問題ここまで----- */
/* -----解説等-----

あるK桁目に着目すると、a[i]をキーとして 2*K-a[i]までの値のbは取れる。
同様に、繰り上がりについても4*K-a[i]~3*K-a[i]とかも取れる。
O(Nlog^2N)ぐらい。

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N;
	cin >> N;
	VI a(N), b(N);
	FOR(i, 0, N) {
		cin >> a[i];
	}
	FOR(i, 0, N) {
		cin >> b[i];
	}
	VI A = a, B = b;
	int ans = 0;
	FOR(bit, 0, 30) {
		LL cnt = 0;
		LL T = 1 << bit;
		FOR(i, 0, N) {
			a[i] = A[i] % (2 * T);
			b[i] = B[i] % (2 * T);
		}
		SORT(b);
		FOR(i, 0, N) {
			cnt += lower_bound(ALL(b), 2 * T - a[i]) - lower_bound(ALL(b), 1 * T - a[i]);
			cnt += lower_bound(ALL(b), 4 * T - a[i]) - lower_bound(ALL(b), 3 * T - a[i]);
		}
		DD(de(cnt));
		ans |= ((cnt & 1) << bit);
	}



	cout << ans << "\n";

	return 0;
}
