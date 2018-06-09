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

/* -----  2018/03/25  Problem: ARC 093 A / Link: http://arc093.contest.atcoder.jp/tasks/arc093_a  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

添字を間違えた後トイレに行くと解けなくなる

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	VL a(N+1);
	a[0] = 0;
	FOR(i, 0, N) {
		cin >> a[i+1];
	}
	LL sum = 0;
	FOR(i, 0, N+1) {
		sum += abs(a[(i + 1) % (N+1)] - a[i]);
	}
	FOR(i, 1, N+1) {

		LL ret = 0;
		LL x = a[i - 1];
		LL y = a[i];
		LL z = a[(i + 1)%(N+1)];
		LL cost = 2 * abs(x - y);// debug(cost);
		if (y < x && x <= z) {
			ret = cost;
		}
		if (z <= x && x < y) {
			ret = cost;
		}
		LL cost23 = 2*abs(y - z);
		if (y < z && z <= x) {
			ret = cost23;

		}

		if (x <= z && z < y) {
			ret = cost23;
		}
//		debug(ret);
		//cout << x << "," << y << "," << z << "," << ret << endl;
		cout << sum - ret << endl;
	}

	return 0;
}
