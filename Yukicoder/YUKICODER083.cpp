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

/* -----  2018/04/17  Problem: yukicoder 083  / Link: http://yukicoder.me/problems/no/083  ----- */
/* ------問題------

あなたは「最大マッチング問題」という有名問題に取り組んでいる。
これは、何本かのマッチ棒が与えられたとき、それらを並べて表記できる最大の数を求める問題である。
数の表記は、0 から 9 までの数字を横に並べることによって行う。
数字の表記法は下図の通りである。
マッチ棒は折ってはいけないが、すべて使い切る必要はない。
さて、N 本のマッチ棒が与えられたとき、それらを並べて表記できる最大の数を求めよ。

-----問題ここまで----- */
/* -----解説等-----

1をたくさんつくって奇数本余ったら7に書き換えると長い文字列を作ることができる。

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	if (N % 2 == 0) {
		cout << string(N / 2, '1') << endl;
	}
	else {
		cout << "7" << string((N - 3) / 2, '1') << endl;
	}


	return 0;
}
