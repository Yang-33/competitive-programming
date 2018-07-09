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

/* -----  2018/07/10  Problem: CodeForces496 A div2 / Link: http://codeforces.com/contest/1005/problem/A  ----- */
/* ------問題------

増加列の個数

-----問題ここまで----- */
/* -----解説等-----

実際に調べる

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N;
	cin >> N;
	VL a(N);

	FOR(i, 0, N) {
		cin >> a[i];
	}
	int s = 0;
	VL ans;
	FOR(i, 0, N) {
		if (a[i] > s) {
			s = a[i];
		}
		else {
			ans.push_back(s);
			s = a[i];
		}
	}
	if (s != 0)ans.push_back(s);
	cout << SZ(ans) << endl;
	FOR(i, 0, SZ(ans)) {
		cout << ans[i] << " \n"[i == SZ(ans) - 1];
	}

	return 0;
}
