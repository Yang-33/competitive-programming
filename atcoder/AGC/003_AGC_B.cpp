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

/* -----  2018/02/23  Problem: 003_agc_b / Link: https://agc003.contest.atcoder.jp/tasks/agc003_b?lang=en ----- */
/* ------問題------

高橋君は 1 から N までの整数のうちのどれかが書かれたカードをたくさん持っています。 高橋君は整数 i が書かれたカードを Ai 枚持っています。

2 枚のカードについて、それらに書かれた整数の差の絶対値が 1 以下のとき、これらをペアにすることができます。

高橋君は、同じカードが複数のペアに使われないように、できるだけ多くのペアを作りたいです。高橋君が作れるペアの個数の最大値を求めてください。

-----問題ここまで----- */
/* -----解説等-----

言われた感じにやっていけば良い

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	VL a(N);

	FOR(i, 0, N) {
		cin >> a[i];
	}

	FOR(i, 0, N) {
		ans += a[i] / 2;
		a[i] = a[i] % 2;
		if (i != N - 1) {
			LL cnt = min(a[i], a[i + 1]);
			assert(cnt < 2);
			a[i] -= cnt;
			a[i + 1] -= cnt;
			ans += cnt;
		}
	}


	cout << ans << "\n";

	return 0;
}
