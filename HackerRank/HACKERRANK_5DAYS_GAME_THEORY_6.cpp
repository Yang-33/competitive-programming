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

/* -----  2017/09/15  Problem: hackerrank_5days_game_theory_6  / Link: https://www.hackerrank.com/contests/5-days-of-game-theory/challenges/nimble  ----- */
/* ------問題------

箱iに石がpile[i]個はいっている。
このときこの石をひとつだけ選び、添え字の小さい箱に移動できる。
全て箱0に移動したら終了として、どちらが勝つか。

-----問題ここまで----- */
/* -----解説等-----

各箱について、一つしか動かせないので、これはpile[i]山にそれぞれi個の石があるNimの集合とみることができる。
XORの演算を考えれば奇数個の山があるときしかgrundy数に影響がないのでこれを計算すればよい。
ちょっと時間かかった。

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int T; cin >> T;
	FOR(t, 0, T) {
		cin >> N;
		LL grundy = 0;
		FOR(i, 0, N) {
			LL pile; cin >> pile;
			if (i!=0&&(pile%2==1))grundy ^= i;
		}
		//debug(grundy);
		cout << ((grundy != 0) ? "First" : "Second") << "\n";
	}
	return 0;
}
