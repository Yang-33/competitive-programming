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

/* -----  2018/07/14  Problem: edu47_f_codeforces / Link: http://codeforces.com/contest/1009/problem/E  ----- */
/* ------問題------

a[i]の発生確率は1/2^iである。
a[i]を選択した時、a[j](j=0:i)を全部足すとする。
全確率に2^{N-1}を掛けたときのaの総和は。

-----問題ここまで----- */
/* -----解説等-----

何もわからないのでOEISをみると書いてある
http://oeis.org/A001792

----解説ここまで---- */

int mod = 998244353;

int add(int a, int b) {
	return (a + b) % mod;
}

int mult(LL a, LL b) {
	return (a * b) % mod;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;
	VI a(N);
	FOR(i, 0, N)cin >> a[i];
	VL two(N + 1, 1);
	FOR(i, 0, N)two[i + 1] = (2 * two[i]) % mod;
	LL ans = 0;
	ans = a[N-1];
	for (int i = N - 2; i >= 0; i--) {
		int iinv = N - i - 1;
		LL fm = mult(iinv+2, two[max(0, iinv - 1)]);
		ans = add(ans, mult(fm , a[i]) );
	}

	cout << ans << endl;

	return 0;
}
