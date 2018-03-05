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

/* -----  2018/03/05  Problem: 079_arc_c / Link: https://arc079.contest.atcoder.jp/tasks/arc079_c?lang=en  ----- */
/* ------問題------

長さ N の非負整数列 ai に対し、数列の最大値が N−1 以下になるまで以下の操作を繰り返し行うことを考えます。なお、この操作はD問題で考える操作と同一です。

数列のうち最も大きい要素を求める、複数ある場合はどれか 1 つ選ぶ。この要素の値を N 減らす。これ以外の要素の値を 1 増やす。
なお、この操作を行い続けると、いつかは数列の最大値が N−1 以下になることが証明できます。

ここで、数列 ai が与えられるので、何回操作を行うことになるかを求めてください。

-----問題ここまで----- */
/* -----解説等-----

ええーこの2問なんでこの点数なのかわからない
こちらも端折っていくだけ

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	VL a(N);
	FOR(i, 0, N) {
		cin >> a[i];
	}
	int update = 1;
	while (update) {
		update = 0;

		FOR(i, 0, N) {
			LL ret = a[i] / N;
			if (ret) {
				a[i] -= ret*N;
				ans += ret;

				FOR(j, 0, N) {
					if (i == j)continue;
					a[j] += ret;
				}
			}
		}
		LL m = 0;
		FOR(i, 0, N) {
			m = max(m, a[i]);
		}

		if (m < N)update = 0;
		else update = 1;
	}

	cout << ans << "\n";

	return 0;
}
