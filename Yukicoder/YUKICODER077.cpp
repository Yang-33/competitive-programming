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

/* -----  2018/04/16  Problem: yukicoder 077  / Link: http://yukicoder.me/problems/no/077  ----- */
/* ------問題------

Vegaはレンガで平面ピラミッドを作りたいと考えてる。

庭には、すでにN列分のレンガが隙間なく積まれていて、それぞれのi列目の積まれている個数はAiで表される。
最初の配置から、レンガをいくつか動かして、ピラミッドの配置になるように並び替えたいです。

ピラミッドの配置とは、1から始めて[1,2,3,4,3,2,1]のように中心の位置まで１ずつ増え、中心以降は1ずつ減るような配置である。
(つまり、ピラミッド配置の列数は奇数になる。）

ピラミッドとは別の場所に、捨て置き場も設けられており、ピラミッドの配置に使われなかったレンガを置くこともできる。

移動とは、任意の列の一番上にある１つのレンガを持ち、別の列に移動するか、もしくは捨て置き場に移動することである。
このとき、ピラミッド配置は、最初の配置の1列目のレンガの場所から始めるとする。
与えられた列数よりか大きい列になる場合がある。
最初の配置から0個以上のレンガを移動しできるピラミッド配置への最小の移動数を求めてください。


ビラミッドの場所には１つのピラミッドのみがあるとして、不要なレンガはすべて捨て置き場に移動するとする。
レンガはどれも同じサイズの立方体であるとする。

-----問題ここまで----- */
/* -----解説等-----

持っている石の数よりも多い石が必要なピラミッドは作ることができない。  
また、頂点の高さがtopであるピラミッドをtopピラミッドと呼ぶことにすると、topピラミッドを作るのに対してtop-1ピラミッドを作るのは意味がない。  
というのは、石が多い場所からゴミあるいは不足している場所に移動させることから、小さいピラミッドを目指してもそこには過剰分の処理が出てしまうからである。  
したがって列のある場所をtopにしたいとしたときに必要な移動回数を全探索すれば良い。

[解説を見た]中心は固定？っぽいのでもっと簡単に解けた…

----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;
	VI a(N*100,0);
	FOR(i, 0, N) {
		cin >> a[i];
	}
	N *= 100;
	int sum = accumulate(ALL(a), 0);
	int s = 0, p = -1;
	while (s + p + 2 <= sum) {
		s += p + 2;
		p += 2;
	}
	int top = (p + 1) / 2;
	ans = INF;
	int t = top * 2 - 1;
	FOR(s, 0, N - t + 1) {//[s,t)に建てるとする
		LL ret = 0;
		FOR(i, 0, s) {
			ret += a[i];
		}

		FOR(i, s, s + t) {
			if (a[i] >= min(i + 1 - s, t - i - s)) {
				ret += a[i] - min(i + 1 - s, t - i - s);
			}
		}
		FOR(i, s + t, N) {
			ret += a[i];
		}
		ans = min(ans, ret);
	}

	cout << ans << "\n";

	return 0;
}
