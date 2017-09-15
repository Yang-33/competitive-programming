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

/* -----  2017/09/15  Problem: hackerrank_5days_game_theory_1  / Link: https://www.hackerrank.com/contests/5-days-of-game-theory/challenges/a-game-of-stones  ----- */
/* ------問題------

2,3,5しか取れない石取りゲーム

-----問題ここまで----- */
/* -----解説等-----

勝ちか負けの盤面しか存在しない。
したがって末尾の状態から再帰で計算していけばよい。
grundy数の計算でもできる

----解説ここまで---- */

LL N;
VI v = { 2,3,5 };
int game[102];

int grundy(int n) {
	if (game[n] != -1)return game[n];
	if (n < 0)return -1;
	set<int>se;
	FOR(i, 0, SZ(v)) {
		if (n - v[i] >= 0) {
			int temp = grundy(n - v[i]);
			if (temp >= 0)
			se.insert(temp);
		}
	}
	int subg = 0;
	while (se.count(subg))subg++;
	return game[n] = subg;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int T; cin >> T;

	FOR(i, 1, 101)game[i] = -1;
	game[0] = 0;

	FOR(t, 0, T) {
		cin >> N;
		cout << ((grundy(N) != 0) ? "First" : "Second") << "\n";
	}

	return 0;
}
