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

/* -----  2018/10/01  Problem: yukicoder 316  / Link: http://yukicoder.me/problems/no/316  ----- */
/* ------問題------

yumechiくんはプログラミング初心者なので， FizzBuzzの問題を解いている．
しかし，普通のFizzBuzzの問題は簡単すぎるので，もう少し発展的な問題を解いてみたいと思った．
普通のFizzBuzzでは，3の倍数の時に"Fizz"，5の倍数の時に"Buzz"が出力されるが，yumechiくんは3の倍数または5の倍数であるものをカウントすることを考える．
例えば，1以上100以下の範囲内で3の倍数または5の倍数の数は47個ある．

yumechiくんはこれを発展させ，1以上N以下の範囲で3つの整数a, b, cのどれかの倍数になる数字の個数（aの倍数またはbの倍数またはcの倍数になる数字の個数）をカウントしたいと考えている．
あなたは負けず嫌いなので，yumechiくんからこの話を聞いた際に，yumechiくんよりも早くプログラムを完成させたいと思い，すぐにコーディングに取り掛かった．

-----問題ここまで----- */
/* -----解説等-----

親切A*B*C感がある

----解説ここまで---- */

LL ans = 0LL;

long long  gcd(long long  a, long long  b) { return b ? gcd(b, a%b) : a; }
long long  lcm(long long  a, long long  b) { return a / gcd(a, b) * b; }


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, A, B, C; cin >> N >> A >> B >> C;
	
	ans = N / A + N / B + N / C - N / lcm(A,B) - N /lcm(B,C) - N / lcm(C,A) + N / lcm(A,lcm(B,C));

	cout << ans << "\n";

	return 0;
}
