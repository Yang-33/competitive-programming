#include <bits/stdc++.h>
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

/* -----  2018/02/14  Problem: 070_abc_c / Link: https://abc070.contest.atcoder.jp/tasks/abc070_c?lang=en  ----- */
/* ------問題------

N 台の時計があり、i(1≦i≦N) 番目の時計の針はちょうど Ti 秒で時計盤を 1 周します。
最初、全ての時計の針は真っ直ぐ上に向いており、止まっています。
イルカは、全ての時計の針を同時に動かし始めました。
再び、全ての時計の針が真っ直ぐ上に向くのは何秒後でしょうか?

-----問題ここまで----- */
/* -----解説等-----

LCMだね

----解説ここまで---- */

LL N;

LL ans = 0LL;
/*最大公約数を求める関数(再帰版ユーグリッドの互除法)*/
long long  gcd(long long  a, long long  b) { return b ? gcd(b, a%b) : a; }

/*最小公倍数を求める関数。最小公倍数の性質( a×b÷[aとbの最大公約数] )を利用。*/
long long  lcm(long long  a, long long  b) { return a / gcd(a, b) * b; }

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	ans = 1;
	FOR(i, 0, N) {
		LL c; cin >> c;
		ans = lcm(ans, c);
	}
	cout << ans << "\n";

	return 0;
}
