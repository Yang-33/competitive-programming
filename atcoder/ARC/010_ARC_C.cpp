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

/* -----  2018/12/14  Problem: ARC 010 C / Link: http://arc010.contest.atcoder.jp/tasks/arc010_c  ----- */
/* ------問題------

高橋君はある日、以下のようなゲームで遊ぶことにしました。
m 色のブロックが n 個、1 つずつ順番に落ちてきます。
1 つ落ちてくるたびに、高橋君は落ちてきたそのブロックを取って山に積むか、積まずに捨てるか選べます。
ブロックを積む山は 1 つで、ブロックは必ず山の一番上に積まないといけません。
全てのブロックが落ちきった後、出来た山は以下のように評価されます。
色ボーナス：色ごとに決められた得点が、山に含まれている個数分与えられます。
コンボボーナス：同じ色のブロックが x 個続いて積まれている場合、コンポボーナス配点 Y に応じて Y×(x−1) 点が与えられます。
全色ボーナス：山の中に m 色のブロックがそれぞれ 1 個以上含まれていると Z 点が与えられます。
落ちてくるブロックの種類と順番、またそれぞれ山を評価するための配点が与えられたとき、評価で得ることのできる最高得点を求めなさい。

-----問題ここまで----- */
/* -----解説等-----

dp。メモリに気をつける。
dp(i,j,k):=ithで今までの選択集合がjで、前にkを選択(無も必要)のときの最大スコアとする。
X個続くことに意味はなくて連続のみが大事であることに気づけば解ける。

----解説ここまで---- */

int N, M, COMBO, ALLCOLOR;
int P[10];
int B[5000];
int dp[5001][1024][11];
int C_to_index[26];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> M >> COMBO >> ALLCOLOR;
	FOR(m, 0, M) {
		char c; int p; cin >> c >> p;
		int cc = c - 'A';
		C_to_index[cc] = m;
		P[m] = p;
	}

	{
		string s; cin >> s;
		FOR(i, 0, N) {
			int cc = s[i] - 'A';
			B[i] = C_to_index[cc];
		}
	}

	int G = 1 << M;
	int GMAX = G - 1;
	int dummy_color = M;

	auto update = [&](int i, int g, int c, int prev, int add) {
		if (prev == INF) return;
		if (dp[i][g][c] == INF) {
			dp[i][g][c] = prev + add;
		}
		else {
			dp[i][g][c] = max(dp[i][g][c], prev + add);
		}
	};

	FOR(i, 0, N)FOR(g, 0, G)FOR(x, 0, M + 1) {
		dp[i][g][x] = INF;
	}
	dp[0][0][dummy_color] = 0;

	// run
	FOR(i, 0, N) {
		FOR(g, 0, G) {
			FOR(c, 0, M + 1) {
				int b = B[i];
				int gg = g | (1 << b);
				int prev = dp[i][g][c];
				int ad = P[b];
				if (b == c) ad += COMBO;
				if (g != GMAX && gg == GMAX) ad += ALLCOLOR;
				update(i + 1, gg, b, prev, ad);
				update(i + 1, g, c, prev, 0);
			}
		}
	}
	int ans = -100000000;
	FOR(g, 0, G) {
		FOR(c, 0, M + 1) {
			if (dp[N][g][c] != INF) {
				ans = max(ans, dp[N][g][c]);
			}
		}
	}
	cout << ans << endl;

	return 0;

}