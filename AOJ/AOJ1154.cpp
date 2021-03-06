#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define FOR(i,s,e) for(int(i)=(s);(i) < (e);(i)++)
#define debug(x) cout << #x << ": " << x << endl

const int INF = 1e9;
const ll LINF = 1e16;
/* -----  2017/11/01  Problem: AOJ1154/ Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1154  ----- */
/* ------問題------

審判長日誌，宇宙暦 48642.5． われわれは，初等整数論から出題することに決めた． 正整数の素因数をすべて求めることに似た問題だが， そうではない．

7 で割った余りが 1 または 6 である正整数は 7N+{1,6} 数と呼ばれる． しかし，発音しにくいので， 月曜土曜数と呼ぼう．

月曜土曜数 a, b に対して， 月曜土曜数 x が存在して ax = b が成り立つとき， a を b の月曜土曜約数と呼ぶ． 月曜土曜数 a が月曜土曜数 b の月曜土曜約数であるためには， a が b の普通の意味の約数であれば必要十分であると， 簡単に証明できる．

1 より大きな月曜土曜数でそれ自身と 1 の他に月曜土曜約数をもたないものを， 月曜土曜素数と呼ぶ． 普通の意味の素数である月曜土曜数は月曜土曜素数であるが， 逆は一般に成り立たない． たとえば，27 は普通の意味の素数ではないが，月曜土曜素数である． 月曜土曜数 a の月曜土曜約数である月曜土曜素数を， a の月曜土曜素因数と呼ぶ． たとえば， 27 は月曜土曜素数であり， 216 = 27 × 8 が成り立つので， 27 は 216 の月曜土曜素因数のひとつである．

1 より大きなどんな月曜土曜数も， 1 個以上の月曜土曜素数の積として表すことができる． 表し方は，順序の違いを無視しても，必ずしも一通りではない． たとえば， 216 = 6 × 6 × 6 = 8 × 27 である．
選手は， 入力された各々の月曜土曜数に対して， その月曜土曜素因数をすべて出力するプログラムを書かなくてはならない．

-----問題ここまで----- */
/* -----解説等-----

月曜土曜数を先に列挙しておけば、クエリに答えるのに楽。

----解説ここまで---- */
bool getuyou[300000];

void getuyouSet() {
	for (int i = 2; i < 300000; i++) {
		if ((i % 7) != 1 && i % 7 != 6) continue;
		bool f = false;
		for (int j = 2; j*j <= i; j++) {
			if (i%j != 0) continue;
			if (j % 7 == 1 || j % 7 == 6) {
				f = true;
				break;
			}
		}
		if (!f) {
			getuyou[i] = true;
		}
	}
}

int main() {
	cin.tie(0); ios::sync_with_stdio(false);
	ll n;

    getuyouSet();

	while (cin >> n) {
		if (n == 1)break;
		cout << n << ":";
		for (int i = 6; i <= n; i++) {
			if (getuyou[i] == true && n%i == 0) {
				cout << " " << i;
			}
		}
		cout << endl;
	}
	return 0;
}