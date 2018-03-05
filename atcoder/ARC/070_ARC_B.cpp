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

/* -----  2018/03/04  Problem: 070_arc_b / Link: https://abc056.contest.atcoder.jp/tasks/arc070_b?lang=en  ----- */
/* ------問題------

シカのAtCoDeerくんは正整数が書かれたカードを N 枚持っています。i(1≦i≦N) 枚目に書かれている数は ai です。 AtCoDeerくんは大きい数が好きなので、カードに書かれた数の総和が K 以上になるようなカードの部分集合をよい集合と呼びます。
そして、各カード i に対して、そのカードが不必要かどうかを次のように判定します。
「カード i を含む任意のよい集合に対して、その集合からカード i を除いたものもよい集合」 ならカード i は不必要
それ以外の場合は、不必要でない
不必要なカードの枚数を求めてください。ただし、それぞれの判定は独立に行われ、不必要だからと言ってカードが途中で捨てられたりすることはありません。

-----問題ここまで----- */
/* -----解説等-----

これ嘘解法やん->あっている
大きい数を持ってきて最低限必要な要素を確保できたとする。
このとき他の要素はあってもなくても現在の状態でKを確保できているため不必要である。
一方ある要素がないとK以上にならないときは必要である。

----解説ここまで---- */

LL N,K;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> K;
	VL a(N);
	FOR(i, 0, N) {
		cin >> a[i];
	}

	RSORT(a);
	FOR(i, 0, N) {
		LL ret = 0;
		FOR(j, 0, N) {
			if (i == j)continue;
			if (ret + a[j] < K) {
				ret += a[j];
			}
		}
		if (ret + a[i] >= K) {
			ans++;
		}

	}

	cout << N - ans << "\n";

	return 0;
}
