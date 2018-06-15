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

/* -----  2018/06/16  Problem: AOJ 2252 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2252  ----- */
/* ------問題------

キーボードを叩くときに右手と左手が入れ替わる回数は？

-----問題ここまで----- */
/* -----解説等-----

やっていけばよいが、状態は2個なのでxorでやると簡単にかける。

----解説ここまで---- */


string k = "yuiophjklnm";
int is_right(char c) {
	FOR(i, 0, SZ(k)) {
		if (c == k[i])return 1;
	}
	return false;
}

void solve() {

	string s;
	while (cin >> s) {
		if (s == "#")break;
		int right = is_right(s[0]);
		int ans = 0;
		FOR(i, 1, SZ(s)) {
			int nx = is_right(s[i]);
			if (nx^right) {
				ans++;
			}
			right = nx;
		}
		cout << ans << endl;
	}


}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	solve();
	return 0;
}