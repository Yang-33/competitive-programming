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

/* -----  2018/04/07  Problem: GCJ2018_qual A / Link: __CONTEST_URL__  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

なんか貪欲にできる

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int T; cin >> T;
	FOR(t, 0, T) {
		cout << "Case #" << t + 1 << ": ";
		LL D; string s, str; cin >> D >> s;
		LL ans = 0; int flag = 0;
		while (1) {
			LL ret = 0; LL p = 1;
			FOR(i, 0, SZ(s)) {
				if (s[i] == 'S')ret += p;
				else p *= 2;
			}
			if (D >= ret) {
				flag = 1; break;
			}
			else {
				ans++;
				str = s;
				FORR(i, SZ(str) - 1, 0) {
					if (str[i] == 'S' && str[i - 1] == 'C') {
						swap(s[i], s[i - 1]);
						break;
					}
				}
				if (s == str)break;

			}
		}

		if (flag)cout << ans << endl;
		else cout << "IMPOSSIBLE" << endl;
	}

	return 0;
}
