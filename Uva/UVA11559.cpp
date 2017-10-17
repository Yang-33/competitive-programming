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

/* -----  2017/10/17  Problem: Uva 11559  / Link: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=27&page=show_problem&problem=2595  ----- */
/* ------問題------

予算内で安いホテルを探す

-----問題ここまで----- */
/* -----解説等-----

お金が足りなかったり泊まれなかったりすると家にいるなんて悲しいね…；；

----解説ここまで---- */

LL N, B, H, W,P;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	while (cin >> N >> B >> H >> W) {
		ans = LINF;
		FOR(i, 0, H) {
			cin >> P;
			FOR(j, 0, W) {
				LL a; cin >> a;
				if (N <= a) {
					ans = min(ans, N*P);
				}
			}

		}
		if(ans!=LINF&&ans<=B)
		cout << ans << "\n";
		else cout << "stay home" << endl;
	}
	return 0;
}