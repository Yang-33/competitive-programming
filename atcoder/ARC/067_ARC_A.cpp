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

/* -----  2018/02/14  Problem: 067_arc_a / Link: https://abc052.contest.atcoder.jp/tasks/arc067_a?lang=en  ----- */
/* ------問題------

整数 N が与えられます。 N! の正の約数の個数を 109+7 で割った余りを求めてください。

-----問題ここまで----- */
/* -----解説等-----

約数の数は高校1年生でやるのでこれを書けば良い。

----解説ここまで---- */


void dividenum(int n, VI&a) {
	for (int i = 2; i*i <= n; i++) {
		while (n%i == 0) {
			n /= i;
			a[i]++;
		}
	}
	if (n > 1)a[n]++;
}
LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	ans = 1;
	VI a(1001,0);
	FOR(i, 2, N + 1) {
		dividenum(i, a);
	}
	FOR(i, 2, N + 1) {
		if (a[i])
			ans *= (a[i] + 1);
		ans %= MOD;
	}
	cout << ans << "\n";

	return 0;
}
