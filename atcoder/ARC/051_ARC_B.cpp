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

/* -----  2018/11/18  Problem: ARC 051 B / Link: http://arc051.contest.atcoder.jp/tasks/arc051_b  ----- */
/* ------問題------

高橋君は、ユークリッドの互除法というアルゴリズムを学びましたが、これがどのぐらいの速度で動くのか気になりました。
なので、以下のようなC言語のコードを書きました。
#include <stdio.h>
int counter = 0;
int gcd(int a, int b) {
	if (b == 0) return a;
	counter++;
	return gcd(b, a%b);
}
int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	gcd(a, b);
	printf("%d\n", counter);
}
これは、2 つの整数を標準入力から受け取り、そのgcdをユークリッドの互除法で求め、求める際に何回再帰したかを出力するコードです。
あなたは、このプログラムにいろんな値を出力させたくなりました。
具体的には、K が与えられるので、このプログラムの出力が K となるような a,b を一組求めてください。

-----問題ここまで----- */
/* -----解説等-----

余計な出力があっても通ったんだけど…
素数とか使おうと思ったけど全然そういう系ではなさそう。
互除法をひっくり返せたら嬉しいと途中で気がついたので、復元した
復元例は適当な1となるseedを逆にしてA+Bみたいにすればできる。
上限は、謎

解説にフィボナッチ数と書いてあった。
賢いなあ

----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N;

	cin >> N;
	auto f = [](int x, int y) {
		int counter = 0;
		function<int(int, int)> gcd = [&](int a, int b) {
			if (b == 0) return a;
			counter++;
			return gcd(b, a%b);
		};
		gcd(x, y);
		return counter;
	};

	int A = 1, B = 2;
	FOR(i, 1, N) {
//		cout << f(B, A) << endl;
		int T = B;
		B = A;
		A = B + T;
		//cerr << "aft:" << B << "," << A <<",,,,res:"<<i+1<<":="<<f(B,A)<< endl;
	}
	cout << B << " " << A << endl;
	//cout << f(B, A) << endl;
	return 0;
}
