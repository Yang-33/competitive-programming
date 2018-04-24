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

/* -----  2018/04/24  Problem: yukicoder 118  / Link: http://yukicoder.me/problems/no/118  ----- */
/* ------問題------

玄関に飾る門松を作っている時に、あることに気づいた。

N本の竹を高さをそれぞれAiとしたときに、
それらから3本を自由に選んでよく、自由に並び替えて良い。
その時に何組の選び方の数が「門松列」になっているかを知りたくなった。

「門松列」とは、選んだ「3つの竹の長さの降順で2番目が、左または右側になっているもの」、「3つの長さはすべて異なる」という条件も満たすものであるとする。

N本の竹の高さが与えられるので、「門松列」にすることができる3つの竹の選び方の数を求めてください。
（並び順が違っても、同じ竹の組み合わせなら同じとカウントする。）

答えの数がintより多くなるので、(longよりは大きくならないようです）その値をmod 109+7で求めてください。

それぞれの竹は番号が振ってあるので区別ができるとする。

-----問題ここまで----- */
/* -----解説等-----

中央値を選択できたとすると、1,3番目の値も決定できる。
したがって中央値を選択し、それよりも小さい数字、それよりも大きい数字の個数がわかればよい。
これは累積和をとっておけば計算できる。
O(val)

また、これは一般化可能で組合せ論的に考えてKparameterでもO(K + N)とかで計算できる。

----解説ここまで---- */



LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	VL a(101, 0);
	FOR(i, 0, N) {
		int x; cin >> x;
		a[x]++;
	}
	FOR(i, 1, 101) {
		a[i] += a[i - 1];
	}
	FOR(i, 1, 101) {
		if (a[i] - a[i - 1]) {
			LL ret = (a[i - 1] - a[0])*(a[i] - a[i - 1]) *  (a[100] - a[i]);
			ans += ret;
			ans%=MOD;
		}
	}

	cout << ans << "\n";

	return 0;
}
