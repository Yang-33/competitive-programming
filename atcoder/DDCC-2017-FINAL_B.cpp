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

/* -----  2018/03/03  Problem: ddcc-2017-final_b / Link: https://ddcc2017-final.contest.atcoder.jp/tasks/ddcc2017_final_b?lang=en  ----- */
/* ------問題------

高橋君は N 台のロボットを持っています。ロボットには番号 1,2,…,N がついています。
ロボットにはそれぞれ正整数が 1 つ書かれており、番号 i のロボットには ai が書かれています。
番号 i のロボットは、正整数 X,Y を渡すと、gcd(X,ai)=gcd(Y,ai) ならば「似てる」、そうでないならば「似てない」と言います。なお、この問題では gcd(X,Y) は X と Y の最大公約数とします。
正整数 X,Y について、N 台のロボット全てが「似てる」と言った時、X と Y はそっくりさんだとすることにします。
正整数 Z が与えられるので、Z とそっくりさんな数のうち、もっとも小さいものを求めてください。

-----問題ここまで----- */
/* -----解説等-----

えーなんでこれ昔解けなかったんや

求めるものをXとして、全てのiについて gcd(Z,a[i]) = gcd(X, a[i])
でなくてはならない
これはXにgcd(Z,a[i])を集める作業である。
これで最小のものが構成できるので、あとはgcd(Z,a[i])から素因数を回収すれば良い。
これはLCMでできる。

----解説ここまで---- */


/*最大公約数を求める関数(再帰版ユーグリッドの互除法)*/
long long  gcd(long long  a, long long  b) { return b ? gcd(b, a%b) : a; }

/*最小公倍数を求める関数。最小公倍数の性質( a×b÷[aとbの最大公約数] )を利用。*/
long long  lcm(long long  a, long long  b) { return a / gcd(a, b) * b; }

LL N,Z;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N>>Z;
	ans = 1;
	FOR(i, 0, N) {
		LL val; cin >> val;
		ans = lcm(ans, gcd(val, Z));
	}
	cout << ans << "\n";

	return 0;
}
