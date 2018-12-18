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

/* -----  2018/10/04  Problem: CodeForces513 B div2 / Link: http://codeforces.com/contest/1060/problem/B  ----- */
/* ------問題------

s.t. A+B=N,f(x) = digitsum(x)
maxi f(A)+f(B)

-----問題ここまで----- */
/* -----解説等-----

9999をつくればよい

----解説ここまで---- */

LL solve(LL N) {
	LL ans = 0;
	if (N <= 10) {
		ans = N;
	}
	else {

		auto f = [](LL n) {
			string s = to_string(n);
			LL ret = 0;
			FOR(i, 0, SZ(s)) {
				ret += s[i] - '0';
			}
			return ret;
		};
		string nt = to_string(N);
		LL ten = nt.front() - '0';
		while (N > ten * 10)ten *= 10;
		LL b = (N % ten) + 1;
		LL a = N - b;
		ans = f(a) + f(b);

	}
	return ans;

}


LL ans = 0LL;


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N;

	cin >> N;
	ans = solve(N);
	cout << ans << "\n";

	return 0;
}
