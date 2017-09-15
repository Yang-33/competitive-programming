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

/* -----  2017/09/15  Problem: hackerrank_5days_game_theory_11  / Link: https://www.hackerrank.com/contests/5-days-of-game-theory/challenges/digits-square-board  ----- */
/* ------問題------

N*Nの盤面に一桁の数字が書き込まれている。この盤面を分割することを考える。
分割が可能なのは、盤面に素数でない数が含まれているときのみである。
分割できなくなった方の負けである。最適な行動をする2人でこのゲームを行ったときどちらが勝つか。

-----問題ここまで----- */
/* -----解説等-----

盤面が分割可能かはその盤面に含まれる素数でない数で決まる。それを求めるが、愚直にやるとN^2ここでオーダーをあげてしまうので、
累積和などを持つとよい。
それでも無思考setを使ったらTLEした。setに60あるだけでもそんなに遅いのかと思った。
O(n^5logN)->O(N^5)でAC. 高速化やめて♡

----解説ここまで---- */

int N;
int a[30][30];
LL ans = 0LL;
int ruiseki[31][31];
int primeSum[31][31];
int memo[31][31][31][31];
void init() {
	//FOR(i, 0, 30)FOR(j, 0, 30)a[i][j] = 0;
	//FOR(i, 0, 31)FOR(j, 0, 31)ruiseki[i][j] = 0;
	FOR(i, 0, 31)FOR(j, 0, 31)FOR(k, 0, 31)FOR(l, 0, 31)memo[i][j][k][l] = -1;
}

inline bool isprime(int x) {
	if (x == 2 || x == 3 || x == 5 || x == 7)return true;
	else return false;
}
int grundy(int sx, int sy, int tx, int ty) {
	int &g = memo[sx][sy][tx][ty];
	if (g != -1)return g;
	if (ruiseki[tx][ty] - ruiseki[sx][ty] - ruiseki[tx][sy] + ruiseki[sx][sy] == (tx - sx)*(ty - sy))return g = 0;
	bool se[62] = {};
	FOR(i, sx + 1, tx) { // x
		int sg = grundy(sx, sy, i, ty) ^ grundy(i, sy, tx, ty);
		se[sg] = 1;
	}
	FOR(i, sy + 1, ty) { // y
		int sg = grundy(sx, sy, tx, i) ^ grundy(sx, i, tx, ty);
		se[sg] = 1;
	}

	int subg = 0;
	while (se[subg])subg++;

	return g = subg;
}

int main() {
	//cin.tie(0);
	//ios_base::sync_with_stdio(false);

	int T; scanf("%d", &T);// cin >> T;
	//printf("%d", T);
	FOR(t, 0, T) {
		init();
		scanf("%d", &N);
		//cin >> N;
		FOR(i, 0, N) {
			FOR(j, 0, N) {
				scanf("%d", &a[i][j]);//cin >> a[i][j];
				ruiseki[i + 1][j + 1] = isprime(a[i][j]);
			}
		}

		FOR(i, 0, N)FOR(j, 0, N)ruiseki[i + 1][j + 1] += ruiseki[i + 1][j];
		FOR(i, 0, N)FOR(j, 0, N)ruiseki[i + 1][j + 1] += ruiseki[i][j + 1];

		puts((grundy(0, 0, N, N) != 0) ? "First" : "Second");
	}
	return 0;
}
