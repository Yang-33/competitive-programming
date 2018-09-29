#include "bits/stdc++.h"
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

/* -----  2018/09/29  Problem: yukicoder 301  / Link: http://yukicoder.me/problems/no/301  ----- */
/* ------問題------

1 から 6 までの整数が等確率にでる普通のサイコロがあります．
出目の和がちょうど N となるまで，このサイコロを振り続けます．
ただし，途中で出目の和が N を超えた場合は，その都度，出目の和をリセットし，0 にします．
振ることになる回数の期待値を求めるプログラムを書いて下さい．
サイコロを振る試行は独立であるとします．
ヒント：ここに全く同じ問題が有ります → http://yukicoder.me/problems/129．

-----問題ここまで----- */
/* -----解説等-----

小さいNについては、復習なのでできる。
不可能だと思うと、実験らしい
実験すると100以上はなんか一致しているので投げると通るとかいうクソ
解説も○○！ちゃんと書いてほしい…

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL T; cin >> T;
	FOR(_, 0, T) {
		LL N; cin >> N;

		double ans = 0;
		if (N >= 100) {
			ans = N + 5.0 / 3.0;
		}
		else {

			vector<double>A(N + 6, 0), B(N + 6, 0);
			FOR(i, N + 1, N + 6) {
				A[i] = 1;
			}
			FORR(i, N - 1, 0 - 1) {
				FOR(k, 1, 6 + 1) {
					A[i] += A[i + k] / 6.0;
					B[i] += B[i + k] / 6.0;
				}
				B[i]++;
			}
			ans = B[0] / (1 - A[0]);
		}

		cout << fixed << setprecision(13) << ans << "\n";
	}

	return 0;
}
