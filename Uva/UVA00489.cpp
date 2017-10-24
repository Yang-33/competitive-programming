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

/* -----  2017/10/18  Problem: Uva 00489  / Link:   ----- */
/* ------問題------

文字あてゲーム

-----問題ここまで----- */
/* -----解説等-----

順序関係に気を付けながらはい

----解説ここまで---- */

LL N;

string ans[3] = { "You win.","You chickened out.","You lose." };
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	while (cin >> N) {
		if (N == -1)break;
		string s, t; cin >> s >> t;
		int cnt[26] = {};
		FOR(i, 0, SZ(s)) {
			cnt[s[i] - 'a']++;
		}
		int stroke = 0;
		int hit = 0;
		int f=-1;
		FOR(i, 0, SZ(t)) {
			if (cnt[t[i] - 'a'] == 0)stroke++;
			else if (cnt[t[i] - 'a'] == -1) { ; }
			else {
				hit += cnt[t[i] - 'a'];
			}
			cnt[t[i] - 'a'] = -1;
			if (stroke < 7 && hit == SZ(s))f = 0;
		}
		if (f == -1) {
			if (stroke >= 7)f = 2;
			else f = 1;
		}
		cout << "Round " << N << endl;
		cout << ans[f] << "\n";

	}

	return 0;
}