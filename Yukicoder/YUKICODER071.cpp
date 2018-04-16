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

/* -----  2018/04/16  Problem: yukicoder 071  / Link: http://yukicoder.me/problems/no/071  ----- */
/* ------問題------

コンピュータが登場する前、計算する道具といえば「そろばん」だった。
今回は、そのそろばんがテーマの問題である。

一般的なそろばんは、一列だけ見ると、５つ珠があり０〜9まで表すことができる。

これは、１列に串刺し状の上部１つの珠と下部４つの珠に分けて、
下部の動いている珠の数、上部の動いている珠分さらに5を足すという数の表現方法を行う。
つまり上部は、下部の数の繰り上がり数と見ることができる。
参考:Wikipedia
http://ja.wikipedia.org/wiki/%E3%81%9D%E3%82%8D%E3%81%B0%E3%82%93#.E5.B8.83.E6.95.B0.E6.B3.95
（そろばんを知らない方はごめんなさい。。）

このとき、Ursaは特殊なそろばんを思いついた。
一列に使える珠の合計をN個とし、上部と下部に使える珠の数は、合計でN個であれば自由に決めることができるとする。
この時、一列分で表現できる最大の数を求めてください。

ただし、表現方法としてできるのは、それぞれの珠の上げ下げの状態のみで判断するとする。
中途半端に動かすなどできないとし、上部・下部はそれぞれ連続に並んでいる珠なので３つ目が動くなら、１つ目２つ目も連動して動くような機構であるとする。
また、0から最大の数まで一意的な表現ができるとする。

-----問題ここまで----- */
/* -----解説等-----

全部のパターンをシュミレーションすれば良い。

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	FOR(i, 0, N) {// i:=上の数
		LL under = N - i;
		ans = max(ans, (i + 1)*(under + 1) - 1);

	}
	cout << ans << "\n";

	return 0;
}
