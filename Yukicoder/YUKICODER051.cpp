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

/* -----  2018/04/12  Problem: yukicoder 051  / Link: http://yukicoder.me/problems/no/051  ----- */
/* ------問題------

Thomasのやる気は、簡単に計算できる。

締め切りまでの残りの日数をD日とし、
残りの作業量をWとすると その日のやる気はWD2となる。
そして、やる気の小数切り捨ての値が、その日の作業量になる。

Thomasは、最終日にどれだけ作業をしないといけなくなるかが気になっている。

最初の日に与えられた作業量Wと締め切りまでの日数Dが与えられるので
あなたは、Thomasが最後の日にどれだけの作業量があるか計算してあげてください。

(値の制約に気をつけてください。)

-----問題ここまで----- */
/* -----解説等-----

次の日の作業量が負になることはないので、シュミレーションしていくだけで良い。

----解説ここまで---- */

LL W,D;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> W>>D;
	FOR(d, 0, D) {
		LL w = W / (D-d) / (D-d);
		W -= w;
		if (d == D - 1)ans = w;

	}
	cout << ans << "\n";

	return 0;
}
