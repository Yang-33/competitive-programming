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

/* -----  2018/06/14  Problem: AOJ 2150 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2150  ----- */
/* ------問題------

Matsuzaki 教授は，宇宙の真理を研究している科学者である．人生，宇宙，すべての答えは 42 であると言われているが，Matsuzaki 教授はこれだけでは宇宙の真理を解明するには不十分であると考えている．Matsuzaki 教授は，宇宙の真理は 2 つのパラメータからなる関数で表されると考えており，42 はその 1 つに過ぎないというのである．
Matsuzaki 教授の定義した関数 M(N, P) は，N より大きい素数を 2 つ選んで（同じ数を 2 つでも構わない）和をとることで得られる数の全体を，小さいほうから順番に並べたときに，P 番目に現れる数を表す．ここで，2 通り以上の和で表されるような数も存在するが，そういった数は和の組み合わせの数と同じ個数だけ並べられる．
例として N = 0 の場合を考えよう．このときは素数全体から 2 つを選んで和をとることになる．そういった和のうちで最小の数を考えると，同じ数を 2 回選ぶことも許されていることから，2 + 2 = 4 であることがわかる．すなわち M(0, 1) = 4 である．次に小さい数は 2 + 3 = 5 であるから M(0, 2) = 5 となる．同様にして考えると，和を並べたものは 4, 5, 6, 7, 8, 9, 10, 10, 12, 13, 14, 14, 16, ... のようになることがわかる．すなわち，たとえば M(0, 9) = 12 である．
同じようにして N = 10 の場合を考えると，このときは 10 より大きい素数 {11, 13, 17, 19, ...} から 2 つを選ぶことになり，得られる和を小さいほうから並べると 22, 24, 26, 28, 30, 30, 32, ... のようになる．
あなたの仕事は，N と P が与えられた時に M(N, P) を計算するプログラムを書くことである．

-----問題ここまで----- */
/* -----解説等-----

まず先に素数表を作る。
次にP<=100なのでP^2ぐらいの表を作る。
これを検索すれば良い

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);


	VI prime(200000, 1);
	VL setp;
	setp.push_back(2);

	prime[0] = prime[1] = false;
	for (long i = 0; i<200000; ++i) {
		if (prime[i])
			for (long j = 2; i*j<200000; ++j) prime[i*j] = false;
	}

	for (long i = 3; i<200000; i += 2) {
		if (prime[i])setp.push_back(i);
	}

	int N, P;
	while (cin >> N >> P) {
		if (N == -1 && P == -1)break;
		VL m;
		int count = 0;
		while (setp[count] <= N) ++count;
		for (long i = count; i<count + 100; ++i) {
			for (long j = i; j<count + 100; ++j) {
				m.push_back(setp[i] + setp[j]);
			}
		}

		SORT(m);
		cout << m[P - 1] << endl;

	}

	return 0;
}