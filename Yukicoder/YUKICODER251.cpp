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
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/08/26  Problem: yukicoder 251  / Link: http://yukicoder.me/problems/no/251  ----- */
/* ------問題------

入力に整数 N と M が与えられる。
NのM乗(NM) を 129402307で割った余りを出力せよ。(129402307は素数である)

-----問題ここまで----- */
/* -----解説等-----

多倍長整数のmodは前からでも後ろからでも逐次とって良い。
これは10^kのもののmodを取る際に、10^kのmodを先にとっても良いからである。
a≧mod ∧ a%mod==0のときは答えが0でないとダメ。

----解説ここまで---- */

const int mod = 129402307;
long long modpow(long long a, long long b) {
	if (b == 0) return 1;
	return modpow(a * a % mod, b / 2) * (b & 1 ? a : 1) % mod;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string N, M; cin >> N >> M;
	LL n = 0;
	for (char c : N) {
		n *= 10;
		n += c - '0';
		n %= mod;
	}
	LL m = 0;
	for (char c : M) {
		m *= 10;
		m += c - '0';
		m %= (mod-1);
	}
	LL ans = modpow(n, m);
	if (M == "0")ans = 1;
	else if (n == 0)ans = 0;

	cout << ans << "\n";

	return 0;
}
