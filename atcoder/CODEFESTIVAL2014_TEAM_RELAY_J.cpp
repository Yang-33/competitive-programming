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

/* -----  2018/12/19  Problem: codefestival2014_team_relay J / Link: __CONTEST_URL__  ----- */
/* ------問題------

n 個の白い石が等間隔で直線上に並んでいます。隣接する石同士の距離は 1 です。
2 人のプレイヤーが、この石でゲームを行います。それぞれのプレイヤーは、自分のターンに、白い石を一つ選んで黒くするという操作を行います。ただし、直前のターンに黒くなった石から距離が k 以内の石を選ぶことはできません。
先に白い石を選べなくなったプレイヤーが負けとなります。
このゲームにおいて、互いに最善を尽くしたとき、先手と後手のどちらが勝つかを求めて下さい。

-----問題ここまで----- */
/* -----解説等-----

何も分からないときは初手実験。
ゲーム木のDPを書くととてもわかり易い規則性がわかるのでこれを書く。
なぜこれなのかはよくわかっていない。

----解説ここまで---- */

int N, K;
const int sz = 60;
map<LL, int>memo[sz][2];
const int WIN = 1;
const int LOSE = 2;
int f(int state, bool player = 0, int pre = 0) {
	if (memo[pre][player].count(state))return memo[pre][player][state];

	bool gotoLOSE = 0;
	FOR(sle, 1, N + 1) {
		if (state & 1LL << sle)continue;
		if (pre && abs(pre - sle) <= K)continue;
		int res = f(state | (1LL << sle), !player, sle);
		gotoLOSE |= (res == LOSE);
	}

	int subgame = gotoLOSE ? WIN : LOSE;
	return memo[pre][player][state] = subgame;
}

void test() {
	int Nmax = 15;
	FOR(n, 1, Nmax + 1) {
		cout << "N:=" << n << ", ";
		FOR(k, 0, n + 1) {
			N = n, K = k;
			FOR(i, 0, sz)FOR(p, 0, 2)memo[i][p].clear();
			int res = f(0, 0, 0);
			cout << "LW"[res == WIN];
		}cout << endl;
	}


}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	//	test();

	int N, K; cin >> N >> K;
	if (N & 1) {
		cout << "first" << endl;
	}
	else {
		if (K < N / 2) {
			cout << "second" << endl;
		}
		else {
			cout << "first" << endl;
		}
	}


	return 0;
}