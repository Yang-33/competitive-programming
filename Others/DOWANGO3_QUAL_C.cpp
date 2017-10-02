#include "bits/stdc++.h"
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

/* -----  2017/10/02  Problem: dowango3_qual_c  / Link: https://dwacon2017-prelims.contest.atcoder.jp/tasks/dwango2017qual_c  ----- */
/* ------問題------

1<=a<=4の待ち行列がある。先頭からとり、その後待ち行列の中から和を最大4までを許容して順番を抜かして先行させる。
この動作を最小化した際の回数は。

-----問題ここまで----- */
/* -----解説等-----

結局のところ、4,3+1,2+2,2+1+1,1+1+1+1をできるだけ作り、その後余りを足してやればよい。

----解説ここまで---- */

LL N;
int p[5];
LL ans = 0LL;
int a[100005];
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	FOR(i, 0, N) {
		cin >> a[i];
		p[a[i]]++;
	}
	ans = p[4]; p[4] = 0;
	int t = min(p[3], p[1]);
	ans += t;
	p[1] -= t; p[3] -= t;
	ans += p[3]; p[3] = 0;
	ans += p[2] / 2; p[2] = p[2] % 2;

	assert(p[2] <= 1);
	if (p[2]) {
		if (p[1] >= 2) {
			ans += 1;
			p[1] -= 2;
			p[2] = 0;
		}
		else {
			p[1] = 0;
			ans += 1;
		}
	}
	ans += (p[1]+3) / 4;

	cout << ans << "\n";

	return 0;
}