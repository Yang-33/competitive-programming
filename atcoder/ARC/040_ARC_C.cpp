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

/* -----  2018/10/17  Problem: ARC 040 C / Link: http://arc040.contest.atcoder.jp/tasks/arc040_c  ----- */
/* ------問題------

イカの高橋君は床を塗るのが大好きです。床は N×N のマス目状に区切られており、すでにいくつかのマスは塗られています。i 行目 j 列目のマスをマス (i,j) と呼ぶことにします。高橋君は特殊なインク発射装置を用いて床を塗ろうとしています。この装置を使うと、以下のように床を塗ることができます。
任意の整数 r,c を入力して装置のボタンを押すと、「i=r かつ j≦c」または「i=r+1 かつ j≧c」を満たすようなすべてのマス (i,j) を塗ることができる。
高橋君は、全てのマスをこの装置で塗ろうと思っています。このとき、装置を使う必要のある回数の最小値を求めてください。

-----問題ここまで----- */
/* -----解説等-----

まず解はMax(ans)=Nである。
これは、小さい方から一回あるrを選択したときに、2回選択するするよりも1回で全部塗るほうが良い。
次に、上の行の選択は次の行までしか影響しないので貪欲で良い。


----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; cin >> N;
	VS vs(N);
	FOR(i, 0, N) {
		cin >> vs[i];
	}
	// 同一のrの選択は一回のみ
	FOR(i, 0, N) {
		int Rend = N;
		FORR(j, N - 1, 0 - 1) {
			if (vs[i][j] == '.') {
				Rend = j; break;
			}
		}
		if (Rend != N) {
			ans++;
			if (i != N - 1) {
				FOR(j, Rend, N) {
					vs[i + 1][j]='o';
				}
			}
		}
	}


	cout << ans << "\n";

	return 0;
}
