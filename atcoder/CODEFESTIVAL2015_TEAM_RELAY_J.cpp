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
//#pragma GCC optimize ("-O3") 
#ifdef YANG33
#include "mydebug.hpp"
#else
#define DD(x) 
#endif
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/12/21  Problem: codefestival2015_team_relay J / Link: __CONTEST_URL__  ----- */
/* ------問題------

すぬけくんとりんごさんは、よくゲームをして遊びます。今日は石を使った以下のようなゲームをするようです。

2 つの石の山を作る。それぞれの山に含まれる石の個数は X 個、Y 個にする。
すぬけくんが先手、りんごさんが後手で交互に石を取っていき、どちらかの山の石の個数を 0 にした方が負けとなる。石を取るときのルールは以下の通りである。
まず、2 つの山のうち残っている石の個数が少ない方の石の個数を k とする。
2 つの山のどちらか一方を選び、1～k 個の石を取る。
2 人ともが勝ちを目指して最適な戦略を取るとき、どちらが勝つでしょうか？



-----問題ここまで----- */
/* -----解説等-----

実験をします。
左右対称なので適当に場合分けして終わり。

----解説ここまで---- */


const int sz = 100;
int dp[sz][sz][2];

const int WIN = 1;
const int LOSE = 2;
int f(int A, int B, bool player) {
	if (A == 0 || B == 0)return WIN;
	if (dp[A][B][player])return dp[A][B][player];

	bool gotoLOSE = 0;
	int ms = min(A, B);
	FOR(i, 1, ms + 1) {
		int res = f(A - i, B, !player);
		if (res == LOSE)gotoLOSE = 1;
	}
	FOR(i, 1, ms + 1) {
		int res = f(A, B - i, !player);
		if (res == LOSE)gotoLOSE = 1;
	}
	int subgame = gotoLOSE ? WIN : LOSE;
	return dp[A][B][player] = subgame;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	if (0) {
		FOR(i, 1, 50) {
			cout << i << " ";
			FOR(j, 1, 50) {
				int res = f(i, j, 0);
				cout << "LW"[res == WIN];
				string s[2] = { "LOSE","WIN" };
				string ans = s[res == WIN];
				//DD(de(i, j, ans));
			}
			cout << endl;
		}
	}
	else {
		auto solve = [](int X, int Y) {
			if (X > Y) swap(X, Y);
			const string Sente = "snuke";
			const string Gote = "rng";
			if (X == 4 && Y == 4) {
				cout << Gote << endl;
			}
			else if (X >= 4 && Y >= 4) {
				cout << Sente << endl;
			}
			else if (X == 1) {
				if (Y % 2 == 1) cout << Gote << endl;
				else cout << Sente << endl;
			}
			else if (X == 2) {
				if ((Y + 2) % 4 == 0) cout << Gote << endl;
				else cout << Sente << endl;

			}
			else {
				if (Y % 4 == 0 && Y > 4) cout << Gote << endl;
				else cout << Sente << endl;
			}
		};
		int X, Y; cin >> X >> Y;
		solve(X, Y);
	}
	return 0;
}
