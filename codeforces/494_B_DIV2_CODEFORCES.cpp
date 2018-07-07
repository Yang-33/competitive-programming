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

/* -----  2018/07/03  Problem: CodeForces494 B div2 / Link: http://codeforces.com/contest/1003/problem/B  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----



----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int a, b, x;
	cin >> a >> b >> x;
	string ans = "01";
	x--;
	a--, b--;
	int cnt = 0;
	for (int i = 0; x>=2 && i< min(a,b); i++) {
		ans += "01";
		x -= 2;
		cnt++;
	}
	a -= cnt, b -= cnt;
	if (x) {
		if (a) {
			ans = string(a-1, '0') + ans + string(b, '1') + string(1, '0');
		}
		else {
			ans = string(1, '1') + string(a, '0') + ans + string(b-1, '1');
		}
	}
	else {
		ans = string(a, '0') + ans + string(b, '1');

	}

	cout << ans << "\n";

	return 0;
}
