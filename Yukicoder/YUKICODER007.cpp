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

/* -----  2018/04/06  Problem: yukicoder 007  / Link: http://yukicoder.me/problems/no/007  ----- */
/* ------問題------

あなたと素数を習ったばかりのEveは、素数のゲームを思いついた。

ゲームの内容は以下のとおりです。
・まず初めに、先攻のプレイヤーに2以上の自然数Nが与えられます。
・その番のプレイヤーはNに対して、「N以下（Nも含む）の素数」のどれかで減算する、
その数をN′とすると、N′が0または1になってしまったら、そのプレイヤーの負けである。
・その後N′を新たなNとし、相手にその数を渡し、以上を繰り返します。

まずあなたが先攻となりゲームを始めます。
この時、どちらも負けないように動くと考える。自然数Nが与えられた時、
あなたが勝つことが出来る場合Win、それ以外はLoseを返してください。

-----問題ここまで----- */
/* -----解説等-----

Grundy数を知っていれば解ける。
負け状態の定義を踏まえると、2,3は負け状態が確定している。
したがってこれ以上のgrundy数を再帰的に求めていけば良い。

----解説ここまで---- */

#define primeN 10000 
vector<int>a;

void make_prime() {
	bool prime[primeN + 1];
	FOR(i, 0, primeN + 1) {
		prime[i] = 1;
	}prime[0] = prime[1] = 0;

	for (int i = 2; i <= primeN; i++) {
		if (prime[i]) {
			a.push_back((long long)i);
			for (int j = i * 2; j <= primeN; j += i)
				prime[j] = 0;
		}
	}
}

LL N;

LL ans = 0LL;

int grundy(int n, VI& state) {
	if (state[n] != -1)return state[n];
	set<int>se;
	FOR(i, 0, SZ(a)) {
		if (n - a[i] >= 2)se.insert(grundy(n - a[i],state));
		else break;
	}
	int subgame = 0;
	while (se.count(subgame))subgame++;
	return state[n] = subgame;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	make_prime();

	VI state(N + 1, -1);
	state[2] = state[3] = 0;
	ans = grundy(N, state);

	cout << (ans == 0 ? "Lose" : "Win") << "\n";

	return 0;
}
