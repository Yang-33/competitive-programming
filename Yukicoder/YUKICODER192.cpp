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

/* -----  2018/07/31  Problem: yukicoder 192  / Link: http://yukicoder.me/problems/no/192  ----- */
/* ------問題------

整数 N が与えられます。N−100 以上 N+100 以下の合成数を 1 個見つけてください。
ここで、合成数とは 1 と自分自身以外の正の約数を持つ正整数のことをいいます。

-----問題ここまで----- */
/* -----解説等-----

実際に合成数かどうかを判定すれば良い。
[解説をみた]
Nのちかくの偶数をみればよい(そう…)

----解説ここまで---- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;
	FOR(i, N - 100, N + 100 + 1) {
		auto check = [](int n) {
			int cnt = 0;
			for (int j = 2; j*j <= n; j++) {
				while (n%j == 0) {
					cnt++;
					n /= j;
				}
			}
			return cnt >= 2;
		};
		if (check(i)) {
			cout << i << endl;
			return 0;
		}
	}

	return 0;
}
