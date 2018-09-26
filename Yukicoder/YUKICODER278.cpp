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

/* -----  2018/09/25  Problem: yukicoder 278  / Link: http://yukicoder.me/problems/no/278  ----- */
/* ------問題------

中学数学では「連続する3個の正整数の和は3で割り切れる」という命題が真であることを証明します。
これをもう少し一般化して、次の命題を考えます。
連続するN個の正整数の和はXで割り切れる

正整数Nが与えられるので、これが真となるような正整数Xの 総和 を求めてください。

-----問題ここまで----- */
/* -----解説等-----

N,N(N-1)/2のうち、no276と一緒になる。
このXに対して、約数は全部Xの条件を満たす。よってこれらの和を取ればよい。
約数和をまとめる式を出したらoverflowしたので普通に書き直した。

----解説ここまで---- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; cin >> N;

	auto f = [](LL n) {
		VL res;
		for (LL i = 1; i *i <= n; i++) {
			if (n%i == 0) {
				res.push_back(i);
				if (n / i != i)res.push_back(n / i);
			}
		}
		return accumulate(ALL(res),0LL);
	};
	LL ans = (N & 1 ? f(N) : f(N / 2));
	cout << ans << "\n";

	return 0;
}
