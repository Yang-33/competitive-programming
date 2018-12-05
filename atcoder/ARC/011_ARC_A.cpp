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
#define DD(x) 
#endif
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/12/14  Problem: ARC 011 A / Link: http://arc011.contest.atcoder.jp/tasks/arc011_a  ----- */
/* ------問題------

世界的大手鉛筆会社のファイバーカステラ社が、小さくなって使えなくなってしまった鉛筆を再利用する画期的な新技術を発明した。
この技術は小さくなった鉛筆 m 本から新しい鉛筆を n 本 (m>n) 作り出すものである。
ファイバーカステラ社が N 本の鉛筆を製造・販売し、その全てが使用されて回収され、回収された使えなくなった鉛筆から新しい鉛筆を作る。
これらを販売し、やはり全てが使用後回収されて新たな鉛筆の原料となる。これを繰り返した結果として、ファイバーカステラ社が総計何本の鉛筆を販売できるか計算するプログラムを作成せよ。
再利用する際に、回収されたにもかかわらず新しい鉛筆の原料とされなかった鉛筆を保持しておき、任意のタイミングで回収した鉛筆に加えても良い。
販売できる本数には、はじめの N 本も忘れずに加えること。また、 N>m とし、m と n が互いに素であるとする。

-----問題ここまで----- */
/* -----解説等-----

ノリがユークリッドの互除法なので計算量はlog、シュミレーションしても大丈夫。

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL m, n, N; cin >> m >> n >> N;
	LL ans = N;
	LL sub = 0;
	while (N >= m) {
		ans += (N / m) * n;
		N = N % m + (N / m) * n;
	}
	cout << ans << endl;

	return 0;
}