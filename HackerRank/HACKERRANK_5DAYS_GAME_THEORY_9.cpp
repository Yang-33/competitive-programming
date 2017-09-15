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

/* -----  2017/09/15  Problem: hackerrank_5days_game_theory_9  / Link: https://www.hackerrank.com/contests/5-days-of-game-theory/challenges/tower-breakers-3  ----- */
/* ------問題------

h[i]の高さのN個の山がある。この山のうち一つを選び、この山の高さを1以外の約数で割った高さに変更する。その際山は分割する。
2人でこのゲームをプレイした際の勝者はどちらか。

-----問題ここまで----- */
/* -----解説等-----

分割した際におなじ山がたくさんできる。これらの直和からgrundy数が分かるので、分割後の山の個数が偶数個のときはgrundy数は0となる。
したがって分割後の山の数が奇数個になるもののみ計算すればよい。
やはり終局面を考えるのは非常に大事。

----解説ここまで---- */

LL N;
int memo[100005];

int grundy(int x) {
	if (memo[x] != -1)return memo[x];
	set<int>se;
	for (int i = 2; i*i <= x; i++) {
		if (x%i != 0)continue;
		int quo = x / i;
		if(i%2)se.insert(grundy(quo));
		if(quo%2)se.insert(grundy(i));
	}
	se.insert(0);//x=> 1,1,1,1,1,..
	int subg = 0;
	while (se.count(subg))subg++;
	
	return memo[x] = subg;
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	FOR(i, 0, 100005)memo[i] = -1;
	memo[0] = memo[1] = 0;
	int T; cin >> T;

	FOR(t, 0, T) {
		cin >> N;
		int g = 0;
		FOR(i, 0, N) {
			int h; cin >> h;
			g ^= grundy(h);
		}
		cout << ((g != 0) ? "1" : "2") << "\n";
	}
	return 0;
}
