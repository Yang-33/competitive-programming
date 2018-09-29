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

/* -----  2018/09/29  Problem: yukicoder 300  / Link: http://yukicoder.me/problems/no/300  ----- */
/* ------問題------

平方数とは、ある整数の2乗で表される整数である。
Xが与えられるので、
X × Y = Z2 (X,Y,Zは1以上の自然数,Z2は平方数)
となるような最小のYを求めよ。

-----問題ここまで----- */
/* -----解説等-----

素因数の指数が奇数のものを集めるのが良い。

----解説ここまで---- */

map<LL, LL> make_factor(long long  n) {
	map<LL, LL> ans;
	for (long long i = 2; i * i <= n; i++) {
		while (n%i == 0) {
			ans[i]++;
			n /= i;
		}
	}
	ans[n]++;
	return ans;
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL X; cin >> X;

	map<LL, LL>psc = make_factor(X);
	LL ans = 1;
	for (auto it : psc) {
		if (it.second % 2) {
			ans *= it.first;
		}
	}


	cout << ans << "\n";

	return 0;
}
