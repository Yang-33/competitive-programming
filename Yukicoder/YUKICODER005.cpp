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

/* -----  2018/04/06  Problem: yukicoder 005  / Link: http://yukicoder.me/problems/no/005  ----- */
/* ------問題------

Ellenは数字のブロックで遊ぼうとしている。

数字が書かれているブロックはそれぞれ高さ1で幅はWi である。
（同じ幅のブロックが複数存在することがある。）

それらのブロックを高さ1,幅Lの箱の中に入れる。　

Ellenは大きな箱にどれだけブロックがたくさん入るか気になったが。
組み合わせがたくさんあって大変なことに気づいて、すぐに夜になってしまいそうである。

あなたは、代わりに大きな箱に最大何個のブロックが入るかを求めてください。

-----問題ここまで----- */
/* -----解説等-----

小さい順に敷き詰めるとするとしたときに、最後の2つについて入らなかったとき幅をa,bとする。(a<b)
a+b ≦ c+dなので(a≦c,b≦d)、小さい順に敷き詰めるのが良い。

----解説ここまで---- */

LL N,L;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> L>>N;
	VL a(N);
	FOR(i, 0, N) {
		cin >> a[i];
	}

	SORT(a);
	FOR(i, 0, N) {
		if (L - a[i] >= 0) {
			ans++;
			L -= a[i];
		}
	}
	cout << ans << "\n";

	return 0;
}
