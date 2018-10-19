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
#define DEBUG(x) 
#endif
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/10/17  Problem: ARC 040 B / Link: http://arc040.contest.atcoder.jp/tasks/arc040_b  ----- */
/* ------問題------

イカの高橋君は床を塗るのが大好きです。床は N 個のマスが左右に 1 列に並んでいるような形をしています。左から i 個目のマスをマス i と呼ぶことにします。すでにいくつかのマスは塗られていますが、いくつかのマスは塗られていません。高橋君はインクを発射できる射程が R の銃を使って全てのマスを塗ろうとしています。高橋君は最初マス 1 にいます。そして、1 秒の間に以下のいずれか 1 つの行動が行えます。

1 つ右のマスに移動する。すなわち、マス i からマス i+1 に移動する。ただし、マス N にいるときは行えない。
銃を撃って床を塗る。マス i にいるときに銃を撃つと、マス i からマス i+R−1 までのマスを全て塗ることができる。ただし、i+R−1 が N より大きい場合は、マス i からマス N までのマスが塗られる。
高橋君が全てのマスを塗るためにかかる時間の最小値を求めてください。

-----問題ここまで----- */
/* -----解説等-----

前から貪欲にとっていけば良い

----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);


	int N, R; cin >> N >> R;
	string s; cin >> s;

	while (N&&s[N - 1] == 'o') N--;

	int cnt = 0;
	FOR(i, 0, N - R) {
		if (s[i] == '.') {
			FOR(j, 0, R) s[i + j] = 'o';
			cnt++;
		}
		cnt++;
	}

	FOR(i, 0, SZ(s)) {
		if (s[i] == '.') {
			cnt++;
			break;
		}
	}

	cout << cnt << endl;

	return 0;
}
