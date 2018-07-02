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

/* -----  2018/07/04  Problem: AOJ 2244 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/2244  ----- */
/* ------問題------

移動順序を守ってドラクエをせよ。
ダメージ床があるので、適当に回復しても良い。
ただしHPに上限があるので、適切な順番をしろ。
このとき生きて全部の移動順序を守れるか。

-----問題ここまで----- */
/* -----解説等-----

やるだけbitDP

----解説ここまで---- */


const string dir = "URDL";
const int dy[] = { -1,0,1,0 }, dx[] = { 0,1,0,-1 };

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int INITHP, MaxHP;
	while (cin >> INITHP >> MaxHP, INITHP) {
		int H, W;
		cin >> H >> W;
		vector<string> g(H);
		FOR(i, 0, H)cin >> g[i];

		VI cost(26, 0);
		int t;  cin >> t;
		FOR(i, 0, t) {
			char c; int d;
			cin >> c >> d;
			cost[c - 'A'] = d;
		}

		VI trap;
		trap.push_back(0);
		int s, x = 0, y = 0;
		cin >> s;
		FOR(i, 0, s) {
			char c; int n;
			cin >> c >> n;
			int d = dir.find(c);
			FOR(k, 0, n) {
				y += dy[d]; x += dx[d];
				trap.push_back(cost[g[y][x] - 'A']);
			}
		}

		int p;
		cin >> p;
		VI potion(p);
		FOR(i, 0, p)cin >> potion[i];

		VVI dp(SZ(trap) + 1, VI(1 << p, 0));
		dp[0][0] = INITHP;

		FOR(i, 0, SZ(trap)) {
			FOR(bit, 0, 1 << p) {
				int cur = dp[i][bit];
				if (cur == 0)continue;
				dp[i + 1][bit] = max(dp[i + 1][bit], cur - trap[i]);
				FOR(j, 0, p) {
					if ((bit >> j) & 1)continue;
					int nxt = min(cur + potion[j], MaxHP);
					dp[i + 1][bit | (1 << j)] = max(dp[i + 1][bit | (1 << j)], nxt - trap[i]);
				}
			}
		}

		bool f = false;
		FOR(bit, 0, 1 << p)f |= (dp[SZ(trap)][bit] > 0);

		cout << (f ? "YES" : "NO") << endl;
	}
}