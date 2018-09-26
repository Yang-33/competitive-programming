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

/* -----  2018/09/25  Problem: yukicoder 276  / Link: http://yukicoder.me/problems/no/276  ----- */
/* ------問題------

中学数学では「連続する3個の正整数の和は3で割り切れる」という命題が真であることを証明します。
これをもう少し一般化して、次の命題を考えます。
連続するN個の正整数の和はXで割り切れる

正整数Nが与えられるので、これが真となるような最大の正整数Xを求めてください。

-----問題ここまで----- */
/* -----解説等-----

整理すると、kN+N*(N-1)/2を割り切れる最大のXを求めることになる。
任意のkを考えることに成るので、結局N,N(N-1)/2の最大公約数を求めることになる。
偶数の時、半分、奇数の時そのままである。

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;

	int ans = (N % 2 ? N : N / 2);

	cout << ans << "\n";

	return 0;
}
