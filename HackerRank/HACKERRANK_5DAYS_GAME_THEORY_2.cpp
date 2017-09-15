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

/* -----  2017/09/15  Problem: hackerrank_5days_game_theory_2  / Link: https://www.hackerrank.com/contests/5-days-of-game-theory/challenges/tower-breakers  ----- */
/* ------問題------

Mの高さのN個の山がある。この山のうち一つを選び、この山の高さを1以外の約数で割った高さに変更する。
2人でこのゲームをプレイした際の勝者はどちらか。

-----問題ここまで----- */
/* -----解説等-----

自分自身の約数の存在からM≧2でgrundy数が必ず1を超えるので、あとはこの山が何個あるかを考えればよい。

----解説ここまで---- */

LL N;

LL ans = 0LL;


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int T; cin >> T;
	FOR(i, 0, T) {
		int M; cin >> N>>M;
		int g = M - 1;

		g = g ^ (((N+1) % 2)*g);
		cout << ((g!=0)?1:2) << "\n";
	}

	return 0;
}
