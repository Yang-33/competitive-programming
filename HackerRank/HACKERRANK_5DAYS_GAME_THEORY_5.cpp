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

/* -----  2017/09/15  Problem: hackerrank_5days_game_theory_5  / Link: https://www.hackerrank.com/contests/5-days-of-game-theory/challenges/misere-nim  ----- */
/* ------問題------

Misere Nim

-----問題ここまで----- */
/* -----解説等-----

Nimの逆形。
ゲームの末尾の状態について考えれば、1がたくさんあるときに、これが奇数なら負け、偶数なら勝利である。
一方で山に1以外のものが存在していれば、これを操作して1である山の数の偶奇を調整できるため、これらはすべて勝ちの盤面になる。(1.1.1.1.11)の前の手(相手)の前の手(自分の手)をみればよい
したがってこの状態に移動することが可能かどうかが分かればよい。
この盤面のgrundy数は明らかに0ではないので、途中までは通常のNim戦略(0をわたす)で戦い、この状態になったときに適切な戦法を考えれば勝ちになる。

----解説ここまで---- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string First = "First";
	string Second = "Second";

	int T;  cin >> T;
	for (int t = 0; t < T; t++) {
		int N; cin >> N;
		vector<int> g(N, 0);
		int grundy = 0;
		int Mx = -INF;
		for (int i = 0; i < N; i++) {
			cin >> g[i];
			grundy ^= g[i];
			Mx = max(Mx, g[i]);
		}
		if (Mx == 1) {
			cout << ((N % 2 == 1) ? Second : First) << "\n";
		}
		else {
			cout << ((grundy != 0) ? First : Second) << "\n";
		}
	}

	return 0;
}
