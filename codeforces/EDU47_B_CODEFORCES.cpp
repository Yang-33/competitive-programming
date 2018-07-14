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

/* -----  2018/07/14  Problem: edu47_b_codeforces / Link: __CONTEST_URL__  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

頭が悪かった。
1は全部通過できるため、先頭か最初の0の後ろに置けば良いことになる。

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);


	string s; cin >> s;
	string ans = "";

	int cnt = 0;
	FOR(i, 0, SZ(s)) {
		if (s[i] == '1') {
			cnt++;
		}
		else {
			ans += string(1, s[i]);
		}
	}
	if (ans[0] == '0') {
		int f = 1;
		FOR(i, 0, SZ(s)) {
			if (s[i] == '1')continue;
			if (f&&s[i] == '2') {
				cout << string(cnt, '1');
				f = 0;
			}
			cout << s[i];
		}
		if (f) {
			cout << string(cnt, '1');
		}
	}
	else {
		cout << string(cnt,'1');
		FOR(i, 0, SZ(s)) {
			if (s[i] == '1')continue;
			cout << s[i];
		}
	}
	cout << endl;

	return 0;
}
