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

/* -----  2017/09/15  Problem: hackerrank_5days_game_theory_8  / Link: https://www.hackerrank.com/contests/5-days-of-game-theory/challenges/tower-breakers-2  ----- */
/* ------問題------

h[i]の高さのN個の山がある。この山のうち一つを選び、この山の高さを1以外の約数で割った高さに変更する。
2人でこのゲームをプレイした際の勝者はどちらか。

-----問題ここまで----- */
/* -----解説等-----

自分自身の約数の存在からM≧2でgrundy数が必ず1を超える。grundy数は実験すると1以外の約数の数になる。
それを求め直和としてXORをとればよい。

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int T; cin >> T;
	FOR(t, 0, T) {
		cin >> N;
		int grundy = 0;
		FOR(j, 0, N) {
			int n; cin >> n;
			int cnt = 0;
			for (int i = 2; i * i <= n; i++) {
				while (n%i == 0) {
					n /= i;
					cnt++;
				}
			}
			if (n != 1)cnt++;
			grundy ^= cnt;
		}
		cout << ((grundy!=0)?1:2) << "\n";
	}
	return 0;
}
